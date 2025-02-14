#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }
    ~LinkedList() { //destructor that was written in class
        Node<T> *current = this->head;
        while (head != NULL) {
            head = head->next;
            delete current;
            current = head;
        }
    }
    Node<T>* getAt(int index) { //method written in class
        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node<T>* temp = head;
        for (int i=0; i<index; i++) {
            temp = temp->next;
        }
        return temp;
    }
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T>* temp = head;
        while (temp->next != NULL) {
            temp=temp->next;
        }
        temp = NULL;
        delete temp;
        length--;
    }

    void deleteNode(int index) {
        int llLength = this->length;
        if (index > llLength - 1) { //edge case if the user wants to delete the last node, method we already wrote
            dellast();
            return;
        }
        if (index == 0) { //edge case for if the user wants to delete the head, also a method already written
            delfirst();
            return;
        }
        Node<T> *temp = head;
        Node<T> *temp2 = head;
        int count = 0;
        while (count < index) { //temp is one node ahead of temp2
            temp = temp->next;
            count++;
            if (count < index) {
                temp2 = temp2->next;
            }
        }
        temp2->next = temp->next; //previous node now points one more node ahead because the next node will be deleted
        delete temp;
        length--;
    }

   void insert(int index, T *value) { //method written in class
        if (index < 0 || index >= length) {
            cout<<"Index is invalid"<<endl;
            return;
        }
        if (index == 0) {
            addhead(value);
        }
        if(index == length){
            add(value);
        }
        else {
            Node<T>* newNode = new Node<T>(value);
            Node<T> *temp = getAt(index);
            newNode->next = temp->next;
            temp->next=newNode;
            length++;
        }
    }

   void reverselist(){
        Node<T> *prev, curr, next;
        prev = NULL;
        curr = head;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->addhead(s3);
    ll->print();
    ll->delfirst();
    ll->print();
    ll->dellast();
    ll->print();
}