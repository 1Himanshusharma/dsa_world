#include<iostream>
using namespace std;

// Structure for linked list node
struct Node {
  int data;
  struct Node *next;
};

// Function to insert a key in a sorted manner in a linked list
void sortedInsert(struct Node **arr, int key) {
  struct Node *t, *q = NULL, *p = *arr;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = key;
  t->next = NULL;

  if (*arr == NULL) {
    *arr = t;
  } else {
    while (p && p->data < key) {  // Fix: Change 'x' to 'key'
      q = p;
      p = p->next;
    }
    if (p == *arr) {
      t->next = *arr;
      *arr = t;
    } else {
      t->next = p;
      q->next = t;
    }
  }
}

// Function to search for a key in a linked list
struct Node *search(struct Node *p, int key) {
  while (p != NULL) {
    if (key == p->data) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

// Hash function to determine the index in the array
int hash(int key) {
  return key % 10;
}

// Function to insert a key into the hash table
void insert(struct Node *arr[], int key) {
  int index = hash(key);
  sortedInsert(&arr[index], key);  // Fix: Change 'H' to 'arr'
}

int main() {
  struct Node *HT[10];
  struct Node *temp;
  int i;

  for (i = 0; i < 10; i++)
    HT[i] = NULL;

  insert(HT, 12);
  insert(HT, 22);
  insert(HT, 42);

  temp = search(HT[hash(21)], 21);

  if (temp != NULL) {
    cout << temp->data << " ";
  } else {
    cout << "Key not found" << endl;
  }

  return 0;
}
