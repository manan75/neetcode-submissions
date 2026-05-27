class Solution {
public:
    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto &it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            graph[u].push_back({v, wt});
        }

        // dist[i] = minimum cost to reach i
        vector<int> dist(n, INT_MAX);

        // {stops, {node, cost}}
        queue<pair<int,pair<int,int>>> q;

        q.push({0, {src, 0}});

        dist[src] = 0;

        while(!q.empty()) {

            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;

            q.pop();

            // cannot exceed k stops
            if(stops > k)
                continue;

            for(auto &it : graph[node]) {

                int neighbour = it.first;
                int price = it.second;

                // relaxation
                if(cost + price < dist[neighbour]) {

                    dist[neighbour] = cost + price;

                    q.push({
                        stops + 1,
                        {neighbour, cost + price}
                    });
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};