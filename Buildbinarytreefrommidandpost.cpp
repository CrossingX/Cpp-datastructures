#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Node{
    public:
    char value;
    Node* lchild;
    Node* rchild;
};
Node* build(string mid, string post){
    if(mid.length()== 0 || post.length() == 0) return nullptr;
    Node* newNode = new Node();
    int len = post.length();
    int i;
    newNode->value = post[len-1];
    newNode->lchild = nullptr;
    newNode->rchild = nullptr;
    for(i = 0; i < len; i++){
        if(mid[i] == post[len-1]) break;
    }
    newNode->lchild = build(mid.substr(0, i), post.substr(0, i));
    newNode->rchild = build(mid.substr(i+1, len-i-1), post.substr(i, len-i-1));
    return newNode;
}
void preorder(Node* n){
    if(n == nullptr) return ;
    cout<<n->value;
    preorder(n->lchild);
    preorder(n->rchild);
}
int main(){
    Node* a = build("1234567", "2315764");
    preorder(a);
    cout<<endl;
    return 0;
}