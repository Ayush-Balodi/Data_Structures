#include<stdio.h>
#include<stdlib.h>

void swap( int *a , int *b ){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void heapify( int nums[] , int n , int i ){

    int c1=2*i+1 , c2=2*i+2;
    if( c1<n && nums[c1] > nums[i] ){
        swap( &nums[c1] , &nums[i] );
        heapify( nums , n , c1 );
    }
    if( c2<n && nums[c2] > nums[i] ){
        swap( &nums[c2] , &nums[i] );
        heapify( nums , n , c2 );
    }
    return;
}

void heapSort( int nums[] , int n ){

    for( int i=n/2 ; i>=0 ; i-- ){
        heapify( nums , n , i );
    }
    return;
}

int main (){

    int nums[] = { 23 , 17 , 31 , 43 , 55 , 27 , 19 , 10 };
    int n = sizeof(nums)/sizeof(nums[0]);
    printf("Answer : ");
    for( int i=0 ; i<n ; i++ ){
        printf("%d ",nums[i]);
    }
    heapSort( nums, n);
    printf("Answer : ");
    for( int i=0 ; i<n ; i++ ){
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
}