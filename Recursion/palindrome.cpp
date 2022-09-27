#include<iostream>
#include<string>
using namespace std;

bool isPalindrome( string str, int l , int r ){

    if( l >= r ){
        return true;
    }
    if( str[l] == str[r] ){
        return isPalindrome( str , ++l , --r );
    }
    else
        return false;
}

int main(){
    
    string str;
    cout << "Enter the string to be checked for palindrome : ";
    cin >> str;
    
    cout << "Answer : ";
    cout << isPalindrome(str, 0 , str.size()-1) << endl;
    return 0;
}