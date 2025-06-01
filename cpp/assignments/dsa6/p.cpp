#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data):data(data),next(nullptr){}
};

class CLL{ 
    public:
    Node *head;
    Node *tail;

    CLL():head(nullptr),tail(nullptr){}
    void insertFirst(int data){
        Node *newNode = new Node(data);
        if(head==nullptr){
            newNode->next = head;
            tail->next = head;
            tail = head;
        }
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
