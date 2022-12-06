#include<iostream>
using namespace std;
void swap(int &i,int &j){
    int temp=i;
    i=j;
    j=temp;
}
int partition(int arr[],int l,int h){
    int pivot=arr[l];
    int i=l,j=h;
    while(i<j)
    {
        do{
            i++;
        }while(arr[i]<=pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[j]);
    return j;
}
void quickSort(int arr[],int l,int h){
  if(l<h){
    int j=partition(arr,l,h);
    quickSort(arr,l,j);
    quickSort(arr,j+1,h);
  }
}
int main(){
    int n,j;
    cout<<"Enter how many number You want to enter";
    cin>>n;
    j=n;
    // cout<<"Enter how many number Yopu want to enter2";
    int arr[n];
     //cout<<"Enter how many number Yopu want to enter1";
    for(int i=0;i<j;i++){
       arr[i]=n;
       n--;
    }
   ///  cout<<"Enter how many number Yopu want to enter2";
    quickSort(arr,0,j);
    // cout<<"Enter how many number Yopu want to enter3";
     for(int i=0;i<j;i++){
       cout<<arr[i]<<endl;
    }
}