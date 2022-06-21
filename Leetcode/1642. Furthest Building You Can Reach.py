class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        
        i, withBricks, withLadder, N = 0, 0, 0, len(heights)

        if N == 0: return 0
        else:
            while i < N - 1:
                if heights[i + 1] > heights[i]: break
                else: i += 1
            
            if i != N - 1:
                if bricks >= heights[i + 1] - heights[i]:
                    withBricks = 1 + self.furthestBuilding(heights[i+1:], bricks - (heights[i + 1] - heights[i]), ladders)

                if ladders > 0:
                    withLadder = 1 + self.furthestBuilding(heights[i+1:], bricks, ladders - 1)
            
            return i + max(withBricks, withLadder)

    # At every step either pick a ladder or number of bricks
        