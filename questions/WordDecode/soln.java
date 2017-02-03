/*** Solution using TreeMap ***/
import java.io.*;
import java.util.*;

public class soln {
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[]args)throws Exception{
		String s=br.readLine();
		String dict[]=s.split(" ");
		String l=br.readLine();
		Map<Integer,String> map=new TreeMap<>();
		for(int i=0;i<dict.length;i++)
			for(int j=l.indexOf(dict[i]);j<l.length() && j>-1;j=l.indexOf(dict[i],j+1))
				map.put(j,dict[i]);
		
		String sen="";
		for(int i:map.keySet()){
			sen=sen+map.get(i)+" ";
		}

		System.out.println(sen.trim());
	}

}
