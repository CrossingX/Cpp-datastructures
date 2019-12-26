/*
 * @Author: Crossing
 * @Date: 2019-12-25 21:16:42
 * @LastEditTime : 2019-12-26 16:14:41
 * @Description: Implement an Graph using adjacency list
 * @FilePath: /crossing/src/DS/Cpp-datastructures/Graph2.h
 */
#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<queue>
#define MAX_SIZE 1000
using namespace std;
int visited[MAX_SIZE] = {0};
class EdgeNode{
    public:
        int adjvex;
	    int weight;
	    EdgeNode* next;
};
template <class T>
class VertexNode{
    public:
        T value;
        EdgeNode* firstedge;
};
template <class T>
class Graph{
    public:
        Graph(T a[], int nv, int ne);
        ~Graph(){}
        void addVertex(T v);
        void addEdge(int start, int end, int w);
        void printMatrix();
        void DFS(int vertex);
        void DFStraverse();
        void BFStraverse();
    private:
        VertexNode<T> adjList[MAX_SIZE];
        int numVertex;
        int numEdge;
};
template <class T>
Graph<T>::Graph(T a[], int nv, int ne){
    numVertex = nv;
    numEdge = ne;
    for(int i=0;i<nv;i++){
        adjList[i].value = a[i];
        adjList[i].firstedge = nullptr;
    }
    for(int i=0;i<ne;i++){
        int start, end;
        int w;
        cin>>start>>end>>w;
        EdgeNode* p = new EdgeNode();
        p->adjvex = end;
        p->weight = w;
        p->next = adjList[start].firstedge;
        adjList[start].firstedge = p;
    }
}
template <class T>
void Graph<T>::addVertex(T v){
    if(MAX_SIZE-numVertex==1){
        cout<<"Full"<<endl;
        return;
    }
    adjList[numVertex+1].value = v;
    adjList[numVertex+1].firstedge = nullptr;   
}
template <class T>
void Graph<T>::addEdge(int start, int end, int w){
    EdgeNode* p = new EdgeNode();
    p->adjvex = end;
    p->weight = w;
    p->next = adjList[start].firstedge;
    adjList[start].firstedge = p;
}
template <class T>
void Graph<T>::printMatrix(){
    for(int i=0;i<numVertex;i++){
        cout<<adjList[i].value<<endl;
        EdgeNode* e = adjList[i].firstedge;
        while(e!=nullptr){
            cout<<e->adjvex<<":"<<e->weight<<" ";
            e = e->next;
        }
        cout<<endl;
    }
}
template <class T>
void Graph<T>::DFS(int vertex){
    visited[vertex] = 1;
    cout<<adjList[vertex].value<<endl;
    EdgeNode* e = adjList[vertex].firstedge;
    while(e!=nullptr){
        if(visited[e->adjvex]==0) DFS(e->adjvex);
        e = e->next;
    }
}
template <class T>
void Graph<T>::BFStraverse(){
    int visited1[MAX_SIZE] = {0};
    for(int k=0;k<numVertex;k++){
        queue<int> q;
        if(!visited1[k]){
            visited1[k] = 1;
            q.push(k);
            while(!q.empty()){
                cout<<q.front()<<endl;
                EdgeNode* e = adjList[q.front()].firstedge;
                while(e!=nullptr){
                    if(visited1[e->adjvex]==0){
                        q.push(e->adjvex);
                        visited1[e->adjvex] = 1;
                    }
                    e = e->next;
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