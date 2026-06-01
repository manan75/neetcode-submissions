class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {  
        map<pair<int,int>,int> mp;
        for(auto it: points){
            int x = it[0];
            int y = it[1];
            mp[{x,y}]=0;
        }
        //start from any node
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{points[0][0],points[0][1]}});
        int cost =0;
        while(!pq.empty()){
            int dist =pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(mp[{x,y}]==1) continue;
            mp[{x,y}]=1;
            cost+=dist;
            for(auto it: points){
                if(mp[{it[0], it[1]}]==1)continue;
                int nx = it[0];
                int ny = it[1];
                int manhattan = abs(x-nx)+ abs(y-ny);
                pq.push({manhattan,{nx,ny}});
            }
        }
        return cost;
    }
};
