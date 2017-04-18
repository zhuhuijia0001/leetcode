int maxSubArray(int* nums, int numsSize) 
{
	int curSum = nums[0];
	int maxSum = nums[0];

	int i;

	for (i = 1; i < numsSize; i++)
	{
		if (curSum < 0)
		{
			curSum = nums[i];
		}
		else
		{
			curSum += nums[i];
		}

		if (curSum > maxSum)
		{
			maxSum = curSum;
		}
	}

	return maxSum;    
}