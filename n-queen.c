#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int board[100],count;
int place(int row,int column);
void print_board(int n)
{

	int i;
	printf("The (row,column) where queen can Placed...\n\n");
	printf("{");
	for(i=1;i<=n;i++)
	{
		printf("(%d , %d ) ",i,board[i]);
	}

	printf("}");
}
void queen(int row,int n)
{
	int column;
	for(column=1;column<=n;column++)
	{
		if(place(row,column))
		{
			board[row]=column;
			if(row==n)
			{
				int i,j;
                printf("\n\nSolution %d:\n\n",++count);

                for(i=1;i<=n;++i)
                   printf("\t%d",i);

                for(i=1;i<=n;++i)
                {
                   printf("\n\n%d",i);
                   for(j=1;j<=n;++j) //for nxn board
                   {
                    if(board[i]==j)
                    printf("\tQ"); //queen at i,j position
                    else
                   printf("\t-"); //empty slot
                  }
        }
        printf("\n");
			    print_board(n);
			    printf("\n");
			}
			else{
				queen(row+1,n);
			    }
		}
	}
}
int place(int row,int column)
{
	int i;
	for(i=1;i<row;i++)
	{
	   if(board[i]==column)
	      return 0;
	   else
	   {
	   	if(abs(board[i]-column)==abs(i-row))
	   	return 0;
	   }
	}
	return 1;
}

int main()
{
	int n;
	clock_t start,end;
	printf("Enter the numner of the queen: ");
	scanf("%d",&n);
	start=clock();
	queen(1,n);
	end=clock();
	double cpu=(double)(end-start)/CLOCKS_PER_SEC;
	printf("\n%f\n",cpu);
	return 0;
}
