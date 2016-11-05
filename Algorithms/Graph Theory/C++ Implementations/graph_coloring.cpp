/** Chromatic Number of a graph...Time Complexity O(V^2)
 ** @author: Arpan Pathak **/
#include <bits/stdc++.h>
#define addEdge(u,v) G[u][v]=G[v][u]=true
using namespace std;
int assignColors(vector< vector<bool> > &G,vector<int>  &color){
    int chromatic_no=0;
    for(int i=0;i<G.size();i++){
        color[i]=1;
        for(int j=0;j<G.size();j++)
            if(G[i][j] && color[j]==color[i])
                color[i]++;
        chromatic_no=max(chromatic_no,color[i]);
    }
    return chromatic_no;
}
int main(){
    vector< vector<bool> > G;
    int n,e,u,v;
    cout<<"Enter number of vertices and edges =";
    cin>>n>>e;
    G.resize(n,vector<bool>(n,false));
    vector<int> color(n);
    cout<<"Enter connections : \n";
    while(e--) { cin>>u>>v; addEdge(u,v); }
    cout<<"Chromatic Number="<<assignColors(G,color)<<endl;
    cout<<"Assigned Colors : \n";
    for(int i=0;i<color.size();i++) cout<<"Vertex "<<i<<": Color"<<color[i]<<endl;
}
