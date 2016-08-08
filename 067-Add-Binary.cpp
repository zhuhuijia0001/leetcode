class Solution 
{
public:
	string addBinary(string a, string b) 
	{
		string c;

		int carry = 0;
		int res;

		int k = 0;

		int i, j;
		for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--)
		{
			res = a[i] - '0' + b[j] - '0' + carry;

			if (res >= 2)
			{
				res -= 2;

				carry = 1;
			}
			else
			{
				carry = 0;
			}

			c.insert(0, 1, '0' + res);
		}

		for ( ; i >= 0; i--)
		{
			res = a[i] - '0' + carry;

			if (res >= 2)
			{
				res -= 2;

				carry = 1;
			}
			else
			{
				carry = 0;
			}

			c.insert(0, 1, '0' + res);
		}

		for ( ; j >= 0; j--)
		{
			res = b[j] - '0' + carry;

			if (res >= 2)
			{
				res -= 2;

				carry = 1;
			}
			else
			{
				carry = 0;
			}

			c.insert(0, 1, '0' + res);
		}

		if (carry > 0)
		{
			c.insert(0, 1, '0' + carry);
		}
	
		return c;
	}
};