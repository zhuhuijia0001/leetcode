class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> vecRes;
        
        int low = 0;
        int high = numbers.size() - 1;
        
        while (low < high) {
            if (numbers[low] + numbers[high] < target) {
                low++;
            } else if (numbers[low] + numbers[high] > target) {
                high--;
            } else {
                vecRes.push_back(low + 1);
                vecRes.push_back(high + 1);
                
                break;
            }
        }
        
        return vecRes;
    }
};