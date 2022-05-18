#include <stdio.h>

void freqCount(int A[], int n, int m) {
    int freq[] = {0,0,0,0,0,0,0};
    for (int i=0; i<n; i++) {
        int val = A[i];
        freq[val] = freq[val] + 1;
    }
    for (int i = 0;i<m; i++) {
        for (int j=0;j<freq[i]; j++){
            printf("%d", i);
        }
    }
    
    //printf("%d", freq[]);
}

int main() {
    int A[] = {5,0,2,4,3,6,1,1,5,5,0,6,0,0,2,4};
    freqCount(A, 16, 7);
    return 0;
}
