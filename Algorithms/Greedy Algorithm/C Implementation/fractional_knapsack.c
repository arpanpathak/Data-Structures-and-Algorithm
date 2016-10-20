/** Fractional Knapsack using greedy approach, @author: Arpan Pathak
 ** Time Complexity O(N log N) **/
#include <stdio.h>
typedef struct Item{
    int no;
    float value,weight,ratio;
}Item;
void swap(Item *a,Item *b) { Item temp=*a; *a=*b; *b=temp; }
int partition(Item *A,int start,int end)
{
   int pIndex=start,i;
   for(i=start;i<end;i++)
       if(A[i].ratio<=A[end].ratio)     swap(&A[i],&A[pIndex++]);
   swap(&A[end],&A[pIndex]);
   return pIndex;
}
void quick_sort(Item *A,int start,int end)
{
    if(start>=end)  return;
    int pIndex=partition(A,start,end);
    quick_sort(A,start,pIndex-1);      quick_sort(A,pIndex+1,end);
}
int main()
{
    int i,n;  float weight=0.0f,capacity,profit=0.0f;
    Item arr[100]; // array of items where each element has no,value,weight and value/weight ratio
    printf("Enter number of items=");   scanf("%d",&n);
    printf("Enter elements (profit,weight) :\n");
    for(i=0;i<n;i++) {		scanf("%f%f",&arr[i].value,&arr[i].weight);
        			arr[i].ratio=arr[i].value/arr[i].weight;    arr[i].no=i;  
    }
    printf("Enter capacity=");  scanf("%f",&capacity);
    quick_sort(arr,0,n-1); // sort using value to weight ratio and taking descending order for calculation
    for(int i=n-1;i>=0; i--)
			if(weight+arr[i].weight<=capacity)
			{
				weight+=arr[i].weight;  profit+=arr[i].value;
                printf("%d ==>100\%\n",arr[i].no);
			}
			else
			{
				profit+=(capacity-weight)*arr[i].ratio;
				printf("%d==>%f %\n",arr[i].no,100*(capacity-weight)/arr[i].weight);
				break;
			}
    printf("Maximum profit=%f",profit);
}
