/** Detect Hamiltonoan Cycle using backtracking.
 ** @author: Arpan Pathak **/
#include <bits/stdc++.h>
#define addEdge(u,v) G[u][v]=G[v][u]=true
using namespace std;
vector< vector<bool> > G;
vector<int> path;
bool isSafe(int pos,int i){
    if(!G[ path[pos-1] ][i] )    return false;
    for(int p=0;p<pos;p++) if(path[p]==i) return false;
    return true;
}
bool hasHamiltonian(int pos){
    if(pos==G.size())
    {
        if ( G[ path[pos-1] ][ 0 ] ) return true;
        else return false;
    }
    for(int i=1;i<G.size();i++){
        if(isSafe(pos,i)){
            path[pos]=i;
            if(hasHamiltonian(pos+1)) return true;
            path[pos]=-1;
        }
    }
    return false;
}
int main(){
    int n,e,u,v,c,k;
    cout<<"Enter number of vertices and edges =";
    cin>>n>>e;
    G.resize(n,vector<bool>(n,false));
    path.resize(n,-1); path[0]=0;
    cout<<"Enter connections : \n";
    while(e--) { cin>>u>>v; addEdge(u,v); }
    if( hasHamiltonian(1) ){
        cout<<"Hamiltonian Cycle : ";
        for(int i: path)
            cout<<i<<"-->";
        cout<<"0";
    }
    else cout<<"Graph doesn't have any hamiltonian cycle...";
}
