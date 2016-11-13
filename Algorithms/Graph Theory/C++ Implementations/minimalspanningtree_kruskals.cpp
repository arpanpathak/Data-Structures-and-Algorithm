/** Kruskal's Minimal Spanning Tree Algorithm, time complexity O(VlogV)
**  @author: Arpan Pathak **/
#include <bits/stdc++.h>
using namespace std;
template<class T> struct Edge{
   T u,v; int w;
   Edge(T u,T v,int w): u(u),v(v),w(w) { }
   bool operator < (Edge<T> &obj) { return w<obj.w;  }
};
template<class T> class DisjointSets{
    map<T,T> disjoint;
    public:
        void makeSet(T a) { disjoint[a]=a; }
        T find(T a) { T parent=disjoint[a]; return (parent==a?a:find(parent) ); }
        bool unionn(T u,T v){
            T p1=find(u),p2=find(v);
            return p1!=p2? (disjoint[p2]=p1) : false;
        }
};
int main(){
    vector< Edge<char> > edges;
    DisjointSets<char> s;
    int n,e,min_cost=0,mst_edges=0;
    cout<<"Enter number of vertices and edges : "; cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        char u,v; int w; cin>>u>>v>>w; s.makeSet(u); s.makeSet(v); edges.push_back(Edge<char>(u,v,w));
    }
    sort(edges.begin(),edges.end());
    for(int i=0; i<e && mst_edges<n; i++){
        if(s.unionn(edges[i].u,edges[i].v)){
            min_cost+=edges[i].w; mst_edges++;
            cout<<"Edge ("<<edges[i].u<<","<<edges[i].v<<") is in MST, weight="<<edges[i].w<<endl;
        }
    }
    cout<<"Cost of Minimal Spanning Tree="<<min_cost;
}
