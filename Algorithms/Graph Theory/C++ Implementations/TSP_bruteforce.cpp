/** Traveling Salesman Problem using brute force, Time Complexity: O(N! )
 ** @author: Arpan Pathak **/
#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;
int G[100][100];
int main(){
    string permutation="",route="";
    int e,n,u,v,w,cost=inf;
    cout<<"Enter number of vertices and edges=";
    cin>>n>>e;
    cout<<"Enter connections(u,v,w) :\n";
    while(e--){ cin>>u>>v>>w; G[u][v]=w; G[v][u]=w; }
    cout<<"Enter source vertex="; cin>>u;
    permutation+=(u+'0');
    for(int i=0;i<n;i++){
        if(i!=u)
        permutation+=(i+'0');
    }
    permutation+=(u+'0');
    do{
        int current_cost=0;
        for(int i=0;i<permutation.length()-1;i++){
            if(!G[permutation.at(i)-'0'][permutation.at(i+1)-'0']){
                current_cost=inf; break;
            }
            current_cost+=G[permutation.at(i)-'0'][permutation.at(i+1)-'0'];
        }
        if(current_cost<cost ){
            cost=current_cost;
            route=permutation;
        }
    }while(next_permutation(permutation.begin()+1,permutation.end()-1));
    cout<<"Minimum Cost of TSP="<<cost<<endl;
    cout<<"TSP route : "<<route;
    return 0;
}
