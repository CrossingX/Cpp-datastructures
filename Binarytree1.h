/*
 * @Author: Crossing
 * @Date: 2019-11-27 13:25:29
 * @LastEditTime: 2019-12-01 13:42:21
 * @Description: Implement a binary tree using an array
 * @FilePath: /src/DS/Cpp-datastructures/Binarytree1.h
 */
#ifndef BINARYTRREE_H
#define BINARYTRREE_H
#define MAX_SIZE 10005  //assume the binarytree will never be full

#include<iostream>
#include<cmath>
using namespace std;
template <class T>
class Binarytree{
    public:
        Binarytree();
        ~Binarytree();
        T& getValue(int pos);
        int getDepth();
        bool isEmpty();
        void insertRoot(T x);
        void insertLeftChild(int pos, T x);
        void insertRightChild(int pos, T x);
        int getParent(int pos);
        void deleteNode(int pos);
        void preordertraverse(int i);
        void midordertraverse(int i);
        void postordertraverse(int i);
        void layerordertraverse();
    private:
        T* t;
        int count;
};
template <class T>
Binarytree<T>::Binarytree(){
    t = new T[MAX_SIZE];
    count = 0;
}
template <class T>
Binarytree<T>::~Binarytree(){
    delete []t;
}
template <class T>
T& Binarytree<T>::getValue(int pos){
    if(0 <= pos && pos < MAX_SIZE){
        return t[pos];
    }
}
template <class T>
int Binarytree<T>::getDepth(){
    int cnt = 0;
    // for(int i = 0; i < MAX_SIZE; i++){
    //     if(t[i] != 0) cnt++;
    //     if(cnt == count) return ((int)(log(i+1)/log(2)) + 1);
    // }
    //I prefer the code below, although both of them are right
    for(int i = 0; i < MAX_SIZE; i++){
        if(cnt == count) return ((int)(log(i)/log(2)) + 1);
        if(t[i] != 0) cnt++;
    }
}
template <class T>
bool Binarytree<T>::isEmpty(){
    return (count == 0);
}
template <class T>
void Binarytree<T>::insertRoot(T x){
    t[0] = x;
    count++;
}
template <class T>
void Binarytree<T>::insertLeftChild(int pos, T x){
    t[2*pos+1] = x;
    count++;
}
template <class T>
void Binarytree<T>::insertRightChild(int pos, T x){
    t[2*pos+2] = x;
    count++;
}
template <class T>
int Binarytree<T>::getParent(int pos){
    if(pos == 0) {
        cout<<"Root has no parent"<<endl;
        return -1;
    }
    else return t[(pos - 1)/2];
}
template <class T>
void Binarytree<T>::deleteNode(int pos){
    if(getValue(pos)){
        deleteNode(2*pos+1);
        deleteNode(2*pos+2);
        t[pos] = 0;
        count--;
    }
}
template <class T>
void Binarytree<T>::preordertraverse(int i){
    if(getValue(i)) {
        cout<<getValue(i);
        preordertraverse(2*i+1);
        preordertraverse(2*i+2);
    }
}
template <class T>
void Binarytree<T>::midordertraverse(int i){
    if(getValue(i)) {
        midordertraverse(2*i+1);
        cout<<getValue(i);
        midordertraverse(2*i+2);
    }
}
template <class T>
void Binarytree<T>::postordertraverse(int i){
    if(getValue(i)) {
        postordertraverse(2*i+1);
        postordertraverse(2*i+2);
        cout<<getValue(i);
    }
}
template <class T>
void Binarytree<T>::layerordertraverse(){
    int cnt = 0;
    for(int i = 0; i < MAX_SIZE; i++){
        if(cnt==count) break;
        if(t[i] != 0) {
            cout<<t[i]<<" ";
            cnt++;
        }
    }
    cout<<endl;
}
#endif