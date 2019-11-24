#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 10005

#include <iostream>
using namespace std;

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
private:
    int top;
    T* s;
};
template <class T>
Stack<T>::Stack(){
    s = new T[MAX_SIZE];
    top = -1;
}
template <class T>
Stack<T>::~Stack(){
    delete []s;
}
template <class T>
bool Stack<T>::isEmpty(){
    return (top==-1);
}
template <class T>
void Stack<T>::push(T x){
    s[top+1] = x;
    top++;
}
template <class T>
void Stack<T>::pop(){
    s[top] = 0;
    top--;
}
template <class T>
T Stack<T>::getTop(){
    return s[top];
}
template <class T>
int Stack<T>::getLength(){
    return (top+1);
}
#endif