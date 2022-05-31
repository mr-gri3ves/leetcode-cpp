#include <math.h>
#include <iostream>

int getDigitsCount(int n)
{
    int count = 0;
    while (n != 0)
    {
        ++count;
        n /= 10;
    }
    return count;
}

int getDigitAt(int n, int digitsCount, int index)
{
    if (index >= digitsCount)
    {
        return -1;
    }
    int powOf10 = std::pow(10, digitsCount - 1 - index);
    return (n / powOf10) % 10;
}

bool isPalindrome(int n)
{
    if (n < 0)
    {
        return false;
    }
    int digitsCount = getDigitsCount(n);

    for(int i = 0, j = digitsCount - 1; i < j; ++i, --j)
    {
        if (getDigitAt(n,digitsCount,i) != getDigitAt(n,digitsCount,j))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << isPalindrome(1000021);
}