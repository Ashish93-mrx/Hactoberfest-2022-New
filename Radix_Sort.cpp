#include<iostream> 
using namespace std; 
  
// A utility function to get maximum value in arr[] 
int getMaximum(int array[], int n) { 
    int max = array[0]; 
    for (int i = 1; i < n; i++) 
        if (array[i] > max) 
            max = array[i]; 
    return max; 
} 
  
void CountSort(int array[], int n, int div) { 
    int output[n]; 
    int count[10] = {0}; 
  
    for (int i = 0; i < n; i++) 
        count[ (array[i]/div)%10 ]++; 
  
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = n - 1; i >= 0; i--) 
    { 
        output[count[ (array[i]/div)%10 ] - 1] = array[i]; 
        count[ (array[i]/div)%10 ]--; 
    } 
  
    for (int i = 0; i < n; i++) 
        array[i] = output[i]; 
} 
  
 
void RadixSort(int array[], int n) 
{ 
    int m = getMaximum(array, n); 
    for (int div = 1; m/div > 0; div *= 10) 
        CountSort(array, n, div); 
} 
  

int main() 
{ 
	int n;
	cout<<"Enter the size of the array:"<<endl;
	cin>>n;
	int array[n];
	cout<<"Enter "<<n<<" elements in any order"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
   cout<<endl<<"Array Before Sorting: "<<endl;
   for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	
	RadixSort(array, n); 
   
	cout<<endl<<"Array after Sorting: "<<endl;
   for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	} 
    
    return 0; 
}
