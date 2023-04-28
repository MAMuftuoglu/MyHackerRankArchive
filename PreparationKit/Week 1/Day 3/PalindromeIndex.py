#
# Complete the 'palindromeIndex' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#
def palindromeIndex(s):
 # Write your code here
    returnIndex = -1
    for index in range(int(len(s)/2)):
        if s[index] != s[len(s) - index - 1]:
            returnIndex = index
            break


    if returnIndex != -1:
        newStr1 = s[:returnIndex] + s[returnIndex + 1:]
        to2 = s[-1:-1:-1]
        newStr2 = to2[:returnIndex] + to2[returnIndex + 1:]
        newStr2 = newStr2[-1:-1:-1]
        valueCheck = returnIndex
        for index in range(int(len(newStr1)/2)):
            if newStr1[index] != newStr1[len(newStr1) - index - 1]:
                valueCheck = -1
                break

        if valueCheck == -1:
            returnIndex = len(s) - returnIndex - 1
            for index in range(int(len(newStr2)/2)):
                if newStr2[index] != newStr2[len(newStr1) - index - 1]:
                    returnIndex = -1
                    break


    return returnIndex