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
    if( head == NULL ){
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
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

    return 0;
}