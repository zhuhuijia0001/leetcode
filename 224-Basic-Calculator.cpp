class Solution 
{
public:
	int calculate(string s) 
	{
		int tmp;

		s += ')';

		const char *p = s.c_str();

		stack<char> stkOptr;
		stack<int>  stkOpnd;

		stkOptr.push('(');

		while (!IsEndChar(*p))
		{
			while (*p == ' ' || *p == '\t')
			{
				p++;
			}

			if (IsOptr(*p))
			{
				char opTop = stkOptr.top();
				char percede = Percede(opTop, *p);

				while (percede == '>')
				{
					int opnd2 = stkOpnd.top();
					stkOpnd.pop();

					int opnd1 = stkOpnd.top();
					stkOpnd.pop();

					tmp = Operate(opTop, opnd1, opnd2);

					stkOpnd.push(tmp);

					stkOptr.pop();

					opTop = stkOptr.top();
					percede = Percede(opTop, *p);
				}

				if (percede == '<')
				{
					stkOptr.push(*p);
				}
				else
				{
					stkOptr.pop();
				}
				p++;
			}
			else if (IsOpnd(*p))
			{
				tmp = CalcOpnd(&p);
				stkOpnd.push(tmp);
			}
		}

		return stkOpnd.top();        
	}

private:
	int CalcOpnd(const char **ppOpnd)
	{
		const char *p = *ppOpnd;
		int res = 0;

		while (*p >= '0' && *p <= '9')
		{
			res *= 10;
			res += (*p - '0');

			p++;
		}

		*ppOpnd = p;

		return res;
	}

	bool IsEndChar(char c)
	{
		if (c == '\0' || c == '\n' || c == '=')
			return true;

		return false;
	}

	bool IsOptr(char c)
	{
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
			return true;

		return false;
	}

	bool IsOpnd(char c)
	{
		if (c >= '0' && c <= '9')
			return true;

		return false;
	}

	char Percede(char optrTop, char optrNew)
	{
		char res = '#';

		switch (optrTop)
		{
		case '+':
		case '-':
			if (optrNew == '+' || optrNew == '-' || optrNew == ')')
			{
				res = '>';
			}
			else if (optrNew == '*' || optrNew == '/' || optrNew == '(')
			{
				res = '<';
			}

			break;

		case '*':
		case '/':
			if (optrNew == '+' || optrNew == '-' || optrNew == ')' || optrNew == '*' || optrNew == '/')
			{
				res = '>';
			}
			else if (optrNew == '(')
			{
				res = '<';
			}

			break;

		case '(':
			if (optrNew == '+' || optrNew == '-' || optrNew == '*' || optrNew == '/' || optrNew == '(')
			{
				res = '<';
			}
			else if (optrNew == ')')
			{
				res = '=';
			}

			break;

		case ')':
			res = '#';

			break;

			break;
		}

		return res;
	}

	int Operate(char optr, int opnd1, int opnd2)
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