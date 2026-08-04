#include <iostream>
#include <string>

/**
 * ============================================================================
 * MODULE 13: GENERIC BLUEPRINTS - CLASS TEMPLATES & SPECIALIZATIONS
 * ============================================================================
 * This file demonstrates class template syntax layout, out-of-class method
 * declarations, CTAD, and explicit template specializations.
 * ============================================================================
 */

// ----------------------------------------------------------------------------
// SECTION 1: GENERIC CLASS TEMPLATE BLUEPRINT
// ----------------------------------------------------------------------------
template <typename T>
class CustomContainer {
private:
    T storedData;
public:
    // Constructor inside the class body layout
    CustomContainer(T value) : storedData(value) {}

    // Method signature declaration (Implementation will be written outside)
    void inspectData() const;
};

// OUT-OF-CLASS METHOD SYNTAX LAW:
// You must restate the template parameters and append <T> to the class scope!
template <typename T>
void CustomContainer<T>::inspectData() const {
    std::cout << "[GENERIC BLUEPRINT] Contained value: " << storedData << "\n";
}

// ----------------------------------------------------------------------------
// SECTION 2: TEMPLATE SPECIALIZATION (The Explicit Override)
// ----------------------------------------------------------------------------
// Scenario: We want a specialized container optimized specifically for strings
// that converts the output message to uppercase layout headers.
template <>
class CustomContainer<std::string> {
private:
    // Remember: Specializations have COMPLETE AUTONOMY. 
    // They do not inherit fields or methods from the generic version automatically.
    std::string internalString;
public:
    CustomContainer(std::string value) : internalString(value) {}

    // Completely unique, custom implementation layout for this specific type
    void inspectData() const {
        std::cout << "[SPECIALIZED BLUEPRINT] String length detected: " 
                  << internalString.length() << " characters.\n";
        std::cout << "  Raw Content: " << internalString << "\n";
    }
};

int main() {
    std::cout << "--- Section 1: Class Template Argument Deduction (CTAD) ---\n";
    
    // Modern C++ (C++17): The compiler examines the integer argument 500
    // and automatically instantiates this object as CustomContainer<int>
    CustomContainer integerContainer(500); 
    integerContainer.inspectData(); // Triggers the Generic Blueprint

    // CTAD deduces this object as CustomContainer<double>
    CustomContainer doubleContainer(99.95);
    doubleContainer.inspectData(); // Triggers the Generic Blueprint


    std::cout << "\n--- Section 2: Specialization Resolution ---\n";
    
    // The compiler checks if there is a specialized class for std::string.
    // It matches our specialization perfectly, completely bypassing the generic class!
    CustomContainer<std::string> messageContainer("Modern C++ Meta-Programming");
    messageContainer.inspectData(); // Triggers the Specialized Blueprint

    return 0;
}
