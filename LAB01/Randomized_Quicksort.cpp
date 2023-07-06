#include <bits/stdc++.h>
using namespace std;
int swap_cnt=0;
int comp=0;
int Partition(int arr[],int p,int r){
	int x=arr[r]; //pivot element
	int i=p-1;
	int j;
	for(int j=p;j<=r-1;j++){
	    comp++;
    	if(arr[j]<=x){
        	i++;
     	swap(arr[i],arr[j]);
     	swap_cnt++;
  	}
	}
  	swap(arr[i+1],arr[r]);
   	swap_cnt++;
  	return i+1;
}
int Randomized_partition(int arr[],int p,int r){
	//rand()%(r-p+1) generate random number in range 0 to r-p
	// we want in range (p,r) so add p
	int i=p+rand()%(r-p+1);
	swap(arr[i],arr[r]);
 	swap_cnt++;
    
	return(Partition(arr,p,r));
}
void Randomized_quicksort(int arr[],int p,int r){
	if(p<r){
    	int q=Randomized_partition(arr,p,r); //generate random index of pivot
    	Randomized_quicksort(arr,p,q-1);
    	Randomized_quicksort(arr,q+1,r);
	}
}
int main() {
   int n;
   cout<<"Enter size of array :"<<endl;
   cin>>n;
   int arr[n]; //sorted array
   int arr2[n]; //reverse array
   int arr3[n]; //random array
   for(int i=0;i<n;i++){
   	arr[i]=i;
   	arr2[i]=n-i-1;
   }
   for(int i=0;i<n;i++){
   	arr3[i]=rand()%100; // generates random number in range 0-99
   }
   
   srand(time(0)); //generate random seed
   
   Randomized_quicksort(arr,0,n-1) ; // arr,p,r;
   cout<<"Randomized quicksort on sorted array input,output is :"<<endl;
   for(int i=0;i<n;i++){
   	cout<<arr[i]<<" ";
   }
   cout<<endl;
   cout<<"Number of swaps : "<<swap_cnt<<endl;
   cout<<"Number of Comparisons : "<<comp<<endl;
   cout<<endl;
   //for sorted input TC<nlogn
   
 	swap_cnt=0;
 	comp=0;
	Randomized_quicksort(arr2,0,n-1) ;
 	cout<<"Randomized quicksort on reverse array input,output is :"<<endl;
   for(int i=0;i<n;i++){
   	cout<<arr2[i]<<" ";
   }
   cout<<endl;
   cout<<"Number of swaps : "<<swap_cnt<<endl;
   cout<<"Number of Comparisons : "<<comp<<endl;
   cout<<endl;
   
   swap_cnt=0;
   	comp=0;
	Randomized_quicksort(arr3,0,n-1) ;
 	cout<<"Randomized quicksort on random array input,output is :"<<endl;
   for(int i=0;i<n;i++){
   	cout<<arr3[i]<<" ";
   }
   cout<<endl;
   cout<<"Number of swaps : "<<swap_cnt<<endl;
   cout<<"Number of Comparisons : "<<comp<<endl;
   
	return 0;
}
