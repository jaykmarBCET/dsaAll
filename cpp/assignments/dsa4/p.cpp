#include <iostream>
#include <stdexcept>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
    ~Node(){
        delete next;
    }
};

class SLL {
    Node *head;
    Node *tail;
    int _size;

public:
    SLL() : head(nullptr), tail(nullptr), _size(0) {}

    ~SLL() {
        while (head) {
            removeFirst();
        }
    }

    void addFirst(int data) {
        Node *temp = new Node(data);
        _size++;
        if (head == nullptr) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void addLast(int data) {
        Node *newNode = new Node(data);
        _size++;
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int getSize() { return _size; }

    void insert(int idx, int data) {
        if (idx < 0 || idx > _size) {
            throw out_of_range("Index out of bounds");
        }
        if (idx == 0) {
            addFirst(data);
            return;
        }
        if (idx == _size) {
            addLast(data);
            return;
        }
        Node *prev = head;
        for (int i = 0; i < idx - 1; ++i) {
            prev = prev->next;
        }
        Node *newNode = new Node(data);
        newNode->next = prev->next;
        prev->next = newNode;
        _size++;
    }

    bool search(int key) {
        Node *temp = head;
        while (temp) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void removeFirst() {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        _size--;
        if (head == nullptr) tail = nullptr;
    }

    void removeLast() {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            _size--;
            return;
        }
        Node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
        _size--;
    }

    void remove(int idx) {
        if (idx < 0 || idx >= _size) {
            cout << "Invalid index\n";
            return;
        }
        if (idx == 0) {
            removeFirst();
            return;
        }
        if (idx == _size - 1) {
            removeLast();
            return;
        }
        Node *prev = head;
        for (int i = 0; i < idx - 1; ++i) {
            prev = prev->next;
        }
        Node *toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        _size--;
    }

    void view() {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        Node *temp = head;
        cout<<"{ ";
        while (temp != nullptr) {
            cout <<temp->data<<" ,";
            temp = temp->next;
        }
        cout <<" }"<< endl;
    }
};

int main() {
    SLL *sll = new SLL();
    sll->addFirst(34);
    sll->addFirst(35);
    sll->addFirst(36);
    sll->addLast(33);
    sll->view();  

    delete sll;  
    return 0;
}
