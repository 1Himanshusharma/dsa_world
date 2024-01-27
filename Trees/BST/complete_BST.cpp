#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *lchild;
  Node *rchild;
  Node(int key){
    this->data = key;
    this->lchild = NULL;
    this->rchild = NULL;
  }
};
class LNode{
  public:
  int data;
  LNode *next;
  LNode(int key){
    this->data = key;
    this->next = NULL;
  }
};

class Queue{
  private:
  LNode *front,*rear;
  public:
  Queue(){
    front = rear = NULL;
  }
  void enqueue(int key){
    LNode *new_node = new LNode(key);
    if (new_node == NULL){
      cout << "Can't create buffer overflow.";
    }
    else{
      if (front == NULL){
        front = new_node;
        rear = new_node;
      }
      else{
        rear->next = new_node;
        rear = new_node;
      }
    }
  }
  LNode *dequeue(){
    LNode *temp = NULL;
    if (front == NULL){
      cout << "Queue is empty.";
    }
    else{
      temp = front;
      front = front->next;
    }
    return temp;
  }
  bool isempty(){
    if (front == NULL){
      return NULL;
    }
  }
  bool isfull(){
    LNode *new_node = new LNode(7);
    if (new_node == NULL){
      return true;
    }
    return false;
  }
  void display(){
    LNode *temp = front;
    while (temp){
      cout << temp->data << " ";
      temp = temp->next;
    }
  }
};

class BST{
  private:
  Node *root;
  public:
  BST() { root = NULL;}
  // in this situation we shall be needing the iterative method
  // Node *insert(int key){
  //   if (root == NULL){
  //     return new Node(key);
  //   }
  //   if (key < root->r)
  // }
  void insert(int key){
    if (root == NULL){
      root = new Node(key);
    }
    else{
      Node *p,*q;
      p = root;
      while (p){
        q = p;
        if (key < p->data){
          p = p->lchild;
        }
        if (key > p->data){
          p = p->rchild;
        }
      }
      p = new Node(key);
      if (key > q->data){
        q->rchild = p;
      }
      else{
        q->lchild = p;
      }
    }
  }
  bool search(int key){
    Node *temp = root;
    if (temp == NULL){
      return false;
    }
    while (temp){
      if (temp->data = key){
        return true;
      }
      if (key > temp->data){
        temp = temp->rchild;
      }
      else if (key < temp->data){
        temp = temp->lchild;
      }
    }
    return false;
  }
  int height(Node *p){
    int x,y;
    if (p== NULL){
      return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    return (x > y ? x : y);
  }
  int count(Node *p){
    if (p == NULL){
      return 0;
    }
    return count(p->lchild) + count(p->rchild) + 1;
  }
  Node *inpre(Node *p){
    // ye right most wla hai
    while (p && p->rchild){
      p = p->rchild;
    }
    return p;
  }
  Node *insucc(Node *p){
    // ye left most wla hai
    while (p && p->lchild){
      p = p->lchild;
    }
    return p;
  }
  Node *deleten(Node *p,int key){
    //okay relax dont panic
    // first condition
    if (p== NULL){
      return NULL;
    }
    // aab ek condition hai jo BST me apply hoti hai 
    // ki jab bhi hum koi node insert karte hai ya delete karte hai tab hum only leaf node ko delete karte hai 
    // orr leaf node per hi insert karte hai
    // aab mujhe lagta hai ki leaf node se ek condition bann sakti hai
    if (p->lchild == NULL && p->rchild == NULL){
      // ager hum leaf wala node delete karna hai tho 
      if (p == root){
        root = NULL;
      }
      free(p);
      // mene usko delete kar diya hai orr mai NULL return karwa rha hu
      return NULL;
    }
    // third condition me shi place per jane kosis karunga
    if (p->data > key){
      // ager ye true hota hai to mai left wala delete karunga
      p->lchild = deleten(p->lchild,key);
    }
    else if (p->data < key){
      // to mai right wala node delete karunga
      p->rchild = deleten(p->rchild,key);
    }
    // hum wo wale case handle kar liye jisme kum or jayada wla ho gya hai
    // aab humare pass condition bachti hai equal wali
    else{
      // aab mere paas 2 options hai shi node se replace karne ke liye
      // ya to mai left wala subtree se shi node le kar aunga or ya fhir right wale subtree se shi node le kar aunga
      if (height(p->lchild) > height(p->rchild)){
        //aab mujhe pta hai ki left wale subtree ki height jayada compare to other then
        Node *temp = inpre(p->lchild);
        p->data = temp->data;
        // aab mene data ko tho replace kar diya 
        // oorr mujhe leaf node tak jana hai tho mai fhri ek baar fhir call karunga
        p->lchild = deleten(p->lchild,temp->data);
      }
      else{
        Node *temp = insucc(p->rchild);
        p->data = temp->data;
        // aab mujhe right subtree me left most element mil gya jo suitable hai replacement key liete
        // mujhe usse copy kar diya
        // but mere paas aab do hai same element 
        // orr mai janta hu ki jisse mene replace kiya usse 
        p->rchild = deleten(p->rchild,temp->data);
      }
    }
    return p;

  }
  // okay level order
  void levelorder(){}
};



int main(){
  cout << "Please enter the values and (enter -1 to stop): ";
  Queue q;
  while (true){
    int key;
    cin >> key;
    if (key == -1){
      break;
    }
    q.enqueue(key);
  }
  //display
  cout << "The elements in queue are: \n";
  q.display();
}
