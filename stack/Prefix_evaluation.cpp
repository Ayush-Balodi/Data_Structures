/*
    Prefix Evaluation is done by traversing the string in reversed order and then adding operands to the stack 
    and poping them out when operator arises and make the operation associated with the operator seperately.

    -+7*45+20       stack = -1[empty]
            <--
    -+7*45+2        stack => 0
            <--
    -+7*45+       stack => 2
          <--
    now operator arises then,
    op1 = top then pop => 2
    op2 = top then pop => 0
    op = op1 + op2 => 2+0 => 2

    This is how this works.
*/

#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>

using namespace std;

int operation ( int op1 , int op2 , char ch ){

    if( ch == '+' ){
        return (op1+op2);
    }
    else if( ch == '-' ){
        return (op1-op2);
    }
    else if( ch == '*' ){
        return (op1*op2);
    }
    else if( ch == '/' ){
        return (op1/op2);
    }
    else{
        return (op1%op2);
    }
}

int prefixEvaluation( string str ){

    stack<int> st;
    int op1 , op2;

    for( int i=str.length()-1 ; i>=0 ; --i ){
        if( str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' ){
            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();

            int op = operation( op1 , op2 , str[i] );
            st.push(op);
        }
        else{
            st.push(str[i]-'0');
        }
    }
    return st.top();
}

int main (){
    
    string str = "-+7*45+20";

    int result = prefixEvaluation( str );
    cout << result << endl;
    return 0;
}