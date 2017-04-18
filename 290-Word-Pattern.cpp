class Solution 
{
public:
    bool wordPattern(string pattern, string str) 
    {
        map<char, string> mapPatternToWord;
        
        map<string, char> mapWordToPattern;
        
		vector<string> vec;

        size_t pos = 0;
		size_t found = 0;

		while (found != string::npos)
		{
			found = str.find(' ', pos);

			vec.push_back(str.substr(pos, found - pos));

			pos = found + 1;
		}

		if (pattern.size() != vec.size())
		{
			return false;
		}

		for (int i = 0; i < pattern.size(); i++)
        {             
            if (mapPatternToWord[pattern[i]].size() == 0
				&& mapWordToPattern[vec[i]] > 0)
            {
                return false;
            }

            if (mapWordToPattern[vec[i]] == 0
				&& mapPatternToWord[pattern[i]].size() > 0)
            {
				return false;
            }
            
			if (mapPatternToWord[pattern[i]].size() == 0
				&& mapWordToPattern[vec[i]] == 0)
			{
				mapPatternToWord[pattern[i]] = vec[i];
				mapWordToPattern[vec[i]] = pattern[i];
			}
        }

        return true;
    }
};