// Practical 2.b:  AIM - Program to Calculate Simple Interest


import java.util.Scanner;

public class SimpleInterest{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the principal amount: ");
        double principal = scanner.nextDouble();
        System.out.print("Enter the rate of interest per month: ");
        double rate = scanner.nextDouble();
        System.out.print("Enter the time period in months: ");
        int time = scanner.nextInt();
        double simpleInterest = (principal * rate * time) / 100;
        System.out.println("Simple Interest is: " + simpleInterest);
    }
}

/*
Concept:
- Simple interest is calculated using the formula:
  Simple Interest = (Principal × Rate × Time) / 100
- In this program, the user is prompted to enter the principal amount, the monthly rate of interest, and the time period in months.
- The program then calculates the simple interest based on the user inputs.

Key Points:
1. **Input**: The program takes the principal amount, rate of interest (per month), and time period (in months) as inputs from the user.
2. **Calculation**: The program uses the simple interest formula to compute the interest.
3. **Output**: The program outputs the calculated simple interest.

Algorithm:
1. Prompt the user to enter the principal amount.
2. Prompt the user to enter the rate of interest per month.
3. Prompt the user to enter the time period in months.
4. Apply the simple interest formula: (Principal × Rate × Time) / 100.
5. Display the calculated simple interest.

Time Complexity: O(1) — The program performs a constant number of arithmetic operations.

Purpose:
- To demonstrate the calculation of simple interest based on user inputs.
- To show the application of basic mathematical formulas in programming.
*/
