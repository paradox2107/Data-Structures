//Create, Insert, Insert-Sorted, Delete_Node and reversal of single linked list



#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node* next;
}node;

node* createNode(node* temp,int x)
{
	temp=(node*)malloc(sizeof(node));
	temp->val=x;
	temp->next=NULL;
	return temp;
}

node* insert(node* head,int x)
{
	node* temp;
	node* temp1;
	temp=head;
	temp1=createNode(temp1,x);
	if(head==NULL)
	{
		head=temp1;
	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=temp1;
	}
	return head;
}

node* insert_sort(node* head,int x)
{
	node* temp;
	node* prev;
	node* temp1;
	temp=head;
	prev=head;
	temp1=createNode(temp1,x);
	if(temp==NULL||temp1->val<temp->val)
	{
		head=temp1;
		head->next=temp;
	}
	else
	{
		while(temp->next!=NULL&&temp1->val>temp->val)
		{
			prev=temp;
			temp=temp->next;
		}	
		if(temp1->val<temp->val)
		{
			prev->next=temp1;
			temp1->next=temp;
		}//does not handle case of equal element being added in first position
		else
		{
			temp->next=temp1;
		}
	}
	return head;
}

void display(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->val);
		temp=temp->next;
	}
}

int count(node* head)
{
	int c=0;
	node* temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	return c;
}

node* delete(node* head,int pos)
{
	int lim=count(head);
	int i;
	node* temp=head;
	node* prev;
	if(pos==1)
	{
		head=head->next;
	}
	else if(pos==lim)
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
	}
	else
	{
		for(i=1;i<pos;i++)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=temp->next;
	}
	free(temp);
	return head;
}

void printrev(node* head)
{
	if(head->next!=NULL)
		printrev(head->next);
	printf("%d\t",head->val);
}

node* reverse(node *head)
{
	node* prev=NULL;
	node* temp=head;
	node* temp1;
	while(temp!=NULL)
	{
		temp1=temp->next;
		temp->next=prev;
		prev=temp;
		temp=temp1;
	}
	return prev;
	
}
void main()
{
	int c;
	node* head=NULL;
	head=insert(head,3);
	head=insert(head,2);
	head=insert(head,1);
	head=insert(head,4);
	head=insert(head,5);
	head=insert(head,6);
	/*head=insert_sort(head,3);
	head=insert_sort(head,2);
	head=insert_sort(head,1);
	head=insert_sort(head,4);
	head=insert_sort(head,6);
	head=insert_sort(head,3);*/
	display(head);
	/*head=delete(head,1);
	head=delete(head,5);
	head=delete(head,2);*/
	head=reverse(head);
	printf("\n%d\n",count(head));
	display(head);
}
