/** Merge Sort... Time Complexity for all cases O(N log N),. @author: Arpan Pathak **/
#include <iostream>
using namespace std;
void merge(int *A,int *L,int leftCount,int *R,int rightCount )
{
    int i=0,j=0,k=0;
    while(i<leftCount && j<rightCount)
        if(L[i]<R[i])   A[k++]=L[i++];
        else            A[k++]=R[j++];
    while(i<leftCount)  A[k++]=L[i++];
    while(j<rightCount) A[k++]=R[j++];
}
void merge_sort(int *arr,int n)
{
    if(n<2) return;
    int mid=n/2, L[mid], R[n-mid];
    for(int i=0 ; i<mid ;i++)      L[i]=arr[i];
    for(int i=mid ;i<n; i++ )      R[i-mid]=arr[i];
    merge_sort(L,mid);             merge_sort(R,n-mid);
    merge(arr,L,mid,R,n-mid);
}
int main()
{
    int A[]={10,9,8,7,6,5,4,3,2,1};
    merge_sort(A,sizeof(A)/sizeof(A[0]));
    for(int i: A) cout<<i<<" ";
}
