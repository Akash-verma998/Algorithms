#include<stdio.h>
#include<limits.h>
int s[10][10];
#define max 9999
 int Matrix_chain_mul(int p[],int n)
 {
     int i,j,k,l,q,m[10][10];
     for(i=1;i<n;i++)
     {
         m[i][i]=0;
     }
     for(l=2;l<n;l++)
     {
         for(i=1;i<n-l+1;i++)
         {
             j=i+l-1;
             m[i][j]=max;
             for(k=i;k<j;k++)
             {
                 q=m[i][k]+m[k+1][j]+p[i-1]*p[j]*p[k];
                 if(q<m[i][j])
                 {
                     m[i][j]=q;
                     s[i][j]=k;
                 }
             }
         }
     }
     return m[1][n-1];
 }

int main()
{
	int n,i;
	printf("Enter the number of matrix :");
	scanf("%d",&n);
	n++;
	int arr[n];
	printf("Enter the dimension:\n");
	for(i=0;i<n;i++)
	{
		printf(" Enter d%d :: ",i);
		scanf("%d",&arr[i]);
	}
	//int size=sizeof(arr)/sizeof(arr[0]);
	printf("Minimum Number of Multipliaction is %d",Matrix_chain_mul(arr,n));
	return 0;

}

