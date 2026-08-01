#include <iostream>
#include <cstdint>

/**
 * ============================================================================
 * MODULE 11: CONTROL FLOW DYNAMICS - ADAPTIVE SWITCH CASES & ENUMS
 * ============================================================================
 * This file serves as an interactive, production-grade architectural guide
 * covering the low-level mechanics of Switch Statements, Scoped Enums, 
 * Variable Scoping Traps, and Fall-through Behavior in C++.
 * ============================================================================
 */

// ----------------------------------------------------------------------------
// SECTION 1: ORGANIZING CHOICES SAFELY (Enums vs. Scoped Enums)
// ----------------------------------------------------------------------------

// OLD C-STYLE ENUM (The Dangerous Way)
// Problems: 
// 1. Unscoped: Names leak into the global/surrounding namespace.
// 2. Implicit conversion: Silently converts to integers, allowing risky math.
enum OldColor { 
    Red,   // Implicitly 0
    Blue   // Implicitly 1
};

// enum OldTraffic { Red }; // ERROR: Compilation fails! "Red" conflicts with OldColor::Red.

// MODERN C++ SCOPED ENUM (The Robust Way)
// Benefits:
// 1. Strictly Scoped: Enclosed entirely within its own type namespace.
// 2. No Implicit Conversion: Will not silently transform into an int.
// 3. Underlying Type Control: Can specify memory size explicitly (e.g., : uint8_t).
enum class SystemState : uint8_t {
    Booting,
    Running,
    ShuttingDown
};

enum class TrafficLight : uint8_t {
    Red,    // No namespace conflict with OldColor::Red or anything else!
    Yellow,
    Green
};

void runSection1() {
    SystemState state = SystemState::Booting;
    
    // int x = state; // COMPILER ERROR: Enforces strict type-safety.
    int x = static_cast<int>(state); // Allowed: Must explicitly request conversion.
}

// ----------------------------------------------------------------------------
// SECTION 2: HOW THE CPU HANDLES SWITCH STATEMENTS (The Low-Level Reality)
// ----------------------------------------------------------------------------
/*
   THE IF-ELSE APPROACH (Sequential Checking):
   If you use an if-else chain for 50 conditions, the CPU performs:
   CMP value, 1; JE label1; CMP value, 2; JE label2; ...
   - Time Complexity: O(N) linear time.
   - Analogy: Iterating through an array element-by-element until you match.

   THE SWITCH APPROACH (The Jump Table Optimization):
   If case constants are closely packed integers (e.g., 0, 1, 2), the compiler 
   generates a hidden array of code pointers called a "Jump Table".
   - Time Complexity: O(1) constant time execution layout.
   - Analogy: Jumping instantly to a specific index in an array via lookup.
   - Fallback: If case values are widely scattered (e.g., case 1, case 99999), 
     the compiler abandons the jump table and reverts to a Binary Search Tree 
     (O(log N)) or an if-else chain to conserve binary size.
*/

// ----------------------------------------------------------------------------
// SECTION 3: THE SWITCH-SCOPE TRAPS & MID-FLIGHT VARIABLE MODIFICATIONS
// ----------------------------------------------------------------------------
void runSwitchDemos(SystemState current) {
    std::cout << "--- Starting Switch Block ---\n";

    // CORE ASSEMBLY RULE: The switch condition is evaluated EXACTLY ONCE 
    // at the very beginning of the switch block to find the jump table index.
    switch (current) {
        
        case SystemState::Booting: {
            std::cout << "[1] System starting up...\n";
            
            // ----------------------------------------------------------------
            // EXPERIMENT: Modifying the switch variable mid-flight
            // ----------------------------------------------------------------
            // We change the real 'current' variable living in the outer scope.
            current = SystemState::Running; 
            
            // ARCHITECTURAL FACT: Modifying the variable does NOT force the 
            // switch to re-evaluate or jump. The routing decision was already 
            // finalized. Execution continues moving linearly downward.
            
            // ----------------------------------------------------------------
            // SCOPE TRAP FIX: Local Variable Declaration
            // ----------------------------------------------------------------
            // Inside a switch, all cases share the same declarative block scope.
            // Declaring raw variables directly under a case causes compile errors
            // because subsequent cases skip initialization but keep the scope.
            // FIX: Enclose the case body in explicit curly braces `{}`.
            int localConfigValue = 100;
            std::cout << "Config value initialized: " << localConfigValue << "\n";
            
            // ----------------------------------------------------------------
            // FALL-THROUGH DYNAMICS: [[fallthrough]]
            // ----------------------------------------------------------------
            // By default, C++ bleeds execution downward into the next label.
            // To do this intentionally without generating modern compiler warnings,
            // we use the standard attribute [[fallthrough]].
            [[fallthrough]]; 
        } // 'localConfigValue' safely dies here, avoiding cross-case leakage.
            
        case SystemState::Running:
            // Execution rolls straight here from Booting due to fall-through!
            std::cout << "[2] System is actively handling requests.\n";
            break; // Prevents execution from rolling down into ShuttingDown
            
        case SystemState::ShuttingDown:
            std::cout << "[3] System offline.\n";
            break;
    }
    
    // Verification of variable state
    if (current == SystemState::Running) {
        std::cout << "--- Switch Ended. Variable state is indeed 'Running' ---\n";
    }
}

int main() {
    // Test the framework with initial state 'Booting'
    runSwitchDemos(SystemState::Booting);
    return 0;
}
