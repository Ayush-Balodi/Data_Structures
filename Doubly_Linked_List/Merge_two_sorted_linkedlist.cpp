/*
    Merging of two linked list in sorted manner through iteration.
    Merge function compares two nodes then add smaller node to dummynode->next
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
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* dummyNode = new node(-1);
    node* ptr3 = dummyNode;

    while( ptr1 != NULL && ptr2 != NULL ){
        if( ptr1->data <= ptr2->data ){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    while( ptr1 != NULL ){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }

    while( ptr2 != NULL ){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return (dummyNode->next);
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
    createnode( head1 , 23 );
    createnode( head1 , 55 );
    createnode( head1 , 65 );
    createnode( head1 , 89 );
    display( head1 );
    
    node* head2 = NULL;
    insertathead( head2 , 45 );
    insertathead( head2 , 99 );
    display( head2 );

    node* newhead = merge( head1 , head2 );

    display( newhead );
    return 0;
}