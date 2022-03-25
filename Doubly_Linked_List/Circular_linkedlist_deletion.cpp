/*
    Deletion in circular linkedlist is samee as of singly linked list but corner cases are to be handled well
    which are present in following functions:-
    => deletion()   ==> temp->next = temp->next->next
    => deleAtHead() ==> temp->next = head->next and head = head->next
*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node( int value ){
            this->data = value;
            this->next =  NULL;
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
        cout << "No elements in the linkedlist." << endl;
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

void deleteAtHead( node* &head ){
    node* temp = head;
    node* todelete = head;

    while( temp->next != head ){
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;

    delete todelete;
    return;
}

void deletion( node* &head , int pos ){

    if( head == NULL ){
        cout << "No element to delete." << endl;
        return;
    }

    if( pos == 1 ){
        deleteAtHead( head );
        return;
    }
    node* temp = head;
    int count = 1;

    while( count != pos-1 ){
        temp = temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    return;
}

int main (){
    node* head = NULL;
    insertAtTail( head , 34 );
    insertAtTail( head , 53 );
    insertAtTail( head , 90 );
    insertAtTail( head , 48 );
    insertAtTail( head , 77 );

    display( head );

    deletion( head , 1 );

    display( head );
    return 0;
}