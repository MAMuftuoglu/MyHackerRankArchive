#include <iostream>
#include <cmath>

unsigned long addMod(unsigned long a, unsigned long b, unsigned long mod) {
    return (a < (mod - b)) ? a + b : a - (mod - b);
}

unsigned long multiplyMod(unsigned long a, unsigned long b, unsigned long mod) {
    unsigned int result = 0;

    while(b > 0){
        if(b & 1) result = addMod(result, a, mod);
        a = addMod(a, a, mod);
        b >>= 1;
    }

    return result;
}

int legoBlocks(int n, int m) {
    unsigned long * rowArr = new unsigned long[m];
    rowArr[0] = 1;
    int indexSum;
    unsigned long mod = std::pow(10, 9) + 7;
    
    for(int index = 1; index < m; index++) {
        indexSum = 0;
        for(int blockSize = 1; blockSize <=4 && (index - blockSize) >= -1; blockSize++) {
            if(index - blockSize == -1) addMod(indexSum, 1, mod);
            else if (index - blockSize > -1) indexSum += rowArr[index - blockSize];
        }
        
        rowArr[index] =  indexSum;
    }
    
    
    unsigned long * resultArr = new unsigned long[m];
    resultArr[0] = 1;
    
    for(int index = 1; index < m; index++) {
        indexSum = std::pow(rowArr[index], n);
        for(int leftCut = 0; leftCut < index; leftCut++) {
            indexSum -= resultArr[leftCut] * std::pow(rowArr[index - leftCut - 1], n);
        }
        resultArr[index] = indexSum;
        // std::cout << indexSum << " ";
    }
    
    // std::cout << std::endl;
    
    return (resultArr[m-1] % mod);
}

int main() {
    int n, m;

    std::cin >> n >> m;

    std::cout << legoBlocks(n, m) << std::endl;

    return 0;
}