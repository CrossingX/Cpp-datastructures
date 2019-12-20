/*
 * @Author: Crossing
 * @Date: 2019-12-20 22:20:26
 * @LastEditTime : 2019-12-20 22:49:41
 * @Description: Implemention of Selectsort
 * @FilePath: /crossing/src/DS/Cpp-datastructures/Selectsort.cpp
 */
#include<iostream>
using namespace std;
void Selectsort(int a[], int len){
    int min;
    int tmp;
    for(int i=0;i<len;i++){
        min = i;
        for(int j=i+1;j<len;j++){
            if(a[min]>a[j]){
                min = j;
            }
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}
int main(){
    int a[100] = {45, 71, 51, 84, 79, 97, 37, 59, 91, 47, 30, 26, 92, 38, 26, 47, 60, 72, 95, 82, 53, 77, 55, 100, 41, 89, 64, 57, 29, 62, 86, 56, 59, 80, 48, 37, 75, 58, 44, 80, 94, 90, 40, 28, 37, 61, 67, 71, 37, 33, 51, 90, 61, 53, 75, 28, 82, 32, 77, 65, 69, 47, 40, 62, 37, 77, 40, 54, 83, 57, 85, 90, 29, 54, 91, 51, 87, 72, 64, 48, 86, 33, 84, 94, 65, 93, 26, 78, 54, 21, 96, 21, 75, 39, 83, 69, 38, 100, 49, 81};
    //answer: [21, 21, 26, 26, 26, 28, 28, 29, 29, 30, 32, 33, 33, 37, 37, 37, 37, 37, 38, 38, 39, 40, 40, 40, 41, 44, 45, 47, 47, 47, 48, 48, 49, 51, 51, 51, 53, 53, 54, 54, 54, 55, 56, 57, 57, 58, 59, 59, 60, 61, 61, 62, 62, 64, 64, 65, 65, 67, 69, 69, 71, 71, 72, 72, 75, 75, 75, 77, 77, 77, 78, 79, 80, 80, 81, 82, 82, 83, 83, 84, 84, 85, 86, 86, 87, 89, 90, 90, 90, 91, 91, 92, 93, 94, 94, 95, 96, 97, 100, 100]
    Selectsort(a,100);
    for(int i=0;i<100;i++) cout<<a[i]<<endl;
}