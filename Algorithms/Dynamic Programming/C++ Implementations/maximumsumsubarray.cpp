/** Maximum Sum Sub Array by simple bottomUp dynamic programming... @uthor: Arpan Pathak **/
/** Time Complexity: O(N^2) this algorithm can be optimized	 			**/
#include <bits/stdc++.h>
#define ninf INT_MIN
using namespace std;
int M[1000][1000];
int maxsum(int *A,int n)
{
    int m=ninf;
    for(int l=1;l<=n;l++)
    {
        int i=0;
        for(int j=i+l-1;i<n && j<n;j++)
        {
            M[i][j]=(i==j)?A[i] : M[i][j-1]+A[j];
            m=max(m,M[i][j]);
            i++;
        }
    }
    return m;
}

int main()
{
    int x[]={-2, -3, 4, -1, -2, 1, 5, -3};
    cout<<maxsum(x,sizeof(x)/sizeof(x[0]));
}
