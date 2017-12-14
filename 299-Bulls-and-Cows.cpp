//Solution 1
class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int bull_count = 0;
        int cow_count = 0;
        
        int secret_map[10];
        int guess_map[10];
        
        int i;
        for (i = 0; i < 10; i++)
        {
            secret_map[i] = 0;
            
            guess_map[i] = 0;
        }
        
        for (i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bull_count++;
            }
            else
            {
                secret_map[secret[i] - '0']++;
                guess_map[guess[i] - '0']++;
                
                if (secret_map[guess[i] - '0'] > 0)
                {
                    secret_map[guess[i] - '0']--;
                    
                    guess_map[guess[i] - '0']--;
                    
                    cow_count++;
                }
                
                if (guess_map[secret[i] - '0'] > 0)
                {
                    guess_map[secret[i] - '0']--;
                    
                    secret_map[secret[i] - '0']--;
                    
                    cow_count++;
                }
            }
        }
        
        string str = int2str(bull_count);
        str.append(1, 'A');
        str.append(int2str(cow_count));
        str.append(1, 'B');
        
        return str;
    }
    
private:
    string int2str(int num)
    {
        string str;
        
        if (num == 0)
        {
            return "0";
        }
        
        while (num > 0)
        {
            str.insert(str.begin(), '0' + num %10);
            
            num /= 10;
        }
        
        return str;
    }
};

//Solution 2
class Solution {
public:
    string getHint(string secret, string guess) {
        
        vector<int> sMap(10, 0);
        vector<int> gMap(10, 0);
        
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                sMap[secret[i] - '0']++;
                
                gMap[guess[i] - '0']++;
            }
        }
        
        for (int i = 0; i < 10; i++) {
            cows += min(sMap[i], gMap[i]);
        }
        
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
