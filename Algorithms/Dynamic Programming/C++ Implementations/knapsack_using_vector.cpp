/** 0,1 Knapsack Problem using bottomUp dynamic programming, implemented by Arpan Pathak **/
#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<vector<int>> items,int capacity)
{
    vector<vector<int>> K;
     for(int i=0;i<=items.size();i++)
     {
        vector<int> temp;
        for(int j=0;j<=capacity;j++)
        {
            if(i==0||j==0)  temp.push_back(0);
            else if(items[i-1][1]<=j)
                temp.push_back(max(K[i-1][ j-items[i-1][1] ] + items[i-1][0], K[i-1][j]));
            else
                temp.push_back(K[i-1][j]);
        }
        K.push_back(temp);
    }
    return K[items.size()][capacity];
}
int main()
{   /** {value, weight } **/
    vector<vector<int>> items={ {22,4},{4,2},{15,3},{30,5},{108,7},{25,8}};
    cout<<knapsack(items,15);
}
