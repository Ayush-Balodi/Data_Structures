/*
    Intersection of linked list and how to intersect two linked list.
    => intersect function  => does the intersection part of the linkedlists.
    => detect_intersection => detects the intersection of two linkedlist.
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

void intersect( node* &head1 , node* &head2 , int pos ){

    if( head1 == NULL || head2 == NULL ){
        cout << "No element to intersect the linked list." << endl;
        return;
    }

    node* temp1 = head1;
    pos--;
    
    while( pos -- ){
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while( temp2->next != NULL ){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    return;
}

int length( node* &head ){
    node* temp = head;
    int count = 0;

    while( temp != NULL ){
        count ++;
        temp = temp->next;
    }
    return count;
}

int detect_intersection( node* &head1 , node* &head2 ){

    if( head1 == NULL || head2 == NULL ){
        cout << "No elements to detect intersection point." << endl;
        return -1;
    }
    int l1 = length( head1 );
    int l2 = length( head2 );
    int k;

    node *ptr1 , *ptr2;

    if( l1 > l2 ){
        k = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        k = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while( k -- ){
        ptr1 = ptr1->next;
    } 

    while( ptr1 != NULL && ptr2 != NULL ){

        if( ptr1 == ptr2 ){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void display( node* &head ){
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

    node* head = NULL;
    createnode( head , 32 );
    createnode( head , 44 );
    createnode( head , 54 );
    createnode( head , 56 );
    createnode( head , 78 );   

    insertathead( head , 89 ); 

    display( head );

    node* head2 = NULL;

    createnode( head2 , 1 );
    createnode( head2 , 2 );
    createnode( head2 , 3 );
    createnode( head2 , 4 );  

    display( head2 );

    intersect( head , head2 , 3 );

    cout << detect_intersection( head , head2 ) << endl;  
    display( head2 );  
    return 0;
}