// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert>
#include <tuple>
#include "matrix.h"


int main()
{
    Matrix<int, 0> matrix;
    
    // Заполнение матрицы.
    for (int i=0; i<=9; i++)
    {
        matrix[i][i] = i;
        matrix[i][9 - i] = 9-i;
    }
    
    // Вывод требуемого фрагмента матрицы.
    for (int i=1; i<=8; i++)
    {
      for (int j=1; j<=8; j++)
      {
          std::cout<<matrix[i][j]<< " ";
      }
      std::cout<< std::endl;
    }
    
    // Количество занятых ячеек.
    std::cout<< "\nNumber of occupied cells: "<<matrix.size()<<"\n\n";

    // Вывод занятых ячеек вместе со своими позициями.
    for(auto c: matrix)
    {
        std::pair<int, int> key;
        int x;
        int y;
        int v;
        std::tie(key, v) = c; 
        std::tie(x, y) = key; 
        std::cout << "matrix["<<x<<"][" << y << "] = " << v << std::endl;
    }

}
