#include<iostream>
using namespace std;

int calcCost(int arr[],int N)
{
	int c=0;
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++) 
			if(arr[j]<arr[i])
		 		c++;
	}
	return c;
}
 
void swap(int arr[],int i,int j)
{
	int tmp=arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
}
 
int main()
{
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++) 
		cin>>arr[i];
	int bestCost=calcCost(arr,N);
	int newCost=0, swaps=0;
	while(bestCost>0)
	{
		for(int i=0;i<N-1;i++)
		{
			swap(arr,i,i+1);
			newCost=calcCost(arr,N);
			if(bestCost>newCost)
			{
				cout<<"After swap "<<++swaps<<endl;
				for(int i=0;i<N;i++) 
					cout<<arr[i]<<endl;
				bestCost=newCost;
			}
			else 
				swap(arr,i,i+1);
		}	
	}
	cout<<"Final Ans\n";
	for(int i=0;i<N;i++) 
		cout<<arr[i]<<endl;
	return 0;
}

/* OUTPUT:-

5
12
25
85
96
74
After swap 1
12
25
85
74
96
After swap 2
12
25
74
85
96
Final Ans
12
25
74
85
96

*/
