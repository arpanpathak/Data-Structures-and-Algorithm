/** Directed Graph using adjacency list, implemented by Arpan Pathak **/
#include <bits/stdc++.h>
#define INF LONG_MAX
using namespace std;
template<class K,class V>
class Edge
{
        public:
            K vertex; V weight;
            Edge(K vertex,V weight): vertex(vertex),weight(weight) { }
};
template<class K,class V>
class Graph
{
    map<K,list<Edge<K,V>> > G;
    int n;

    public:
        Graph(int n): n(n) { }

        void addEdge(K u,K v,V w) { G[u].push_front(Edge<K,V>(v,w)); }
        // typename required for this kind of user defined type object iterator
         V getWeight(K u,K v) {
            for(typename list<Edge<K,V>>::iterator i=G[u].begin();i!=G[u].end();++i)
                if(i->vertex==v) return i->weight;
            return INF;
        }
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
};
int main()
{
    Graph<string,int> G(5);
    G.addEdge("Delhi","Mumbai",15);
    G.addEdge("Delhi","Kolkata",20);
    G.addEdge("Dhaka","Kolkata",50);
    G.print();
}

