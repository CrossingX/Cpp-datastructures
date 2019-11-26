#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;

template <class T>
class Node{
    public:
        Node(T x = 0, Node* p = nullptr):data(x), next(p){}
        T data;     
        Node* next;
};
template <class T>
class Stack{
    public:
        Stack();
        ~Stack();
        bool isEmpty();
        void push(T x);
        void pop();
        T getTop();
        int getLength();
        void display();
    private:
        Node<T>* top;
        int length;
};
template <class T>
Stack<T>::Stack(){
    top = nullptr;
    length = 0;
}
template <class T>
Stack<T>::~Stack(){
    Node<T>* p = top;
    while(p){
        top = top->next;
        delete p;
        p = top;
    }
    length = 0;
}
template <class T>
bool Stack<T>::isEmpty(){
    return (length==0);
}
template <class T>
void Stack<T>::push(T x){
    Node<T>* newNode = new Node<T>(x,top);
    top = newNode;
    length++;
}
template <class T>
void Stack<T>::pop(){
    if(isEmpty()) cout<<"Empty"<<endl;
    else{
        Node<T>* p = top->next;
        delete top;
        top = p;
        length--;
    }
}
template <class T>
T Stack<T>::getTop(){
    return top->data;
}
template <class T>
int Stack<T>::getLength(){
    return length;
}
template <class T>
void Stack<T>::display(){
    if(isEmpty()) cout<<"Empty"<<endl;
    Node<T>* p = top;
    while(p){
        cout<<p->data<<endl;
        p = p->next;
    }
}
#endif