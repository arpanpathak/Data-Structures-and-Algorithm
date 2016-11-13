/** Generate Combination of an Array of r elements *=
 ** @author: Arpan Pathak **/
#include <bits/stdc++.h>
using namespace std;
template<class T> void doCombinations(T *arr,T *data,int n,int r,int index,int i){
    if(index==r){
        for(int x=0;x<r;x++) cout<<data[x]<<",";
        cout<<endl;
        return;
    }
    if(i>=n) return;
    data[index]=arr[i];
    doCombinations(arr,data,n,r,index+1,i+1);
    doCombinations(arr,data,n,r,index,i+1);
}
template<class T> void combinations(T *arr,int n,int r){
    T data[n];
    doCombinations(arr,data,n,r,0,0);
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    combinations(arr,5,3);
    char a[]="ABCDEFGHI";
    combinations(a,9,4);
    combinations(a,9,1);
    return 0;
}
