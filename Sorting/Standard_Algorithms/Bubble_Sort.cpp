#include<iostream>
using namespace std;
void swap(int *x, int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void bubbleSort(int arr[], int n)
{
	bool swapped=false;
	for(int i=1;i<n;i++)
	{
		swapped=false;
		for(int j=0;j<n-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				swapped=true;
			}
		}
		if(swapped==false)
			break;
	}
}
int main()
{
	int n;
	cout<<"Enter the size of array:"<<endl;
	cin>>n;
	int *arr=new int[n];
	cout<<"Enter the elements of array:"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	bubbleSort(arr,n);
	cout<<"Array after sorting:"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}

