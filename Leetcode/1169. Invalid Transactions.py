class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        possiblyValid = {}
        invalid = []
        for transaction in transactions:
            temp = transaction.split(',')
            if temp[2] > 1000:
                invalid.append(transaction)
            else:
                possiblyValid[temp[0]].append()
        
