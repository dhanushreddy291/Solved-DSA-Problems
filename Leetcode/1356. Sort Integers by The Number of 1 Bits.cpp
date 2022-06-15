class Solution
{
	private:
		static bool setBits(const int &a, const int &b)
		{
			int n1 = a, n2 = b, bits1 = 0, bits2 = 0;
			while (n1)
			{
				n1 &= (n1 - 1);
				bits1++;
			}
			while (n2)
			{
				n2 &= (n2 - 1);
				bits2++;
			}
			return bits1 == bits2 ? a < b : bits1 < bits2;
		}
	public:
		vector<int> sortByBits(vector<int> &arr)
		{
			sort(arr.begin(), arr.end(), setBits);
			return arr;
		}
};