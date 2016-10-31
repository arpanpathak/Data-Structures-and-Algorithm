/** This Header File Contains definition of Edge structure and quick sort
 ** Quick Sort Time Complexity O(N log N)... @author: Arpan Pathak
**/
typedef struct Edge{
    int u,v,weight; // u it the start vertex, v is the end vertex
}Edge;
// Applying quikc sort to sort the edge list in increasing order of their wright
void swap(Edge *a,Edge *b) { Edge temp=*a; *a=*b; *b=temp; }
int partition(Edge *A,int start,int end)
{
   int pIndex=start,i;
   for(i=start;i<end;i++)
       if(A[i].weight<=A[end].weight)     swap(&A[i],&A[pIndex++]);
   swap(&A[end],&A[pIndex]);
   return pIndex;
}
void quick_sort(Edge *A,int start,int end)
{
    if(start>=end)  return;
    int pIndex=partition(A,start,end);
    quick_sort(A,start,pIndex-1);      quick_sort(A,pIndex+1,end);
}
