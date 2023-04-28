#include <bits/stdc++.h>

int flippingMatrix(std::vector<std::vector<int>> matrix)
{
    int sum = 0;
    for (int i = 0; i < matrix.size() / 2; i++)
    {
        for (int j = 0; j < matrix.size() / 2; j++)
        {
            int maxScore = matrix[i][j];
            if (maxScore < matrix[i][matrix.size() - j - 1])
                maxScore =
                    matrix[i][matrix.size() - j - 1];
            if (maxScore < matrix[matrix.size() - i - 1][j])
                maxScore =
                    matrix[matrix.size() - i - 1][j];
            if (maxScore < matrix[matrix.size() - i - 1][matrix.size() - j -
                                                         1])
                maxScore = matrix[matrix.size() - i - 1][matrix.size() - j - 1];
            sum += maxScore;
        }
    }
    return sum;
}