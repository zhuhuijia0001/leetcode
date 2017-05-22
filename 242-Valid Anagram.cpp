bool isAnagram(char* s, char* t) 
{
    int len1, len2;
    
    len1 = strlen(s);
    len2 = strlen(t);
    
    if (len1 != len2)
    {
        return false;
    }
    
    int i;
    int count1[26], count2[26];
    memset(count1, 0, sizeof(count1));
    memset(count2, 0, sizeof(count2));
    
    for (i = 0; i < len1; i++)
    {
        count1[s[i] - 'a']++;
        
        count2[t[i] - 'a']++;
    }
    
    for (i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }
    
    return true;
}