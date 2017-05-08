void Reverse(int *arr, int b, int e)
{
	for ( ; b < e; b++, e--)
	{
		int temp = arr[e];
		arr[e] = arr[b];
		arr[b] = temp;
	}
}

void rotate(int* nums, int numsSize, int k) 
{
	k %= numsSize;
	Reverse(nums, 0, numsSize - k - 1);
	Reverse(nums, numsSize - k, numsSize - 1);
	Reverse(nums, 0, numsSize - 1);
}