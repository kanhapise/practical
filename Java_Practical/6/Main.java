// Practical 6: AIM - Implement Concept of Multilevel Inheritance

class Calculation {
    int a = 10;
    int b = 2;
}

class Addition extends Calculation {
    public int add() {
        return (a + b);
    }
}

class Subtraction extends Addition {
    public int sub() {
        return (a - b);
    }
}
class Multiplication extends Subtraction {
    public int mul() {
        return (a * b);
    }
}

class Division extends Multiplication {
    public int div() {
        if (b == 0) {
            System.out.println("Error: Division by zero.");
            return -1;
        }
        return (a / b);
    }
}

public class Main {
    public static void main(String[] args) {

        Addition addition = new Addition();
        System.out.println("Addition is: " + addition.add());

        Subtraction subtraction = new Subtraction();
        System.out.println("Subtraction is: " + subtraction.sub());

        Multiplication multiplication = new Multiplication();
        System.out.println("Multiplication is: " + multiplication.mul());

        Division division = new Division();
        int result = division.div();
        if (result != -1) {
            System.out.println("Division is: " + result);
        }
    }
}



/*

Concept:
- Inheritance in Java allows a class to inherit fields and methods from another class.
- **Multilevel inheritance** occurs when a class is derived from a class that is also derived from another class. 
- In this scenario, we have a chain of classes, where each subclass inherits from the previous class in the hierarchy.

Algorithm:
1. Create a base class (`Calculation`) with common fields (`a` and `b` in this case).
2. Create a derived class (`Addition`) that extends the base class and adds additional functionality (addition).
3. Create another derived class (`Subtraction`) that extends the `Addition` class and adds more functionality (subtraction).
4. Create further subclasses (`Multiplication`, `Division`) which extend the previous class and perform multiplication and division operations respectively.
5. In the `main` method, create objects for each class and perform calculations using the inherited methods.

Time Complexity: 
- Each operation (`add()`, `sub()`, `mul()`, `div()`) has constant time complexity O(1) because they perform a simple arithmetic operation.

Purpose:
- To demonstrate **multilevel inheritance** where one class inherits the properties and methods of another class, and the chain continues.
- To understand how functionality can be extended through multiple levels of inheritance in Java.
*/
