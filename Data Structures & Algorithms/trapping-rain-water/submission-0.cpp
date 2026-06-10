class Solution {
public:
    int trap(vector<int>& height) {
        //we need to find total water, and total water for a level is how high is the smaller height of nearest max height to the left and right
        int n = height.size();
        vector<int>prefixMax(n,0);
        vector<int>suffixMax(n,0);
        //not 0 as that can make water go -ve, remember edges cant have any water it will overflow cuz

        prefixMax[0]= height[0];
        suffixMax[n-1]= height[n-1];
        for(int i =1;i<height.size();i++){
            prefixMax[i] = max(prefixMax[i-1], height[i]);
        }
        for(int i = n-2;i>=0;i--){
            suffixMax[i]= max(suffixMax[i+1], height[i]);
        }
        int water =0 ;
        for(int i =0;i<n;i++){
            water+= min(prefixMax[i], suffixMax[i]) - height[i];
        }
        return water;
        
    }
};
