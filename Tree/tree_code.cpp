#include<iostream>
using namespace std;

class node{
public:
  int key;
  node *right;
  node *left;

  node(){

  }
  node( int k ){
    this->key = k;
    left = right = NULL;
  }
};

void traverse( node* root ){
  if( root == NULL ){
    return;
  }
  cout << root->key << " ";
  traverse( root->left );
  traverse( root->right );
  return;
}

int main(){

  node *root = new node(30);
  root->left = new node(40);
  root->right = new node(50);
  root->left->left = new node(60);

  traverse(root);
  return 0;
}
