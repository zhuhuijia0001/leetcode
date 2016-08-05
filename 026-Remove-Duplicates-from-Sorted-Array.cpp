
int removeDuplicates(int* nums, int numsSize) 
{
    int start = 0;
    
    int i = 0;
    
    if (numsSize < 2)
    {
        return numsSize;
    }
    
    for (i = 1; i < numsSize; i++)
    {
        if (nums[start] < nums[i])
        {
            start++;
            nums[start] = nums[i];
        }
    }
    
    return start + 1;
}