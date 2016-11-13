/** Next lexicographic permutation 
 ** @author: Arpan Pathak **/
#include <bits/stdc++.h>
using namespace std;
template<class T> bool nextpermu(T *arr,int n){
    int pivot=n-1,j=n-1,i;
    for(i=n-1;arr[i]<=arr[i-1];i--) pivot=i-1;
    pivot--;
    if(pivot<0) return false; // this is the last permutation.. no next permutation possible
    while(arr[j]<=arr[pivot]) j--;
    swap(arr[j],arr[pivot]);
    for(i=pivot+1,j=n-1;i<j;i++,j--)
        swap(arr[i],arr[j]);
    return true;
}
int main(){
    int arr[]={0,1,2,5,3,3,0};
    nextpermu(arr,sizeof(arr)/sizeof(int));
    for(int i: arr) cout<<i<<",";
    char str[]="abc";
    do{
        cout<<str<<endl;
    }while(nextpermu(str,3));
}
