//Practical 4:  AIM - Implement Runtime Polymorphism in Java

class Animal {
    void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Dog barks");
    }
}

class Cat extends Animal {
    @Override
    void sound() {
        System.out.println("Cat meows");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal myAnimal = new Animal();
        Animal myDog = new Dog();
        Animal myCat = new Cat();
        
        myAnimal.sound(); 
        myDog.sound();   
        myCat.sound();    
    }
}

/*

Concept:
- Runtime polymorphism (also called dynamic method dispatch) in Java occurs when a method in a subclass overrides a method in its superclass.
- The method to be invoked is determined at runtime based on the object being referred to by the superclass reference.
- This allows objects of different classes to be treated as objects of the superclass while still calling the subclass's overridden methods.

Algorithm:
1. Create a superclass with a method.
2. Create one or more subclasses that override the method from the superclass.
3. In the main method, create instances of both the superclass and the subclass using the superclass reference.
4. Call the overridden method through the superclass reference.
5. The appropriate method of the subclass is called at runtime based on the object type, not the reference type.

Example:
- The superclass `Animal` has a method `sound()`.
- The subclasses `Dog` and `Cat` each override the `sound()` method with their own implementation.
- At runtime, the method corresponding to the actual object type (whether `Dog` or `Cat`) is invoked, even though the reference is of type `Animal`.

Time Complexity: O(1) — The runtime polymorphism is resolved during method invocation, which is a constant-time operation.

Purpose:
- To demonstrate how runtime polymorphism allows for flexibility in method calls and how Java resolves method calls at runtime.
- To understand how method overriding in Java enables different behaviors in subclasses while using a common superclass reference.
*/
