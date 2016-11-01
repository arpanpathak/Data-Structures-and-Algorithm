/** Implementation of all pairs shortest path for Directed Graph by Arpan Pathak
  * using floyd warshall algorithm. Time Complexity O(V^3) **/
#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
/** Using Adjacency Matrix to implement Directed weighted graph **/
class Graph
{
    int **G,**PATH,n;
    public:
        Graph(int n){
            this->n=n;
            G=new int*[n];
            PATH=new int*[n];
            for(int i=0;i<n;i++){
                G[i]=new int[n];
                PATH[i]=new int[n];
                for(int k=0;k<n;k++) { G[i][k]=(i==k?0:INF); PATH[i][k]=-1; }
            }
        }
        void connect(int i,int j,int weight) { G[i][j]=weight; PATH[i][j]=i; }
        void generateSortestPath()
        {
            for(int k=0;k<n;k++)
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        {
                            if(G[i][k]==INF || G[k][j]==INF) continue;
                            if(G[i][j] > G[i][k] + G[k][j])
                            {
                                G[i][j]=G[i][k]+G[k][j]; PATH[i][j]=PATH[k][j];
                            }
                        }
        }
        void printPath(int start,int end,int i,int j)
        {
            if(i<0 || j<0 || PATH[i][j]<0) return;
            if(PATH[i][j]==start){ cout<<start<<"-->"; return; }
            printPath(start,end,i,PATH[i][j]);
                cout<<PATH[i][j]<<"-->";
            if(j==end) cout<<end;
        }
        friend ostream& operator <<(ostream& out,Graph &obj){
            for(int i=0;i<obj.n;i++){
                for(int j=0;j<obj.n;j++)
                    if(obj.G[i][j]==INF) out<<"\t INF "; else out<<"\t "<<obj.G[i][j]<<" ";
                out<<endl;
            }
            out<<"\tPATH MATRIX:\n";
            for(int i=0;i<obj.n;i++){
                for(int j=0;j<obj.n;j++)
                    if(obj.PATH[i][j]==-1) out<<"\t N"; else out<<"\t "<<obj.PATH[i][j]<<" ";
                out<<endl;
            }
            return out;
        }
        ~Graph(){
            for(int i=0;i<n;i++){
                delete[] G[i];
                delete[] PATH[i];
                }
        }
};
int main()
{
    int n,e,u,v,w;
    cout<<"Enter Number of nodes and edges=";
    cin>>n>>e;
    Graph G(n);
    cout<<"Enter all the edges (u,v,w) :\n";
    for(int i=1;i<=e;i++) { cin>>u>>v>>w; G.connect(u,v,w); }
    G.generateSortestPath(); // Generate all pair shortest path using floyd Warshall 
    cout<<G;
    cout<<endl;
    // G.printPath(0,2,0,2); // call as printPath(start,end,start,end); extra parameter is added to avoid stack implementation
}
