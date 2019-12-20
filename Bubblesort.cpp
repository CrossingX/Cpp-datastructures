/*
 * @Author: Crossing
 * @Date: 2019-12-13 23:28:01
 * @LastEditTime : 2019-12-20 17:16:22
 * @Description: Bubblesort
 * @FilePath: /src/DS/Cpp-datastructures/Bubblesort.cpp
 */
#include<iostream>
using namespace std;
void Bubblesort1(int a[], int len){
    int tmp;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(a[i]>a[j]) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void Bubblesort2(int a[], int len){
    int tmp;
    for(int i=0;i<len;i++){
        for(int j=len-1;j>i;j--){
            if(a[j]<a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}

void Bubblesort3(int a[], int len){
    int tmp;
    int flag;
    for(int i=0;i<len;i++){
        flag = 1;
        for(int j=len-1;j>i;j--){
            if(a[j]<a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 0;
            }
        }
        if(flag) return ;
    }
}

int main(){
    int a[5] = {3,6,1,2,2};
    int b[5] = {3,6,1,2,2};
    int c[5] = {3,6,1,2,2};
    
    Bubblesort1(a,5);
    Bubblesort2(b,5);
    Bubblesort3(c,5);
    for(int i=0;i<5;i++) cout<<a[i]<<endl;
    for(int i=0;i<5;i++) cout<<b[i]<<endl;
    for(int i=0;i<5;i++) cout<<c[i]<<endl;
    return 0;
}