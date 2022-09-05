class Node{

    int data;
    Node left;
    Node right;
    Node( int val ){
        this.data = val;
    }

    void traverse( Node root ){
        if( root == null ){
            return;
        }
        System.out.print(root.data+" ");
        traverse( root.left );
        traverse( root.right );
        return;
    }
}

class tree_node{
    public static void main( String args[] ){
        Node root = new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.left.left = new Node(40);

        root.traverse( root );
    }
}