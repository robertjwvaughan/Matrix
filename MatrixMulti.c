#include <stdio.h>
#include <stdlib.h>

void allocationCheck(int*);
void inputMatrix(int, int, int*);
void printMatrix(int, int, int*);
int calMatrix(int*, int*, int*, int, int, int);
 
int main()
{
    int row1, col1;
    int row2, col2;
    int i;
    
    printf("Please enter the row and col for martix 1\n");
    printf("Row: ");
    scanf("%d", &row1);
    printf("Col: ");
    scanf("%d", &col1);
    
    printf("\n");
    
    printf("Please enter the row and col for martix 2\n");
    printf("Row: ");
    scanf("%d", &row2);
    printf("Col: ");
    scanf("%d", &col2);
    
    if (row1 != col2)
    {
    	printf("\nPlease re-enter your values\n");
	}
    
    int *matrix1 = (int*)malloc(row1 * col1 * sizeof(int));
	
	allocationCheck(matrix1);
	
	printf("\nMatrix 1\n");
	inputMatrix(row1, col1, matrix1);
    //int *matrix1 = (int *)malloc(r * c * sizeof(int));
	
	int *matrix2 = (int*)malloc(row1 * col1 * sizeof(int));
	
	int *matrix3 = (int*)malloc(row1 * col2 * sizeof(int));
	
	allocationCheck(matrix2);
	allocationCheck(matrix3);
	
	printf("\nMatrix 1\n");
    inputMatrix(row2, col2, matrix2);
    
	calMatrix(matrix1, matrix2, matrix3, row1, col2, col1);
}//end main

void allocationCheck(int* matrix)
{
	if (matrix == NULL)
	{
		printf("Error: Allocation fail\n");
		exit(1);
	}//end if
}//end allocationCheck()

void inputMatrix(int row, int col, int* matrix)
{
	printf("\nPlease enter values for:\n");
	
	int i;
	int j;
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("Row %d	Col %d\n", i + 1, j + 1);
			scanf("%d", (matrix + i*col + j));
			
			//printf("%d", *(matrix + i*col + j));
		}//end for
	}//end for
	
	printMatrix(row, col, matrix);
	
}//end printMatrixx()

void printMatrix(int row, int col, int* matrix)
{
	int i, j;
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", *(matrix + (i * col) + j));
		}//end for
		
		printf("\n");
	}//end for
}//end printMatrix

int calMatrix(int* matrix1, int* matrix2, int* final, int row1, int col2, int col1)
{
	int sum = 0;
	int i, j, k;
	
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < col2; j++)
		{
			for (k = 0; k < col1; k++)
			{
				sum += *(matrix1 + i * col1 + k) * *(matrix2 + k * col2 + j);
			}//end for
		
			*(final + i * col2 + j) = sum;
			sum = 0;
		}//end for
	}//end for
	
	printMatrix(row1, col2, final);
	
}//end calMatrix
