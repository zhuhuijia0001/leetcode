class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> vec(n + 1);
        
        vec[0] = vec[1] = 1;
        
        int i;
        for (i = 2; i <= n; i++)
        {
            int j;
            for (j = 0; j < i; j++)
            {
                vec[i] += vec[j] * vec[i - 1 - j];
            }
        }
        
        return vec[n];
    }
};