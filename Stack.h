#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 10005

template <class T>
class Stack{
public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(T& x);
    void pop();
    T& getTop();
private:
    int top;
    T* s;
};

#endif