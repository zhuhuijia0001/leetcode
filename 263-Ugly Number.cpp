bool isUgly(int num) 
{
    if (num <= 0)
    {
        return false;
    }
    else if (num == 1)
    {
        return true;
    }
    else
    {
        if ((num & 0x01) == 0)
        {
            return isUgly(num / 2);
        }
        else if ((num % 3) == 0)
        {
            return isUgly(num / 3);
        }
        else if ((num % 5) == 0)
        {
            return isUgly(num / 5);
        }
        else
        {
            return false;
        }
    }
}
