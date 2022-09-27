#include<iostream>
#include<string>
using namespace std;

void set(string str , int index=0 , string curr="" ){

    int n=str.length();
    if( index == n ){
        cout << curr << endl;
        return;
    }
    set(str , index+1 , curr+str[index]);
    set(str , index+1 , curr);
    return;
}

int main (){

    string str;
    cout << "Enter the string : ";
    cin >> str;

    set( str );
    return 0;
}