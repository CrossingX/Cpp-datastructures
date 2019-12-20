/*
 * @Author: Crossing
 * @Date: 2019-12-13 23:28:01
 * @LastEditTime : 2019-12-20 22:31:01
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
    int a[100] = {45, 71, 51, 84, 79, 97, 37, 59, 91, 47, 30, 26, 92, 38, 26, 47, 60, 72, 95, 82, 53, 77, 55, 100, 41, 89, 64, 57, 29, 62, 86, 56, 59, 80, 48, 37, 75, 58, 44, 80, 94, 90, 40, 28, 37, 61, 67, 71, 37, 33, 51, 90, 61, 53, 75, 28, 82, 32, 77, 65, 69, 47, 40, 62, 37, 77, 40, 54, 83, 57, 85, 90, 29, 54, 91, 51, 87, 72, 64, 48, 86, 33, 84, 94, 65, 93, 26, 78, 54, 21, 96, 21, 75, 39, 83, 69, 38, 100, 49, 81};
    int b[100] = {45, 71, 51, 84, 79, 97, 37, 59, 91, 47, 30, 26, 92, 38, 26, 47, 60, 72, 95, 82, 53, 77, 55, 100, 41, 89, 64, 57, 29, 62, 86, 56, 59, 80, 48, 37, 75, 58, 44, 80, 94, 90, 40, 28, 37, 61, 67, 71, 37, 33, 51, 90, 61, 53, 75, 28, 82, 32, 77, 65, 69, 47, 40, 62, 37, 77, 40, 54, 83, 57, 85, 90, 29, 54, 91, 51, 87, 72, 64, 48, 86, 33, 84, 94, 65, 93, 26, 78, 54, 21, 96, 21, 75, 39, 83, 69, 38, 100, 49, 81};
    int c[100] = {45, 71, 51, 84, 79, 97, 37, 59, 91, 47, 30, 26, 92, 38, 26, 47, 60, 72, 95, 82, 53, 77, 55, 100, 41, 89, 64, 57, 29, 62, 86, 56, 59, 80, 48, 37, 75, 58, 44, 80, 94, 90, 40, 28, 37, 61, 67, 71, 37, 33, 51, 90, 61, 53, 75, 28, 82, 32, 77, 65, 69, 47, 40, 62, 37, 77, 40, 54, 83, 57, 85, 90, 29, 54, 91, 51, 87, 72, 64, 48, 86, 33, 84, 94, 65, 93, 26, 78, 54, 21, 96, 21, 75, 39, 83, 69, 38, 100, 49, 81};

    
    Bubblesort1(a,100);
    Bubblesort2(b,100);
    Bubblesort3(c,100);
    for(int i=0;i<100;i++) cout<<a[i]<<endl;
    for(int i=0;i<100;i++) cout<<b[i]<<endl;
    for(int i=0;i<100;i++) cout<<c[i]<<endl;
    return 0;
}