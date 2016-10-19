#include <bits/stdc++.h>
#define INF INT_MAX
#define SHORTEST(u,v) print_path(PATH,u,v,u,v)
using namespace std;
void floyed_warshahh(vector<vector<int>> &arr,vector<vector<int>> &PATH)
{
    for(int k=0;k<arr.size();k++)
        for(int i=0;i<arr.size();i++)
            for(int j=0;j<arr.size();j++){
                arr[i][j]=(arr[i][k]==INF|| arr[k][j]==INF)?arr[i][j]   : min(arr[i][j],arr[i][k]+arr[k][j]);
                PATH[i][j]=(arr[i][k]==INF|| arr[k][j]==INF)?PATH[i][j] : PATH[k][j];
                }
}
void print_path(vector<vector<int>> &PATH,int start,int end,int i,int j)
{
    if(i<0 || j<0 || PATH[i][j]<0 )   return;
    if(PATH[i][j]==start)           { cout<<start<<"-->"; return; }
    print_path(PATH,start,end,i,PATH[i][j]);
        cout<<PATH[i][j]<<"-->";
    if(j==end)  cout<<end;
}
int main()
{
    vector<vector<int>> G,PATH; int n,e,u,v,w;
    cout<<"Enter number of vertices and edges : ";          cin>>n>>e;
    G.resize(n,vector<int>(n,INF));                         PATH.resize(n,vector<int>(n,-1));
    cout<<"Enter edges and their weights (u,v,w) : ";
    while(e--) { cin>>u>>v>>w; G[u][v]=w; PATH[u][v]=u; }
    floyed_warshahh(G,PATH);
    cout<<"Enter the pair of vertices that you want to see shortest path : ";
    cin>>u>>v;
    SHORTEST(u,v);
}
