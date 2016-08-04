
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        if (k > nums1.size() * nums2.size()) {
            k = nums1.size() * nums2.size();
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> pq;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (pq.size() < k) {
                    pq.push(pair<int, int>(nums1[i], nums2[j]));
                } else {
                    pair<int, int> p = pq.top();
                    if (nums1[i] + nums2[j] < p.first + p.second) {
                        pq.pop();

                        pq.push(pair<int, int>(nums1[i], nums2[j]));
                    } else {
                        break;
                    }
                }
            }
        }

        vector<pair<int, int>> vec;
        vec.reserve(k);

        while (!pq.empty()) {
            vec.push_back(pq.top());

            pq.pop();
        }

        return vec;
    }

private:
    struct MyCompare {
    public:
        bool operator () (const pair<int, int> &op1, const pair<int, int> &op2) {

            if (op1.first + op1.second < op2.first + op2.second) {
                return true;
            }

            return false;
        }
    };
};