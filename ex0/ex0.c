#include <stdio.h>
#include <time.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()
#define MIN -999999999 


 //testing git
int main() {
	double time_spent = 0.0;
    clock_t begin = clock();

	int n = 5;
	int A[] =  { 11, 3, -3, 2, -5};
	int pos1 = -1, pos2 = -1; //Why -1?
	int target = MIN;
	for(int i = 0; i < n; i++ ) {
		if(A[i] > target) {
			pos1 = i;
			target = A[i];
		}
	}
	target = MIN;
	for(int i = 0; i < n; i++ ) {
		if(i != pos1 && A[i] > target) {
			pos2 = i;
			target = A[i];
		}
	}
	printf("%d\n", A[pos2]);

	sleep(3);
 
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent); 
	//The elapsed time is 0.000104 seconds
	return 0;
}