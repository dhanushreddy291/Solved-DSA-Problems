class Solution:
    
    def validTicTacToe(self, board: List[str]) -> bool:
        countofX = sum([sum([1 if board[i][j] == 'X' else 0 for j in range(3)]) for i in range(3)])
        countofO = sum([sum([1 if board[i][j] == 'O' else 0 for j in range(3)]) for i in range(3)])
        if countofO > countofX or countofX > 1 + countofO:
            return False
        if countofX < 3:
            return True
        isXSolved = self.isSolved(board, 'X')
        isOSolved = self.isSolved(board, 'O')
        if isOSolved and isXSolved or (isXSolved and countofO == countofX) or (isOSolved and countofO + 1 == countofX):
            return False
        return True
    
    def isSolved(self, board, ch):
        return max([sum([1 if board[i][j] == ch else 0 for j in range(3)]) for i in range(3)]) == 3 or max([sum([1 if board[i][j] == ch else 0 for i in range(3)]) for j in range(3)]) == 3 or sum([1 if board[i][i] == ch else 0 for i in range(3)]) == 3 or sum([1 if board[2 - i][i] == ch else 0 for i in range(3)]) == 3