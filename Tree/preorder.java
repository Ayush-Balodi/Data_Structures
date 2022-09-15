class Node{

    int val;
    Node left;
    Node right;
    Node( int val ){
        this.val = val;
    }

    void pre( Node root ){

        if( root == null ){
            return;
        }
        System.out.print(root.val+" ");
        pre( root.left );
        pre( root.right );
        return;
    }
}

class preorder{
    public static void main (String[] args){
        Node root = new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.left.left = new Node(40);

        root.pre( root );
    }
}