/** Dijkstra's using priority queue... Time Complexity O(ElogV)
 ** @author: Arpan Pathak... **/
#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;
struct Edge{
    int v,w;
    Edge(int v,int w): v(v), w(w) { }
};
struct Comparator{ bool operator()(Edge &e1,Edge &e2) { return e1.w>e2.w;  } };
class Graph
{
    map<int,list< Edge> > G;
    map<int,int> parent;
    int n; // no of vertices
    public:
        Graph(int n): n(n+1) { }
        void addEdge(int u,int v,int w) { G[u].push_front(Edge(v,w)); //G[v].push_front(Edge(u,w));
         }
        void dijkstra(vector<int> &d,int source){
            priority_queue<Edge,vector<Edge>,Comparator> pque;
            d[source]=0;
            pque.push(Edge(source,0));
            while(!pque.empty())
            {
                Edge current=pque.top(); pque.pop();
                for(auto i: G[current.v])
                    if(d[i.v]>d[current.v]+i.w)
                    {
                        d[i.v]=d[current.v]+i.w;
                        pque.push(Edge(i.v,d[i.v]));
                        parent[i.v]=current.v;
                    }
            }
            cout<<"Vertex=>Parent"<<endl;
            for(auto i: parent)
                cout<<i.first<<"=>"<<i.second<<endl;
        }
};
int main(){
    int n,e,u,v,w;
    cout<<"Enter number of vertex and edges=";
    cin>>n>>e;
    Graph g(n);
    vector<int> d(n,inf);
    while(e--){
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    cout<<"Enter source vertex=";
    cin>>u;
    g.dijkstra(d,u);
    for(int i: d) cout<<i<<" ";
    return 0;
}
