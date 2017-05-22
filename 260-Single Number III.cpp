//Solution 1
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int i;
        int num1, num2;
        
        num1 = 0;
        num2 = 0;
        
        int bit = findFirstOne(XOR(nums));
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] & (1 << bit))
            {
                num1 ^= nums[i];
            }
            else
            {
                num2 ^= nums[i];
            }
        }
        
        vector<int> vec;
        vec.push_back(num1);
        vec.push_back(num2);
        
        return vec;
    }
    
private:
    int XOR(vector<int>& nums)
    {
        int i;
        int ret = 0;
        for (i = 0; i < nums.size(); i++)
        {
            ret ^= nums[i];
        }
        
        return ret;
    }
    
    int findFirstOne(int dat)
    {
        if (dat == 0)
        {
            return -1;
        }
        
        int bit = 0;
        while ((dat & 0x01) == 0)
        {
            bit++;
            
            dat >>= 1;
        }
        
        return bit;
    }
};


//solution 2
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int i;
        int num1, num2;
        
        vector<int> vec(2);
        
        int res = XOR(nums);
        int val = res & ~(res - 1);
        
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] & val)
            {
                vec[0] ^= nums[i];
            }
        }
        
        vec[1] = res ^ vec[0];
        
        return vec;
    }
    
private:
    int XOR(vector<int>& nums)
    {
        int i;
        int ret = 0;
        for (i = 0; i < nums.size(); i++)
        {
            ret ^= nums[i];
        }
        
        return ret;
    }
};
