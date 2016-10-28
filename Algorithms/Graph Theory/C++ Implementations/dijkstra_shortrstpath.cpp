/** Dijkstra'shortest path algorithm... Time COmplexity: O(N^2)
 ** @author: Arpan Pathak **/
#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;
int main()
{
    vector< vector<int> > G;
    vector<int> D,parent;   vector<bool> done;
    int n,v,e,u,w,previous,current_min=inf,index;
    cout<<"Enter number of vertices and edges=";
    cin>>n>>e;
    G.resize(n,vector<int>(n,inf));
    D.resize(n,inf);
    parent.resize(n,-1);
    done.resize(n,false);
    cout<<"Enter edges with weight u,v,w:\n";
    while(e--) { cin>>u>>v>>w;  G[u][v]=w;  }
    cout<<"Enter source vertex=";   cin>>u;
    D[u]=0; done[u]=true; previous=u;
    for(int j=1;j<n;j++){
        current_min=inf;
        for(int i=0;i<n;i++)
            if(!done[i] &&  G[previous][i]!=inf && D[i]>D[previous]+G[previous][i])
            {
                D[i]=D[previous]+G[previous][i];
                parent[i]=previous;
                if(D[i]< current_min){ current_min=D[i]; index=i; }
            }
            previous=index; done[previous]=true;
    }
    for(int i: D) cout<<i<<" ";
    cout<<"Path Array:-\n";
    for(int i: parent) cout<<i<<" ";
}
