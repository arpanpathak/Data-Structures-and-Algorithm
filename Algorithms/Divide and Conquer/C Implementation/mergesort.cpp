/** Merge Sort Impmelented by Arpan Pathak
 ** Time Complexity O(N log N) **/
#include<stdio.h>
#include<stdlib.h>
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
	i = 0; j = 0; k =0;
	while(i<leftCount && j< rightCount) {
		if(L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return;

	mid = n/2;
	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((n- mid)*sizeof(int));
	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];

	MergeSort(L,mid);
	MergeSort(R,n-mid);
	Merge(A,L,mid,R,n-mid);
        free(L);
        free(R);
}
int main() {
  int n, array[1000], i;
  printf("Enter number of elements\n");
  scanf("%d", &n);
  printf("Enter %d integers\n", n);
  for (i = 0; i < n; i++)   scanf("%d", &array[i]);
  MergeSort(array,n);
  printf("Sorted list in ascending order:\n");
  for (i = 0; i < n ; i++)  printf("%d\n", array[i]);
  return 0;
}
