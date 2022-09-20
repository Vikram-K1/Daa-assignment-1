
#include<bits/stdc++.h>
using namespace std;

void max_crossing_subarray(int arr[],int low, int mid, int high,int &max_left,int &max_right, int &total_sum)
{
    int left_sum=INT_MIN;      //assigning left_sum minimum int value
    int sum=0; 
    int i,j;
    for(i=mid;i>=low;i--){     //traversing array from middle to lower elements and updating sum and left_sum
        sum=sum+arr[i];
        if(sum>left_sum){
            left_sum=sum;
            max_left=i;         //Store start index in max_left 
        }
    }
    
    int right_sum=INT_MIN;
    sum=0;
    for(j=mid+1;j<=high;j++){
        sum=sum+arr[j];
        if(sum>right_sum){
            right_sum=sum;
            max_right=j;        //Store end index in max_right
        }
    }
    total_sum=left_sum+right_sum; //
    
}

void maximum_subarray(int arr[],int low,int high,int &start_index,int &end_index,int &total_sum){
 
 if(high==low){
     start_index=low;
     end_index=high;
     total_sum=arr[low];
     return;
 }
 int mid=(high+low)/2;
 
 int left_low,left_high,left_sum;
 maximum_subarray(arr,low,mid,left_low,left_high,left_sum); //Recursive calling for maximum subarray in left half
 
 int right_low,right_high,right_sum;
 maximum_subarray(arr,mid+1,high,right_low,right_high,right_sum); //Recursive calling for maximum subarray in right half
 
 int cross_low,cross_high,cross_sum;
 max_crossing_subarray(arr,low,mid,high,cross_low,cross_high,cross_sum); //Maximum subarray sum such that the subarray crosses the midpoint
 
 if(left_sum>=right_sum && left_sum>=cross_sum){  //returning values of start index, end index and sum whichever part's sum is greatest
     start_index=left_low;                        //left, right or cross
     end_index=left_high;
     total_sum=left_sum;
     return;
 }
 else if(right_sum>=left_sum && right_sum>=cross_sum)
 {
     start_index=right_low;
     end_index=right_high;
     total_sum=right_sum;
     return;
 }
 else{
     start_index=cross_low;
     end_index=cross_high;
     total_sum=cross_sum;
     return;
 }
    
}
int main()
{
   int arr[]={12,54,-2,6,-54,6,-33,30,-8,5,21,-34,76,-9}; //array of 14 non-zero integers
   int start_index;
   int end_index;
   int final_sum;
   maximum_subarray(arr,0,13,start_index,end_index,final_sum);  //calling the function. Indices and sum variables are passed by reference
   cout<<"Maximum sum is -> ";
   for(int i=start_index;i<=end_index;i++){
       cout<<arr[i];
       if(i==end_index){
           break;
       }
       cout<<" + ";
  }
   cout<<" = ";
   cout<<final_sum;
   cout<<" \nFrom index "<<start_index<<" to "<<end_index;
   
    return 0;
}


