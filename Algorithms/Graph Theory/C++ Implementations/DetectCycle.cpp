/** Detect Cycle in directed graph using DFS algorithm, implemented by Arpan Pathak **/
#include <bits/stdc++.h>
#define INF INT_MAX
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

         V getWeight(K u,K v) {

            for(typename list<Edge<K,V>>::iterator i=G[u].begin();i!=G[u].end();++i)
                if(i->vertex==v) return i->weight;
            return INF; // if there is no edge between u and v then return infinity
        }

        /** following method will print the adjacency list which represents this Graph object **/
        void print()
        {
            for(auto i: G)
            {
                cout<<i.first<<"==>";
                for(typename list<Edge<K,V>>::iterator j=G[i.first].begin(); j!=G[i.first].end(); ++j)
                    cout<<"("<<j->vertex<<","<<j->weight<<"), ";
                cout<<endl;
            }
        }
        bool hasCycle(K start)
        {
            stack<K> s; map<K,char> status;
            for(auto i: Vertices)
                status[i]=(i==start?'P':'N'); // N indicate Not Processed, P indicates Processing and F indicate Finished
            s.push(start);
            while(!s.empty())
            {
                int c=0;
                K explore=s.top();
                for(auto i: G[explore])
                {
                    if(status[i.vertex]=='N'){
                        s.push(i.vertex); status[i.vertex]='P'; c++;
                        break;
                    }
                    else if(status[i.vertex]=='P') { return (cout<<"Graph has cycle") && true; }
                }
                if(!c) { status[explore]='F'; s.pop(); }
            }
            return (cout<<"Graph has no Cycle") && false;
        }
};

int main()
{
    Graph<string,int> G;
    G.addEdge("A","B",10);
    G.addEdge("A","C",20);
    G.addEdge("A","D",12);
    G.addEdge("D","E",12);

    //G.addEdge("E","A",13); // addition of this edge will create a cycle in the graph
    G.print();
    G.hasCycle("A");
}
