class Node{

    int val;
    Node left;
    Node right;
    Node( int val ){ 
        this.val = val;
    }

    void ino( Node root ){
        if( root == null ){
            return;
        }
        ino( root.left );
        System.out.print( root.val+" " );
        ino( root.right );
        return;
    }
}

class inorder{
    public static void main( String[] args ){
        Node root = new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.left.left = new Node(40);

        root.ino(root);
    }
}