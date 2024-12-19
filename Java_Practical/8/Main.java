//Practical 8: Design a custom exception class called InvalidAgeException. Write a method 
//that checks if a person's age is valid and throws this exception if the age is invalid.


class InvalidAgeException extends Exception {  
    public InvalidAgeException(String message) {  
        super(message);  
    }  
}  
 //Ye(zero division error) nahi pucha to cut krlena .
class ZeroDivisionError extends ArithmeticException {  
    public ZeroDivisionError(String message) {  
        super(message);  
    }  
}  
  
public class Main {  
    public static void checkAge(int age) throws InvalidAgeException {  
        if(age < 18 || age > 100) {  
            throw new InvalidAgeException("Invalid age: Age must be between 18 and 100.");  
        } else {  
            System.out.println("Age is valid: " + age);  
        }  
    }  
    
    
    //Ye(zero division error) nahi pucha to below function cut krlena .
    public static void checkDivision(int numerator, int denominator) throws ZeroDivisionError {  
        if(denominator == 0) {  
            throw new ZeroDivisionError("Error: Division by zero is not allowed.");  
        } else {  
            System.out.println("Result: " + (numerator / denominator));  
        }  
    }  

    public static void main(String[] args) {  
        try {  
            checkAge(15);  
            checkAge(25);  
        } catch (InvalidAgeException e) {  
            System.out.println(e.getMessage());  
        }  

    //Ye(zero division error) nahi pucha to below try-catch block cut krlena .
        try {  
            checkDivision(10, 0);  
            checkDivision(10, 2);  
        } catch (ZeroDivisionError e) {  
            System.out.println(e.getMessage());  
        }  
    }  
}

/*

Theory:
In Java, exceptions are used to handle runtime errors and provide a way to transfer control 
to a specific block of code when an error occurs. Java allows the creation of custom exceptions 
which can be thrown when a particular condition is met. In this practical, we design a custom 
exception class called InvalidAgeException that will be used to check if a given age is valid.

1. Custom Exception Class:
   - We extend the Exception class to create our custom exception class `InvalidAgeException`.
   - This class can be used to represent invalid age errors during the execution of a program.

2. Throwing the Custom Exception:
   - In the `checkAge` method, we validate the age entered by the user.
   - If the age is invalid (e.g., negative age or age greater than a certain limit), we throw 
     the `InvalidAgeException`.

3. Handling the Exception:
   - In the main method, we use a try-catch block to handle the custom exception when it is thrown.
   - The catch block catches the `InvalidAgeException` and displays a meaningful error message.

Benefits of Custom Exceptions:
- Custom exceptions allow for more specific and informative error handling.
- They help in maintaining a clean, readable, and organized codebase.
- By defining exceptions relevant to the business logic, we can catch errors more easily and 
  respond with meaningful error messages.

Example Scenario:
- A valid age could be between 0 and 120. If the entered age is outside this range, 
  an `InvalidAgeException` is thrown.
*/
