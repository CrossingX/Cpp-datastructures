#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;
#define MAX_SIZE 10005
//Circle Queue
template <class T>
class Queue{
    public:
        Queue();
        ~Queue();
        void enQueue(T x);
        void deQueue();
        bool isEmpty();
        bool isFull();
        T& getHead();
        int getLength();
    private:
        int front;
        int rear;
        T* q;
};

template <class T>
Queue<T>::Queue(){
    q = new T[MAX_SIZE];
    front = rear = 0;
}
template <class T>
Queue<T>::~Queue(){
    delete []q;
}
template <class T>
void Queue<T>::enQueue(T x){
    if(isFull()) cout<<"Full"<<endl;
    else{
        q[rear] = x;
        rear = (rear + 1) % MAX_SIZE;
    }
}
template <class T>
void Queue<T>::deQueue(){
    if(isEmpty()) cout<<"Empty"<<endl;
    else{
        front = (front + 1) % MAX_SIZE;
    }
}
template <class T>
bool Queue<T>::isEmpty(){
    return (front == rear);
}
template <class T>
bool Queue<T>::isFull(){
    return (front == (rear + 1) % MAX_SIZE);
}
template <class T>
T& Queue<T>::getHead(){
    return q[front];
}
template <class T>
int Queue<T>::getLength(){
    return (rear - front + MAX_SIZE) % MAX_SIZE;
}
#endif