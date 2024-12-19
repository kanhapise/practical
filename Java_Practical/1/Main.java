// Practical 1: Implementation of Class, Data Members, and Member Functions

//AIM : Write a program to implement the concept of class and data members and member functions(a. WAP to calculate the area and perimeter of Square, Rectangle, and Circle)

class Rectangle{
    int length , width ;
    void getData(int x, int y)
    {
        this.length = x;
        this.width = y;
    }
    void area()
    {
        double area = length * width;
        System.out.println("Area of Rectangle: "+area);
    }
    void perimeter(){
        double perimeter = 2 * (length + width);
        System.out.println("Perimeter of Rectangle is: "+ perimeter);
    }
}
class Circle{
    double radius;
    void getData(int r)
    {
        this.radius = r;
    }
    void area()
    {
        double area = radius * radius *3.14;
        System.out.println("Area of Circle: "+area);
    }
    void perimeter(){
        double perimeter = 2 * 3.14 * radius;
        System.out.println("Perimeter of Circle is: "+ perimeter);
    }
}
class Square{
    int side;
    void getData(int a){
        this.side = a;
    }
    void area(){
        double area = side * side;
        System.out.println("Area of Square: "+area);
    }
    void perimeter(){
        double perimeter = 4 * side;
        System.out.println("Perimeter of Square is: "+ perimeter);
    }
}
public class Main {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle();
        r1.getData(24,12);
        r1.area();
        r1.perimeter();
        Circle c1 = new Circle();
        c1.getData(30);
        c1.area();
        c1.perimeter();
        Square s1 = new Square();
        s1.getData(6);
        s1.area();
        s1.perimeter();
    }
}


/*

Concept:
- A class is a blueprint for creating objects, encapsulating data (fields) and behavior (methods).
- Data members (also known as fields or attributes) store the state or properties of an object.
- Member functions (also known as methods) define the behavior or operations that can be performed on the data.

Key Points:
1. A class is defined using the `class` keyword.
2. Data members are variables declared within a class.
3. Member functions are methods defined inside a class that operate on data members.
4. Objects are instances of a class, created using the `new` keyword.

Example Use:
- A `Student` class can store properties like `name`, `rollNo`, and `marks`.
- Member functions like `inputDetails` and `displayDetails` can be used to set and retrieve these properties.

Purpose:
- To understand how classes and objects encapsulate data and behavior in object-oriented programming.
- To demonstrate how to define and use a class in Java effectively.
*/
