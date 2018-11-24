//To find the Median of two sorted arrays of same size
#include<bits/stdc++.h>
using namespace std;
//O(n) time complexity
int getMedianOfArrays(int *arr1,int *arr2, int n)
{
	int i=0;
	int j=0;
	int count;
	int m1=-1,m2=-1;
	if(arr1[0]>arr2[n-1])
	{
		m1=arr2[n-1];
		m2=arr1[0];
	}
	else if(arr2[0]>arr1[n-1])
	{
		m1=arr1[n-1];
		m2=arr2[0];
	}
	else
	{
		for(count=0;count<=n;count++)
		{
			if(arr1[i]<arr2[j])
			{
				m1=m2;
				m2=arr1[i];
				i++;
			}
			else
			{
				m1=m2;
				m2=arr2[j];
				j++;
			}
		}
	}
	return (m1+m2)/2;
}
//O(logn) time complexity
//Divide and conquer based efficient solution
int median(int *arr,int n)
{
	if(n%2==0)
		return (arr[n/2-1]+arr[n/2])/2;
	return arr[n/2];
}
int getMedianOfArraysLogn(int *arr1,int *arr2, int n)
{
	if(n<=0)
		return -1;
	if(n==1)
		return (arr1[0]+arr2[0])/2;
	if(n==2)
		return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;
	int m1=median(arr1,n);
	int m2=median(arr2,n);
	if(m1==m2)
		return m1;
	if(m1<m2)
	{
		if(n%2==0)
			return getMedianOfArraysLogn(arr1+n/2-1,arr2,n-n/2+1);
		return getMedianOfArraysLogn(arr1+n/2,arr2,n-n/2);
	}
	if(n%2==0)
		return getMedianOfArraysLogn(arr1+n/2-1,arr2,n-n/2+1);
	return getMedianOfArraysLogn(arr1+n/2,arr2,n-n/2);	
}
int main()
{
	int n; //Size of arrays
	cout<<"Enter the size of arrays:"<<endl;
	cin>>n;
	cout<<"Enter the elements of first array:"<<'\n';
	int *arr1=new int[n];//First array
	int *arr2=new int[n];//Second array
	for(int i=0;i<n;i++)
		cin>>arr1[i];
	cout<<"Enter the elements of second array:"<<'\n';
	for(int i=0;i<n;i++)
		cin>>arr2[i];
	cout<<"Median of merged array="<<getMedianOfArrays(arr1,arr2,n);
	cout<<"Median of merged array in logn="<<getMedianOfArraysLogn(arr1,arr2,n);
	return 0;
}
