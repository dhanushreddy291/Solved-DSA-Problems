class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        Stack = []
        Answer = [0] * len(temperatures)
        for i in range(len(temperatures) - 1, -1, -1):
            while Stack and temperatures[i] >= temperatures[Stack[-1]]: 
                Stack.pop()
            if len(Stack) != 0: 
                Answer[i] = Stack[-1] - i
            Stack.append(i)
        return Answer