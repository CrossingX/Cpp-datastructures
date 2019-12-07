/*
 * @Author: Crossing
 * @Date: 2019-12-07 15:47:14
 * @LastEditTime: 2019-12-07 15:50:56
 * @Description: Application of BinarySearchtree
 * @FilePath: /src/DS/Cpp-datastructures/12Months.cpp
 */
#include "BinarySearchtree.h"
int main(){
    Binarysearchtree<string> bst;
    bst.insertNode("Jan", bst.getRoot());
    bst.insertNode("Feb", bst.getRoot());
    bst.insertNode("Mar", bst.getRoot());
    bst.insertNode("Apr", bst.getRoot());
    bst.insertNode("May", bst.getRoot());
    bst.insertNode("Jun", bst.getRoot());
    bst.insertNode("July", bst.getRoot());
    bst.insertNode("Aug", bst.getRoot());
    bst.insertNode("Sep", bst.getRoot());
    bst.insertNode("Oct", bst.getRoot());
    bst.insertNode("Nov", bst.getRoot());
    bst.insertNode("Dec", bst.getRoot());
    bst.preordertraverse(bst.getRoot());
    cout<<endl;
    bst.midordertraverse(bst.getRoot());
    cout<<endl;
    bst.postordertraverse(bst.getRoot());
    cout<<endl;
}