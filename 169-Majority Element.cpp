int majorityElement(int* nums, int numsSize) 
{
	int candidate;  
	int nTime, i;

	nTime = 0;  
	for (i = 0; i < numsSize; i++)  
	{  
		if (nTime == 0)  
		{  
			candidate = nums[i];  
			nTime = 1;  
		}  
		else  
		{  
			if (candidate == nums[i])
			{
				nTime++;
			}
			else
			{
				nTime--;
			}
		}  
	}

	return candidate;      
}