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
		
		/* Calculating next power of two... if size of arr is power of 2
		 * then size of segment tree will be 2*size of arr-1, else
		 * the size will be 2*next power of two -1 
		 */
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
	public long rangeMinQuery(int qlow,int qhigh)
	{
		return rangeMinQuery(qlow,qhigh,0,arr.length-1,0);
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
	
	@Override
	public String toString()
	{
		String result="";
		for(MiniMax i: tree)
			result+="("+i.min+","+i.max+",sum="+i.sum+")";
		return result;
	}
}
public class SegmentTreeExample {
	public static void main(String[] args) 
	{
		long a[]={-1,0,3,6};
		SegmentTree st=new SegmentTree(a);
		System.out.println(st);
		System.out.println(st.rangeMinQuery(0, 3));
	}
}

