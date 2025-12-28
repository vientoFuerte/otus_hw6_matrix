// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert>
#include "matrix.h"

int main()
{

    Matrix<int, -1> matrix;

    assert(matrix.size() == 0);  // Все ячейки свободны

    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.size() == 0);


    std::cout << "Hello World!\n";
}

