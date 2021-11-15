class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        
        def MinCostWhenEmpty(needs, price, M):
            Cost = 0;
            for i in range(M): 
                Cost += needs[i] * price[i]; 
            return Cost

        def ModifyTheNeeds(needs, special, Operation, M, i):
            if Operation == '+':
                for j in range(M):
                    needs[j] += special[i][j]
            else:
                for j in range(M): 
                    needs[j] -= special[i][j]
        
        def ValidOffer(needs, special, M, i):
            for j in range(M): 
                if needs[j] < special[i][j]: 
                    return False
            return True

        MinCost = 10 ** 9
        N = len(special)
        M = len(needs)
        
        for i in range(N):
            if ValidOffer(needs, special, M, i):
                ModifyTheNeeds(needs, special, '-', M, i)
                MinCost = min(MinCost, special[i][-1] + self.shoppingOffers(price, special, needs))
                ModifyTheNeeds(needs, special, '+', M, i)
        
        return min(MinCost, MinCostWhenEmpty(needs, price, M))