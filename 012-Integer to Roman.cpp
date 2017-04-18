
class Solution {
private:
    struct Map {
        int num;
        
        string roman;
    };

    static const Map s_map[];
 
public:   
    string intToRoman(int num) {
        
        string str = "";
        
        int index = 0;
        while (num > 0) {
            while (num >= s_map[index].num) {
                str += s_map[index].roman;
                
                num -= s_map[index].num;
            }
            
            index++;
        }
        
        return str;
    }
};

const Solution::Map Solution::s_map[] = {
    { 1000, "M"  },
    { 900,  "CM" }, 
    { 500,  "D", },
    { 400,  "CD" },
    { 100,  "C"  }, 
    { 90,   "XC" },
    { 50,   "L"  },
    { 40,   "XL" }, 
    { 10,   "X"  },
    { 9,    "IX" }, 
    { 5,    "V"  },
    { 4,    "IV" },
    { 1,    "I"  }
};