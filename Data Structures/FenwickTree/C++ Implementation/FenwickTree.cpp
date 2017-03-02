/*** Fenwick Tree or Binary Index Tree for range and prefix sum query
    Time Complexity for constructing tree --> O(n*log n),
                range or prefixSum query  --> O(log n),
                updating single element   --> O(log n)
    @author: arpanpathak
 ***/
#include <bits/stdc++.h>
using namespace std;
template<class T> class BIT
{
    vector<T> arr,tree;
    public:
        BIT(vector<T> &arr)
        {
            tree.resize(arr.size()+1,0);
            this->arr=arr;
            for(int i=0;i<arr.size();i++)
                update(i,arr[i]);
        }
        void update(int idx,int val)
        {
            for( ++idx ; idx<=arr.size();tree[idx]+=val,idx+=idx&(-idx) );
        }
        T prefixSum(int idx)
        {
            T sum=0;
            for( ++idx ; idx>0; sum+=tree[idx],idx-=idx&(-idx) );
            return sum;
        }
        T rangeSum(int l,int r)
        {
            return prefixSum(r)-prefixSum(l-1);
        }
};
int main()
{
    vector<int> ar={1,2,3,-4,5,6,7,1};
    BIT<int> bt(ar);
    cout<<bt.prefixSum(4)<<endl;
    cout<<bt.rangeSum(3,6);
    return 0;
}
