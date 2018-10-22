//Merge Sort implementation without using sentinel value
#include<iostream>
using namespace std;
void merge(int *arr, int low, int mid, int high)
{
	int i,j,k,n1,n2;
	n1=(mid-low+1);
	n2=(high-mid);
	int *left=new int[n1];
	int *right= new int[n2];
	for(i=0;i<n1;i++)
		left[i]=arr[low+i];
	for(j=0;j<n2;j++)
		right[j]=arr[mid+j+1];
	i=0;
	j=0;
	k=low;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k++]=left[i++];
	}
	while(j<n2)
	{
		arr[k++]=right[j++];
	}
}


void mergeSort(int *arr, int low, int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}


int main()
{
	int n;
	cout<<"Enter no of elements in array:";
	cin>>n;
	int *arr=new int[n];
	cout<<"Enter elements of array:";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Array before Sorting:"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	mergeSort(arr,0,n-1);
	cout<<"\nArray After Sorting:"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
	
