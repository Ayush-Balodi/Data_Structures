/*
    Reversing a stack without any extra space. For this I have used recusrion in two functions:
    inserAtBottom() => In this function, element id inserted at the bottom.
    revers()        => This function calls stores the top element aant call to store another, then calls insertAtBottom when becomes empty.
 */
#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom( stack<int> &st , int element ){

    if( st.empty() == 1 ){
        st.push( element );
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom( st , element );
    st.push(top);
}

void reverse( stack<int> &st ){

    if( st.empty() == 1 ){
        return;
    }

    int top_element = st.top();
    st.pop();
    reverse( st );
    insertAtBottom( st , top_element );
}

int main (){
    stack<int> st;
    for( int i=5 ; i>=1; i-- ){
        st.push( i );
    }
    reverse( st );

    while( !st.empty() ){
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}