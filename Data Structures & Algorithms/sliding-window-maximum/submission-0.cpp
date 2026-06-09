class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       // 1,3,-1,-3,5,3,6,7   k=3
        //3,1,-1,
        //3,1,-1,-3
        //5
        //5,3
        //6
        //7
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove elements outside the window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Push current index
            dq.push_back(i);

            // 4. Record answer when window is ready
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;



    }
};