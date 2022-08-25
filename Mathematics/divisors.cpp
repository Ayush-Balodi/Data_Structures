#include<iostream>
#include<cmath>
using namespace std;

void divisorsOfNumber( int num ){

    //cout << "1 ";
    int i=1;
    for( i ; i<=sqrt(num) ; i++ ){
        if( num%i == 0 ){
            cout << i << " ";
        }
    }

    for( ; i>=1 ; i-- ){
        if( num % i == 0 ){
            cout << (num/i) << " ";
        }
    }
    return;
}

int main (){

    int num;
    cout << "Enter the number : ";
    cin >> num;

    divisorsOfNumber( num );
    return 0;
}