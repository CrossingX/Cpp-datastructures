/*
 * @Author: Crossing
 * @Date: 2019-12-13 23:28:01
 * @LastEditTime: 2019-12-13 23:46:30
 * @Description: Bubblesort
 * @FilePath: /src/DS/Cpp-datastructures/Bubblesort.cpp
 */
#include<iostream>
using namespace std;
void Bubblesort(int a[], int len){
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
int main(){
    int a[4] = {3,6,1,2};
    Bubblesort(a,4);
    for(int i=0;i<4;i++) cout<<a[i]<<endl;
}