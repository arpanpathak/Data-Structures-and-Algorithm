/** Coin Change Problem implemented by Arpan Pathak using greedy approach
 * Greedy approach will not work for all denominations but it will work for indian rupee **/
public class CoinChangeINR {
	static int min(int arr[],int val)
	{
		int m=0;
		for(int i=arr.length-1;i>=0;i--) if(arr[i]<=val) {m=arr[i]; break; }
		return m;
	}
	static int mimimumCoin(int arr[],int amount)
	{
		int n=0,remaining=amount;
		while(remaining>0)
		{
			int m=min(arr,remaining);
			n+=remaining/m;
			System.out.println(remaining/m+" No of "+m+" Rupee Coin/Note");
			remaining-=m*(remaining/m);
		}
		return n;
	}
	public static void main(String[] args) {
		int arr[]={1,5,7,10};
		System.out.println("Minimum Coin required="+mimimumCoin(arr,65));
	}
}
