#include<stdio.h>
#include<stdlib.h>	
typedef struct node
{
	int data;
	struct node* right;
	struct node* left;
}node;

typedef struct stack
{
	node* val;
	struct stack* next;
}stack;

node* pop(stack* stack)
{
	
}
void inorder(node* root)
{
	node* current = root;
	node* temp;
	stack* stack;
	while(current!=NULL && !isEmpty(stack))
	{
		if(current == NULL)
		{
			temp = pop(stack);
			printf("%d\t",temp->data);
			push(stack,temp->right);
		}
		else
		{
			push(stack,current);
			current = current->right;
		}
	}
}


node* newNode(int x)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data  = x;
	temp->right = NULL;
	temp->left  = NULL;
	return temp;
}

int height(node* root)
{
	if(root == NULL)
		return 0;

	int l = height(root->left);
	int r = height(root->right);

	return (l>r?l+1:r+1);
}

void printGivenLevel(node* root,int i)
{
	if(root == NULL)
		return;
	if(i==1)
		printf("%d\t",root->data);
	else
	{
		printGivenLevel(root->left,i-1);
		printGivenLevel(root->right,i-1);
	}
}

int max(int a,int b)
{
	return a>b?a:b;
}

void printLevel(node* root)
{
	int h = height(root);
	int i;
	for(i=1;i<=h;i++)
	{
		printGivenLevel(root,i);
	}
}

int diameter(node* root)
{
	if(root == NULL)
		return 0;
	int l = height(root->left);
	int r = height(root->right);

	int d1 = diameter(root->left);
	int d2 = diameter(root->right);

	return max(max(d1,d2),l+r+1);
}

int main()
{
	node* root  = newNode(1);
	root->left  = newNode(2);
	root->right = newNode(4);
	root->left->left  = newNode(3);
	root->left->right = newNode(5);
	root->left->left->left = newNode(6);
	printLevel(root);
	printf("\n%d\n",diameter(root));
}