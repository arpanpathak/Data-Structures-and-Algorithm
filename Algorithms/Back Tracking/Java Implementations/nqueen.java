/** nqueen problem using back tracking, implemented by Arpan Pathak
 ** Worst Case Time Complexity O(N^3) **/
import java.io.*;
public class nqueen {
	static int[] placed=new int[25];
	public static boolean isSafe(int k,int i)
	{
		if(k==0) return true;
		for(int j=0;j<=k-1;j++)
		{
			if(placed[j]==i || (Math.abs(j-k)==Math.abs(placed[j]-i)))
				return false;
		}
		return true;
	}
	public static void nqueen(int initial,int k,int n)
	{
		 boolean flag=false;
		    if(k<0 || k==n) return;
		    for(int j=initial;j<n;j++)
		    {
		        if(isSafe(k,j))
		        {
		            placed[k]=j;
		            flag=true;
		            break;
		        }
		    }
		    if(flag==true) nqueen(0,k+1,n);
		    else
		        nqueen(placed[k-1]+1,k-1,n);
	}
	public static void main(String[] args) throws Exception{
		BufferedReader ip=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter the value of n=");
		int n=Integer.parseInt(ip.readLine());
		nqueen(0,0,n);
		for(int i=0;i<n;i++)
	    	{
	        	for(int j=0;j<n;j++)
	        	{
	            	if(placed[i]==j)
	                	System.out.print("Q ");
	            	else
	            		System.out.print(". ");
	        	}
	        	System.out.println();
	    	}
	}
}
