class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int ans = *max_element(piles.begin(), piles.end());
        int l = 1;
        int r = ans;
        while(l<=r){
            int mid = (l+r)/2;
          long long  int m = 0;
            for(int i =0;i<piles.size();i++){
                if(m>h){
                    break;
                }
                if(piles[i]<=mid){
                    m++;
                }
                else{
                    m+= (piles[i] + mid - 1) / mid;
                }
            }
            if(m<=h){
                ans = min(ans,mid);
                r= mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
