#include <stdio.h>
#include "quicksort.h"
#define makeSet(a) parent[a]=a
int parent[100]={0};
int find(int a){  return (parent[a]==a? a: find(parent[a]) ); }
int uniion(int a,int b)
{
    if(find(a)!=find(b)) { parent[b]=a; return 1; }
    else return 0; // tricky.. if union forms a cycle in MST then don't do union
}
int main(){
    Edge edges[100]; // maximum 100 edges are allowed.. Array of edges are used
    int n,e,u,v,w,min_cost=0,mst_edges=0;
    printf("Enter number of edges and vertices=");
    scanf("%d%d",&n,&e);
    printf("Enter connections (u,v,weight) :\n");
    for(int i=0;i<e;i++){  scanf("%d%d%d",&u,&v,&w);    makeSet(u);   makeSet(v);
                           edges[i].u=u;                edges[i].v=v; edges[i].weight=w;  }
    quick_sort(edges,0,e-1);
    for(int i=0; i<e && mst_edges<n; i++){
        if(uniion(edges[i].u,edges[i].v)){
            min_cost+=edges[i].weight;
            printf("Edge (%d,%d) is in MST, weight=%d\n",edges[i].u,edges[i].v,edges[i].weight);
        }
    }
    printf("Cost of Minimal Spanning Tree=%d",min_cost);
}
