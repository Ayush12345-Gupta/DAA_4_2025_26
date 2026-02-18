#include<iostream>
using namespace std;
int lowerbound(int arr[],int n,int target){
    int s=0,e=n-1;
    int ans=n;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]>=target){
            ans=mid;
            e=mid-1;
        }
        else{
         s=mid+1;
        }
    }
    return ans;
}
int upperbound(int arr[],int n,int target){
    int s=0,e=n-1;
    int ans=n;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]>target){
            ans=mid;
            e=mid-1;
        }
        else{
         s=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[7]={1,3,5,6,7,8,9};
    int n=7;
    int target=6;
    cout<< lowerbound(arr,n, target)<<" "<< upperbound(arr,n, target);
    cout<<endl;

}