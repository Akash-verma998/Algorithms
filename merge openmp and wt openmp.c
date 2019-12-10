#include<stdio.h>
#include<time.h>
#include<omp.h>
#include<stdlib.h>
void  mergesort1(int a[],int n);
void  mergesort2(int a[],int n);
void merge(int a[],int l[],int r[],int left_count,int right_count );
int main()
{
  int i,n;
  clock_t start1,start2,end1,end2;
  printf("Enter the value of n:\n");
  scanf("%d",&n);
  int a[n];
  printf("Input is geting by complier...\n");
  for(i=0;i<n;i++)
   {
     a[i]=rand()%100;
     printf("%d\t",a[i]);
   }
   start1=clock();
   mergesort1(a,n);
   end1=clock();
   start2=clock();
   mergesort2(a,n);
   end2=clock();

   double cpu1,cpu2;
   cpu1=(double)(end1-start1)/CLOCKS_PER_SEC;
   cpu2=(double)(end2-start2)/CLOCKS_PER_SEC;

   printf("\ncpu %f   %f\n",cpu1,cpu2);
   //for(i=0;i<n;i++)
    // printf("%d\t",a[i]);
}
void mergesort1(int a[],int n)
{
 int *l,*r,mid,i,j;
  if(n<2)
   return ;
   mid=n/2;
   l=(int*)malloc(mid*sizeof(int));
   r=(int*)malloc((n-mid)*sizeof(int));
   for(i=0;i<mid;i++)
     l[i]=a[i];
    for(i=mid;i<n;i++)
     r[i-mid]=a[i];

     mergesort1(l,mid);
     mergesort1(r,n-mid);
     merge(a,l,r,mid,n-mid);
     free(l);
     free(r);
}
void merge(int a[],int l[],int r[],int left_count,int right_count )
{
  int i=0,j=0,k=0;
  while(i<left_count  && j<right_count)
  {
    if(l[i]<r[j])
    {
      a[k]=l[i];
      i++;
    }
    else
    {
      a[k]=r[j];
      j++;
    }
    k++;
  }

  while(i<left_count)
  {
   a[k]=l[i];
   i++;
   k++;
  }
  while(j<right_count)
  {
   a[k]=r[j];
   j++;
   k++;
  }
}

void mergesort2(int a[],int n)
{
 int *l,*r,mid,i,j;
  if(n<2)
   return ;
   mid=n/2;
   l=(int*)malloc(mid*sizeof(int));
   r=(int*)malloc((n-mid)*sizeof(int));
   for(i=0;i<mid;i++)
     l[i]=a[i];
    for(i=mid;i<n;i++)
     r[i-mid]=a[i];
 #pragma omp parallel sections num_threads(2)
 {
   #pragma omp section
   {
     mergesort2(l,mid);
   }
   #pragma omp section
   {
     mergesort2(r,n-mid);
    }

 }
 merge(a,l,r,mid,n-mid);
 free(l);
 free(r);
}



