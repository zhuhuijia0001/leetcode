//solution 1
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        
        for (int i = 0; i < numCourses; i++) {
            int j;
            for (j = 0; j < numCourses; j++) {
                if (indegree[j] == 0) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            
            indegree[j] = -1;
            for (auto it = graph[j].begin(); it != graph[j].end(); ++it) {
                indegree[*it]--;
            }
        }
        
        return true;
    }
};

//solution 2
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        while (!q.empty()) {
            count++;
            
            int n = q.front(); q.pop();
            
            for (auto it = graph[n].begin(); it != graph[n].end(); ++it) {
                indegree[*it]--;
                
                if (indegree[*it] == 0) {
                    q.push(*it);
                }
            }
        }
        
        return count == numCourses;
    }
};