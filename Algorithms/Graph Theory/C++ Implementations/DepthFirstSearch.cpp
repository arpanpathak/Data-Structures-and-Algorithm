/** Depth First Search algorithm .. @author: Arpan Pathak
 *  Time Complexity O(VE) **/
#include <bits/stdc++.h>
using namespace std;
/* Edge Class will contain description of edge (end vertex and weight) */
template<class K,class V>
class Edge
{
        public:
            K vertex; V weight;
            Edge(K vertex,V weight): vertex(vertex),weight(weight) { }
};
/** Graph Template class where K specifies data type of vertex value and V specifies data type of edge weight **/
template<class K,class V>
class Graph
{
    map<K,list<Edge<K,V>> > G; // map will map each vertex to a linked list which contains all adjacent vertices
    set<K> Vertices; // set is used to keep track of all vertices because we are using adjacency list

    public:
        void addEdge(K u,K v,V w) { G[u].push_front(Edge<K,V>(v,w));  Vertices.insert(u); Vertices.insert(v); }
        void DFS(K start_vertex)
        {
            map<K,bool> visited;
            for(auto i: Vertices)       visited[i]=(i==start_vertex?true:false);
            DFS(start_vertex,visited);
        }
        void DFS(K start_vertex,map<K,bool> &visited)
        {
            cout<<start_vertex<<",";
            visited[start_vertex]=true;
            for(auto i: G[start_vertex])
                if(!visited[i.vertex]) DFS(i.vertex,visited);
        }
};
int main()
{
    Graph<string,int> G;
    G.addEdge("A", "D", 1);
    G.addEdge("A", "B", 1);
    G.addEdge("B", "C", 1);
    G.addEdge("D", "E", 1);
    G.DFS("A");
}
