/**
 * ============================================================================
 * MODULE 12: EXCEPTION SAFETY SYNTAX AND LIFECYCLE GUIDE
 * ============================================================================
 * This file demonstrates the correct syntax implementation for try/catch blocks,
 * RAII memory protection, copy-and-swap semantics, and noexcept functions.
 * ============================================================================
 */

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

// Custom exception type to demonstrate polymorphism and prevent slicing
class DatabaseError : public std::runtime_error {
private:
    int errorCode;
public:
    DatabaseError(const std::string& msg, int code) 
        : std::runtime_error(msg), errorCode(code) {}
        
    int getCode() const noexcept { return errorCode; }
};

// Dummy resource tracker to observe automatic cleanup
class DeviceConnection {
private:
    std::string id;
public:
    DeviceConnection(std::string name) : id(name) {
        std::cout << "  [RAII] Connection " << id << " opened.\n";
    }
    ~DeviceConnection() {
        std::cout << "  [RAII] Connection " << id << " automatically closed via Destructor!\n";
    }
};

// ----------------------------------------------------------------------------
// RULE DEMONSTRATION: NOEXCEPT & PERFORMANCE
// ----------------------------------------------------------------------------
class SmartDataBuffer {
private:
    size_t size;
    int* rawData;

public:
    SmartDataBuffer(size_t s) : size(s), rawData(new int[s]()) {}
    ~SmartDataBuffer() { delete[] rawData; }

    // The No-Throw Guarantee: Move operations MUST be marked noexcept so 
    // containers like std::vector will safely use them during memory reallocations.
    SmartDataBuffer(SmartDataBuffer&& other) noexcept 
        : size(other.size), rawData(other.rawData) 
    {
        other.size = 0;
        other.rawData = nullptr; // Handover complete without allocations
        std::cout << "  [MOVE] noexcept move constructor invoked.\n";
    }

    // Swapping internal pointers cannot throw errors, making it the bedrock of safety.
    void swap(SmartDataBuffer& other) noexcept {
        std::swap(this->size, other.size);
        std::swap(this->rawData, other.rawData);
    }
};

// ----------------------------------------------------------------------------
// STRUCTURAL IMPLEMENTATION: THE STRONG EXCEPTION GUARANTEE (Copy-and-Swap)
// ----------------------------------------------------------------------------
class DatabaseManager {
private:
    std::string currentRecord = "Original Stable Entry";

public:
    // This function promises the Strong Exception Guarantee: Commit or Rollback
    void updateRecord(const std::string& newText, bool simulateFailure) {
        // Step 1: Make a copy of the state layout (Work on a isolated clone)
        std::string backupCopy = this->currentRecord;

        // Step 2: Perform risky modification work
        backupCopy = newText + " [Staged Changes]";

        if (simulateFailure) {
            std::cout << "  [THROW] Network packet lost! Activating panic button...\n";
            throw DatabaseError("Database write aborted: Connection timeout", 503);
        }

        // Step 3: No exceptions occurred? Safely swap data. (Commit point)
        this->currentRecord = std::move(backupCopy); 
    }

    void printState() const {
        std::cout << "  Current Data State: \"" << currentRecord << "\"\n";
    }
};

// ----------------------------------------------------------------------------
// CONTROLFLOW FLOW LAYOUT
// ----------------------------------------------------------------------------
void executeTransaction(bool generateError) {
    // RAII: This connection tracking object sits purely on the stack
    DeviceConnection link("Secure_SQL_Link");
    
    // RAII: Heap storage bound securely inside a smart pointer stack layout
    auto safeHeapBuffer = std::make_unique<int[]>(10);

    DatabaseManager db;
    db.printState();

    std::cout << "  Attempting transaction update...\n";
    db.updateRecord("New Highly Volatile Transaction Data", generateError);
    
    // If an error happened inside updateRecord(), stack unwinding tears down 
    // this frame INSTANTLY. 'link' and 'safeHeapBuffer' are wiped out cleanly.
    // The line below is skipped entirely on failure paths.
    std::cout << "  Transaction applied successfully!\n";
    db.printState();
}

int main() {
    std::cout << "=== Test Path 1: Simulation of a structural transaction failure ===\n";
    try {
        executeTransaction(true); // Forces a throw condition mid-flight
    }
    // Intercepting strictly by Constant Reference to prevent data object slicing
    catch (const DatabaseError& caughtException) {
        std::cout << "\n[CATCH HANDLER IN MAIN] Emergency caught error layout!\n";
        std::cout << "  Error String: " << caughtException.what() << "\n";
        std::cout << "  SQL Error Code: " << caughtException.getCode() << "\n";
    }
    catch (const std::exception& genericException) {
        std::cout << "  Caught standard fallback exception: " << genericException.what() << "\n";
    }

    std::cout << "\n=== Test Path 2: Simulation of a completely clean run ===\n";
    try {
        executeTransaction(false); // Runs smoothly without errors
    }
    catch (const std::exception& e) {
        std::cout << "This catch block will be skipped completely.\n";
    }

    return 0;
}
