#include <iostream>
#include <string>

/**
 * ============================================================================
 * MODULE 13: GENERIC BLUEPRINTS - TEMPLATE BASICS & COMPILATION MECHANICS
 * ============================================================================
 * This file serves as an interactive, production-grade architectural guide
 * covering how the C++ compiler processes templates under the hood, the 
 * One Definition Rule (ODR) header requirement, and Compile-Time Duck Typing.
 * ============================================================================
 */

// ----------------------------------------------------------------------------
// SECTION 1: THE INJECTION MOLD SYNTAX (Function Templates)
// ----------------------------------------------------------------------------
// 'template <typename T>' declares that 'T' is a placeholder token.
// This is not actual executable code yet—it is a code-generation blueprint.
template <typename T>
T findMax(T a, T b) {
    // CRITICAL ASSUMPTION: This blueprint relies on type 'T' supporting
    // the binary operator> overload. If a type lacks it, instantiation fails.
    return (a > b) ? a : b;
}

// ----------------------------------------------------------------------------
// SECTION 2: UNDER THE HOOD MECHANICS (Two-Phase Compilation)
// ----------------------------------------------------------------------------
/*
   PHASE 1: SYNTAX CHECK (Building the Mold)
   - When the compiler first reads the template declaration block below, it 
     performs a lexical evaluation (checking for typos, semicolons, brackets).
   - ZERO assembly or machine instructions are generated in this phase.

   PHASE 2: INSTANTIATION (Stamping out concrete implementations)
   - The moment a user invokes the template with a real type, the compiler 
     copies the template code, replaces 'T' with the real type, and injects 
     a standalone, unique machine-code function into the final binary.
   - Example: If you call it with 'int' and 'double', the compiler generates 
     TWO independent functions: `findMax_int` and `findMax_double`.
   - PERFORMANCE: Because this expansion happens entirely at compile time,
     templates have ZERO runtime overhead. They are as fast as raw handwritten code.
*/

// ----------------------------------------------------------------------------
// SECTION 3: COMPILE-TIME DUCK TYPING (Capability Validation)
// ----------------------------------------------------------------------------
/*
   Unlike Object-Oriented Polymorphism which forces types to belong to a specific
   class hierarchy via inheritance, templates use "Duck Typing". 
   Rule: "If it walks like a duck and quacks like a duck, it's a duck."
   The compiler only mandates that the passed object physically supports the 
   called syntax operations.
*/

class LaserCannon {
public:
    void fire() { std::cout << "  [LASER] Zap! High-energy beam discharged.\n"; }
};

class WaterPistol {
public:
    void fire() { std::cout << "  [WATER] Squirt! Water jet released.\n"; }
};

class BrokenDevice {
    // Lacks a fire() function layout!
};

// Generic blueprint using Duck Typing
template <typename TDevice>
void dischargeWeapon(TDevice weapon) {
    // The ONLY hardware requirement for TDevice is possessing a .fire() method!
    weapon.fire(); 
}

// ----------------------------------------------------------------------------
// SECTION 4: THE HEADER FILE TRAP (The Compilation Law)
// ----------------------------------------------------------------------------
/*
   HARD RULE: Template declarations AND definition bodies must reside entirely 
   within header files (.h / .hpp). They CANNOT be split into separate .cpp files.
   
   Why? Because when a separate file (like main.cpp) compiles, it processes completely 
   in isolation. If it sees a template function signature but the actual body is hidden 
   inside another compiled .cpp file, the compiler cannot see inside the mold to 
   generate the type code. This triggers an 'Unresolved External Symbol' Linker Error.
*/

int main() {
    std::cout << "--- Section 1: Template Argument Deduction ---\n";
    
    // Explicit Instantiation: We manually force the type T to be 'int'
    int result1 = findMax<int>(10, 20);
    std::cout << "Explicit int Max: " << result1 << "\n";

    // Template Argument Deduction: The compiler looks at the values (5.5, 2.1)
    // and automatically infers/deduces that T must be 'double'.
    double result2 = findMax(5.5, 2.1);
    std::cout << "Deduced double Max: " << result2 << "\n";

    // Ambiguity Trap:
    // auto badResult = findMax(10, 5.5); // COMPILER ERROR: Is T an int or double?
    // Fix: We must resolve ambiguity by explicitly forcing the target type path:
    auto fixedResult = findMax<double>(10, 5.5);
    std::cout << "Resolved Mixed Max: " << fixedResult << "\n";


    std::cout << "\n--- Section 2: Duck Typing Demonstrations ---\n";
    
    LaserCannon plasmaGun;
    WaterPistol toyGun;
    BrokenDevice paperweight;

    // LaserCannon has a .fire() function? Yes! Generates dischargeWeapon_LaserCannon()
    dischargeWeapon(plasmaGun);

    // WaterPistol has a .fire() function? Yes! Generates dischargeWeapon_WaterPistol()
    dischargeWeapon(toyGun);

    // BrokenDevice has a .fire() function? No! 
    // Un-commenting the line below triggers a massive compile-time error layout:
    // dischargeWeapon(paperweight); 

    return 0;
}
