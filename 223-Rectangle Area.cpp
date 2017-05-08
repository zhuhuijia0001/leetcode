int overlay(int A, int B, int C, int D, int E, int F, int G, int H)
{
	if (A < E)
	{
		A = E;
	}

	if (C > G)
	{
		C = G;
	}

	if (A > C)
	{
		A = 0;
	}
	else
	{
		A = C - A;
	}

	if (B < F)
	{
		B = F;
	}

	if (D > H)
	{
		D = H;
	}

	if (B > D)
	{
		B = 0;
	}
	else
	{
		B = D - B;
	}
    
    return A * B;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
    return (C - A) * (D - B) - overlay(A, B, C, D, E, F, G, H) + (G - E) * (H - F);
}