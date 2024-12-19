//Practical 5.a
// Aim: Design a class "Printer" with overloaded methods to print messages.

class Printer {

    public void print(int number) {
        System.out.println("Number: " + number);
    }

    public void print(String message) {
        System.out.println("Message: " + message);
    }

    public void print(String message, int number) {
        System.out.println("Message: " + message + ", Number: " + number);
    }

    public void print(int number, String message) {
        System.out.println("Number: " + number + ", Message: " + message);
    }

    public static void main(String[] args) {
        Printer printer = new Printer();

        printer.print(42);                            
        printer.print("Hello, world!");               
        printer.print("Count is", 10);                
        printer.print(99, "items left in stock");    
    }
}


/*
    
    1. **Method Overloading**:
       - In Java, method overloading is a concept where multiple methods in the same class have the same name but different parameter lists.
       - Overloaded methods can differ in the number of parameters or the type of parameters they take.

    2. **Concept**:
       - In this practical, we implement a class `Printer` with four overloaded methods:
         - `print(int number)`: Prints an integer number.
         - `print(String message)`: Prints a string message.
         - `print(String message, int number)`: Prints a string message followed by an integer number.
         - `print(int number, String message)`: Prints an integer number followed by a string message.

    3. **Purpose**:
       - The purpose of method overloading is to provide multiple ways of performing the same operation, depending on the data that is passed to the method. This is useful when you want the method name to remain consistent but accommodate different data types or numbers of arguments.

    4. **How It Works**:
       - The Java compiler determines which overloaded method to call based on the arguments passed during the method call.
       - In this case, we have provided methods with varying parameter types and numbers, so when you call `print()`, Java decides which version of the method to execute depending on the arguments you provide.

    5. **Example**:
       - We call the `print` method with different types of arguments to demonstrate method overloading.
       - The correct method is chosen based on the type of arguments.

    6. **Output**:
       - The program prints the message or number based on the overloaded method that matches the parameters passed.

    7. **Advantages**:
       - Method overloading enhances code readability by keeping the method name consistent.
       - It allows for flexibility in how methods are called with different types or numbers of arguments.
*/
