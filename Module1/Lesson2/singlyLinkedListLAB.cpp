#include <iostream>

using namespace std;

class Node {
public:
  Node(int val);
  ~Node();
  int value;
  Node *next;
};

Node::Node(int val) : value(val), next(nullptr) {}

Node::~Node() {}

class List {
public:
  List();
  ~List();
  void push_front(int value);
  bool pop_front(int &value);
  void push_back(int value);
  bool pop_back(int &value);
  int size();

private:
  Node *head;
  Node *tail;
  int listSize;
};

List::List() : head(nullptr), tail(nullptr) { listSize = 0; }

List::~List() {
  while (head != nullptr) {
    Node *n = head;
    head = head->next;
    delete n;
  }
}

void List::push_front(int value) {
  Node *new_head = new Node(value);
  new_head->next = head;
  head = new_head;
  //if list was empty, update tail
  if (tail == nullptr) {
    tail = new_head;
  }
  listSize += 1;
}

bool List::pop_front(int &value) {
  if (head != nullptr) {
    Node *popped = head;
    head = popped->next;
    // if list becomes empty
    if (head == nullptr) {
      tail = nullptr;
    }
    value = popped->value;
    delete popped;
    listSize -= 1;
    return true;
  }
  return false;
}

int List::size() { return listSize; }

void List::push_back(int value) {
  Node *new_tail = new Node(value);
  if (tail == nullptr) {
    head = new_tail;
    tail = new_tail;
  } else {
    tail->next = new_tail;
    tail = new_tail;
  }
  listSize += 1;
}

bool List::pop_back(int &value) {
  if (head != nullptr) {
    Node *node = head;
    // if list has only one element
    if (node == tail) {
      value = node->value;
      delete node;
      head = nullptr;
      tail = nullptr;
    } else {
      // find previous to tail
      while (node->next != tail) {
        node = node->next;
      }
      value = tail->value;
      delete tail;
      tail = node;
      tail->next = nullptr;
    }
    --listSize;
    return true;
  }
  return false;
}

int main() {
  List list;
  //
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);

  int value = 0;
  while (list.pop_back(value)) {
    cout << value << endl;
  }
  return 0;
}