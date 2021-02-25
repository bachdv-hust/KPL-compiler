#include<stdio.h>
typedef struct {
    char word[20];
    int count;
    char line[100];
}Data;
typedef struct NodeType{
    Data key;
    struct NodeType * right, * left;
}Node ;
typedef Node * Tree;
