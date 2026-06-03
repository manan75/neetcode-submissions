class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int,vector<int>> pq;
        for(int i = 0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(!pq.empty()){
            int a = pq.top();
            pq.pop();
            if(pq.empty()) return a;
            int b = pq.top();
            pq.pop();
            if(a==b) continue;
            else pq.push(a-b);
        }
        return 0;
    }
};
