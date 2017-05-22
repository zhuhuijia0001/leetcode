// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int mid;
        
        int low, high;
        
        int bad;
        
        low = 1;
        high = n;
        
        while (low <= high)
        {
            mid = (high - low) / 2 + low;
            
            if (isBadVersion(mid))
            {
                bad = mid;
                
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return bad;
    }
};

