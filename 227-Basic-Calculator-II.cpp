class Solution 
{
public:
    int calculate(string s) 
    {
        int tmp;
        
        stack<char> stkOptr;
        stack<int>  stkOpnd;
    
        stkOptr.push('#');
    
		s += '#';

        for (size_t pos = 0; pos < s.size(); )
        {
            while (s[pos] == ' ' || s[pos] == '\t')
            {
                pos++;
            }
			if (pos == s.size())
			{
				break;
			}
    
            if (isOptr(s[pos]))
            {
				while (stkOptr.top() != '#')
				{
					char opTop = stkOptr.top();
					char cmp = precede(opTop, s[pos]);
	    
					if (cmp == '<')
					{
						break;
					}

					int opnd2 = stkOpnd.top();
					stkOpnd.pop();
	    
					int opnd1 = stkOpnd.top();
					stkOpnd.pop();
	    
					tmp = operate(opTop, opnd1, opnd2);
	    
					stkOpnd.push(tmp);
	    
					stkOptr.pop();
				}
                
				stkOptr.push(s[pos]);

				pos++;
            }
            else
            {
				tmp = 0;
				while (isOpnd(s[pos]))
				{
					tmp *= 10;
					tmp += s[pos] - '0';
					pos++;
				}

                stkOpnd.push(tmp);
            }
        }

		return stkOpnd.top();
    }
    
private:
    bool isOptr(char c)
    {
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '#')
            return true;
    
        return false;
    }
    
    bool isOpnd(char c)
    {
        if (c >= '0' && c <= '9')
            return true;
    
        return false;
    }
    
    char precede(char optrTop, char optrNew)
    {
        char res = '#';
    
        switch (optrTop)
        {
        case '+':
        case '-':
			if (optrNew == '+' || optrNew == '-' || optrNew == '#')
            {
                res = '>';
            }
            else if (optrNew == '*' || optrNew == '/')
            {
                res = '<';
            }
    
            break;
    
        case '*':
        case '/':
            if (optrNew == '+' || optrNew == '-' || optrNew == '*' || optrNew == '/' || optrNew == '#')
            {
                res = '>';
            }
    
            break;

		case '#':
			if (optrNew == '+' || optrNew == '-' || optrNew == '*' || optrNew == '/')
            {
                res = '<';
            }
            else if (optrNew == '#')
            {
                res = '>';
            }

			break;
        }
    
        return res;
    }
    
    int operate(char optr, int opnd1, int opnd2)
    {
        int res = 0;
    
        switch (optr)
        {
        case '+':
            res = opnd1 + opnd2;
    
            break;
    
        case '-':
            res = opnd1 - opnd2;
    
            break;
    
        case '*':
            res = opnd1 * opnd2;
    
            break;
    
        case '/':
    		if (opnd2 != 0)
    		{
    			res = opnd1 / opnd2;
    		}
    		else 
    		{
    			res = 0;
    		}
    
            break;
        }
    
        return res;
    }
};