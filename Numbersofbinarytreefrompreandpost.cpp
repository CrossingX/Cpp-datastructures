#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int len = a.length();
    int count = 0;
    for(int i = 0; i < len-1; i++){
        for(int j = 1; j < len; j++){
            if(a[i] == b[j] && a[i+1] == b[j-1]){
                count++;
            }
        }
    }
    cout<<(1<<count)<<endl;
}