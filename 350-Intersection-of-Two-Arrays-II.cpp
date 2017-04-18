//Solution 1
class Solution 
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(), nums1.end());
        
        sort(nums2.begin(), nums2.end());
        
        vector<int> vec(nums1.size() + nums2.size());
        
        auto it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), vec.begin());
        vec.resize(it - vec.begin());
        
        return vec;        
    }
};

//Solution 2
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector <int> vec_res;
        
        unordered_map<int, int> dict;
        for (auto itr = nums1.begin(); itr != nums1.end(); ++itr) {
            auto itr_dict = dict.find(*itr);
            if (itr_dict != dict.end()) {
                itr_dict->second++;
            } else {
                dict.insert(pair<int, int>(*itr, 1));
            }
        }
        
        for (auto itr = nums2.begin(); itr != nums2.end(); ++itr) {
            auto itr_dict = dict.find(*itr);
            if (itr_dict != dict.end()) {
                if (--itr_dict->second >= 0) {
                    vec_res.push_back(*itr);
                }
            }
        }
        
        return vec_res;
    }
};