/*
 * @Author: Crossing
 * @Date: 2019-12-27 09:23:55
 * @LastEditTime : 2019-12-27 09:41:59
 * @Description: Recursive and non-Recursive
 * @FilePath: /crossing/src/DS/Cpp-datastructures/Binarysearch.cpp
 */
#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include<iostream>
#include<algorithm>
using namespace std;
int Binarysearch1(int a[], int start, int end, int x){
    if(start > end) {
        return -1;
    }
    int mid = (start + end)/2;
    if(a[mid] > x){
        Binarysearch1(a,start,mid-1,x);
    }
    else if(a[mid] < x){
        Binarysearch1(a,mid+1,end,x);
    }
    else return mid;
}
int Binarysearch2(int a[], int n, int x){
    int start = 0;
    int end = n-1;
    int mid;
    while(start <= end){
        mid = (start + end)/2;
        if(a[mid] > x) end = mid-1;
        else if(a[mid] < x) start = mid+1;
        else return mid;
    }
    return -1;
}
int main(){
    int a[] = {-1,0,1,3,4,6,8,10,12};
    cout<<Binarysearch1(a,0,8,6)<<endl;
    cout<<Binarysearch2(a,9,6)<<endl;
    return 0;
}


#endif