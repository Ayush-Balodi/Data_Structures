/*
    Postfix Evaluation is done by traversing the string and then adding operands to the stack 
    and poping them out when operator arises and make the operation associated with the operator seperately.

    46+2/5*7+       stack = -1[empty]
 -->
    6+2/5*7+        stack => 4
 -->
    +2/5*7+         stack => 6
 -->      
    now operator arises then,
    op2 = top then pop => 6
    op1 = top then pop => 4
    op = op1 + op2 => 4+6 => 10

    This is how this works.
*/
#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

int operation(int op1 , int op2 , char op){

    if(op == '+'){
        return (op1+op2);
    }
    else if(op == '-'){
        return (op1-op2);
    }
    else if(op == '*'){
        return (op1*op2);
    }
    else if(op == '/'){
        return (op1/op2);
    }
    else{
        return (op1%op2);
    }
}

int postfixEvaluation(string str){

    int op1 , op2;
    int n = str.length();
    stack<int> st;

    for(int i=0 ; i<n ; i++){
        if( str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' ){
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();

            int res = operation(op1 , op2 , str[i]);
            st.push(res);
        }
        else{
            st.push(str[i]-'0');
        }
    }
    return st.top();
}

int main (){
    string str = "46+2/5*7+";

    int result = postfixEvaluation(str);

    cout << "The result of the operation is : " << result;
    return 0;
}