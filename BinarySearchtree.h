/*
 * @Author: Crossing
 * @Date: 2019-12-06 23:46:19
 * @LastEditTime : 2019-12-20 15:52:45
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
        Node<T>* deleteNode(T x, Node<T>* a);   // a should be root
        Node<T>* findMax(Node<T>* a);
        Node<T>* findMin(Node<T>* a);
        Node<T>* find(T x);     // a should be root
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
        a = new Node<T>(x, nullptr, nullptr);
    }
    else{
        if(a->value > x){
            if(a->lchild != nullptr) insertNode(x, a->lchild);
            // else {
            //     Node<T>* newNode = new Node<T>(x, nullptr, nullptr);
            //     a->lchild = newNode;
            // }
        }
        else if(a->value < x) {
            if(a->rchild != nullptr) insertNode(x, a->rchild);
            // else {
            //     Node<T>* newNode = new Node<T>(x, nullptr, nullptr);
            //     a->rchild = newNode;
            // }
        }
    }
}
//Thanks Qinming He from http://www.icourse163.org/course/ZJU-93001?tid=1001757011 for help 
template <class T>
Node<T>* Binarysearchtree<T>::deleteNode(T x, Node<T>* a){ 
    // if(a == nullptr) cout<<"Can't find it."<<endl;
    // else{
    //     if(a->value > x) {
    //         if(a->lchild != nullptr){
    //             if(a->lchild->value == x){
    //                 destroyNode(a->lchild);
    //                 a->lchild = nullptr;
    //             }
    //             else deleteNode(x,a->lchild);
    //         }
    //     }
    //     else if(a->value < x) {
    //         if(a->rchild != nullptr){
    //             if(a->rchild->value == x){
    //                 destroyNode(a->rchild);
    //                 a->rchild = nullptr;
    //             }
    //             else deleteNode(x,a->rchild);
    //         }
    //     }
    //     else if(a->value == x) destroyNode(a);
    // }
    if(a == nullptr) return nullptr;
    if(a->value > x) {
        a->lchild = deleteNode(x, a->lchild);
    }
    else if(a->value < x) {
        a->rchild = deleteNode(x, a->rchild);
    }
    else{
        if(a->lchild != nullptr && a->rchild != nullptr){
            Node<T>* tmp = findMin(a->rchild);
            a->value = tmp->value;
            a->rchild = deleteNode(a->value, a->rchild);
        }
        else {
            Node<T>* tmp = a;
            if(a->lchild == nullptr){
                a = a->rchild;
            }
            else if(a->rchild == nullptr){
                a = a->lchild;
            }
            delete tmp;
        }
    }
    return a;
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
Node<T>* Binarysearchtree<T>::findMax(Node<T>* a){
    if(a == nullptr) return nullptr;
    Node<T>* p = a;
    while(p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}
template <class T>
Node<T>* Binarysearchtree<T>::findMin(Node<T>* a){
    if(a == nullptr) return nullptr;
    Node<T>* p = a;
    while(p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}
template <class T>
Node<T>* Binarysearchtree<T>::find(T x){ //if recurse, require another parameter which is the Node<T>* a
    // if(a == nullptr) return nullptr;
    // if(a->value == x) return a;
    // else if(a->value > x) find(x, a->lchild);
    // else if(a->value < x) find(x, a->rchild);
    Node<T>* p = root;
    while(p){
        if(p->value > x) p = p->lchild;
        else if(p->value < x) p = p->rchild;
        else return p;
    }
    return nullptr;
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