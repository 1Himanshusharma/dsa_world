#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head, * last;

    void display(Node* current) {
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    Node * reverse(Node* pre,Node * &curr){
      if (curr == NULL){
        return pre;
      }
      Node *temp = curr->next;
      curr->next = pre;
      return reverse(curr,temp);
    }

public:
    LinkedList() {
        head = NULL;
        last = NULL;
    }

    void insert(int val) {
        Node* new_node = new Node;
        new_node->data = val;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            last = head;
        }
        else {
            last->next = new_node;
            last = new_node;
        }
    }

    void display() {
        display(head);
    }

    void reverse() {
        Node* p, * q, * r;
        p = head;
        q = NULL;
        r = NULL;
        while (p) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
    }
    void reverse_using_recur(){
      head = reverse(NULL,head);
    }
};

int main() {
    int n;
    cout << "Enter Length of Linked list: ";
    cin >> n;
    LinkedList L;
    while (n > 0) {
        int key;
        cin >> key;
        L.insert(key);
        n--;
    }
    L.reverse_using_recur();
    cout << "Reversed Linked List: ";
    L.display();

    return 0;
}
