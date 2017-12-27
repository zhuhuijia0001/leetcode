//Solution 1
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        
        vector<int> vec;
        for (auto n : findNums) {
            int index = map[n];
            
            do {
                index++;
            } while (index < nums.size() && nums[index] < n);
            
            if (index < nums.size()) {
                vec.push_back(nums[index]);
            } else {
                vec.push_back(-1);
            }
        }
        
        return vec;
    }
};

//Solutiion 2
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        
        unordered_map<int, int> map;
        stack<int> stk;
        
        for (auto n : nums) {
            while (!stk.empty() && stk.top() < n) {
                map[stk.top()] = n;
                
                stk.pop();
            }
            
            stk.push(n);
        }
  
        vector<int> vec;
        for (auto n : findNums) {
            if (map.find(n) != map.end()) {
                vec.push_back(map[n]);
            } else {
                vec.push_back(-1);
            }
        }
        
        return vec;
    }
};
