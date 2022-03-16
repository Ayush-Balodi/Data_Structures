/*
    Append k nodes from last to front of the linked list.
    length_of_linkedlist => This functions tells the legth of the linikedlist.
    append               => This function append the k nodes to front of linkedlist.
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
    node* n = new node( value );

    if( head == NULL ){
        insertathead( head , value );
        return;
    }
    node* temp = head;
    while( temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = n;
    return;
}

void display( node* head ){
    if( head == NULL ){
        cout << "No nodes in the linked list." << endl;
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

int length_of_linkedlist( node* head ){
    node* temp = head;
    int count = 0;

    while( temp != NULL ){
        count ++;
        temp = temp->next;
    }
    return count ;
}

node* append( node* &head , int k ){
    if( head == NULL ){
        cout << "No nodes in the linked list." << endl;
        return head;
    }

    int l = length_of_linkedlist( head );
    
    if( l < k ){
        cout << "Not possible." << endl;
        return head;
    }
    
    node* temp = head;
    int count = 0;

    node *newhead , *newtail , *tail;
    
    while( temp != NULL ){
        count++;
        if( count == ( l-k ) ){
            newtail = temp;
        }
        if( count == ( l-k+1 ) ){
            newhead = temp;
        }
        if( count == l ){
            tail = temp;
        }
        temp = temp->next;
    }
    newtail->next = NULL;
    tail->next = head;

    return newhead;
}

int main (){

    node* head = NULL;

    createnode( head , 23 );
    createnode( head , 78 );
    createnode( head , 45 );
    createnode( head , 32 );
    createnode( head , 54 );
    createnode( head , 55 );
    display( head );

    insertathead( head , 46 );
    display( head );

    node* newhead = append( head , 3 );
    display( head );
    display( newhead );

    return 0;
}