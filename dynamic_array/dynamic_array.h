/** this is the format for a doc not a comment (doesnt affect c++ compile) use @ for labels
 * 
 * ======== dynamic array notes =====================
 * 
 * 
 * dictionary =======================================
 * int = 4 bytes
 * pointer = size of an address
 * thread = asyncrounous parts of a program
 * cpu = execute machine code
 * byte = 8 bits
 * process = program container
 * program = the code
 * registers = cpu memory, fast
 * machine code = instructions for how the cpu to execute the line
 * fault = hardware fail
 * 64 bit width = 64 bit registers in the cpu
 * array = consecutive type sizes in memory
 * address = 8 bytes
 * 
 * virtual memory ===========================================
 * - each process gets its own vm  
 * - process acts as if this is the real memory
 * - os maps vm to physical ram process locations
 * - os sets memory limit for each section
 * - compiler can optimise memory layout
 * - starts empty and is only the memory in use
 * - limits are a range of addresses
 * 
 * stack:
 *      lifespan = tied to scope
 *      "automatic"
 *      each thread in a process gets its own stack with its own limit (only type of vm that gets this)
 *      stackframe = a scope that contains the lifespan of memory defined inside a function, the compiler decides the size for the function
 *      write and read      
 * 
 * static-------
 *      lifespan = program
 *      read only
 * 
 * heap---------
 *      lifespan = from allocation to free
 *      allocate = get x address from the os
 *      block starts empty
 *      write and read
 * 
 * code---------
 *      lifespan = program 
 *      program machine code
 *      read and execute
 * 
 * compilers ============================
 * - different compilers have different rules
 * - optimises memory layout, can optimise memory into different secions of vm or away entierly
 * - converts code into machine code
 * 
 * os ===================================
 * - holds the rules for mapping vm to ram
 * - has rules for process locations of ram and kernel locations of ram
 * - has bookeeping and mapping rules built into its code
 * - either has memory limits or ram will be blown out
 * 
 * ram ====================================
 * - phisical runitme memory
 * - built in a way to have locations with addresses
 * 
 * learn what it is =================================
 * - kernels
 * - optimisation
 * - time and space complexity
 * - overflow
 * - signed vs unsigned
 * - runtime allocater
 * - vectors
 * - cache
 * 
 * learn how ===================================
 * - os
 * - compiler
 * - threading
 * - machine code / assembly
 * - abi agnostic
 * 
 * sizes ===================================
 * - based off hardware and os then compatibity check with compiler
 * - linux 64-bit = lp64 (abi)
 * - abi gives the type sizes
 * 
 * 
 */


// 2 files including a header overwrites the first one, this breaks the translation unit in the compiler
// ifndef == if not defined
// # = compiler code
#ifndef DYNAMIC_ARRAY_H // if this macro does not exist in the compiler continue down, if it does exists skip to endif
#define DYNAMIC_ARRAY_H // create macro 

// a dynamic array is 1 object
// struct defualts to public, class defaults to private
class DynamicArray {
// order of members corresponds to address order in memory
// public vs private is normal encapsulation?
private:
    // pointer is 8 bytes
    // compiler turns this into machine code that starts at this address and uses int offset to get the value
    // this specifically holds the address of the first byte of int
    // int tells the compiler how to create the machine code to offset from this address
    // when the first array element is placed into memoery what is the address it starts at + type to offset
    // address could be empty, purpose is to know what address it starts in memory + how the compiler should create the machine code to offset
    // int becuase its a small sized project so long is not needed?
    int* data;
    int size; // track how many elements are in the array, size * 4 is the offset, sie is how many offsets to apply to the first address
    int capacity; // element cap in ints (not addresses)

public:
    // compiler determines memory size for object based on class
    // each filed has an offset from the starting address that maps to the fields of the object for alignment
    DynamicArray(); // initialse empty with no params
    ~DynamicArray(); // when the object's lifetime ends jump to this machine code
    void push_back(int value); // standard name
    void remove(int index);
    int get(int index) const; // const = do not change member data, mostly getters but more conceptual
    void set(int index, int value);
    int get_capacity() const; 
    int get_size() const; // how does const work with memory and convert to machine code?
    void resize(int new_capacity); // keep the method focused on memory
    void insert(int index, int value); // parameters as values are copies not the original values so they dont need const, if it is passed in by address it would 

};

#endif // skip to here (header gaurd ends here)