class Node{
    int data;
    Node next;
    public Node(int data){
        this.data = data;
        this.next = null;
    }
}


 public class LinkedList{
    Node head=null;

    void addFisrt(int data){
        Node newNode = new Node(data);
        if(head==null){
            head = newNode;
            return;
        }
        newNode.next = head;
        head = newNode;
    }
    void addLast(int data){
        Node newNode = new Node(data);
        if(head==null){
            head = newNode;
            return;
        }
        Node temp = head;
        while(temp.next!=null){
            temp = temp.next;
        }
        temp.next = newNode;
        temp = newNode;
    }
    void addPos(int pos,int data){
        Node newNode = new Node(data);
        if(pos<0){
            System.out.println("Cant insert less then 0 position");
            return;
        }
        if(pos==0){
            addFisrt(data);
            return;
        }
        Node temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp==null){
                System.out.println("Null pointer exceptions");
                return;
            }
            temp = temp.next;
        }
        if(temp==null){
            System.out.println("Null pointer exception");
            return;
        }
        newNode.next = temp.next;
        temp.next = newNode;
    }
    int removeFirst(){
        if(head==null)return Integer.MIN_VALUE;
        int data = head.data;
        head = head.next;
        return  data;
    }
    int removeLast(){
        if(head==null)return Integer.MIN_VALUE;
        if(head.next==null){
            int data = head.data;
            head = null;
            return data;
        }
        Node temp = head;
        while(temp.next.next!=null){
            temp= temp.next;
        }
        int data = temp.next.data;
        temp.next = null;
        return  data;
    }
    int removePos(int pos) {
        if (head == null || pos < 0) {
            return Integer.MIN_VALUE;
        }
    
       
        if (pos == 0) {
            int data = head.data;
            head = head.next;
            return data;
        }
    
        Node temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == null || temp.next == null) {
                return Integer.MIN_VALUE;
            }
            temp = temp.next;
        }
    
        if (temp.next == null) {
            return Integer.MIN_VALUE;
        }
    
        int data = temp.next.data;
        temp.next = temp.next.next;
        return data;
    }

 }