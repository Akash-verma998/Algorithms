#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void knapSack(int M, float w[], float p[], int n);
int main()
{
	int n,i,j;
	float r[100000],w[100000],p[100000],temp1,temp2,temp3,M;
	printf("Enter the capcity of the knapsack:");
	scanf("%f",&M);
	printf("Enetr the number of object:");
	scanf("%d",&n);
   //printf("Enter the weight of the object:");

	clock_t start=clock();
	for(i=0;i<n;i++)
	{
		w[i]=rand()%100;
	    //printf("%f \n",w[i]=rand()%100);
	}
	printf("Enetr the profit of the object:");
	for(i=0;i<n;i++)
	{
		p[i]=rand()%100;
	//	printf("%f \n",p[i]=rand()%100);
	}
    for (i=0; i<n; i++)
	{
      r[i] = p[i]/w[i];
    }
    for (i=0;i<n;i++) {
      for (j=i+1;j<n;j++) {
         if (r[i]<r[j]) {
            temp1=r[j];
            r[j]=r[i];
            r[i]=temp1;
            temp2=w[j];
            w[j]=w[i];
            w[i]=temp2;
            temp3=p[j];
            p[j]=p[i];
            p[i]=temp3;
         }
      }
   }
	knapSack(M,w,p,n);
	clock_t end=clock();
	double result=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time: %f\n",result);
	return 0;
}
void knapSack(int m,float w[],float p[],int n) {
   float x[100000], tp = 0;
   int i, j, u;
   u = m;

   for (i=0;i<n;i++)
      x[i]=0.0;

   for (i=0;i<n;i++) {
      if (w[i]>u)
         break;
      else {
         x[i]=1.0;
         tp=tp+p[i];
         u=u-w[i];
      }
   }
   if(i<=n)
      x[i]=u/w[i];

   tp=tp+(x[i]*p[i]);
   int c=1;
   printf("\nThe Values of x:  ");
   for (i = 0; i<n; i++){
   	  if(x[i]!=0.0)
   	  printf("\n object no : %d and x[%d]=%.2f\n",c++,i, x[i]);
   	  else
   	  {
   	  	break;
	  }
   }
   printf("\nMaximum profit is: %.2f\n ", tp);
}
