/** Prims Algorithm using priority queue... Time Complexity O(VlogV)
 ** @author: Arpan Pathak... **/
#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int v,w;
    Edge(int v,int w): v(v), w(w) { }
};
struct Comparator{ bool operator()(Edge &e1,Edge &e2) { return e1.w>e2.w;  } };
class Graph
{
    map<int,list< Edge> > G;
    int n; // no of vertices
    public:
        Graph(int n): n(n+1) { }
        void addEdge(int u,int v,int w) { G[u].push_front(Edge(v,w)); G[v].push_front(Edge(u,w)); }
        int getMSTPrims(int start_vertex){
            int cost=0;
            vector<bool> visited(n);
            priority_queue<Edge,vector<Edge>,Comparator> pque;

            pque.push(Edge(start_vertex,0));

            while(!pque.empty())
            {
                Edge current=pque.top(); pque.pop();
                if(visited[current.v]) continue;
                cost+=current.w;
                visited[current.v]=true;
                for(auto i: G[current.v])
                    if(!visited[i.v])
                        pque.push(Edge(i.v,i.w));
            }
            return cost;
        }
};
int main(){
    int n,e,u,v,w;
    cin>>n>>e;
    Graph g(n);
    while(e--){
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    cin>>u;
    cout<<g.getMSTPrims(u);
    return 0;
}
