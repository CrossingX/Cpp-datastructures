#include<iostream>

using namespace std;
//the definition of Node
template <class T>
class Node{
    public:
        Node(T x = 0, Node* p = nullptr):data(x), next(p){}
        T data;     
        Node* next;
};
//the definition of LinkedList
template <class T>
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        LinkedList<T> operator+(LinkedList<T>* L);
        void insert(int pos, T x);  //insert the Node whose data is x between pos and pos+1(pos starts with 0 which is the position of head)
        void deleteAtPos(int pos);  //delete the Node at pos
        void deleteAtData(T x);     //delete all the Nodes whose data is x
        int getLength();
        void travelList();
        void reverseList();
        void bubbleSort();
    private:
        Node<T>* head;
        int length;
};
template <class T>
LinkedList<T>::LinkedList(){
    head = new Node<T>();
    length = 0;
}
template <class T>
LinkedList<T>::~LinkedList(){
    Node<T>* p = head;
    while(p->next){
        head = head->next;
        delete p;
        p = head;
    }
    delete p;
    length = 0;
}
template <class T>
void LinkedList<T>::insert(int pos, T x){
    if(pos <= length && pos >= 0){
        Node<T>* p = head;
        for(int i=0;i<pos;i++){
            p = p->next;
        }
        Node<T>* newNode = new Node<T>(x, p->next);
        p->next = newNode;
        length++;
    }
    else cout<<"Out of range"<<endl;
}
template <class T>
void LinkedList<T>::deleteAtPos(int pos){
    if(pos <= length && pos > 0 && length > 0){
        Node<T>* p = head;
        for(int i=0;i<pos-1;i++){
            p = p->next;
        }
        Node<T>* q = p->next;
        p->next = q->next;
        delete q;
        length--;
    }
    else cout<<"Out of range"<<endl;
}
template <class T>
void LinkedList<T>::deleteAtData(T x){
    Node<T>* p = head;
    for(int i=0;i<length;i++){
        p = p->next;
        if(p->data == x) deleteAtPos(i+1);
    }
}
template <class T>
int LinkedList<T>::getLength(){
    return length;
}
template <class T>
void LinkedList<T>::travelList(){
    Node<T>* p = head;
    cout<<"head";
    while(p->next){
        p = p->next;
        cout<<"->"<<p->data;
    }
    cout<<endl;
}