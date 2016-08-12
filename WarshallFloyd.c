#include <stdio.h>
#include <stdlib.h>
#define INFINITE 32767;
typedef struct warshallfloyd
{
	int** adj;
}warshallfloyd;

void print(warshallfloyd *w,int n)
{
	int i,j,k;
	for(k=0;k<=n;k++)
	{
		printf("\nT[%d]:\n",k);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
            {
                if(w[k].adj[i][j]==32767)
                    printf("~\t");
            else
				printf("%d\t",w[k].adj[i][j]);
            }
			printf("\n");
		}
}
}
void freefun(warshallfloyd *w,int n)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
			free(w[i].adj[j]);
	}
	free(w);
}
void warshallalgo(warshallfloyd *w,int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)//for all the vertices
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(w[k-1].adj[i][j]==1||(w[k-1].adj[i][k-1]==1 && w[k-1].adj[k-1][j]==1))
					w[k].adj[i][j]=1;
			}
		}
	}
	print(w,n);
}
warshallfloyd*  mem_alloc(int n,warshallfloyd *w)
{

	int i,j;
	w=(warshallfloyd *)calloc((n+1),sizeof(warshallfloyd *));
	for(i=0;i<=n;i++)
			w[i].adj=(int **)calloc((n+1),sizeof(int *));//(step 1) 1D array of pointers (rows)
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			w[i].adj[j]=(int*)calloc((n+1),sizeof(int));//(step 2)for each row create another 1D array (colms)
return w;

}

void warshal()
{
	int n,x,y,ch;
	warshallfloyd *w;
	printf("\nEnter num of vertices");
	scanf("%d",&n);
	w=mem_alloc(n+1,w);

	do{
		printf("\nEnter the edge source and destination");
		scanf("%d%d",&x,&y);
		while(x<1||y>n)
		{
			printf("\nPlease enter valid source and destination");
			scanf("%d%d",&x,&y);
		}
		if(w[0].adj[x-1][y-1])
			printf("\nEdge already entered");
		else
			w[0].adj[x-1][y-1]=1;
		printf("\nEnter 1 for entering more edges");
		scanf("%d",&ch);
	}while(ch==1);
	//printf("T[0]:\n");
	//print(w,0,n);

	warshallalgo(w,n);

  freefun(w,n);
}
void initialise(warshallfloyd *w,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(w->adj[i][j]==0&&i!=j)
				w->adj[i][j]=INFINITE;
		}
	}

}
void floydalgo(warshallfloyd *w,int n)
{

	int i,j,k;
	for(k=1;k<=n;k++)//for all the vertices
	{

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((w[k-1].adj[i][j])>((w[k-1].adj[i][k-1]+w[k-1].adj[k-1][j])))
					w[k].adj[i][j]=w[k-1].adj[i][k-1]+w[k-1].adj[k-1][j];
				else
					w[k].adj[i][j]=w[k-1].adj[i][j];

			}
		}
		printf("\nF[%d]:\n",k);
	}
	print(w,n);
}

void floyd()
{
	int n,x,y,ch,wt,i;
		warshallfloyd *w;
		printf("\nEnter num of vertices");
		scanf("%d",&n);
		w=mem_alloc(n+1,w);


		do{
				printf("\nEnter the edge source and destination and corresponding weight");
				scanf("%d%d",&x,&y);
				scanf("%d",&wt);
				while(x<1||y>n)
				{
					printf("\nPlease enter valid source and destination");
					scanf("%d%d",&x,&y);
				}
				if(w->adj[x-1][y-1]!=0)
					printf("\nEdge already entered");
				else
				{

					w->adj[x-1][y-1]=wt;
				}

				printf("\nEnter 1 for entering more edges");
				scanf("%d",&ch);
		}while(ch==1);
		//initialising the adj matrix with infinity value
		for(i=0;i<n;i++)
			initialise(w+i,n);
		//printf("F[0]:\n");
		//print(w,0,n);

		floydalgo(w,n);

		freefun(w,n);
}
void main()
{
	int ch;
	while(ch!=3)
	{
		printf("Enter your choice\n1.Warshalls\n2.floyd\n3.Exit\n");
			scanf("%d",&ch);
		switch(ch)
		{
		case 1:warshal();break;
		case 2:floyd();
			break;

		}
	}

}
