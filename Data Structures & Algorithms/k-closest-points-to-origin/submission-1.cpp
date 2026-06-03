class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>> >pq;

        for(auto it: points){
            int x = it[0];
            int y = it[1];
            double dist = sqrt(abs(x*x) + abs(y*y));
            pq.push({dist,{x,y}});
        }
        while(k--) {  
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            ans.push_back({x,y});
        }
        return ans;
    }
};
