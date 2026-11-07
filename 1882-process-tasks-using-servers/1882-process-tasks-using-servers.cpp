
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq1;

        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>> pq2;

        for(int i = 0; i < n; i++) {
            pq1.push({servers[i], i});
        }

        vector<int> ans;

        long long time = 0;

        for(int i = 0; i < tasks.size(); i++) {

            time = max(time, (long long)i);

            while(!pq2.empty() && get<0>(pq2.top()) <= time) {
                auto [t, w, idx] = pq2.top();
                pq2.pop();
                pq1.push({w, idx});
            }

            if(pq1.empty()) {
                time = get<0>(pq2.top());

                while(!pq2.empty() && get<0>(pq2.top()) <= time) {
                    auto [t, w, idx] = pq2.top();
                    pq2.pop();
                    pq1.push({w, idx});
                }
            }

            auto [w, idx] = pq1.top();
            pq1.pop();

            ans.push_back(idx);

            pq2.push({time + tasks[i], w, idx});
        }

        return ans;
    }
};
