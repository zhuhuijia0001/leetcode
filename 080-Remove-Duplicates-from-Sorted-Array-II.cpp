int removeDuplicates(int* nums, int numsSize) 
{
    if (numsSize == 0)
    {
        return 0;
    }
    
    int duplicate_count;
    
    int cur;
    
    int i;
    cur = 0;
    duplicate_count = 1;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[cur] == nums[i])
        {
            if (duplicate_count < 2)
            {
                nums[++cur] = nums[i];
            }
            
            duplicate_count++;
        }
        else
        {
            nums[++cur] = nums[i];
            
            duplicate_count = 1;
        }
    }
    
    return cur + 1;
}