/** Segment Tree for range Mini,Max and sum query
 * Time Complexity for constructing the tree: O(N)
 * Time Complexity for finding minimum within a range : O(log N)
 * Time Complexity for finding maximum within a range : O(log N)
 * Time Complexity for finding sum within a range : O(log N)
 * @author arpanpathak
 *
 */
class SegmentTree
{
	final long inf=Long.MAX_VALUE, ninf=Long.MIN_VALUE;
	MiniMax[] tree; 
	long[] arr;
	int size;
	class MiniMax
	{
		long min,max,sum;
		MiniMax(long min,long max,long sum){ this.min=min; this.max=max; this.sum=sum;  }
	}
	SegmentTree(long arr[])
	{
		
		int x = (int) (Math.ceil(Math.log(arr.length) / Math.log(2)));
        size = 2 * (int) Math.pow(2, x) - 1; // 2*size will be next power of two-1 
      
        tree=new MiniMax[size]; // allocating ....
        this.arr=arr;
        for(int i=0;i<size;i++)
        	tree[i]=new MiniMax(inf,ninf,0);
        // Now calling the constructTree function to construct segment tree
        constructTree(0,arr.length-1,0);
	}
	
	
	/** Utility Function to test rangeMinQuery **/
	public long rangeMin(int qlow,int qhigh)
	{
		return rangeMinQuery(qlow,qhigh,0,arr.length-1,0);
	}
	
	public long rangeMax(int qlow,int qhigh)
	{
		return rangeMax(qlow,qhigh,0,arr.length-1,0);
	}
	public long rangeMax(int qlow,int qhigh,int low,int high,int pos)
	{
		if(qlow<=low && qhigh>=high) // total overlap
			return tree[pos].max;
		if( qlow>high || qhigh<low) // no overlap
			return ninf;
		int mid=(high+low)/2;
		return Math.max(rangeMax ( qlow,qhigh,low,mid,2*pos+1 ),
					    rangeMax ( qlow,qhigh, mid+1, high, 2*pos+2) );
	}
	// method for range minimum query
	public long rangeMinQuery(int qlow,int qhigh,int low,int high,int pos)
	{
		if(qlow<=low && qhigh>=high) // total overlap
			return tree[pos].min;
		if( qlow>high || qhigh<low) // no overlap
			return inf;
		int mid=(high+low)/2;
		return Math.min(rangeMinQuery ( qlow,qhigh,low,mid,2*pos+1 ),
					    rangeMinQuery ( qlow,qhigh, mid+1, high, 2*pos+2) );
	}
	public long rangeSum(int qlow,int qhigh)
	{
		return rangeSum(qlow,qhigh,0,arr.length-1,0);
	}
	public long rangeSum(int qlow,int qhigh,int low,int high,int pos)
	{
		if(qlow<=low && qhigh>=high) // total overlap
			return tree[pos].sum;
		if( qlow>high || qhigh<low) // no overlap
			return 0;
		int mid=(high+low)/2;
		return rangeSum ( qlow,qhigh,low,mid,2*pos+1 )+
					    rangeSum ( qlow,qhigh, mid+1, high, 2*pos+2);
	}
	private void constructTree(int low,int high,int pos)
	{
		if(low==high){
			tree[pos].sum=tree[pos].max=tree[pos].min=arr[low];
			return;
		}
		int mid=(low+high)/2;
		constructTree(low,mid,2*pos+1); // construct left subtree
		constructTree(mid+1,high,2*pos+2); // construct right subtree
		
		tree[pos].max=Math.max(tree[2*pos+1].max,tree[2*pos+2].max);
		tree[pos].min=Math.min(tree[2*pos+1].min,tree[2*pos+2].min);
		tree[pos].sum=tree[2*pos+1].sum + tree[2*pos+2].sum;
	}
	void update(int node, int start, int end, int idx, long val)
	{
	    if(start == end)
	    {
	        // Leaf node
	        arr[idx] += val;
	        tree[node].sum += val;
	        tree[node].min=tree[node].max=tree[node].sum;
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
	        tree[node].min = Math.min(tree[2*node+1].min , tree[2*node+2].min);
	        tree[node].max= Math.max(tree[2*node+1].max , tree[2*node+2].max);
	    }
	}
}
public class SegmentTreeExample {
	public static void main(String[] args) 
	{
		long a[]={-1,0,3,6};
		SegmentTree st=new SegmentTree(a);
		System.out.println(st);
		System.out.println(st.rangeMin(0, 3));
	}
}

