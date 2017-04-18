
//Solution 1
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //max heap
        priority_queue<int, vector<int> > pq;
    
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (pq.size() < k) {
                    pq.push(matrix[i][j]);
                } else if (matrix[i][j] < pq.top()) {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        
        return pq.top();
    }
};

//Solution 2
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int low = matrix.front().front();
        int high = matrix.back().back();
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            int count = 0;
            for (int i = 0; i < matrix.size(); i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
};