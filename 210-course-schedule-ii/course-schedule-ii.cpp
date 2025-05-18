class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g = vector<vector<int>>(numCourses);
        vector<int> inDeg = vector<int>(numCourses, 0);

        for(auto edge : prerequisites) {
            inDeg[edge[0]]++;
            g[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for(int u = 0; u < numCourses; ++u) {
            if(inDeg[u] == 0) {
                q.push(u);
            }
        }

        vector<int> ret;
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            ret.push_back(u);

            for(auto v : g[u]) {
                if(--inDeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        for(auto x : inDeg) {
            if(x) return vector<int>(0);
        }
        
        return ret;
    }   
};