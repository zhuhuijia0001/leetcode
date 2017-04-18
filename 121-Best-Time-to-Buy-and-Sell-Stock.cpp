int maxProfit(int* prices, int pricesSize) 
{
    if (pricesSize < 2)
    {
        return 0;
    }
    
    int max_profit = 0;
    int minPrice = prices[0];
    int i;
    for (i = 1; i < pricesSize; i++)
    {
        if (minPrice > prices[i])
        {
            minPrice = prices[i];
        }
        
        if (prices[i] - minPrice > max_profit)
        {
            max_profit = prices[i] - minPrice;
        }
    }
    
    return max_profit;
}