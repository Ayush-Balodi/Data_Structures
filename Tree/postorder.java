class Node{

    int val;
    Node left;
    Node right;

    Node( int val ){
        this.val = val;
    }

    void post( Node root ){
        if( root == null ){
            return;
        }
        post( root.left );
        post( root.right );
        System.out.print(root.val+" ");
        return;
    }
}

class postorder{
    public static void main( String[] args ){

        Node root = new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.left.left = new Node(40);

        root.post( root );
    }
}