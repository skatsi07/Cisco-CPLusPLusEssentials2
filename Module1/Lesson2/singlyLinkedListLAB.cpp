#include <iostream>

using namespace std;

class Node {
public:
  Node(int val);
  ~Node();
  int value;
  Node *next;
};

Node::Node(int val) : value(val), next(nullptr) {
}

Node::~Node()
{
}

class List {
public:
  List();
  ~List();
  void push_front(int value);
  bool pop_front(int &value);
  void push_back(int value);
  int size();

private:
  Node *head;
  Node* tail;
  int listSize;
};

List::List() : head(nullptr), tail(nullptr) {
    listSize = 0;
}

List::~List()
{
  while (head != nullptr) {
    Node* n = head;
    head = head->next;
    delete n;
  }
}

void List::push_front(int value) {
  Node *new_head = new Node(value);
  new_head->next = head;
  head = new_head;
  listSize += 1;
}

bool List::pop_front(int &value) {
  if (head != nullptr) {
    Node *popped = head;
    head = popped->next;
    value = popped->value;
    delete popped;
    listSize -= 1;
    return true;
  }
  return false;
}

int List::size(){
    return listSize;
}

void List::push_back(int value)
{
  Node *new_tail = new Node(value);
  if (tail == nullptr) {
    head = new_tail;
    tail = new_tail;
  }
  else {
    tail->next = new_tail;
    tail = new_tail;
  }
  listSize += 1;
}

int main()
{
  List list;
  //
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);

  int value = 0;
  while (list.pop_front(value))
  {
    cout << value << endl;
  }
  return 0;
}