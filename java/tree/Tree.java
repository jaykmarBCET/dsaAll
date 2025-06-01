
class Node{
    int data;
    Node left;
    Node right;

    Node(int data){
        this.data = data;
        left = null;
        right = null;
    }
}

class BinaryTree{
    public static int index =-1;
    public static Node buildTree(int node[]){
        index++;
        if(node[index]==-1){
            return null;
        }
        Node newNode = new Node(node[index]);
        newNode.left = buildTree(node);
        newNode.right = buildTree(node);
        return newNode; 
    }
    public void traver(Node root){
        if(root==null)return;
        System.out.println(root.data);
        traver(root.left);
        traver(root.right);
    }    
}

public class Tree{
    public static void main(String args[]){
        int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        BinaryTree tree = new BinaryTree();
        Node root = tree.buildTree(nodes);
        tree.traver(root);
    }
}