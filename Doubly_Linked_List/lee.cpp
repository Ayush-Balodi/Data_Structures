#include<iostream>
using namespace std;

int main (){
    
    string str ,result="";
    cout << "Enter the string : ";
    cin >> str;
    
    int n=str.size(), c;
    for( int i=0 ; i<n ; i++ ){
        if( str[i] == '@' ){
            c=i;
        }
    }
    result.push_back(tolower(str[0]));
    
    int x=5;
    while( x-- ){
        result.push_back('*');
    }
    result.push_back(tolower(str[c-1]));
            
    for( int i=c ; i<n ; i++ ){
        result.push_back(tolower(str[i]));
    }
    cout << "Converted string is : " << result << endl;
    return 0;
}