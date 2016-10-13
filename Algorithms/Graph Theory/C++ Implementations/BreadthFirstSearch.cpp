/** Breadth First Search algorithm implemented by Arpan Pathak
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
        void BFS(K start_vertex)
        {
            queue<K> que; map<K,bool> visited;
            for(auto i: Vertices)
                visited[i]=(i==start_vertex?true:false);
            que.push(start_vertex);
            while(!que.empty())
            {
                K explore=que.front(); que.pop(); cout<<explore<<",";
                for(auto i: G[explore])
                {
                    if(!visited[i.vertex]){
                        que.push(i.vertex); visited[i.vertex]=true;
                    }
                }
            }
        }
};
int main()
{
    Graph<string,int> g;
    g.addEdge("A", "B", 10);
    g.addEdge("A", "C", 15);
    g.addEdge("A", "D", 11);
    g.addEdge("D", "E", 20);
    g.BFS("A");
}
