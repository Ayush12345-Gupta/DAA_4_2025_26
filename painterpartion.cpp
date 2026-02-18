bool isPossible(vector<int>&boards,int k,int mid){
    int n=boards.size();
    int painterscount=1;
    int paintboards=0;
    for(int i=0;i<n;i++){
        if(paintboards+boards[i]<=mid){
            paintboards+=boards[i];
        }
        else{
            painterscount++;
            if(painterscount>k||boards[i]>mid){
               return false;
            }
             paintboards=boards[i];
        }
       
    }
     return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{   
   
    int n=boards.size();
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=boards[i];

    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(boards,k,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}