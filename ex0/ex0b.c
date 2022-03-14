#include <stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()
#define MIN -999999999 //??

int main(){
    
    int size;    
    printf("how large is your array? ");
    scanf("%d", &size);
    int a[size];

    printf("input your %d values\n", size);

    for(int i = 0; i < size; i++){
        scanf("%d", &a[i]);
    }   
        
    double time_spent = 0.0;
    clock_t begin = clock();

    int temp1 = MIN;    
    int temp2 = MIN;

    for (int i = 0; i < size; i++){
        if (a[i] > temp1){
            temp1 = a[i];
        }    
    }

    for (int i = 0; i < size; i++){
        if (a[i] < temp1 && a[i] > temp2){
            temp2 = a[i];
        }
    }
   
    printf("the second largest value is: %d\n", temp2);

    sleep(3);
 
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds\n", time_spent); 
    //The elapsed time is 0.000092 seconds
    return 0;
}


