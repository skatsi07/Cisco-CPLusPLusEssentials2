#include <iostream>

using namespace std;

class Node {
public:
  Node(int val);
  ~Node();
  int value;
  Node *next;
  Node *prev;
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
  //if list was empty, update tail
  if (tail == nullptr) {
    tail = new_head;
    head = new_head;
  } else {
    new_head->next = head;
    head -> prev = new_head;
    head = new_head;
  }
  listSize += 1;
}

bool List::pop_front(int &value) {
  if (head != nullptr) {
    Node *popped = head;
    value = popped -> value;
    head = popped->next;
    // if list becomes empty
    if (head == nullptr) {
      tail = nullptr;
    } else {
        head->prev = nullptr;
    }
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
    Node *popped = tail;
    value = popped -> value;
    tail = popped->prev;
    // if list has only one element
    if (tail == nullptr) {
      head = nullptr;
    } else {
      tail->next = nullptr;
    }
    delete popped;
    listSize -= 1;
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
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        //set prev node to new node
        // and new node next to exisiting next node
        Node* new_node = new Node(value);
        new_node->next = node->next;
        new_node->prev = node;
        node->prev->next = new_node;
        node->prev = new_node;
        listSize += 1;
    }
    
}

//remove node at index without returning it
void List::remove_at(int index){
    if (index + 1 <= listSize && index >= 0)
    {
        Node* target = head;
        for (int i = 0; i < index; i++)
        {
            target = target->next;
        }
        //set prev node to next next node
        // and new node next to exisiting next node
        target -> prev -> next = target -> next;
        target -> next -> prev = target -> prev;
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

int main() {
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