/*
    Here , to reverse the sentence I have used while loop to callibrate 
    word then push it onto the stack to print it later on.
*/
#include<iostream>
#include<stack>

using namespace std;

int main (){
    string str = "Hey, how are you doing?";
    stack<string> st;

    for( int i=0 ; i<str.length() ; i++ ){
        string word = "";
        while( str[i] != ' ' && i < str.length() ){
            word += str[i];
            i++;
        }
        st.push( word );
    }

    while( (st.empty()) != 1 ){
        cout << st.top() << " " ;
        st.pop();
    }
    cout << endl;
    return 0;
}