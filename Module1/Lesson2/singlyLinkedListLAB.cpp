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
  List(List &other);
  void push_front(int value);
  bool pop_front(int &value);
  void push_back(int value);
  bool pop_back(int &value);
  int  at(int index);
  void insert_at(int index, int value);
  void remove_at(int index);
  int size();

private:
  Node *head;
  Node *tail;
  int listSize;
};

List::List() : head(nullptr), tail(nullptr) { listSize = 0; }

List::List(List &other): List()
{
  Node* node = other.head;
  while (node != nullptr) {
    push_back(node->value);
    node = node->next;
  }
}

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

//returns value at that index
int List::at(int index){
    if (index + 1 <= listSize && index >= 0)
    {
        Node* node = head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        return node->value;
    }
}

//insert value at index
void List::insert_at(int index, int value){
    if (index + 1 <= listSize && index >= 0)
    {
        Node* node = head;
        for (int i = 0; i < index-1; i++)
        {
            node = node->next;
        }
        //set prev node to new node
        // and new node next to exisiting next node
        Node* new_node = new Node(value);
        new_node->next = node->next;
        node->next = new_node;
        listSize += 1;
    }
    
}

//remove node at index without returning it
void List::remove_at(int index){
    if (index + 1 <= listSize && index >= 0)
    {
        Node* prev = head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        //set prev node to next next node
        // and new node next to exisiting next node
        Node* target = prev->next;
        prev -> next = target -> next;
        delete target;
        listSize -= 1;
    }
}

void printList(List &list)
{
  for (int i = 0; i < list.size(); i++)
  {
    cout << "list[" << i << "] == " << list.at(i) << endl;
  }
}

int main()
{
  List list1;
  list1.push_front(1);
  list1.push_front(2);
  list1.push_front(3);
  list1.push_front(4);
  cout << "list1" << endl;
  printList(list1);
  cout << endl;

  List list2(list1);
  cout << "list2" << endl;
  printList(list2);
  cout << endl;

  list1.insert_at(1, 6);
  list2.remove_at(2);

  cout << "list1" << endl;
  printList(list1);
  cout << "list2" << endl;
  printList(list2);
  cout << endl;

  return 0;
}