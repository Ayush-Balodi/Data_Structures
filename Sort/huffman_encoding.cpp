#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    char data;
    int freq;
    struct node *left, *right;

    node( char x , int y ){
        data = x;
        freq = y;
        left = NULL; right = NULL;
    }
    // node( char x , int y ): data(x), freq(y), left(NULL), right(NULL);
}node;

typedef struct compare{
    bool operator()( node *a , node*b ){
        return (a->freq>b->freq);
    }
}compare;

void display( node *pq  , string str ){

    if( pq  ){
        if(pq->data != '#' ){
            cout << pq->data << ": " << str << endl;
        }
        display( pq->left , str+'0' );
        display( pq->right , str+'1' );
    }
}

void hc( char data[] , int freq[], int n ){
    priority_queue<node*, vector<node*> , compare> pq;
    for( int i=0 ; i<n ; i++ ){
        node* t = new node(data[i],freq[i]);
        pq.push(t);
    }

    while( pq.size() != 1 ){
        node *l = pq.top();
        pq.pop();

        node *r = pq.top();
        pq.pop();

        node* t= new node('#',l->freq + r->freq);
        t->left = l;
        t->right= r;
        pq.push(t);
    }
    display( pq.top() , "" );
}

int main (){
    int n;
    cin >> n;
    char data[n]; 
    int freq[n];
    
    cout << "Enter the characters: ";
    for( auto &x:data ){ cin >> x; }
    cout << " Enter the frequency: ";
    for( auto &x:freq ){ cin >> x; }

    hc( data , freq, n );
    return 0;
}