/** 0,1 knapsack problem using 2d array , implemented by Arpan Pathak **/
#include <iostream>
using namespace std;
unsigned long long int M[100][100];
int knapsack(int items[][2],int n,int capacity)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=capacity;j++)
        {
            if(items[i-1][1]<=j)
                M[i][j]=max(items[i-1][0]+M[i-1][j-items[i-1][1]] , M[i-1][j] );
            else M[i][j]=M[i-1][j];
        }
    }
    return M[n][capacity];
}
int main()
{
     int items[][2]={ {22,4},{4,2},{15,3},{30,5},{108,7},{25,8}};
    cout<<knapsack(items,6,15);
}
