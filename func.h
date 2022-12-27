#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include "struct.h"

void Print(Matrix matrix);
Item* NewItem(int val, int i, int j);
Line* NewLine(int i);
Line* InputItem(Line* line, Item* item);
int vozr(int x);
int ubiv (int x);
Matrix Init(Matrix matrix);
Matrix Input(Matrix matrix);
Line* InputLine2(Line* line, Item* item);
Matrix Copymatrix(Matrix matrix, Matrix newmatrix);
void Print2(Matrix matrix);
void Delite(Matrix matrix);

#endif // FUNC_H_INCLUDED