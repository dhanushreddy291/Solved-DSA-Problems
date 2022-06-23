class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        Set = set()
        for num in arr:
            if (num % 2 == 0 and num // 2 in Set) or 2 * num in Set:
                    return True
            Set.add(num)
        return False