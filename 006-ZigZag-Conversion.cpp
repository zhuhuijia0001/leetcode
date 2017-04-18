
class Solution {
public:
	string convert(string s, int numRows) 
	{
		if (numRows == 1)
		{
			return s;
		}

		vector<string> vec(numRows);
		int index = 0;

		int row = 0;

		vec[row].push_back(s[index++]);

		while (index < s.size())
		{
			for (row = 1; row < numRows && index < s.size(); row++)
			{
				vec[row].push_back(s[index++]);
			}

			for (row = numRows - 2 ; row >= 0 && index < s.size(); row--)
			{
				vec[row].push_back(s[index++]);
			}
		}

		string str;
		for (vector<string>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		{
			str += *itr;
		}

		return str;
	}
};