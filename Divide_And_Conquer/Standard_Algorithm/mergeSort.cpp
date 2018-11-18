//Quick Sort 
#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int *arr, int low, int high)
{
	int i=low-1;
	for(int j=0;j<=high-1;j++)
	{
		if(arr[j]<=arr[high])
		{
			swap(&arr[++i],&arr[j]);
		}
	}
	swap(&arr[++i],&arr[high]);
	return i;
}

void quickSort(int *arr, int low, int high)
{
	if(low<high)
	{
		int pivot=partition(arr,low,high);
		quickSort(arr,low,pivot-1);
		quickSort(arr,pivot+1,high);
	}
}

int main()
{
	int n;
	cout<<"Enter the number of elements in array:"<<endl;
	cin>>n;
	int *arr=new int[n];
	int i;
	cout<<"Enter the elements of array:"<<endl;
	for(i=0;i<n;i++)
		cin>>arr[i];
	quickSort(arr,0,n-1);
	cout<<"Array after sorting:"<<endl;
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
