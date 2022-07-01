class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=cmp_to_key(lambda x, y: y[1] - x[1]))
        N, index, units = len(boxTypes), 0, 0
        while truckSize >= 0 and index < N:
            unit = min(boxTypes[index][0], truckSize)
            units += unit * boxTypes[index][1]
            index += 1
            truckSize -= unit
        return units