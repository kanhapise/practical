//Practical 3: AIM - Program to Implement the Concept of Class Constructor and Its Types

public class Student {
    String name;
    int age;
    String major;
    
    //Default constructor
    public Student() {
        name = "Unknown";
        age = 0;
        major = "Undeclared";
    }
    // Parameterized constructor
    public Student(String name, int age, String major) {
        this.name = name;
        this.age = age;
        this.major = major;
    }
    // Copy constructor
    public Student(Student s) {
        this.name = s.name;
        this.age = s.age;
        this.major = s.major;
    }
    // Method to display student information
    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Major: " + major);
    }
    public static void main(String[] args) {
        // Using the default constructor
        Student student1 = new Student();
        System.out.println("Student 1 details:");
        student1.display();

        // Using the parameterized constructor
        Student student2 = new Student("Alice", 20, "Computer Science");
        System.out.println("\nStudent 2 details:");
        student2.display();

       // Using the copy constructor
        Student student3 = new Student(student2);
        System.out.println("\nStudent 3 details (copy of Student 2):");
        student3.display();
    }
}



/*

Concept:
- A constructor is a special type of method in a class that is automatically called when an object of that class is created. 
- It is used to initialize the object. There are different types of constructors in Java:
  1. **Default Constructor**: A constructor that does not take any arguments and initializes the object with default values.
  2. **Parameterized Constructor**: A constructor that allows the passing of arguments to initialize the object with specific values.
  3. **Copy Constructor**: A constructor that creates a new object by copying values from an existing object of the same class.

Algorithm:
1. Define a class with attributes (e.g., name, age, and major for a `Student` class).
2. Create a **default constructor** to initialize the attributes with default values.
3. Create a **parameterized constructor** that accepts parameters to initialize the attributes with user-defined values.
4. Create a **copy constructor** that takes another object of the same class and copies its attribute values to initialize the new object.
5. Create a method to display the object’s attributes.
6. In the `main` method, demonstrate the usage of the default, parameterized, and copy constructors by creating objects and displaying their information.

Time Complexity: O(1) — All constructor operations are constant-time operations.

Purpose:
- To understand how constructors are used to initialize objects in Java.
- To demonstrate the different types of constructors: default, parameterized, and copy constructors.
- To show how constructors help set initial values for object attributes when objects are created.
*/
