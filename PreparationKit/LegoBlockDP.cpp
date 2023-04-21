#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>

typedef unsigned long long ull;

ull addMod(ull a, ull b, ull mod)
{
    return (a < (mod - b)) ? a + b : a - (mod - b);
}

ull powMod(ull a, ull b, ull mod)
{
    ull result = 1;
    ull a_ = a % mod;

    while (b > 0)
    {
        if (b & 1)
            result = result = result * a_ % mod;
        a_ = a_ * a_ % mod;
        b >>= 1;
    }

    return result;
}

ull legoBlocks(ull n, ull m)
{
    std::vector<ull> rowArr(m + 1);
    rowArr[0] = 1;
    ull indexSum;
    ull mod = 1000000007;

    for (int index = 1; index <= m; index++)
    {
        indexSum = 0;
        for (int blockSize = 1; blockSize <= 4 && (index - blockSize) >= 0; blockSize++)
        {

            indexSum = addMod(indexSum, rowArr[index - blockSize], mod);
        }

        rowArr[index] = indexSum;
    }

    std::vector<ull> resultArr(m + 1);
    resultArr[1] = 1;

    for (int index = 2; index <= m; index++)
    {
        indexSum = powMod(rowArr[index], n, mod);
        ull partToSubstract = 0;
        for (int leftCut = 1; leftCut < index; leftCut++)
        {
            partToSubstract = resultArr[leftCut] * powMod(rowArr[index - leftCut], n, mod) % mod;
            indexSum = (indexSum - partToSubstract + mod) % mod;
        }
        resultArr[index] = indexSum;
    }

    return resultArr[m];
}

int main()
{
    ull n, m;

    std::cin >> n >> m;

    std::cout << legoBlocks(n, m) << std::endl;

    return 0;
}