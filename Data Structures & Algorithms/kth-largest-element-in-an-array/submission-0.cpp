class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;

        int last =0;
        for(int i: nums){
            pq.push(i);
        }
        while(k--){
            last = pq.top();
            pq.pop();
        }
        return last;
    }
};
