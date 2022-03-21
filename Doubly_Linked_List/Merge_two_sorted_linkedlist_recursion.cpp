/*
    Merging of two linked list in sorted manner through recursion.
    Merge function compares two nodes then add smaller node toresult and call the function 
    again for next.
*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node( int value ){
            this->data = value;
            this->next = NULL;
        }
};

void insertathead( node* &head , int value ){
    node* n = new node( value );
    n->next = head;
    head = n;
    return;
}

void createnode( node* &head , int value ){

    if( head == NULL ){
        insertathead( head , value );
        return;
    }
    node* n = new node( value );
    node* temp = head;

    while( temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = n;
    return;
}

node* merge( node* &head1 , node* &head2 ){

    if( head1 == NULL ){
        return head2;
    }
    if( head2 == NULL ){
        return head1;
    }

    node* result;
    if( head1->data < head2->data ){
        result = head1;
        result->next = merge( head1->next , head2 );
    }
    else{
        result = head2;
        result->next = merge( head1 , head2->next );
    }
    return result;
}

void display( node* head ){
    if( head == NULL ){
        cout << "No elements in the linkedlist." << endl;
        return;
    }
    node* temp = head;
    while( temp != NULL ){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return;
}

int main (){
    node* head1 = NULL;

    createnode( head1 , 23 );
    createnode( head1 , 55 );
    createnode( head1 , 65 );
    createnode( head1 , 89 );
    display( head1 );
    
    node* head2 = NULL;
    insertathead( head2 , 89 );
    insertathead( head2 , 65 );
    insertathead( head2 , 55 );
    insertathead( head2 , 23 );    

    display( head2 );

    node* newhead = merge( head1 , head2 );

    display( newhead );
    return 0;
}