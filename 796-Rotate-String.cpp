//solution 1
class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};

//solution 2
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.empty() && B.empty()) {
            return true;
        }
        
        bool found = false;
        for (int i = 0; i < B.length(); i++) {
            if (A == B) {
                found = true;
                
                break;
            }
            
            A = shift(A);
        }
        
        return found;
    }
    
private:
    string shift(string s) {
        char c = s[0];
        s.erase(0, 1);
        s.push_back(c);
        
        return s;
    }
};