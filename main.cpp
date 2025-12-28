// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert>
#include <tuple>
#include "matrix.h"


int main()
{
    Matrix<int, 0> matrix;
    
    for (int i=0; i<9; i++)
    {
        matrix[i][i] = i;
        matrix[i][8 - i] = 8-i;
    }
    
    for (int i=1; i<=8; i++)
    {
      for (int j=1; j<=8; j++)
      {
          std::cout<<matrix[i][j]<< "\t";
      }
      std::cout<< std::endl;
    }
    
    std::cout<<matrix.size()<<std::endl;

}
