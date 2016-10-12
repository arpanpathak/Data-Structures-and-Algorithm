/** Fractional Knapsack Problem 
 * Implemented By Arpan Pathak
 * Greedy Approach
 * **/
import java.util.*;
class Item implements Comparable<Item>
{
	public int value,weight;
	public String name;
	public float ratio; // value to weight ratio
	Item(String name,int value,int weight)
	{
		this.name=name;
		this.value=value;
		this.weight=weight;
		this.ratio=(float)value/(float)weight;
	}
	@Override // Overdiding compareTo method to make the objects of Item comparable
	public int compareTo(Item obj) {
		if(obj.ratio>this.ratio) return -1;
		else if(obj.ratio<this.ratio) return 1;
		return 0;
	}
	@Override
	public String toString(){
		return name+"=>{ value : "+value+", Weight : "+weight+", Ratio : "+ratio+" }";
	}

}
class Example {
	public static void main(String[] args) {
		Item[] arr={new Item("A",10,2),
					new Item("B",5,3),
					new Item("C",15,5),
					new Item("D",7,7),
					new Item("E",6,1),
					new Item("F",18,4),
					new Item("G",3,1)}; // Array of items used to test knapsack algorithm
		Arrays.sort(arr,Collections.reverseOrder());
		float capacity=15.0f,weight=0.0f,max_profit=0.0f;
		for(int i=0;i<7 && weight<=capacity; i++)
		{
			if(weight+arr[i].weight<=capacity)
			{
				weight+=arr[i].weight;
				max_profit+=arr[i].value;
				System.out.println(arr[i].name+"=>"+100+"%");
			}
			else
			{
				max_profit+=(capacity-weight)*arr[i].ratio;
				System.out.println(arr[i].name+"=>"+100*(capacity-weight)/arr[i].weight+"%");
				break;
			}
		}
		System.out.println("Maximum Profit ="+max_profit);
		
	}
}
