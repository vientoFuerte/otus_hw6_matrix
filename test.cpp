#include "matrix.h"
#include <gtest/gtest.h>


TEST(MatrixTest, DirectTest) {
 
    Matrix<int, 0> matrix;
    
    EXPECT_EQ(matrix.size(), 0);
    EXPECT_EQ(matrix[0][0], 0) ;
    EXPECT_EQ(matrix[100][100], 0);
    
    EXPECT_EQ(matrix.size(), 0);
    
    for (int i=0; i<=9; i++)
    {
        matrix[i][i] = i;
        matrix[i][9 - i] = 9-i;
    }
        
    EXPECT_EQ(matrix.size(), 18);
    
    EXPECT_EQ(matrix[4][5], 5);
    EXPECT_EQ(matrix[9][9], 9);

}

  



