/*
    Difference between circular linkedlist and singly list is the circular end element
    pointing to head.
*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node( int val ){
            this->data = val;
            this->next = NULL;
        }
};

void insertAtHead( node* &head , int value ){
    node* n = new node( value );
    if( head == NULL ){
        n->next = n;
        head = n;
        return;
    }
    node* temp = head;
    while( temp->next != head ){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
    return;
}

void insertAtTail( node* &head , int value ){
    
    if( head == NULL ){
        insertAtHead( head , value );
        return;
    }
    node* n = new node( value );
    node* temp = head;

    while( temp->next != head ){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    return;
}

void display( node* head ){

    if( head == NULL ){
        cout << "No elements in linkedlist to display." << endl;
        return;
    }
    node* temp = head;
    do{
        cout << temp->data << "->";
        temp = temp->next;
    }while( temp != head );
    
    cout << "NULL" << endl;
    return;
}

int main (){

    node* head = NULL;

    display( head );

    insertAtTail( head, 67 );
    insertAtTail( head, 44 );
    insertAtTail( head, 34 );
    insertAtTail( head, 56 );
    insertAtTail( head, 53 );
    insertAtTail( head, 89 );

    display( head );

    insertAtHead( head , 4 );
    insertAtHead( head , 5 );
    insertAtHead( head , 6 );

    display( head );

    return 0;
}