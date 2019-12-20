/*
 * @Author: Crossing
 * @Date: 2019-12-07 21:06:44
 * @LastEditTime : 2019-12-20 16:26:44
 * @Description: Implemention of an AVLtree
 * @FilePath: /src/DS/Cpp-datastructures/AVLtree.h
 */
#ifndef AVLTREE_H
#define AVLTREE_H

#include<iostream>
using namespace std;
template <class T>
class Node{
    public:
        T value;
        int height;
        Node* lchild;
        Node* rchild;
        Node(T v, Node* l, Node* r):value(v),lchild(l),rchild(r){}
};
template <class T>
class AVLtree{
    public:
        AVLtree();
        ~AVLtree();
        void insertNode(T x, Node<T>* p);
        int getHeight(Node<T>* p);
        Node<T>* RRightRotation(Node<T>* p);
        Node<T>* LLeftRotation(Node<T>* p);
        Node<T>* LeftRightRotation(Node<T>* p);
        Node<T>* RightLeftRotation(Node<T>* p);
        void destroyNode(Node<T>*& p);
        Node<T>* deleteNode(T x, Node<T>* p);
        Node<T>* findMax(Node<T>* p);
        Node<T>* findMin(Node<T>* p);
        Node<T>* find(T x);
        void preordertraverse(Node<T>* p);
        void midordertraverse(Node<T>* p);
        void postordertraverse(Node<T>* p);
        Node<T>*& getRoot();
    private:
        Node<T>* root;
};
template <class T>
AVLtree<T>::AVLtree(){
    root = nullptr;
}
template <class T>
AVLtree<T>::~AVLtree(){
    destroyNode(root);
}
template <class T>
Node<T>* AVLtree<T>::RRightRotation(Node<T>* p){
    Node<T>* q = p->rchild;
    p->rchild = q->lchild;
    q->lchild = p;
    p->height = (getHeight(p->lchild)>getHeight(p->rchild)?getHeight(p->lchild):getHeight(p->rchild)) + 1;
    q->height = (getHeight(q->rchild)>p->height?getHeight(q->rchild):p->height) + 1;
    return q;
}
template <class T>
Node<T>* AVLtree<T>::LLeftRotation(Node<T>* p){
    Node<T>* q = p->lchild;
    p->lchild = q->rchild;
    q->rchild = p;
    p->height = (getHeight(p->lchild)>getHeight(p->rchild)?getHeight(p->lchild):getHeight(p->rchild)) + 1;
    q->height = (getHeight(q->lchild)>p->height?getHeight(q->lchild):p->height) + 1;
    return q;
}
template <class T>
Node<T>* AVLtree<T>::LeftRightRotation(Node<T>* p){
    p->lchild = RRightRotation(p->lchild);
    return LLeftRotation(p);
}
template <class T>
Node<T>* AVLtree<T>::RightLeftRotation(Node<T>* p){
    p->rchild = LLeftRotation(p->rchild);
    return RRightRotation(p);
}
template <class T>
int AVLtree<T>::getHeight(Node<T>* p){
    if(p == nullptr) return 0;
    int i = getHeight(p->lchild);
    int j = getHeight(p->rchild);
    return i>j?i+1:j+1;
}
template <class T>
void AVLtree<T>::insertNode(T x, Node<T>* p){
    if(p == nullptr){
        p = new Node<T>(x, nullptr, nullptr);
        p->height = 0;
    }
    else if(x < p->value){
        insertNode(x, p->lchild);
        if(getHeight(p->lchild) - getHeight(p->rchild) == 2){
            if(x < p->lchild->value){
                p = LLeftRotation(p);
            }
            else p = LeftRightRotation(p);
        }
    }
    else if(x > p->value){
        insertNode(x, p->rchild);
        if(getHeight(p->rchild) - getHeight(p->lchild) == 2){
            if(x > p->rchild->value){
                p = RRightRotation(p);
            }
            else p = RightLeftRotation(p);
        }
    }
    p->height = (getHeight(p->lchild)>getHeight(p->rchild)?getHeight(p->lchild):getHeight(p->rchild)) + 1;
}
template <class T>
void AVLtree<T>::destroyNode(Node<T>*& p){
    if(p != nullptr){
        destroyNode(p->lchild);
        destroyNode(p->rchild);
        delete p;
        p = nullptr;
    }
}
template <class T>
Node<T>* AVLtree<T>::deleteNode(T x, Node<T>* p){ 
    if(p == nullptr) return nullptr;
    if(p->value > x) {
        p->lchild = deleteNode(x, p->lchild);
    }
    else if(p->value < x) {
        p->rchild = deleteNode(x, p->rchild);
    }
    else{
        if(p->lchild != nullptr && p->rchild != nullptr){
            Node<T>* tmp = findMin(p->rchild);
            p->value = tmp->value;
            p->rchild = deleteNode(p->value, p->rchild);
        }
        else {
            Node<T>* tmp = p;
            if(p->lchild == nullptr){
                p = p->rchild;
            }
            else if(p->rchild == nullptr){
                p = p->lchild;
            }
            delete tmp;
        }
    }
    return p;
}
template <class T>
Node<T>* AVLtree<T>::findMax(Node<T>* p){
    if(p == nullptr) return nullptr;
    Node<T>* q = p;
    while(q->rchild != nullptr){
        q = q->rchild;
    }
    return q;
}
template <class T>
Node<T>* AVLtree<T>::findMin(Node<T>* p){
    if(p == nullptr) return nullptr;
    Node<T>* q = p;
    while(q->lchild != nullptr){
        q = q->lchild;
    }
    return q;
}
template <class T>
Node<T>* AVLtree<T>::find(T x){ //if recurse, require another parameter which is the Node<T>* a
    Node<T>* p = root;
    while(p){
        if(p->value > x) p = p->lchild;
        else if(p->value < x) p = p->rchild;
        else return p;
    }
    return nullptr;
}
template <class T>
void AVLtree<T>::preordertraverse(Node<T>* p){
    if(p != nullptr){
        cout<<p->value;
        preordertraverse(p->lchild);
        preordertraverse(p->rchild);
    }
}
template <class T>
void AVLtree<T>::midordertraverse(Node<T>* p){
    if(p != nullptr){
        midordertraverse(p->lchild);
        cout<<p->value;
        midordertraverse(p->rchild);
    }
}
template <class T>
void AVLtree<T>::postordertraverse(Node<T>* p){
    if(p != nullptr){
        postordertraverse(p->lchild);
        postordertraverse(p->rchild);
        cout<<p->value;
    }
}
template <class T>
Node<T>*& AVLtree<T>::getRoot(){
    return root;
}
#endif