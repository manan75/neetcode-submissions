class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) { 
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto it: times){
            int u = it[0];
            int v = it[1];
            int time = it[2];
            graph[u].push_back({v,time});
        }
        vector<int> ans(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({0,k});
        ans[k]=0;
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            //imp optimization, early exit
            if(dist > ans[node]) continue;
            for(auto neighbours : graph[node]){
                int neigh = neighbours.first;
                int wt = neighbours.second;    
                if(dist+ wt < ans[neigh]){
                    ans[neigh] = dist+wt;
                    pq.push({dist+wt, neigh});
                }
            }
        }
        int res = *max_element(ans.begin()+1,ans.end());
        if(res==INT_MAX)return -1;
        return res;
    }
};
