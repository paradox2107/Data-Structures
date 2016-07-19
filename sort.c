#include <stdio.h>

//Program contains sorting techniques : Bubble, Selection, Insertion, Quick, Merge, Bucket
//Insitu/Inplace modification of array

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubble(int *arr, int len)
{
	int i,j;
	for(i=0;i<len;i++)
		for(j=0;j<len-1;j++)
			if(arr[j]>arr[j+1])
				swap((arr+j),(arr+j+1));
}

void selection(int *arr, int len)
{
	int i,j,pos,temp;
	for(i=0;i<len;i++)
	{
		pos=i;
		temp=i+1;
		for(j=i+1;j<len;j++)
			if(arr[temp]>arr[j+1])
				temp=j+1;
		if(arr[pos]>arr[temp])
			swap((arr+pos),(arr+temp));
	}
}

void insertion(int *arr, int len)
{
	int i,val,pos;
	for(i=1;i<len;i++)
	{
		pos=i;
		val=arr[i];
		while(arr[pos-1]>val && pos>0)
		{
			arr[pos] = arr[pos-1];
			pos = pos-1;
		}
		arr[pos]= val;
	}
}
 
int partition(int *arr, int l, int h)
{
	int pivot = arr[h];
	int pos=l;
	int j;
	for(j=l;j<h;j++)
	{
		if(arr[j]<=pivot)
		{
			swap((arr+pos),(arr+j));
			pos = pos+1;
		}
	}
	swap((arr+pos),(arr+h));
	return pos;
}

void quick(int *arr, int l, int h)
{
	int pos;
	if(l<h)
	{
		pos = partition(arr,l,h);
		quick(arr,l,pos-1);
		quick(arr,pos+1,h);
	}
}

void disp(int *arr,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

int length(int *arr)
{
	int count=0;
	while(arr[count]!='\0')
	{
		count++;
	}
	return count;
}

void merge(int *left, int *right, int *arr)
{
	int nL = length(left);
	int nR = length(right);
	int i=0,j=0,k=0;
	while(i<nL && j<nR)
	{
		if(left[i]<right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while(i<nL)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j<nR)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(int *arr, int len)
{
	int size,i;
	if(len<2)
		return;
	size = len/2;
	int *left  = (int*)malloc(size * sizeof(int));
	int *right = (int*)malloc((len-size) * sizeof(int));
	for(i=0;i<size;i++)
		left[i] = arr[i];
	for(i=size;i<len;i++)
		right[i-size] = arr[i];
	mergeSort(left,size);
	mergeSort(right,len-size);
	merge(left,right,arr);
}

void main()
{
	int arr[]={6,4,3,5,2,1};
	mergeSort(arr,6);//Replace by desired technique
	disp(arr,6);
}