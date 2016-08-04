
int lengthOfLongestSubstring(char* s) 
{
	int dic[256];

	int len;

	int i;

	int max_len;
	int prev;

	len = strlen(s);
	if (len == 0)
	{
		return 0;
	}

	max_len = 0;

	for (i = 0; i < 256; i++)
	{
		dic[i] = -1;
	}

    prev = -1;
    
	for (i = 0; i < len; i++)
	{
		if (dic[s[i]] > -1)
		{
			/* update prev */
			prev = prev > dic[s[i]] ? prev : dic[s[i]];
		}

		if (i - prev > max_len)
		{
			max_len = i - prev;
		}

		dic[s[i]] = i;
	}

	return max_len;
}
