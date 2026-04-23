#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

struct LinkedList {
  Node *head = NULL;

  void insertNode(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
  }

  void traverseList() {
    Node *current = head;
    while (current != NULL) {
      cout << current->data << " -> ";
      current = current->next;
    }
    cout << "NULL\n";
  }

  void deleteNode() {
    if (head != NULL) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }

  void searchNode(int key) {
    Node *current = head;
    while (current != NULL) {
      if (current->data == key) {
        cout << "Data " << key << " ditemukan\n";
        return;
      }
      current = current->next;
    }
    cout << "Data " << key << " tidak ditemukan\n";
  }

  void updateNode(int oldValue, int newValue) {
    Node *current = head;
    while (current != NULL) {
      if (current->data == oldValue) {
        current->data = newValue;
      }
      current = current->next;
    }
  }
};

int main() {
  LinkedList list;

  list.insertNode(30);
  list.insertNode(20);
  list.insertNode(10);

  cout << "Setelah Traversal & Insertion:\n";
  list.traverseList();

  cout << "\nMencari data 20:\n";
  list.searchNode(20);

  cout << "\nSetelah Updating (20 menjadi 99):\n";
  list.updateNode(20, 99);
  list.traverseList();

  cout << "\nSetelah Deletion (hapus awal):\n";
  list.deleteNode();
  list.traverseList();

  return 0;
}
