// Aim: Create a Class VolumeCalculator with overloaded methods to calculate the volume of different shapes.
// Practical 5.b

class VolumeCalculator {

    public double calculateVolume(double radius) {
        return (4.0 / 3.0) * Math.PI * Math.pow(radius, 3); // Volume of sphere
    }

    public double calculateVolume(double length, double width, double height) {
        return length * width * height; // Volume of rectangular prism
    }

    public double calculateVolume(double baseArea, double height) {
        return baseArea * height; // Volume of triangular prism
    }

    public static void main(String[] args) {
        VolumeCalculator vc = new VolumeCalculator();

        double sphereVolume = vc.calculateVolume(5.0);
        System.out.println("Volume of Sphere: " + sphereVolume);

        double rectangularPrismVolume = vc.calculateVolume(10.0, 7.0, 5.0);
        System.out.println("Volume of Rectangular Prism: " + rectangularPrismVolume);

        double triangularPrismVolume = vc.calculateVolume(20.0, 8.0);
        System.out.println("Volume of Triangular Prism: " + triangularPrismVolume);
    }
}


/*

Theory:
1. **Method Overloading**:
   - Method overloading is the concept where multiple methods can have the same name but differ in the number or type of parameters they accept. This allows different operations to be performed with the same method name, depending on the arguments passed.
   - In this practical, method overloading is implemented in the `calculateVolume` method. The method name is the same, but it performs different calculations based on the type and number of arguments passed.

2. **Volume of Sphere**:
   - The volume of a sphere is calculated using the formula:
     - Volume = (4/3) * π * r³
     - The method `calculateVolume(double radius)` is used to calculate the volume of a sphere when only the radius is provided.

3. **Volume of Rectangular Prism**:
   - The volume of a rectangular prism (or cuboid) is calculated using the formula:
     - Volume = length * width * height
     - The method `calculateVolume(double length, double width, double height)` is used to calculate the volume of the rectangular prism when the length, width, and height are provided.

4. **Volume of Triangular Prism**:
   - The volume of a triangular prism is calculated using the formula:
     - Volume = Base Area * Height
     - The method `calculateVolume(double baseArea, double height)` is used to calculate the volume of a triangular prism when the base area and height are provided.

5. **Importance of Method Overloading**:
   - By overloading the `calculateVolume` method, we provide a flexible way to calculate volumes for different shapes using the same method name. This makes the code more readable and efficient, allowing us to handle different use cases without needing multiple method names.

*/
