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

*/