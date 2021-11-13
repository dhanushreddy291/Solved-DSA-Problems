class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        Stack = []
        N = len(temperatures)
        Stack.append(N - 1)
        Answer = [0] * N
        for i in range(N - 2, -1, -1):
            while len(Stack) > 0 and temperatures[i] >= temperatures[Stack[-1]]: 
                Stack.pop()
            if len(Stack) != 0: 
                Answer[i] = Stack[-1] - i
            Stack.append(i)
        return Answer