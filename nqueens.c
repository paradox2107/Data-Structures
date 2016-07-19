
#include<stdio.h>

void init(int x[],int n)
{
	int i=0;
	for(;i<n;i++)
	{
		x[i]=-1;
	}
}

void print(int x[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(x[i]==j)
				printf("Q\t");
			else
				printf("-\t");
		}
		printf("\n");
	}
	printf("\n");
}

int abs(int a)
{
	return a>0?a:-1*a;
}

int place(int x[],int k,int i)
{
	int j;
	for(j=0;j<k;j++)
		if((x[j]==i)||(abs(x[j]-i)==(abs(j-k))))
			return 0;
	return 1;
}

void recursive(int x[],int k,int n,int *flag,int *sol)
{
	int i;
	for(i=x[k]+1;i<n;i++)
	{
		if(place(x,k,i))
		{
			x[k]=i;
			if(k==n-1)
			{
				if(*flag==1)
				{
					print(x,n);
					*flag=-1;
				}
				if(*flag==0)
				{
					printf("\nSolution %d\n",*sol);
					*sol=*sol+1;
					print(x,n);
				}
			}
			else
				recursive(x,k+1,n,flag,sol);
		}
	}
	x[k]=-1;
	return;
}

void iterative(int x[],int k,int n,int flag,int *sol)
{
	while(k>-1)
	{
		x[k]++;
		if(x[k]<n)
		{
			if(place(x,k,x[k]))
			{
				if(k==n-1)
				{
					if(flag==1)
					{
						print(x,n);
						return;
					}
					if(flag==0)
					{
						printf("Solution %d\n",*sol);
						print(x,n);
						*sol=*sol+1;
					}
				}
				else
					k++;
			}
		}
		if(x[k]>n)
		{
			x[k]=-1;
			k--;
		}
	}
}

void recursive_call(int x[],int n,int k,int *flag,int *sol)
{
	printf("Enter number of queens\n");
	scanf("%d",&n);
	x=(int*)malloc(n*sizeof(int));
	init(x,n);
	recursive(x,k,n,flag,sol);
	free(x);
}

void iterative_call(int x[],int n,int k,int flag,int *sol)
{
	int *y;
	printf("Enter number of queens\n");
	scanf("%d",&n);
	x=(int*)malloc(n*sizeof(int));
	init(x,n);
	iterative(x,k,n,flag,sol);
	y=x;
	printf("\n%d\n",*(x+1));
	free(x);
	printf("\n%d\n",*(y+1));
}

int main()
{
	int ch=1,n,k=0,ch1=1;
	int *x;
	int flag,sol;
	while(ch!=0)
	{
		printf("Enter 1. for a Recursive Solution\nEnter 2. for an Iterative Solution\nEnter 0 to exit\n ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			{
				while(ch1!=0)
				{
					printf("Recursive Solution\nEnter 1. for one solution\nEnter 2 for all solutions\nEnter 0. to go back to Main Menu\n");
					scanf("%d",&ch1);
					switch(ch1)
					{
					case 1: flag=1;
							sol=1;
							recursive_call(x,n,k,&flag,&sol);
							break;
					case 2: flag=0;
							sol=1;
							recursive_call(x,n,k,&flag,&sol);
							printf("Total number of solutions : %d\n\n",sol-1);
					case 0: printf("Back to Main Menu\n");
							break;
					}
				}
				break;
			}
		case 2:
			{
				while(ch1!=0)
				{
					printf("Iterative Solution\nEnter 1. for one solution\nEnter 2 for all solutions\nEnter 0. to go back to Main Menu\n");
					scanf("%d",&ch1);
					switch(ch1)
					{
					case 1: flag=1;
							sol=1;
							iterative_call(x,n,k,flag,&sol);
							break;
					case 2: flag=0;
							sol=1;
							iterative_call(x,n,k,flag,&sol);
							printf("Total number of solutions : %d\n\n",sol-1);
					case 0: printf("Back to Main Menu\n");
							break;
					}
				}
				break;
			}
		case 0:	printf("You have now terminated the program\n");
				break;
		}
	}
	return 0;
}
