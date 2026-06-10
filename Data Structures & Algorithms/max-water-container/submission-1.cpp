class Solution {
public:
    int maxArea(vector<int>& heights) {
        int j =heights.size()-1;
        int i=0;
        int ans = -1;
        while(i<j){
            int water = min(heights[i], heights[j])*(j-i);
            ans = max(ans,water);
            if(heights[j]>heights[i]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;

    }
};
