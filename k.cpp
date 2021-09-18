int main()
{
	int N = 30;
	int knightPos[] = { 1, 1 };
	int targetPos[] = { 30, 30 };
	cout << minStepToReachTarget(knightPos, targetPos, N);
	return 0;
}