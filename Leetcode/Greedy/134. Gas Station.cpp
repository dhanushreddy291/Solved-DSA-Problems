class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // Check whether solution exists
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;
        else
        {
            // Find where to start. Need not find cumulutive sum for indexes ending at the right part of array if they are positive because there is a solution that exists, so no need to even check
            int tank = 0, start = 0;
            for (int i = 0; i < gas.size(); i++)
            {
                tank += gas[i] - cost[i];
                if (tank < 0)
                {
                    start = i + 1;
                    tank = 0;
                }
            }
            return start;
        }
    }
};
