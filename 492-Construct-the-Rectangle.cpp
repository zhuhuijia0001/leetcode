//Solution 1
class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        vector<int> vec;
        int length = (int)sqrt(area);
        if (length * length == area) {
            vec.push_back(length);
            vec.push_back(length);
        } else {
            for (int i = length + 1; i <= area; i++) {
                if (area % i == 0) {
                    vec.push_back(i);
                    vec.push_back(area / i);
                    
                    break;
                }
            }
        }
        
        return vec;
    }
};

//Solution 2
class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        for (int width = (int)sqrt(area); width > 0; width--) {
            if (area % width == 0) {
                return { area / width, width };
            }
        }
    }
};
