int trailingZeroesInFactorial(int n) {
	return n == 0 ? 0 : n/5 + trailingZeroesInFactorial(n/5);
}
