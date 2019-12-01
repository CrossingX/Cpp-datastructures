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
Node* build(string pre, string mid){
    if(pre.length()== 0 || mid.length() == 0) return nullptr;
    Node* newNode = new Node();
    newNode->value = pre[0];
    newNode->lchild = nullptr;
    newNode->rchild = nullptr;
    int len = mid.length();
    int i;
    for(i = 0; i < len; i++){
        if(mid[i] == pre[0]) break;
    }
    newNode->lchild = build(pre.substr(1,i), mid.substr(0,i));
    newNode->rchild = build(pre.substr(i+1, len-i-1), mid.substr(i+1, len-i-1));
    return newNode;
}
void postorder(Node* n){
    if(n == nullptr) return ;
    postorder(n->lchild);
    postorder(n->rchild);
    cout<<n->value;
}
int main(){
    Node* a = build("BCDAEGFIH", "DCEAGBIFH");
    postorder(a);
    cout<<endl;
    return 0;
}
