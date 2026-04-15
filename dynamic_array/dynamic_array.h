/*
learning notes

normal array:
    int is 4 bytes

    documentation not comments

    automatic variable:
        life span begins and ends with its scope
        stored on stack frame
            stack frame is a portion of stack allocatd for a function
            compiler generates code that creates the stack frame size based on the spec and the frame is removed when the function returns
            differnet compilers can have different rules and result in different sizes
        can be optimised to a register or optimised away entierly

    stack:
        size depends on the operating system (linux, windows, etc)
        size is limited though
        fast though

    ram = main physical memory hardware (working memoery a program can uses)
    operating systems = sets up the regions 

    1 address = label for 1 location in ram which holds a byte (byte = 8 bits)
    ram is built in a way that locations can be refered to by an address

    ram has phyciscal locations with a phicial address map of those loactions
    os has an address space and maps that space to the ram address map

    programs have a virtual address space
    os maps that virtual address space to the physical ram addresses


    virtual memory / address space
        set of address teh program uses

        includes
            stack, heap, etc

        program acts as if this is the real memory

        the os maps the vm to the actual phyiscal ram addresses

    virtual memory map has ranges that correspond to the different areas such as stack, heap etc

    os gives the vm and sets the ranges

    the os gives new a vm to a process

    os can have multiple processes

    each process gets its own vm

    vm keeps track of the addresses reserved for that process

    each process has its own vm that keeps track for that process

    compiler optimises how code will use memory before it ever gets to teh vm in runtime

    different process vm all go to the same physical memory?

    process x address y -> physical location z

    ram has to hold this ^ and actual z data 

    os has to keep track of this

    vm is the ranges not a physical map, built into the os

    stack, heap, static categories are mostly for lifetime of memory in ram

    static = create at beginning, free at end

    stack = each thread has a stack limit size, functinos create stack frames, which is where automatic variables are recorded, when the function ends the stack frame ends the vars go with it

    1 process can have many threads

    they hav limits, the acutal memory has lifetimes

    heap = manual allocation and free

    many threads can work at the same time

    either limited by os count or blowing out ram

    static = read only
    heap/stack = write

    registers what happensi foyu blow out ram? overflow limits

    registers = cpu temporary memory, very fast

    machine code == asembly 
    byte instructions == human readable

    cpu executes teh program
    cpu loads instruction from code memory

    machine code dicates when cpu registers are needed, typically for computation

    how is heap allocated

    thread = the same code excecution at the same time

    each thread has its own function state thats why each thread needs a stack

    static data = once for process not for each thread

    heap = allocater book keeper

    os bookeeping logic

    os and compiler langueges?

    vm ranges = os rules

    vm = active representation of memory

    os maps representation to ram

    code = the compiled machine code, life time == the process

    code = read and execute, once its already in memory it shouldnt be changed
    heap, static, stack = read and write, values not code so nothing to execute

    kernals 

    unit test for practice 
    maybe integration test

    static memoery is reserved at the beginning

    overflow = crash

    mv has limits but visually starts empty
    add addresses
    initialise them or reserve them

    fault = hardware not code

    how does machine code alloce memory?

    what is runtime allocater?

*/ 


/*
project specific notes

establish at beginning of every project
os
cpu architecture
-uname -m
-tells processor class and bit width

abi = lp64 (me)

compiler (just has to be compatible)


allocate memory as a variable

dynamic array of ints

lp64 int = 4 bytes

refer to first byte

features
int array

how much to allocate

when to allocate

delete

insert

what does a 64 bit system mean?

pointer == 1 address
address = 8 bytes, 64 bits (lp64)

design for 1 abi?

think interms of machine code
*/

// 2 files both include the header breaks the translation unit in the compiler
// it is redefining the things in the header the second time its included
// ifndef == if not defined
#ifndef DYNAMIC_ARRAY_H // if this macro does not exists continue down, if it does exists skip to end if
#define DYNAMIC_ARRAY_H // defined by the compiler? compiler has its own memory system/handling

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