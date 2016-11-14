/** Longest Common Subsequence using Dynamic Programming, Time Complexity: O(l1 X l2)
 * @author Arpan Pathak */
public class LongestCommonSubsequence {
	static int[][] M;
	static int LCS(String str1,String str2){
		M=new int[str1.length()+1][str2.length()+1];
		for(int i=1;i<=str1.length();i++)
			for(int j=1;j<=str2.length();j++)
				if(str1.charAt(i-1)==str2.charAt(j-1))
					M[i][j]=M[i-1][j-1]+1;
				else
					M[i][j]=Math.max(M[i-1][j],M[i][j-1]);

		return M[str1.length()][str2.length()];
	}
	static void print(String str,int i,int j){ 
		if(i<=0 || j<=0) return;
		if( (M[i][j]!=M[i][j-1] && M[i][j]!=M[i-1][j]) && (M[i][j]==M[i-1][j-1]+1) ){ 
			System.out.print(str.charAt(j-1));
			i--; j--;
		}
		else if( M[i][j-1] > M[i-1][j] ) j--;
		else  i--;
		print(str,i,j);
	}
	public static void main(String[] args) {
		System.out.println(LCS("abcxgzggmn","acttvvmnvt"));
		print("acttvvmnvt","abcxgzggmn".length(),"acttvvmnvt".length()); // Print in reverse order
	}
}
