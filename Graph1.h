/*
 * @Author: Crossing
 * @Date: 2019-12-24 01:26:33
 * @LastEditTime : 2019-12-26 16:16:42
 * @Description: Implement an Graph using adjacency matrix
 * @FilePath: /crossing/src/DS/Cpp-datastructures/Graph1.h
 */
#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<queue>
#define MAX_SIZE 1000
using namespace std;
int visited[MAX_SIZE] = {0};
template <class T>
class Graph{
    public:
        Graph(T a[], int nv, int ne);
        ~Graph(){}
        void addVertex(T v);
        void addEdge(int start,int end, int w);
        void printMatrix();
        void DFS(int vertex);
        void DFStraverse();
        void BFStraverse();
    private:
        int adjMatrix[MAX_SIZE][MAX_SIZE];
        int numVertex;
        int numEdge;
        T Vertex[MAX_SIZE];
};
template <class T>
Graph<T>::Graph(T a[], int nv, int ne){
    numVertex = nv;
    numEdge = ne;
    for(int i=0;i<nv;i++){
        Vertex[i] = a[i];
    }
    for(int i=0;i<nv;i++){
        for(int j=0;j<nv;j++){
            adjMatrix[i][j]=0;
        }
    }
    for(int i=0;i<ne;i++){
        int start, end, weight;
        cin>>start>>end>>weight;
        adjMatrix[start][end] = weight;
        adjMatrix[end][start] = weight;
    }
}
template <class T>
void Graph<T>::addVertex(T v){
    if(MAX_SIZE-numVertex==1) {
        cout<<"Full"<<endl;
    }
    else
    Vertex[numVertex+1] = v;
}
template <class T>
void Graph<T>::addEdge(int start,int end, int w){
    adjMatrix[start][end] = w;
    adjMatrix[end][start] = w;
}
template <class T>
void Graph<T>::printMatrix(){
    for(int i=0;i<numVertex;i++){
        for(int j=0;j<numVertex;j++){
            cout<<adjMatrix[i][j]<<((j==numVertex-1)?"\n":" ");
        }
    }
}
template <class T>
void Graph<T>::DFS(int vertex){
    cout<<Vertex[vertex]<<endl;
    visited[vertex]=1;
    for(int i=0;i<numVertex;i++){
        if(adjMatrix[vertex][i]!=0 && visited[i]==0) DFS(i);
    }
}
template <class T>
void Graph<T>::BFStraverse(){
    int visited1[MAX_SIZE] = {0};
    for(int k=0;k<numVertex;k++){
        queue<int> q;
        if(!visited1[k]){
            visited1[k]=1;
            q.push(k);
            while(!q.empty()){
                cout<<q.front()<<endl;
                for(int i=0;i<numVertex;i++){
                    if(adjMatrix[q.front()][i]!=0&&visited1[i]==0){
                        q.push(i);
                        visited1[i]=1;
                    }
                }
                q.pop();
            }
        }
    }
}
template <class T>
void Graph<T>::DFStraverse(){
    for(int i=0;i<numVertex;i++){
        visited[i] = 0;
    }
    for(int i=0;i<numVertex;i++){
        if(!visited[i]){
            DFS(i);
        }
    }
}
#endif