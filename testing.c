#include <stdio.h>

int DNumbers(int i[4], int n) {
	if (n == 1) {
		return i[1] + i[2] + i[3] + i[4] + i;
	}
	return i + DNumbers(i, n - 1);
}

int main() {
	int A[4] = {1, 2, 0, 0};
	int result = DNumbers(A, 3);
	printf("%d", result);
}
