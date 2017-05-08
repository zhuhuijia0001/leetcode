class Solution {
public:
    int countDigitOne(int n) 
    {
        if (n < 0)
        {
            return 0;
        }
        
        int iCount = 0;
    
    	long iFactor  = 1;
    	long iLowerNum = 0;
    	long iCurrNum = 0;
    	long iHigherNum = 0;
    
    	while (n / iFactor != 0)
    	{
    		iLowerNum = n - (n / iFactor) * iFactor;
    		iCurrNum = (n / iFactor) % 10;
    		iHigherNum = n / (iFactor * 10);
    
    		switch (iCurrNum)
    		{
    		case 0:
    			iCount += iHigherNum * iFactor;
    
    			break;
    
    		case 1:
    			iCount += iHigherNum * iFactor + iLowerNum + 1;
    
    			break;
    
    		default:
    			iCount += (iHigherNum + 1) * iFactor;
    
    			break;
    		}
    
    		iFactor *= 10;
    	}
    
    	return iCount;        
    }
};