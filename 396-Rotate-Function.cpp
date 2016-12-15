class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        
        int sum = 0;
        int f = 0;
        int len = A.size();
        for (int i = 0; i < len; i++) {
            sum += A[i];
            
            f += i * A[i];
        }
        
        int max = f;
        for (int i = 1; i < len; i++) {
            f += sum - A[len - i] * len; 
            
            if (f > max) {
                max = f;
            }
        }
        
        return max;
    }
};