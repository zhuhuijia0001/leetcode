int missingNumber(int* nums, int numsSize) 
{
    int res = 0;
    
    int i;
    for (i = 0; i < numsSize; i++)
    {
        res ^= i ^ nums[i];
    }
    
    res ^= numsSize;
    
    return res;
}