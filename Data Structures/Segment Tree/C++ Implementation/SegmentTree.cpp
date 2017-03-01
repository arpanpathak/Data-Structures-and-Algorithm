/** Binary Interval Tree or Segment Tree,
 ** Time Complexity for construct tree O(n),rangeQuery O(n log n)
 ** Space Complexity O(4n)
 ** @author: arpanpathak **/
#include <bits/stdc++.h>
#define inf INT_MAX
#define ninf INT_MIN
using namespace std;

template<class T> class SegmentTree
{
    vector<T> A;
    struct Node{
        T mx,mn,sum;
        Node(T m,T n,T s): mx(m),mn(n),sum(s) {  }
    };
    vector<Node> tree;
    public:
        SegmentTree(vector<T> &AR)
        {
            int s=AR.size();
            if(s&(s-1)==0)
                s=2*s-1;
            else{
                int bit=0;
                while(s!=0){
                    s>>=1; bit++;
                }
                s=1<<bit;
            }
            A=AR;
            tree.resize(2*s-1,Node(ninf,inf,0));
            construct(0,A.size()-1,0);
        }
        // Construct the segment tree in top down manner,....
        void construct(int low,int high,int pos)
        {
            if(low==high){
                tree[pos].mn=tree[pos].mx=tree[pos].sum=A[low];
                return;
            }

            int mid=(low+high)/2;
            construct(low,mid,2*pos+1);     // Constructing Left subtree
            construct(mid+1,high,2*pos+2); // Constructing Right subtree

            // Construct current node on the basis of left and right child//
            tree[pos].mx=max<T>(tree[2*pos+1].mx,tree[2*pos+2].mx);
            tree[pos].mn=min<T>(tree[2*pos+1].mn,tree[2*pos+2].mn);
            tree[pos].sum=tree[2*pos+1].sum + tree[2*pos+2].sum;
        }

        //Range Min Query
        T rangeMinQuery(int qlow,int qhigh,int low,int high,int pos)
        {
            if(qlow<=low && qhigh>=high) // total overlap
                return tree[pos].mn;
            if( qlow>high || qhigh<low) // no overlap
                return inf;
            int mid=(high+low)/2;
            return min(rangeMinQuery ( qlow,qhigh,low,mid,2*pos+1 ),
					    rangeMinQuery ( qlow,qhigh, mid+1, high, 2*pos+2) );
        }
        //Range Max Query..
        T rangeMaxQuery(int qlow,int qhigh,int low,int high,int pos)
        {
            if(qlow<=low && qhigh>=high) // total overlap
                return tree[pos].mx;
            if( qlow>high || qhigh<low) // no overlap
                return ninf;
            int mid=(high+low)/2;
            return max(rangeMaxQuery ( qlow,qhigh,low,mid,2*pos+1 ),
					    rangeMaxQuery ( qlow,qhigh, mid+1, high, 2*pos+2) );
        }
        //Range Sum Query
        T rangeSumQuery(int qlow,int qhigh,int low,int high,int pos)
        {
            if(qlow<=low && qhigh>=high) // total overlap
                return tree[pos].sum;
            if( qlow>high || qhigh<low) // no overlap
                return 0;
            int mid=(high+low)/2;
            return rangeSumQuery ( qlow,qhigh,low,mid,2*pos+1 )+
					    rangeSumQuery ( qlow,qhigh, mid+1, high, 2*pos+2);
        }
        void update(int node, int start, int end, int idx, T val)
        {
            if(start == end)
            {
                // Leaf node
                A[idx] += val;
                tree[node].sum += val;
                tree[node].mn=tree[node].mx=tree[node].sum;
            }
            else
            {
                int mid = (start + end) / 2;
                if(start <= idx && idx <= mid)
                {
                    // If idx is in the left child, recurse on the left child
                    update(2*node+1, start, mid, idx, val);
                }
                else
                {
                    // if idx is in the right child, recurse on the right child
                    update(2*node+2, mid+1, end, idx, val);
                }
	        // Internal node will have the sum of both of its children
	        tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
	        tree[node].mn = min(tree[2*node+1].mn , tree[2*node+2].mn);
	        tree[node].mx= max(tree[2*node+1].mx , tree[2*node+2].mx);
            }
        }
        /** All the public methods that can be called by users...
            Inner Implemention is hidden **/
        friend ostream& operator <<(ostream &o,SegmentTree &s){
            for(int i=0;i<s.tree.size();i++)
                o<<"(max="<<s.tree[i].mx<<",min="<<s.tree[i].mn
                <<",sum="<<s.tree[i].sum<<"),\n";
            return o;
        }
        /** For Range Minimum Query,Max Query and Sum Query **/
        T rangeMin(int qlow,int qhigh)
        {
            return rangeMinQuery(qlow,qhigh,0,A.size()-1,0);
        }
        T rangeMax(int qlow,int qhigh)
        {
            return rangeMaxQuery(qlow,qhigh,0,A.size()-1,0);
        }
        T rangeSum(int qlow,int qhigh)
        {
            return rangeSumQuery(qlow,qhigh,0,A.size()-1,0);
        }
};

int main()
{
    vector<int> a={1,2,3,4,5};
    SegmentTree<int> st(a);
    cout<<"Range Minimum (1,3) : "<<st.rangeMin(3,3)<<endl;
    cout<<"Range Sum (2,4) : "<<st.rangeSum(2,4);
}

