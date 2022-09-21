class Node{
    int val;
    Node left;
    Node right;

    Node(){

    }

    Node( int val ){ 
        this.val = val;
        left = right = null;
    } 

    int heightOfBinaryTree( Node root ){
        if( root == null ){
            return 0;
        }
        return Math.max(heightOfBinaryTree(root.left),heightOfBinaryTree(root.right))+1;
    }
}

class height{
    public static void main( String[] args ){
        Node root = new Node( 10 );
        root.left = new Node(8);
        root.right = new Node(30);
        root.right.left = new Node(40);
        root.right.right = new Node(50);

        int result = root.heightOfBinaryTree( root );
        System.out.println("The height of the binary tree is : "+result);
    } 
}