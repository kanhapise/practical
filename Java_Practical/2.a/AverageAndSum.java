//Practical 2.a: AIM- Program to Find Average and Sum of n Numbers Using Command Line Arguments

import java.util.Scanner;

public class AverageAndSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int sum = 0;
        double average;
        System.out.println("Enter " + n + " numbers:");
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            sum += num;
        }
        average = (double) sum / n;
        System.out.println("Sum: " + sum);
        System.out.println("Average: " + average);
    }
}


/*

Concept:
- Command line arguments allow the user to pass input to the program during execution. 
- In this program, the user is prompted to enter a number `n`, and then `n` numbers are taken as input.
- The sum of these numbers is calculated and then used to compute the average.

Key Points:
1. **Scanner Class**: The program uses the `Scanner` class to capture user input.
2. **Sum Calculation**: The program loops through the entered numbers and calculates their sum.
3. **Average Calculation**: The average is computed by dividing the sum by the number of elements (`n`).
4. **Output**: The program displays both the sum and the average of the entered numbers.

Algorithm:
1. Prompt the user to input the number of elements, `n`.
2. Initialize a variable `sum` to 0.
3. Using a loop, take `n` numbers as input and add them to the `sum`.
4. Calculate the average by dividing the `sum` by `n`.
5. Display the calculated `sum` and `average`.

Time Complexity: O(n) — The program iterates through the list of `n` numbers once to calculate the sum.

Purpose:
- To demonstrate the basic use of the `Scanner` class for user input.
- To perform basic arithmetic operations like summing up numbers and calculating the average.
*/
