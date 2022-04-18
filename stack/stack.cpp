/*
	Stack is a lifo based data structure where insertion(push) and deletion(pop)
	takes place in O(1) time.
	push( int val )
	pop()
	top_element()
	empty()
*/

#include<iostream>
using namespace std;

#define n 10

class stack{

	int* arr;
	int top;

	public:
		stack(){
			arr = new int[n];
			top = -1;
		}

		void push( int val ){
			if( top == n-1 ){
				cout << "Overflow" << endl;
				return;
			}
			arr[++top] = val;
			return;
		}

		void pop(){
			if( top == -1 ){
				cout << "Underflow" << endl;
				return;
			}
			top--;
			return;
		}

		int top_element(){
			if( top == -1 ){
				cout << "Underflow" << endl;
				return -1;
			}
			return (arr[top]);
		}

		bool empty(){
			return (top == -1);
		}
};

int main (){
	stack s;
	s.push(2);
	s.push(3);
	s.push(4);

	s.pop();
	cout << s.top_element() << endl;

	s.pop();
	s.pop();
	cout << s.top_element() << endl;

	return 0;
}