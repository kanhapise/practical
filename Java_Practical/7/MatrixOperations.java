//Practical 7: AIM - Implement Matrix Operations Using Java Arrays


// remove the opration which are not asked!
//NOTE : only adding operation code is written in another file.

import java.util.Scanner;

public class MatrixOperations {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of rows for matrix A: ");
        int rowsA = scanner.nextInt();
        System.out.print("Enter the number of columns for matrix A: ");
        int colsA = scanner.nextInt();
        
        int[][] matrixA = new int[rowsA][colsA];
        
        System.out.println("Enter elements of matrix A:");
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsA; j++) {
                matrixA[i][j] = scanner.nextInt();
            }
        }

        System.out.print("Enter the number of rows for matrix B: ");
        int rowsB = scanner.nextInt();
        System.out.print("Enter the number of columns for matrix B: ");
        int colsB = scanner.nextInt();
        
        int[][] matrixB = new int[rowsB][colsB];
        
        System.out.println("Enter elements of matrix B:");
        for (int i = 0; i < rowsB; i++) {
            for (int j = 0; j < colsB; j++) {
                matrixB[i][j] = scanner.nextInt();
            }
        }

        if (rowsA == rowsB && colsA == colsB) {
            System.out.println("Matrix A + Matrix B:");
            addMatrices(matrixA, matrixB, rowsA, colsA);
            System.out.println("Matrix A - Matrix B:");
            subtractMatrices(matrixA, matrixB, rowsA, colsA);
        } else {
            System.out.println("Matrices cannot be added or subtracted because their dimensions do not match.");
        }

        if (colsA == rowsB) {
            System.out.println("Matrix A * Matrix B:");
            multiplyMatrices(matrixA, matrixB, rowsA, colsA, rowsB, colsB);
        } else {
            System.out.println("Matrices cannot be multiplied because the number of columns of A is not equal to the number of rows of B.");
        }
    }

    public static void addMatrices(int[][] matrixA, int[][] matrixB, int rows, int cols) {
        int[][] result = new int[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }
        
        displayMatrix(result, rows, cols);
    }

    public static void subtractMatrices(int[][] matrixA, int[][] matrixB, int rows, int cols) {
        int[][] result = new int[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrixA[i][j] - matrixB[i][j];
            }
        }
        
        displayMatrix(result, rows, cols);
    }

    public static void multiplyMatrices(int[][] matrixA, int[][] matrixB, int rowsA, int colsA, int rowsB, int colsB) {
        int[][] result = new int[rowsA][colsB];
        
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                result[i][j] = 0;
                for (int k = 0; k < colsA; k++) {
                    result[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
        
        displayMatrix(result, rowsA, colsB);
    }


    //dont delete this function
    public static void displayMatrix(int[][] matrix, int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}



/*
Concept:
- A matrix is a two-dimensional array consisting of rows and columns of elements.
- The program performs basic matrix operations such as addition, subtraction, and multiplication using Java arrays.
- It demonstrates how to manipulate matrices using arrays and perform mathematical operations on them.

Algorithm:
1. Prompt the user to input the dimensions (rows and columns) for matrix A and matrix B.
2. Read the elements of matrix A and matrix B from the user.
3. **Addition**: Check if the matrices have the same dimensions. If they do, add corresponding elements of matrix A and matrix B.
4. **Subtraction**: Check if the matrices have the same dimensions. If they do, subtract corresponding elements of matrix B from matrix A.
5. **Multiplication**: Check if the number of columns in matrix A is equal to the number of rows in matrix B. If true, multiply the matrices using the standard matrix multiplication rule.
6. Display the results of all the operations performed.

Time Complexity:
- **Addition/Subtraction**: O(n * m) — where n is the number of rows and m is the number of columns.
- **Multiplication**: O(n * m * p) — where n is the number of rows in matrix A, m is the number of columns in matrix A (also the number of rows in matrix B), and p is the number of columns in matrix B.

Purpose:
- To demonstrate basic matrix operations using Java arrays.
- To understand how to manipulate and perform mathematical operations on two-dimensional arrays.
- To implement matrix addition, subtraction, and multiplication by following the respective mathematical rules.
*/
