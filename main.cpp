#include <iostream>
#include "struct.h"
#include "func.h"

using namespace std;

int main ()
{
    Matrix matrix, newmatrix;
    int line,column;
    std::cout << "enter the number of lines" << std::endl;
    std::cin >> line;
    std::cout << "enter the number of columns" << std::endl;
    std::cin >> column;
    newmatrix.line = matrix.line = line;
    newmatrix.column = matrix.column = column;
    newmatrix.maxi = matrix.maxi = -1;
    matrix = Init(matrix);
    matrix = Input(matrix);
    Print(matrix);
    newmatrix = Copymatrix(matrix, newmatrix);
    std::cout << std::endl;
    Print2(newmatrix);
    Delite(matrix);
    Delite(newmatrix);
    return 0;
}
