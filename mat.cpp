#include "mat.hpp"
#include <array>
#include "doctest.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace ariel
{
    string mat(int num1, int num2, char str1, char str2)
    {
        // according to test3
        int const min = 33;
        int const max = 126;

        if (num2 < 0 || num1 < 0)
        {
            std::__throw_invalid_argument("should be a positive number");
        }
        if (num2 % 2 == 0 || num1 % 2 == 0)
        {
            std::__throw_invalid_argument("should be an odd number!");
        }

        if (str2 < min || str1 < min)
        {
            std::__throw_invalid_argument("Invalid symbol!! symbol less than the min");
        }
        
        if (str2 > max || str1 > max)
        {
            std::__throw_invalid_argument("Invalid symbol!! symbol more than the max");
        }
        // the board that i build in
        vector<vector<char>> board(num2, vector<char>(num1));
        vector<vector<bool>> mat(num2, vector<bool>(num1));

        // we start from the first to the last
        int start_i = 0;
        int end_i = num1 - 1;  
        int start_j = 0;
        int end_j = num2 - 1;                                                            
        int size = (num2 + 1) / 2;                                
        
        // size = the depth of the board
        while (size > 0)
        {
            for (int i = start_i; i <= end_i; i++)
            {
                for (int j = start_j; j <= end_j; j++)
                {
                    board[start_j][i] = str1;
                    board[j][start_i] = str1;
                    board[end_j][i] = str1;
                    board[j][end_i] = str1;

                    // to know the empty indexes to fill him after..
                    mat[start_j][i] = true;
                    mat[j][start_i] = true;
                    mat[end_j][i] = true;
                    mat[j][end_i] = true;

                }
            }
            // from the examples in every itartion we go forward 4 staps ((start + 2)2 + 2(end - 2) = 4) 
            start_i += 2;
            end_i -= 2;
            start_j += 2;
            end_j -= 2;
            size--;// size of the depth of the board, we should 

            for (int i = 0; i < num2 - 1; i++)
            {
                for (int j = 0; j < num1 - 1; j++)
                {
                    if (!mat[i][j]) // if the current index is empty fill them with the other char...
                    {
                        board[i][j] = str2;
                    }
                }
            }
        }

        // the answer.. (toString)
        string result;
        for (int i = 0; i < num2; i++)
        {
            for (int j = 0; j < num1; j++)
            {
                result += board[i][j];
            }
        }

        return result;
    }

};