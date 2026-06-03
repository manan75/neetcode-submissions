class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    int num_letters = 'Z' - 'A' + 1;
    vector<int> freqs(num_letters, 0);
    for (const auto& task : tasks) {
        ++freqs[task - 'A'];
    }
    priority_queue<int, vector<int>> max_heap;
    for (int i = 0; i < freqs.size(); ++i) {
        if (freqs[i] > 0) {
            max_heap.push(freqs[i]);
        }
    }
    queue<pair<int, int>> cooldown_queue;
    int time = 0;
    while (!max_heap.empty() || !cooldown_queue.empty()) {
        ++time; 
        if (!cooldown_queue.empty()) {
            auto [freq, timestamp] = cooldown_queue.front();
            if (timestamp <= time) {
                cooldown_queue.pop();
                max_heap.push(freq);
            }
        }  
        if (!max_heap.empty()) {
            int max_freq = max_heap.top();
            max_heap.pop();
            if (max_freq > 1) {
                cooldown_queue.push({max_freq - 1, time + n + 1});
            }
        }
    }
    return time;
}

};