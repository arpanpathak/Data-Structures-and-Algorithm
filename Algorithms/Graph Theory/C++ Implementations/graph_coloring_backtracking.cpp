/** Graph Coloring using backtracking. Time Complexity O(k*n^k)
 ** @author: Arpan Pathak **/
#include <bits/stdc++.h>
#define addEdge(u,v) G[u][v]=G[v][u]=true
using namespace std;
vector< vector<bool> > G;
vector<int> color;
bool isSafe(int v,int i){
    for(int p=0;p<G.size();p++)
        if(G[v][p] && color[p]==i)  return false;
    return true;
}
bool kcolor(int k,int v){
    if(v==G.size())
        return true;
    for(int i=1;i<=k;i++){
        color[v]=i;
        if(isSafe(v,i)){
            color[v]=i;
            if(kcolor(k,v+1)) return true;
            color[v]=0;
        }
    }
    return false;
}
int main(){
    int n,e,u,v,c,k;
    cout<<"Enter number of vertices and edges =";
    cin>>n>>e;
    G.resize(n,vector<bool>(n,false));
    color.resize(n,-1);
    cout<<"Enter connections : \n";
    while(e--) { cin>>u>>v; addEdge(u,v); }
    cout<<"Value of k="; cin>>k;
    if( kcolor(k,0) )
        for(int i: color)
            cout<<i<<" ";
    else cout<<"Graph can't be colored with "<<k<<" colors";
}
