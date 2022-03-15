/*

Doubly linkedlist
    =>createnode function adds new node to last
    =>inserathead function adds bew node from the front
    =>display function display the contents of the linkedlist
    =>deletion function deletes the node other then the first node
    =>deleteathead function deletes nodes from the front
*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* prev;
        node* next;

        node( int value ){
            this->data = value;
            this->prev = NULL;
            this->next = NULL;
        }
};

void insertathead( node* &head , int value ){
    node* n = new node( value );
    n->next = head;
    if( head != NULL ){
        head->prev = n;
    }
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
    n->prev = temp;
    return;
}

void deleteathead( node* &head ){

    if( head == NULL ){
        cout << "No nodes to delete from linkedlist" << endl;
        return;
    }
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
    return;
}

void deletion( node* &head , int pos ){
    node* temp = head;
    int count = 1;

    if( head == NULL ){
        cout << "No nodes to delete from linkedlist" << endl;
        return;
    }
    if( pos == 1 ){
        deleteathead( head );
        return;
    }

    while( temp->next != NULL && count != pos ){
        temp=temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    
    if( temp->next != NULL ){
        temp->next->prev = temp->prev;
    }
    delete temp;

    return;
}

void display( node* head ){
    if( head == NULL ){
        cout << "No elements in the linked list to print." << endl;
    }
    node* temp = head;
    while( temp != NULL ){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return;
}

int main(){
    node* head = NULL;
    
    createnode( head , 2 );
    createnode( head , 3 );
    createnode( head , 4 );
    createnode( head , 5 );
    createnode( head , 6 );

    insertathead( head , 77 );
    display ( head );

    deletion( head , 3 );
    display( head );
    
    deletion( head , 1 );
    display( head );

    return 0;
}