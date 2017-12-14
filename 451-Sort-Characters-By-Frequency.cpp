//Solution 1
class Solution {
public:
	string frequencySort(string s) {
		
		string res;

		unordered_map<char, int> map;
		for (auto c : s) {
			if (map.find(c) == map.end()) {
				map[c] = 1;
			} else {
				map[c]++;
			}
		}

		auto cmp = [](const pair<char, int> &a, const pair<char, int> &b) {
			return a.second < b.second;
		};

		priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> q(cmp);
		for (auto p : map) {
			q.push(p);
		}

		while (!q.empty()) {
			auto count = q.top().second;
			while (count--) {
				res.push_back(q.top().first);
			}
			q.pop();
		}

		return res;
	}
};

//Solution 2
class Solution {
public:
	string frequencySort(string s) {

		string res;

		unordered_map<char, int> map;
		for (auto c : s) {
			if (map.find(c) == map.end()) {
				map[c] = 1;
			}
			else {
				map[c]++;
			}
		}

		vector<vector<char>> vec(s.length() + 1);

		for (auto p : map) {
			if (p.second > 0) {
				vec[p.second].push_back(p.first);
			}
		}

		for (auto i = (int)vec.size() - 1; i >= 0; i--) {
			if (!vec[i].empty()) {
				for (auto c : vec[i]) {
					auto count = i;
					while (count--) {
						res.push_back(c);
					}
				}
			}
		}

		return res;
	}
};

//Solution 3
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};
