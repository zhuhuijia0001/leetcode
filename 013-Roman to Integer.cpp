
class Solution {
public:
    int romanToInt(string s) {
        int map['X' - 'A' + 1];
        map['I' - 'A'] = 1;
        map['V' - 'A'] = 5;
        map['X' - 'A'] = 10;
        map['L' - 'A'] = 50;
        map['C' - 'A'] = 100;
        map['D' - 'A'] = 500;
        map['M' - 'A'] = 1000;

        int len = s.size();
        int prev = map[s.back() - 'A'];
        int sum = prev;
        for (int i = len - 2; i >= 0; i--) {
            int cur = map[s[i] - 'A'];
            if (cur >= prev) {
                sum += cur;
            } else {
                sum -= cur;
            }

            prev = cur;
        }

        return sum;
    }
};