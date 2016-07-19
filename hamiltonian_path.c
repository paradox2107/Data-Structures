#include <stdio.h>
#include <stdlib.h>

void printadj(int **a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

void print(int *x,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d-->",x[i]+1);
	printf("%d\n",x[0]+1);
}

void nextval(int **adj,int *x,int k,int n)
{

	int i;
	while(1)
	{
		x[k]=(x[k]+1)%(n);
		if(x[k]==0)
			return;
		if(adj[x[k-1]][x[k]] == 1)
		{
			for(i=0;i<k;i++)
				if(x[i] == x[k])
					break;
			if(i==k)
			{
				if(((k<n-1)||(((k==n-1))&&(adj[x[n-1]][x[0]]==1))))
					return;
			}
		}
	}
}

void hamilton(int **adj,int n,int k)
{
	int count=0;
	int *x=(int*)calloc(n,sizeof(int));
	while(k!=0)
	{
		nextval(adj,x,k,n);
		if(x[k]==0)
			k--;
		else
		{
			if(k == n-1)
			{
				printf("Solution %d\n",++count);
				print(x,n);
			}
			k++;
		}
	}
	printf("Total number of solutions: %d\n",count);
	free(x);
}

void destruct(int **a,int size)
{
	int i;
	for(i=0;i<size;i++)
		free(a[i]);
	free(a);
}

void inputadj(int **adj,int n)
{
	int x,y,ch=1;
	while(ch==1)
	{
		printf("Enter the source and destination\n");
		scanf("%d %d",&x,&y);
		while(x<1||y>n)
		{
			printf("Enter valid source and destination of edge\n");
			scanf("%d %d",&x,&y);
		}
		if(adj[x-1][y-1])
			printf("Edge is already entered\n");
		else
			adj[x-1][y-1]=1;
		printf("Enter 1. for entering more edges\nEnter 0. if done\n");
		scanf("%d",&ch);
		if(ch==0)
			break;
	}
}

int main(void)
{
	int **adj=NULL;
	int n,ch,i;
	int k=1;
	do
	{
		printf("Enter 1. to Input the graph\nEnter 2. for Hamiltonian Path\nEnter 0. to Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{

				printf("Enter number of vertices\n");
				scanf("%d",&n);
				while(n<2)
				{
					printf("Number of vertices should be more than two.\n");
					scanf("%d",&n);
				}
				if(adj!=NULL)
				{
					  destruct(adj,n);
				}

				adj=(int**)calloc(n,sizeof(int*));
				for(i=0;i<n;i++)
				adj[i]=(int*)calloc(n,sizeof(int));

				inputadj(adj,n);
				printadj(adj,n);
				break;
			}
			case 2:
			{
					hamilton(adj,n,k);
					break;
			}
			case 0:
			{
				printf("You are now exiting\n");
				break;
			}
			default: printf("Invalid entry\n");
		}
	}while(ch!=0);
}
