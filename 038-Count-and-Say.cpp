class Solution 
{
public:
	string countAndSay(int n) 
	{
		string str = "1";

		for (int i = 1; i < n; i++)
		{
			string strTmp;

			size_t found = 0;
			size_t pos = 0;
			while (pos < str.size())
			{
				found = pos + 1;
				while (found < str.size() && str[found] == str[pos])
				{
					found++;
				}

				char buf[10];
				sprintf(buf, "%d", found - pos);
				strTmp += string(buf);
				strTmp += str[pos];

				pos = found;
			}

			str = strTmp;
		}

		return str;
	}
};
