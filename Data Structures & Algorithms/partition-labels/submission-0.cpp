class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;

        vector<pair<int,int>> pos(26, {-1, -1});

        for (int i = 0; i < s.size(); i++) {
            int p = s[i] - 'a';

            if (pos[p].first == -1)
                pos[p].first = i;

            pos[p].second = i;
        }

        int i = 0;

        while (i < s.size()) {
            int last = pos[s[i] - 'a'].second;

            for (int j = i + 1; j <= last; j++) {
                last = max(last, pos[s[j] - 'a'].second);
            }

            ans.push_back(last - i + 1);
            i = last + 1;
        }

        return ans;
    }
};