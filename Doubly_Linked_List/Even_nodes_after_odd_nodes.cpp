/*
    In this program, there is no replacement of data but rather even nodes suggest 
    the position of that node in linkedlist.

    1->2->3->4->5->NULL
    odd->even->odd->even->odd->NULL ==> Refers position not data inside nodes.

    even_after_odd() ==> This function deals of how to do this.

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

void insertAtHead( node* &head , int value ){
    node* n= new node( value );
    if( head == NULL ){
        head = n;
        return;
    }
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

    while( temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = n;
    return;
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

void even_after_odd( node* &head ){

    if( head == NULL ){
        cout << "No elements to make this possible." << endl;
        return;
    }

    if( head->next==NULL || head->next->next == NULL ){
        cout << "No need." << endl;
        return;
    }

    node* odd = head;
    node* even = head->next;
    node* evenStart = even;

    while( even->next != NULL && odd->next != NULL ){
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    if( odd->next != NULL ){
        even->next = NULL;
    }
    return;
}

int main (){

    node* head = NULL;
    int arr[]= {1,2};
    for( int i=0 ; i<2 ; i++ ){
        insertAtTail( head , arr[i] );
    }
    display( head );
    even_after_odd( head );

    display( head );    
    return 0;
}