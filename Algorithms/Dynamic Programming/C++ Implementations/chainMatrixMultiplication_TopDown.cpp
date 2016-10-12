/** implemented by Arpan Pathak, Top Down dynamic Programming to solve matrix chain multiplication cost 
    Time Complexity O(N^3) **/
#include <iostream>
#define ULL unsigned long long int
#define inf 9223372036854775808
using namespace std;
ULL M[100][100];
ULL cost(int *A,int i,int j)
{
    if(i==j) return 0; // Matrix Multiplication need atleast two matrices
    if(M[i][j]!=0) return M[i][j]; // Memorized previous sub problems
    M[i][j]=inf;
    for(int k=i;k<j;k++) {
        M[i][j]=min(M[i][j],cost(A,i,k) + cost(A,k+1,j) + A[i-1]*A[k]*A[j]);
    }
    return M[i][j];
}
int main()
{
    int n;
    cout<<"Size of chain ? ";
    cin>>n;
    int arr[n+1];
    cout<<"Enter orders : ";
    for(int i=0;i<=n;i++)   cin>>arr[i];
    cout<<"Minimum Multiplication Cost : "<<cost(arr,1,n);
}
