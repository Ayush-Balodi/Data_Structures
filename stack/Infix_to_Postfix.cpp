/*
    (a-b/c)*(a/k-l)
 -->                stack => ( ; result = ""
    a-b/c)*(a/k-l) 
 -->                stack => ( ;  result = "a"
    -b/c)*(a/k-l)
 -->                stack => - ; result = "a"
    b/c)*(a/k-l)
 -->                stqck => - ; result = "a"
    /c)*(a/k-l)
 -->                stack => /[since - has less precedence then / so pop and print] result=>"a-"
 that is how this works
*/

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int precedence( char ch ){
    
    if( ch == '+' || ch == '-' ){
        return 1;
    }    
    else if( ch == '*' || ch == '/' || ch == '%' ){
        return 2;
    }
    else{
        return -1;
    }
}

string infixToPostfix( string str ){

    string result = "";
    stack<char> st;
    int n = str.length();
    for( int i=0 ; i<n ; i++ ){
        
        if( str[i] == '(' ){
            st.push( str[i] );
        }
        else if ( str[i] == ')' ){

            while( !st.empty() && (st.top() != '(') ){

                result += st.top();
                st.pop();
            }     
            if( !st.empty() ){
                st.pop();
            }       
        }
        else if( str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' ){
            
            while( !st.empty() && (precedence(st.top())>precedence(str[i])) ){
                result += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        else{
            result += str[i];
        }
    }

    while( !st.empty() ){
        result += st.top();
        st.pop();
    }

    return result; 
}

int main (){
    string str = "(a-b/c)*(a/k-l)";
    string result = infixToPostfix( str );
    cout << "The result is : " << result;
    return 0;
}