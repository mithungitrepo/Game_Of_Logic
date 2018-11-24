//Given an array of integers(both +ve and -ve) 
//Find the two elements whose sum is closest to zero
#include<iostream>
#include<limits.h>
#include<stdlib.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
//O(n^2) time complexity
void findClosestSum(int *arr, int n)
{
	if(n<2)
	{
		cout<<"Invalid Input";
		return;
	}
	int i,j,min_sum,sum,min_l,min_r;
	min_sum=arr[0]+arr[1];
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			sum=arr[i]+arr[j];
			if(abs(min_sum)>abs(sum))
			{
				min_sum=sum;
				min_l=i;
				min_r=j;
			}
		}
	}
	cout<<"Elements whose sum is closest to zero arr\
		="<<arr[min_l]<<" and "<<arr[min_r]<<endl;	
	
}
void exchange(int *a, int *b) 
{ 
  int temp; 
  temp = *a; 
  *a   = *b; 
  *b   = temp; 
} 
  
int partition(int arr[], int si, int ei) 
{ 
  int x = arr[ei]; 
  int i = (si - 1); 
  int j; 
  
  for (j = si; j <= ei - 1; j++) 
  { 
    if(arr[j] <= x) 
    { 
      i++; 
      exchange(&arr[i], &arr[j]); 
    } 
  } 
  
  exchange (&arr[i + 1], &arr[ei]); 
  return (i + 1); 
} 
  
/* Implementation of Quick Sort 
arr[] --> Array to be sorted 
si  --> Starting index 
ei  --> Ending index 
*/
void quickSort(int arr[], int si, int ei) 
{ 
  int pi;    /* Partitioning index */
  if(si < ei) 
  { 
    pi = partition(arr, si, ei); 
    quickSort(arr, si, pi - 1); 
    quickSort(arr, pi + 1, ei); 
  } 
} 
void findClosestSumImproved(int *arr, int n)
{
	int min_sum,sum,l,r,min_l,min_r;
	if(n<2)
	{
		cout<<"Invalid Input"<<endl;
		return;
	}
	quickSort(arr,0,n);
	l=0,r=n-1;
	min_sum=arr[0]+arr[n-1];
	min_l=0;
	min_r=n-1;
	while(l<r)
	{
		sum=arr[l]+arr[r];
		if(abs(min_sum)>abs(sum))
		{
			min_sum=sum;
			min_l=l;
			min_r=r;
		}
		if(sum<0)
			l++;
		else
			r--;
	}
	cout<<"Elements are: "<<arr[min_l]<<" "<<arr[min_r];
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
	findClosestSum(arr,n);
	findClosestSumImproved(arr,n);
	return 0;	
}
