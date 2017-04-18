//Solution 1
int singleNumber(int* nums, int numsSize) 
{
	int bit_count[32];

	int i;

	int res;

	unsigned int mask;

	for (i = 0; i < 32; i++)
	{
		bit_count[i] = 0;
	}

	for (i = 0; i < numsSize; i++)
	{
		int dat = nums[i];

		int j;
		mask = 0x01;
		for (j = 0; j < 32; j++)
		{
			if (mask & dat)
			{
				bit_count[j]++;
			}

			mask <<= 1;
		}
	}

	res = 0;
	mask = 0x01;

	for (i = 0; i < 32; i++)
	{
		bit_count[i] %= 3;

		if (bit_count[i])
		{
			res |= mask;
		}

		mask <<= 1;
	}

	return res;    
}

//Solution 2
int singleNumber(int* nums, int numsSize) 
{
	int ones, twos;
	int i;

	ones = 0;
	twos = 0;

	for (i = 0; i < numsSize; i++)
	{
		ones = ones ^ nums[i] & ~twos;

		twos = twos ^ nums[i] & ~ones;
	}

	return ones;
}