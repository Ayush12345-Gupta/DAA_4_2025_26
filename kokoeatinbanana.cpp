class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long hours=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid!=0){
                    hours++;
                }
                hours+=piles[i]/mid;
            }
            if(hours<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return ans;
        
    }
};