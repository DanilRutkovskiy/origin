double add(double n1, double n2) {
	return n1 + n2;
}

double substract(double minuend, double subtrahend) {
	return minuend - subtrahend;
}

double multiply(double n1, double n2) {
	return n1 * n2;
}

double divide(double dividend, double divisor) {
	return dividend / divisor;
}

double power(double n1, double pow) {
	double ret = 1;
	for (int i = 0; i < pow; i++)
		ret *= n1;
	
	return ret;
}