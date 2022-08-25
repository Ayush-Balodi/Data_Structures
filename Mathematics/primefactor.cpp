/*
    this solution focuses on each number and explicitly check for every number
*/

#include <iostream>
#include<cmath>
using namespace std;

void primeFactor( int num ){

    for( int i=2 ; i<=sqrt(num) ; i++ ){
        while( num % i == 0 ){
            cout << i << " ";
            num = num/i;
        }
    }
    if( num > 1 ){
        cout << num << " ";
    }
    return;
}

int main(){
    int num;
    cout << "Enter the number for which you want prime factors : ";
    cin >> num;
    primeFactor( num );
    return 0;
}

/*
    this method is optimized as in we are elimnating the number divisible by 2 and 3 beforehand.
*/

#include<iostream>
#include<cmath>
using namespace std;

void primeFactor( int num ){

    if( num <= 1 ){
        return;
    }
    while( num%2 == 0 ){
        cout << "2 ";
        num /= 2;
    }
    while( num%3 == 0 ){
        cout << "3 ";
        num /= 3;
    }
    for( int i=5 ; i<=sqrt(num) ;i+=6 ){

        while( num%i == 0 ){
            cout << i << " ";
            num /= i;
        }
        while( num%(i+2) == 0 ){
            cout << i << " ";
            num /= (i+2) ;
        }
    }
    if( num > 3 ){
        cout << num << " ";
    }
    return;
}

int main (){

    int num;
    cout << "Enter the number for which you want prime factors : ";
    cin >> num;
    primeFactor( num );
    return 0;
}