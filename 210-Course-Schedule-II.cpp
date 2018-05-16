class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

        vector<unordered_set<int>> graph(numCourses);
        
        for (auto p : prerequisites) {
            graph[p.second].insert(p.first);
        }

        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it = graph[i].begin(); it != graph[i].end(); ++it) {
                indegree[*it]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        vector<int> vec;
        while (!q.empty()) {
            int n = q.front(); q.pop();
            vec.push_back(n);
            
            count++;
            for (auto it = graph[n].begin(); it != graph[n].end(); ++it) {
                indegree[*it]--;
                
                if (indegree[*it] == 0) {
                    q.push(*it);
                }
            }
        }
        
        if (count < numCourses) {
            vec.clear();
        }
        
        return vec;
    }
};