/** Bellman ford shortest path algorithm... Time Complexity: O(V.E)
 ** @author: Arpan Pathak **/
#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;
class Edge{
    public: int u,v,weight;
    Edge(int u,int v,int weight): u(u), v(v), weight(weight) { }
};
int main()
{
    vector<Edge> G;
    vector<int> D;
    int n,v,e,u,w;
    cout<<"Enter number of vertices and edges=";
    cin>>n>>e;
    D.resize(n,inf);
    cout<<"Enter edges with weight u,v,w:\n";
    while(e--) { cin>>u>>v>>w;    G.push_back(Edge(u,v,w)); }
    cout<<"Enter source vertex=";   cin>>u;
    D[u]=0;
    for(int i=1;i<=n-1;i++)
        for(int j=0;j<G.size();j++)
            if(D[G[j].u]!=inf && D[G[j].v] > D[G[j].u] + G[j].weight )
                D[G[j].v] = D[G[j].u] + G[j].weight;
    for(int i: D) cout<<i<<" ";
}
