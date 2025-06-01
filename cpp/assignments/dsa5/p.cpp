#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data) : next(nullptr), prev(nullptr), data(data) {}
    ~Node()
    {
        delete prev;
        delete next;
    }
};

class DLL
{
    Node *head;
    Node *tail = head;

public:
    DLL()
    {
        head = nullptr;
        tail = nullptr;
    }
    void addFirst(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            newNode->next = head;
            tail = newNode;
            tail->prev = head;
        }
        newNode->next = head;
        head = newNode->prev;
    }
    void addLast(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            addFirst(data);
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    Node *search(int data)
    {
        if (head == nullptr)
            return nullptr;
        Node *temp = head;
        while (temp)
        {
            if(temp->data == data){
                return temp;
            }
        }
        return nullptr;
        
    }
    void insert(int idx,int data){
        Node *newNode = new Node(data);

        if(idx<0){
            cout<<"Invalid index";
        }
        if(idx==0){addFirst(data); return;}
        Node *temp = head;
        while(temp && idx){
            idx--;
            temp=temp->next;
        }
        if(idx==0 && temp!=nullptr){
            newNode->next = temp;

        }
        

    }
    Node* insertAfter(Node *node,int data){
        Node *t = new Node(data);
        if(node==nullptr){
            t->next = node;
            node = t;
        }
        node->next = new Node(data);
    }
    void deleteFirst(){
        if(head==nullptr)return;

        Node  *toDelete = head;
        head = head->next;
        head->prev = nullptr;
        delete toDelete;

    }
    void deleteLast(){
        if(head==nullptr)return;
        if(head->next==nullptr){
            Node *temp = head;
            head = nullptr;
            delete temp;
            return;
        }
        Node *temp= tail;
        tail->prev = tail;
        delete temp;
    }
    void searchAndDelete(int data) {
        Node* node = search(data);
        if (node) {
            if (node == head) {
                head = head->next;
                delete node;
                return;
            }
            Node* temp = head;
            while (temp->next != nullptr) {
                if (temp->next == node) {
                    temp->next = node->next;
                    delete node;
                    return;
                }
                temp = temp->next;
            }
        }
    }
    void deleteNode(int data){
        
    }
    
    ~DLL(){
        while(head) deleteFirst();
    }
};  