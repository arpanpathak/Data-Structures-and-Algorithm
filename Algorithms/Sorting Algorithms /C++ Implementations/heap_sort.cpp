/* Heap sort implemented by Arpan Pathak, Time Complexity O(NlogN) */
#include <bits/stdc++.h>
using namespace std;
void downHeapify(int *H,int N)
{
	int i=0,j=0;
	while(2*i+1<N)
	{
		j=2*i+1;
		if(( (j+1<N) && H[i]>H[j] && H[i]>H[j+1]) || H[i]>H[j] ) break;// No need to heapify if max heap property is satisfied
		if((j+1<N) && H[j+1]>H[j]) j++;// extracting children with max value
		swap(H[i],H[j]);
		i=j;
	}
}
void heapsort(int *H,int N)
{
	int M=N;
	/* ** Interchaning leaf node and root, then delete leaf node
			and
		  Keep doing down heapify to restore max heap property **/
	for(int i=0;i<M;i++)
	{
		swap(H[0],H[N-1]);
		N--;
		downHeapify(H,N);
	}
}
void upHeapify(int *H,int index)
{
	while((index>0) && (H[(index-1)/2]<H[index]) )
	{
		swap(H[index],H[(index-1)/2]);
		index=(index-1)/2;
	}
}
int main()
{
    int n;
    cout<<"Please Enter the size of the Array=";
    cin>>n;
    int H[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>H[i];
        upHeapify(H,i);
    }
    heapsort(H,n);
    cout<<"Displaying the sorted Array : ";
    for(int i: H)
        cout<<i<<" ";
    return 0;
}
