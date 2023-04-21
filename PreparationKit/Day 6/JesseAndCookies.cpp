#include <bits/stdc++.h>

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */


int cookies(int k, std::vector<int> A) {
    int result = -1;



    return result;
}


int main()
{
    int n, k;

    std::cin >> n >> k;

    std::vector<int> array(n);

    for(int index = 0; index < n; index++) {
        std::cin >> array[index];
    }

    std::cout << cookies(k, array) << std::endl;

    return 0;
}
