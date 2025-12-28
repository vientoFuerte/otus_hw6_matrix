// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert>
#include <tuple>
#include "matrix.h"


int main()
{

    Matrix<int, -1> matrix;

    assert(matrix.size() == 0);  // Все ячейки свободны

    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.size() == 0);
    
    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);
    // выведется одна строка
    // 100100314
    for(auto c: matrix)
    {
        std::pair<int, int> key;
        int x;
        int y;
        int v;
        std::tie(key, v) = c; 
        std::tie(x, y) = key; 
        //std::tie(x, y, v) = c;
        std::cout << x << y << v << std::endl;
    }
}
