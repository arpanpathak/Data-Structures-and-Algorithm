/** Chain Matrix Multiplication using bottomUp dynamic programming implemented by Arpan Pathak 
 ** Time Complexity: O(N^3) 
**/
#include <bits/stdc++.h>
#define ULL unsigned long long int
#define inf 9223372036854775808
using namespace std;
ULL M[100][100];
int S[100][100];
ULL getMinimumCost(int *arr,int n)
{
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            M[i][j]=inf;
            for(int k=i;k<j;k++)
            {
                int q=M[i][k]+M[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(q<M[i][j])
                    M[i][j]=q;
                    S[i][j]=k;
            }
        }
    }
    return M[1][n];
}
void print(int i,int j)
{
 if(i==j)
 {
      cout<<"a"<<i;
      return;
 }
  cout<<"(";
  print(i,S[i][j]);
  print((S[i][j]+1),j);
  cout<<")";

}
int main()
{
    int n;
    cout<<"Size of chain ? ";
    cin>>n;
    int arr[n+1];
    cout<<"Enter orders : ";
    for(int i=0;i<=n;i++)   cin>>arr[i];
    cout<<"Minimum Multiplication Cost : "<<getMinimumCost(arr,n);
    cout<<endl;
    print(1,n);
}
