class Solution:
    def mergeAlternately(self, a: str, b: str) -> str:
        return ''.join([str(a[i]) + str(b[i]) for i in range(min(len(a), len(b)))]) + a[min(len(a), len(b)):] + b[min(len(a), len(b)):]