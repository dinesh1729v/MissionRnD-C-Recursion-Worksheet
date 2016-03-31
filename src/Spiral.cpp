/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void spiralRecursion(int rows, int columns, int **input_array, int *ans, int dir, int index, int rowsStart, int columnsStart, int rowsEnd, int columnsEnd)
{
	if (index == (rows*columns))
		return;
	int i;
	if (dir == 4)dir = 0;
	if (dir == 0)
	{
		for (i = columnsStart; i < columnsEnd; i++)
		{
			
			ans[index] = input_array[rowsStart][i];
			index++;
		}
		rowsStart++;

	}
	else if (dir == 1)
	{
		
		for (i = rowsStart; i < rowsEnd; i++)
		{
		
			ans[index] = input_array[i][columnsEnd - 1];
			index++;
		}
		columnsEnd--;
	}
	else if (dir == 2)
	{
		
		for (i = columnsEnd - 1; i >= columnsStart; i--)
		{
			
			ans[index] = input_array[rowsEnd - 1][i];
			index++;
		}
		rowsEnd--;
	}
	else if (dir == 3)
	{
		
		for (i = rowsEnd - 1; i >= rowsStart; i--)
		{
			
			ans[index] = input_array[i][columnsStart];
			index++;
		}
		columnsStart++;
	}
	dir++;
	spiralRecursion(rows, columns, input_array, ans, dir, index, rowsStart, columnsStart, rowsEnd, columnsEnd);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL)return NULL;
	if (rows <= 0 || columns <= 0)return NULL;
	int *ans = (int *)malloc(rows*columns*sizeof(int)), index = 0;
	spiralRecursion(rows, columns, input_array, ans, index, 0, 0, 0, rows, columns);
	return ans;
}

/*
if (dir == 0)
	{
		for (i = 0; i < columns1; i++)
		{
			ans[index] = input_array[rows - rows1][i];
			index++;
		}
		rows1--;
		spiralRecursion(rows, columns, input_array, ans, dir, index, rowsStart, columnsStart,);
	}
	else if (dir == 1)
	{
		for (i = rows1; i < rows; i++)
		{
			ans[index] = input_array[i][columns1-1];
			index++;
		}
		columns1--;
	}

*/