/** Fractional Knapsack problem by greedy approach
/** Time Complexity O(Nlog N), @author: Arpan Pathak **/
#include <bits/stdc++.h>
using namespace std;
class Item
{
    public:  string name; float value,weight,ratio;
    Item(string name,float value,float weight): name(name),value(value),weight(weight), ratio(value/weight) {  }
    bool operator <(Item &obj) { return ratio>obj.ratio; }
};
int main()
{
    vector<Item> arr={ Item("A",10 ,2),
                       Item("B",5  ,3),
                       Item("C",15 ,5),
                       Item("D",7  ,7),
                       Item("E",6  ,1),
                       Item("F",18 ,4),
                       Item("G",3  ,1) }; // Array of items used to test knapsack algorithm
		sort(arr.begin(),arr.end()); // sorting in descending order of value/weight ratio
		float capacity=15.0f,weight=0.0f,max_profit=0.0f;
		for(int i=0;i<arr.size() && weight<=capacity; i++) // not using for each loop
		{
			if(weight+arr[i].weight<=capacity)
			{
				weight+=arr[i].weight;
				max_profit+=arr[i].value;
				cout<<arr[i].name<<"=>"<<100<<"%\n";
			}
			else
			{
				max_profit+=(capacity-weight)*arr[i].ratio;
				cout<<arr[i].name<<"=>"<<100*(capacity-weight)/arr[i].weight<<"%\n";
				break;
			}
        }
        cout<<"Maximum Profit="<<max_profit;
}
