/*
    To reverse a sentence using stack , we just push it in the stack and
    just print it back while popping other elements to get reverses string.

    Here , I have overloaded getline() function to delimit the string using space.
    For that I have use string stream to convert the flow of string to character to make it easier and efficient
    to delimit the string.
*/

#include<iostream>
#include<stack>
#include<sstream>

using namespace std;

int main (){
    string word , str = "Hey, how are you doing?";
    stack<string> st;

    stringstream ss(str);

    while( getline( ss , word , ' ' ) ){
        st.push( word );
    }

    while( (st.empty()) != 1 ){
        cout << st.top() << " " ;
        st.pop();
    }
    cout << endl;
    return 0;
}