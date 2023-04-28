def findMedian(arr):
    # Write your code here
    arr.sort()
    return arr[int(len(arr)/2)]
