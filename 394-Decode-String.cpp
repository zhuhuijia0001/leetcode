class Solution {
public:
    string decodeString(string s) {
        
		int index = 0;

		s.push_back(']');
		
		string res = decodeStringInternal(s, index);

		return res;
    }

private:
	string decodeStringInternal(string &s, int &index) {
		string res;

		while (s[index] != ']') {
			while (s[index] >= 'a' && s[index] <= 'z') {
				res.push_back(s[index]);

				index++;
			}

			int num = 0;
			while (s[index] >= '0' && s[index] <= '9') {
				num *= 10;
				num += s[index] - '0';

				index++;
			}
		
			if (num > 0) {
				index++;

				string substr = decodeStringInternal(s, index);
				for (int i = 0; i < num; i++) {
					res += substr;
				}

				index++;
			}
		}

		return res;
	}
};