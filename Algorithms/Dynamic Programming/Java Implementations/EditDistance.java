/*** Minimum Edit Distance using dynamic programming
 * @author: Arpan Pathak */
public class EditDistance {
	static int getMinEdit(String str1,String str2)
	{
		int[][] M=new int[str1.length()+1][str2.length()+1];
		for(int i=0;i<=str2.length();i++) M[0][i]=i;
		for(int j=0;j<=str1.length();j++) M[j][0]=j;
		for(int i=1;i<=str1.length();i++)
			for(int j=1;j<=str2.length();j++)
				M[i][j]=(str1.charAt(i-1)==str2.charAt(j-1)?
						 M[i-1][j-1]: Math.min(M[i-1][j], Math.min(M[i-1][j-1], M[i][j-1]))+1);
		return M[str1.length()][str2.length()];
	}
	public static void main(String[] args) {
		System.out.println(getMinEdit("abcdef","azced"));
	}
}

