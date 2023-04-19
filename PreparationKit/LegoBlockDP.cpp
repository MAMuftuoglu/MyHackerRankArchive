#include <iostream>
#include <cmath>

int legoBlocks(int n, int m) {
    int * rowArr = new int[m];
    rowArr[0] = 1;
    int indexSum;
    
    for(int index = 1; index < m; index++) {
        indexSum = 0;
        for(int blockSize = 1; blockSize <=4 && (index - blockSize) >= -1; blockSize++) {
            if(index - blockSize == -1) indexSum++;
            else if (index - blockSize > -1) indexSum += rowArr[index - blockSize];
        }
        
        rowArr[index] =  indexSum;
    }
    
    
    int * resultArr = new int[m];
    resultArr[0] = 1;
    
    for(int index = 1; index < m; index++) {
        indexSum = std::pow(rowArr[index], n);
        for(int leftCut = 0; leftCut < index; leftCut++) {
            indexSum -= resultArr[leftCut] * std::pow(rowArr[index - leftCut - 1], n);
        }
        resultArr[index] = indexSum;
        std::cout << indexSum << " ";
    }
    
    std::cout << std::endl;

    int mod = std::pow(10, 9) + 7;
    
    return (resultArr[m-1] % mod);
}

int main() {
    int n, m;

    std::cin >> n >> m;

    std::cout << legoBlocks(n, m) << std::endl;

    return 0;
}