/** Heap Sort, implemented by Arpan Pathak,... Time Complexity O(N logN) **/
import java.io.*;
public class HeapSort {
	static void swap(int[] H,int i,int j) {int temp=H[i]; H[i]=H[j]; H[j]=temp;  } 
	static void downHeapify(int[] H,int N)
	{
		int i=0,j=0;
		while(2*i+1<N)
		{
			j=2*i+1;
			if(( (j+1<N) && H[i]>H[j] && H[i]>H[j+1]) || H[i]>H[j] ) break;// No need to heapify if max heap property is satisfied
			if((j+1<N) && H[j+1]>H[j]) j++;// extracting children with max value
			swap(H,i,j);
			i=j;
		}
	}
	static void heapsort(int[] H)
	{
		int M=H.length,N=M;
		/* ** Interchaning leaf node and root, then delete leaf node
				and
			  Keep doing down heapify to restore max heap property **/
		for(int i=0;i<M;i++)
		{
			swap(H,0,N-1);
			N--;
			downHeapify(H,N);
		}
	}
	static void upHeapify(int[ ] H,int index)
	{
		while((index>0) && (H[(index-1)/2]<H[index]) )
		{
			swap(H,index,(index-1)/2);
			index=(index-1)/2;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader ip=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the size of the array : ");
		int n=Integer.parseInt(ip.readLine());
		int[] H=new int[n];
		System.out.println("Enter Elementes");
		for(int i=0;i<n;i++)
		{
			H[i]=Integer.parseInt(ip.readLine());
			upHeapify(H,i);
		}
		heapsort(H);
		System.out.println("Displaying the sorted Array : ");
		for(int i: H)
			System.out.print(i+" ");
	}
}
