class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if (wordList.empty()) {
            return 0;
        }
        
        unordered_set<string> visited;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        
        int step = 1;
        
        while (!q.empty()) {
            
            int n = q.size();
            for (int i = 0; i < n; i++) {
                
                string str = q.front(); q.pop();
                int len = str.length();
                for (int j = 0; j < len; j++) {
                    int letter = str[j];
                    for (int k = 0; k < 26; k++) {
                        str[j] = 'a' + k;
                        
                        if (str[j] == letter) {
                            continue;
                        }
                        
                        auto it = dict.find(str);
                        if (it == dict.end()) {
                            continue;
                        }

                        if (visited.find(str) != visited.end()) {
                            continue;
                        }
                        
                        if (str == endWord) {
                            return ++step;
                        }
                        
                        q.push(str);
                        
                        dict.erase(it);
                        
                        visited.insert(str);
                    }
                    
                    str[j] = letter;
                }
            }
            
            step++;
        }
        
        return 0;
    }
};