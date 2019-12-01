/*
 * @Author: Crossing
 * @Date: 2019-11-28 01:02:10
 * @LastEditTime: 2019-12-01 13:56:09
 * @Description: Implement a binary tree using a linkedlist
 * @FilePath: /src/DS/Cpp-datastructures/Binarytree2.h
 */
#ifndef BINARYTRREE_H
#define BINARYTRREE_H

#include<iostream>
#include<queue>
using namespace std;
template <class T>
class Node{
    public:
        Node(T val, Node* l, Node* r):value(val), lchild(l), rchild(r){}
        Node* lchild;
        Node* rchild;
        T value;
};
template <class T>
class Binarytree{
    public:
        Binarytree();
        ~Binarytree();
        void destroyNode(Node<T>*& n);
        T getValue(Node<T>* n);
        Node<T>* getRoot();
        int getDepth(Node<T>* n);
        bool isEmpty();
        void insertRoot(T x);
        void insertLeftChild(Node<T>* n, T x);
        void insertRightChild(Node<T>* n, T x);
        Node<T>* getParent(Node<T>* s, Node<T>* n);
        void preordertraverse(Node<T>* n);
        void midordertraverse(Node<T>* n);
        void postordertraverse(Node<T>* n);
        void layerordertraverse();
    private:
        Node<T>* root;
};
template <class T>
Binarytree<T>::Binarytree(){
    root = nullptr;
}
template <class T>
Binarytree<T>::~Binarytree(){
    destroyNode(root);
}
template <class T>
void Binarytree<T>::destroyNode(Node<T>*& n){
    if(n){
        destroyNode(n->lchild);
        destroyNode(n->rchild);
        delete n;
        n = nullptr;
    }
}
template <class T>
T Binarytree<T>::getValue(Node<T>* n){
    if(n != nullptr) return n->value;
    else {
        cout<<"nullptr"<<endl;
        return root->value;
    }
}
template <class T>
int Binarytree<T>::getDepth(Node<T>* n){
    if(n != nullptr){
        int i = getDepth(n->lchild);
        int j = getDepth(n->rchild);
        return i < j ? j+1 : i+1;
    }
    return 0;
}
template <class T>
bool Binarytree<T>::isEmpty(){
    return (root == nullptr);
}
template <class T>
void Binarytree<T>::insertRoot(T x){
    root = new Node<T>(x, nullptr, nullptr);
}
template <class T>
void Binarytree<T>::insertLeftChild(Node<T>* n, T x){
    Node<T>* newNode = new Node<T>(x, nullptr, nullptr);
    n->lchild = newNode;
}
template <class T>
void Binarytree<T>::insertRightChild(Node<T>* n, T x){
    Node<T>* newNode = new Node<T>(x, nullptr, nullptr);
    n->rchild = newNode;
}
//I can't implement it on my own so I learn it from someone on the Internet
template <class T>
Node<T>* Binarytree<T>::getParent(Node<T>* s, Node<T>* n){
    if(s == nullptr) return nullptr;
    if(s->lchild == n || s->rchild == n) return s;
    Node<T>* p = getParent(s->lchild, n);
    if(p) return p;
    return getParent(s->rchild, n);
}
template <class T>
void Binarytree<T>::preordertraverse(Node<T>* n){
    if(n){
        cout<<n->value;
        preordertraverse(n->lchild);
        preordertraverse(n->rchild);
    }
}
template <class T>
void Binarytree<T>::midordertraverse(Node<T>* n){
    if(n){
        midordertraverse(n->lchild);
        cout<<n->value;
        midordertraverse(n->rchild);
    }
}
template <class T>
void Binarytree<T>::postordertraverse(Node<T>* n){
    if(n){
        postordertraverse(n->lchild);
        postordertraverse(n->rchild);
        cout<<n->value;
    }
}
template <class T>
Node<T>* Binarytree<T>::getRoot(){
    return root;
}
template <class T>
void Binarytree<T>::layerordertraverse(){
    queue<Node<T>* > q;
    q.push(root);
    while(!q.empty()){
        if((q.front())->lchild != nullptr) q.push((q.front())->lchild);
        if((q.front())->rchild != nullptr) q.push((q.front())->rchild);
        cout<<q.front()->value;
        q.pop();
    }
    cout<<endl;
}
#endif