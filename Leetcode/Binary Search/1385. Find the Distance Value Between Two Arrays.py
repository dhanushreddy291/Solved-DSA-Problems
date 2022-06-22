class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        
        N = len(arr2)
        arr2.sort()
        distanceValue = 0

        for num in arr1:
            index1, index2 = bisect_left(arr2, num + d), bisect_left(arr2, num - d)  
            if  index1 == index2 and arr2[index1 % N] != num + d:
                distanceValue += 1

        return distanceValue