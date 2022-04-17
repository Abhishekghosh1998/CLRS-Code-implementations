#include<stdio.h>

void sort(int n, int* A)
{
	int i;
	for(i=1;i<n;i++)
	{
		int j=i-1;
		int temp=A[i];
		while(j>=0 && A[j]>temp)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=temp;
	}
}

int main()
{
	int n;
	printf("ENTER THE NUMBER OF ELEMENT : ");
	scanf("%d",&n);
	int A[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",A+i);
	printf("ARRAY AFTER SORTING : \n");
	sort(n,A);
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}
