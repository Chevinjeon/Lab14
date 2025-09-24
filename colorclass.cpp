// COMSC-210 | Lab 14 | Chevin Jeon 
// IDE used: VSC
// Date: 2025-09-23

/**
 * ---------------------------------------------------------
 * Program: Color Class Demonstration
 * Author: Chevin Jeon
 * 
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

#include <iostream>
#include <iomanip>   // for std::setw, std::setfill
#include <stdexcept> // for exceptions

// --------------------- Color class ---------------------
class Color {
private:
    int r; // red channel (0–255)
    int g; // green channel (0–255)
    int b; // blue channel (0–255)

    // Helper function to validate that a channel value is in [0, 255]
    int clampByte(int value) const {
        if (value < 0 || value > 255) {
            throw std::out_of_range("Color channel must be in range 0–255");
        }
        return value;
    }
