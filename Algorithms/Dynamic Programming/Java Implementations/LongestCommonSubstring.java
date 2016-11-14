/** Longest Common Substring using Dynamic Programming
 * @author arpanpathak */
public class LongestCommonSubstring {
	static int M[][],x,y;
	static int length_common_substring(String s1,String s2)
	{
		M=new int[s1.length()+1][s2.length()+1];
	    int max_length=Integer.MIN_VALUE;
	    for(int i=1;i<=s1.length();i++)
	    {
	        for(int j=1;j<=s2.length();j++)
	        {
	                M[i][j]=(s1.charAt(i-1)==s2.charAt(j-1))? M[i-1][j-1]+1 : 0;
	                if(M[i][j]>max_length) { x=i; y=j; }
	                max_length=Math.max(max_length,M[i][j]);
	        }
	    }
	    return max_length;
	}
	static void print(String s1,String s2,int i,int j)
	{
	    if(M[i][j]==0 ) return;
	    print(s1,s2,i-1,j-1);
	    System.out.print(s1.charAt(i-1));
	}
	public static void main(String[] args) {
		String s1="abcdxyzggmn",s2="cdxytvmty";
		System.out.println(length_common_substring(s1,s2));
		print(s1,s2,x,y);
	}
}
