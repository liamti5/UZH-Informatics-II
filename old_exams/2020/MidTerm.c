#include <stdio.h>
#include <math.h>

// ex1

int sum ( int a [] , int b [] , int n ) {
     int s = 0;
     int o = 0;
     for ( int i = n - 1; i >= 0; i--) {
     s = s + (( a [ i ] + b [ i ] + o ) % 10) * ( int ) pow (10 , n -1 - i ) ;
     o = ( a [ i ] + b [ i ] + o ) / 10 ;
     }
     return s + o * ( int ) pow (10 , n ) ;
    }
