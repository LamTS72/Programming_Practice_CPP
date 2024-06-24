#include <iostream>
//#include<cstring>
#include<fstream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

//==================================LAB3=====================
//====LINKED LIST===============
struct node
{
  int data;
  node *next;
};

node *createLinkedListTail(int n){
    if(n <= 0) return nullptr;
    node *head = nullptr;
    node *tail = nullptr;
    int i = 0;
    while (i < n)
    {
        int value;
        std::cin >> value;

        node *newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {

            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        i++;
    }

    return head;
}
node *createLinkedListHead(int n){
    if(n <= 0) return nullptr;
    node *head = nullptr;
    int i = 0;
    while (i < n)
    {
        int value;
        std::cin >> value;
        node *newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        i++;
    }

    return head;
}
node *insertNode(node *head, node *newNode, int position)
{
    if(position <= 0) return head;
    if(head == nullptr){
        head = newNode;
    }
    else{
        if(position == 1){
            newNode->next = head;
            head = newNode;
        }
        else if(position > 1){
            int idx = 1;
            node *curr = head;
            node *prev = nullptr;
            while(curr != nullptr && idx < position){
                idx++;
                prev = curr;
                curr = curr->next;
            }
            if (curr == nullptr) {  // Reached the end of the linked list
                prev->next = newNode;
            } else {
                newNode->next = curr;
                prev->next = newNode;
            }

        }
    }
    return head;
}
void replace(node* head, int position, int value) {
    if (position < 0 || head == nullptr) {
        return; // Do nothing for invalid position or empty list
    }
    
    int idx = 0;
    node* curr = head;
    
    while (curr != nullptr && idx < position) {
        curr = curr->next;
        idx++;
    }
    
    if (curr != nullptr) {
        curr->data = value;
    }
}

int searchLinkedList(node* head, int key)
{
  // TODO
    node *curr = head;
    int idx = 0;
    while(curr != nullptr){
        if(key == curr->data){
            return idx;
        }
        idx++;
        curr = curr->next;
    }
    return -1;
}

bool isEqual(node *head1, node *head2)
{
    node *current1 = head1;
    node *current2 = head2;


    while (current1 != nullptr && current2 != nullptr)
    {

        if (current1->data != current2->data)
            return false;

        current1 = current1->next;
        current2 = current2->next;
    }


    if (current1 != nullptr || current2 != nullptr)
        return false;

    return true;
}
int countNode(node* head)
{
    node *curr = head;
    int count = 0;
    while(curr != nullptr){
        curr = curr->next;
        count++;
    }
    return count;
    
}

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}
//============LINKED LIST=============

//============OOP===================
//template <typename T>
//class Array {
//public:
//    Array(int size, T initValue);
//    ~Array();
//
//    void setAt(int idx, const T & value);
//    T getAt(int idx);
//    T& operator[](int idx);
//
//    void print();
//
//private:
//    int size;
//    T * p;
//};
//
//template<typename T>
//void Array<T>::print() {
//    for (int i = 0; i < this->size; ++i) {
//        cout << (i > 0 ? " " : "")
//            << this->p[i];
//    }
//    cout << endl;
//}
//
//// TODO
//template<typename T>
//void Array<T>::setAt(int idx, const T & value){
//
//}
//
//template <typename T>
//T Array<T>::getAt(int idx){
//
//}
//template <typename T>
//T& Array<T>::operator[](int idx){
//    if (idx < 0 || idx >= size) {
//        throw -1; // Throw an exception for invalid index
//    }
//    return p[idx];
//}

//============OOP===================

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    Array(const Array<T> & other); // Copy constructor
    Array<T> & operator=(const Array<T> & other); // Copy assignment operator
    
    void print();

private:
    int size;
    T * p;
};
template<typename T>
Array<T>::Array(int size, T initValue) {
    this->size = size;
    this->p = new T[size];
    for (int i = 0; i < size; ++i) {
        this->p[i] = initValue;
    }
}

template<typename T>
Array<T>::~Array() {
    delete[] p;
}

template<typename T>
Array<T>::Array(const Array<T>& other) {
    cout << "Call copy constructor" << endl;
    this->size = other.size;
    this->p = new T[size];
    for (int i = 0; i < size; ++i) {
        this->p[i] = other.p[i];
    }
}
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    cout << "Call assignment operator" << endl;
    if (this != &other) {
        delete[] p;
        this->size = other.size;
        this->p = new T[size];
        for (int i = 0; i < size; ++i) {
            this->p[i] = other.p[i];
        }
    }
    return *this;
}

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "")
            << this->p[i];
    }
    cout << endl;
}

// TODO

// TODO
class Integer{
private:
    int val;
    
public:
    Integer(int);
    Integer(Integer*);
    Integer operator+(const Integer&) const;
    Integer operator+(int) const;
    void print();
};
Integer::Integer(int val){
    this->val = val;
}
Integer::Integer(Integer* others){
    this->val = others->val;
}
void Integer::print() {
    cout << this->val << endl;
}
Integer Integer::operator+(const Integer& other) const {
    return Integer(val + other.val);
}
Integer Integer::operator+(int value) const{
    return Integer(val + value);
}


int main(int argc, const char * argv[]) {   //LAB3
//    int n = 0;
//    cin>> n;
//    node *head = createLinkedListHead(n);
//    int m = 0;
//    cin>> m;
//    node *head2 = createLinkedList(m);
//    cout << isEqual(head1, head2) << endl;
//    print(head);
//    cout<<endl;
//    cout<<countNode(head);
//    cout << endl;
//    int n = 0;
//    cin >> n;
//    node *head = createLinkedListTail(n);
//    int m;
//    cin>>m;
//    cout<<searchLinkedList(head,m);
//    Array<int> * a3;
//    Array<int> * a4 = new Array<int>(10, 3);
//    a3 = new Array<int>(*a4);
//    delete a4;
//    a3->print();
//    delete a3;
    int x, y, z;
    cin >> x >> y >> z;
    Integer a(x);
    Integer b(y);
    Integer* t = new Integer(z);
    Integer c(t);
    
    a.print(); b.print();
    (a + b + c + 4).print();
    
    delete t;
    
    return 0;
}

