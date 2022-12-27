#ifndef LAB1_STRUCT_H
#define LAB1_STRUCT_H


typedef struct Item{
    int i;
    int j;
    int value;
    Item* next;
}Item;

typedef struct Line{
    //Column* head;
    Item* head;
    int i;
    Line* next;
    int maxj;
}Line;

typedef struct Matrix{
    Line* head;
    int maxi;
    int line;
    int column;
}Matrix;

#endif //LAB1_STRUCT_H
