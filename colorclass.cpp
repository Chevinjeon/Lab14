// COMSC-210 | Lab 14 | Chevin Jeon 
// IDE used: VSC
// Date: 2025-09-23

/**
 * ---------------------------------------------------------
 * Program: Color Class Demonstration
 * Author: Chevin Jeon
 *
 * Description:
 *   This program defines a Color class that represents an
 *   RGB color using three integers (red, green, blue).
 *   - Each channel is private and restricted to [0, 255].
 *   - Public getters/setters provide controlled access.
 *   - A print() method displays the color in both
 *     decimal RGB and hexadecimal (#RRGGBB) format.
 *
 *   In main(), several Color objects are created, modified,
 *   and printed to demonstrate class functionality.
 *
 *   This file combines both the class declaration and its
 *   implementation, so no separate .h file is needed.
 * ---------------------------------------------------------
 */

#include <iostream>   // std::cout, std::endl
#include <iomanip>    // std::hex, std::setw, std::setfill, std::uppercase
#include <stdexcept>  // std::out_of_range

// --------------------- Color class ---------------------
class Color {
private:
    int r; // red channel (0–255)
    int g; // green channel (0–255)
    int b; // blue channel (0–255)

    // Helper: validate a single 8-bit channel and return it
    int clampByte(int value) const {
        if (value < 0 || value > 255) {
            throw std::out_of_range("Color channel must be in range 0–255");
        }
        return value;
    }

public:
    // Default constructor: black
    Color() : r(0), g(0), b(0) {}

    // Parameterized constructor: validates all channels
    Color(int red, int green, int blue)
        : r(clampByte(red)), g(clampByte(green)), b(clampByte(blue)) {}

    // ---- Getters ----
    int getR() const { return r; }
    int getG() const { return g; }
    int getB() const { return b; }

    // ---- Setters (validate inputs) ----
    void setR(int red)   { r = clampByte(red); }
    void setG(int green) { g = clampByte(green); }
    void setB(int blue)  { b = clampByte(blue); }

    // ---- Formatted print: RGB + #RRGGBB ----
    void print() const {
        std::cout << "Color(r=" << r
                  << ", g=" << g
                  << ", b=" << b
                  << ", hex=#"
                  << std::uppercase << std::hex << std::setfill('0')
                  << std::setw(2) << r
                  << std::setw(2) << g
                  << std::setw(2) << b
                  << std::dec  // restore decimal for any later prints
                  << ")"
                  << std::endl;
    }
};

// --------------------- Main function ---------------------
int main() {
    try {
        // Create several colors using the parameterized ctor
        Color red(255, 0, 0);
        Color green(0, 255, 0);
        Color blue(0, 0, 255);
        Color white(255, 255, 255);
        Color black(0, 0, 0);
        Color custom(123, 45, 67);

        std::cout << "== Initial colors ==" << std::endl;
        red.print();
        green.print();
        blue.print();
        white.print();
        black.print();
        custom.print();

        std::cout << "\n== After modifying custom ==" << std::endl;
        // Use getters to read, setters to write (keeps validation in one place)
        custom.setR(custom.getR() + 10);
        custom.setG(custom.getG() + 10);
        custom.setB(custom.getB() + 10);
        custom.print();

        // Validation examples (uncomment to test exceptions)
        // Color bad1(-1, 0, 0);
        // Color bad2(0, 0, 300);
        // custom.setR(-5);

    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1; // non-zero exit on error
    }

    return 0; // success
}
