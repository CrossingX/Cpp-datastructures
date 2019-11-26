#ifndef QUEUE_H
#define QUEUE_H

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
class Queue{
    public:
        Queue();
        ~Queue();
        void enQueue(T x);
        void deQueue();
        bool isEmpty();
        T& getHead();
        int getLength();
    private:
        Node<T>* front;
        Node<T>* rear;
};
template <class T>
Queue<T>::Queue(){
    front = rear = new Node<T>();
}
template <class T>
Queue<T>::~Queue(){
    Node<T>* p = front;
    while(front != rear){
        front = front->next;
        delete p;
        p = front;
    }
    delete p;
}
template <class T>
void Queue<T>::enQueue(T x){
    Node<T>* newNode = new Node<T>(x,nullptr);
    rear->next = newNode;
    rear = newNode;
}
template <class T>
void Queue<T>::deQueue(){
    if(isEmpty()) cout<<"Empty"<<endl;
    else{
        Node<T>* p = front->next;
        front->next = p->next;

        if(p == rear) rear = front;     //where I didn't pay attention
        
        delete p;
    }
}
template <class T>
bool Queue<T>::isEmpty(){
    return (front == rear);
}
template <class T>
T& Queue<T>::getHead(){
    return front->next->data;
}
template <class T>
int Queue<T>::getLength(){
    Node<T>* p = front;
    int i=0;
    while(p != rear){
        i++;
        p = p->next;
    }
    return i;
}
#endif