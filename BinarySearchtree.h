/*
 * @Author: Crossing
 * @Date: 2019-12-06 23:46:19
 * @LastEditTime: 2019-12-07 15:16:54
 * @Description: Implement a binary search tree using a linkedlist
 * @FilePath: /src/DS/Cpp-datastructures/BinarySearchtree.h
 */

#ifndef BINARTSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<iostream>
using namespace std;

template <class T>
class Node{
    public:
        T value;
        Node* lchild;
        Node* rchild;
        Node(T v, Node* l, Node* r):value(v),lchild(l),rchild(r){}
};
template <class T>
class Binarysearchtree{
    public:
        Binarysearchtree();
        ~Binarysearchtree();
        void insertNode(T x, Node<T>* a);   // a should be root
        void deleteNode(T x, Node<T>* a);   // a should be root
        Node<T>* findMax();
        Node<T>* findMin();
        Node<T>* find(T x, Node<T>* a);     // a should be root
        void destroyNode(Node<T>*& a);           // a should be root
        void preordertraverse(Node<T>* a);
        void midordertraverse(Node<T>* a);
        void postordertraverse(Node<T>* a);
        Node<T>*& getRoot();
    private:
        Node<T>* root;
};
template <class T>
Binarysearchtree<T>::Binarysearchtree(){
    root = nullptr;
}
template <class T>
Binarysearchtree<T>::~Binarysearchtree(){
    destroyNode(root);
}
template <class T>
void Binarysearchtree<T>::insertNode(T x, Node<T>* a){
    if(a == nullptr){
        root = new Node<T>(x, nullptr, nullptr);
    }
    else{
        if(a->value > x){
            if(a->lchild != nullptr) insertNode(x, a->lchild);
            else {
                Node<T>* newNode = new Node<T>(x, nullptr, nullptr);
                a->lchild = newNode;
            }
        }
        else if(a->value < x) {
            if(a->rchild != nullptr) insertNode(x, a->rchild);
            else {
                Node<T>* newNode = new Node<T>(x, nullptr, nullptr);
                a->rchild = newNode;
            }
        }
    }
}
template <class T>
void Binarysearchtree<T>::deleteNode(T x, Node<T>* a){
    if(a == nullptr) cout<<"Can't find it."<<endl;
    else{
        if(a->value > x) { 
            if(a->lchild != nullptr){
                if(a->lchild->value == x){
                    destroyNode(a->lchild);
                    a->lchild = nullptr;
                }
                else deleteNode(x,a->lchild);
            }
        }
        else if(a->value < x) {
            if(a->rchild != nullptr){
                if(a->rchild->value == x){
                    destroyNode(a->rchild);
                    a->rchild = nullptr;
                }
                else deleteNode(x,a->rchild);
            }
        }
        else if(a->value == x) destroyNode(a);
    }
}
template <class T>
void Binarysearchtree<T>::destroyNode(Node<T>*& a){
    if(a != nullptr){
        destroyNode(a->lchild);
        destroyNode(a->rchild);
        delete a;
        a = nullptr;
    }
}
template <class T>
Node<T>* Binarysearchtree<T>::findMax(){
    if(root == nullptr) return nullptr;
    Node<T>* p = root;
    while(p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}
template <class T>
Node<T>* Binarysearchtree<T>::findMin(){
    if(root == nullptr) return nullptr;
    Node<T>* p = root;
    while(p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}
template <class T>
Node<T>* Binarysearchtree<T>::find(T x, Node<T>* a){
    if(a == nullptr) return nullptr;
    if(a->value == x) return a;
    else if(a->value > x) find(x, a->lchild);
    else if(a->value < x) find(x, a->rchild);
}
template <class T>
void Binarysearchtree<T>::preordertraverse(Node<T>* a){
    if(a != nullptr){
        cout<<a->value;
        preordertraverse(a->lchild);
        preordertraverse(a->rchild);
    }
}
template <class T>
void Binarysearchtree<T>::midordertraverse(Node<T>* a){
    if(a != nullptr){
        midordertraverse(a->lchild);
        cout<<a->value;
        midordertraverse(a->rchild);
    }
}
template <class T>
void Binarysearchtree<T>::postordertraverse(Node<T>* a){
    if(a != nullptr){
        postordertraverse(a->lchild);
        postordertraverse(a->rchild);
        cout<<a->value;
    }
}
template <class T>
Node<T>*& Binarysearchtree<T>::getRoot(){
    return root;
}
#endif