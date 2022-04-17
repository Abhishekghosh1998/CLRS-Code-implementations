#include<stdio.h>
#include<limits.h>

void merge(int *A, int p, int q, int r)
{

	int L[q-p+2];
	int R[r-q+1];
	
	int i;
	
	for(i=p;i<=q;i++)
		L[i-p]=A[i];
	L[i-p]=INT_MAX;
	
	for(i=q+1;i<=r;i++)
		R[i-q-1]=A[i];
	R[i-q-1]=INT_MAX;
	
	int j;
	i=0;j=0;
	int k=p;
	while(k<=r)
	{
		if(L[i]<=R[j])
			A[k++]=L[i++];
		else
			A[k++]=R[j++];
	}
}

void mergeSort(int *A, int p, int r)
{
	if(p>=r)
		return;
	int q=(p+r)/2;
	mergeSort(A,p,q);
	mergeSort(A,q+1,r);
	merge(A,p,q,r);
}

int main()
{
	int n;
	printf(" N ? ");
	scanf("%d",&n);
	int i;
	int A[n];
	for(i=0;i<n;i++)
		scanf("%d",A+i);
	printf("ARRAY AFTER SORTING : \n");
	mergeSort(A,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
}

