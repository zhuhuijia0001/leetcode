//solution 1
class Solution {
public:
    int nthUglyNumber(int n) {
        
        int *arr = new int[n];
        
        int val_1, val_2, val_3;
        val_1 = 2;
        val_2 = 3;
        val_3 = 5;
        
        int index_1, index_2, index_3;
        index_1 = 0;
        index_2 = 0;
        index_3 = 0;
        
        arr[0] = 1;
        for (int i = 1; i < n; i++) {
            arr[i] = min(val_1, min(val_2, val_3));
            
            if (arr[i] == val_1) {
                val_1 = arr[++index_1] * 2;
            }
            
            if (arr[i] == val_2) {
                val_2 = arr[++index_2] * 3;
            }
            
            if (arr[i] == val_3) {
                val_3 = arr[++index_3] * 5;
            }
        }
        
        int ret = arr[n - 1];
        delete []arr;
        
        return ret;
    }
};

//solution 2
class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> vec;
        vec.reserve(n);
        
        int val_1, val_2, val_3;
        val_1 = 2;
        val_2 = 3;
        val_3 = 5;
        
        int index_1, index_2, index_3;
        index_1 = 0;
        index_2 = 0;
        index_3 = 0;
        
        vec.push_back(1);
        for (int i = 1; i < n; i++) {
            int tmp = min(val_1, min(val_2, val_3));
            vec.push_back(tmp);
            
            if (tmp == val_1) {
                val_1 = vec[++index_1] * 2;
            }
            
            if (tmp == val_2) {
                val_2 = vec[++index_2] * 3;
            }
            
            if (tmp == val_3) {
                val_3 = vec[++index_3] * 5;
            }
        }
        
        return vec.back();
    }
};
