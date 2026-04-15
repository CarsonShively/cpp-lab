#include "dynamic_array.h" // # == compiler syntax

/*
:: is for the compiler to know scope
why does classes need to end with ; but not methods?

overflow and bit sign are core concepts

have a clear distincion between machine code compilatino concept vs virtual memory

double pointers etc?
runtime and efficiency?
cache etc

which is more common in low level struct vs class vs functions

class = private default
struct = public defaul

runtime, optimisation, complexities

static, class vars and methods?

convert from comments to documentation

alot of c++ is compiling to machine code

dynimic arrays are for storing runtime values and not fixed values at compile time

4 main phases of c++: runtime (code execution), compile (to machine code), os (vm to hardware), hardware (ram and cpu right now)

nothing to integration test

unit tests structure is the same wether you define them before or after coding

for unit tests hardcoding the values can be more direct, and better for the purpose of testing
*/

DynamicArray::DynamicArray() {
    // members are apart of the same class as the method, so they have access
    // parameters would mean the values would be passed in on creation as arguments
    // just set them here, passing in no arguments on creation
    // object initialisation (initial state == empty) not a default or a fill
    data = nullptr; // null ptr == address 0000 for all 8 bytes, meaning no data yet so no address of it
    size = 0;
    capacity = 0;
}

void DynamicArray::resize(int new_capacity) {
    // key = not resizing current heap, creating a new one with larger capacity then copying over

    int* new_data = new int[new_capacity]; // translates to machine code: create a new heap of int size new capacity times and set new data to the first byte
    // int[] is the size calculation 4 bytes * new capacity (for creation not compiler offset)
    // int in int* is for the compiler to know how to offset when working with elements, allows working with indexes from the first byte
    // index is the offset size
    // new == allcoate, int[] == this many int sized bytes, machine code compilation does the conversion


    // for loop just gets compiled to machine code, things like ; are just languege to compile rules
    for (int i=0; i<size; i++) {
        // 0 == no offset, that is why its i = 0
        // offset from the address of the first byte by int* which is why you attach int to the pointer
        // this is not about how memory is stored, its about how it is compiled to machine code
        new_data[i] = data[i];
    } // for loops methods etc not needing ; but class does is just languege to compiler translation rules, the reason is not as critical as other compiler rules, still something to learn later

    // find the consecutive heap block that starts at this address and free it
    // runtime allocator keeps bookeeping objects of allocation
    // if allocated with new free with delete
    // if allocated with new type[] free with delete[]
    // different bookeeping objects cant mismatch
    // single int vs block
    // bookeeping object keeps the bytes size and frees starting at this address that size 
    delete[] data; 
    data = new_data; // swap pointer
    capacity = new_capacity;

}

void DynamicArray::push_back(int value) {
    // check before adding
    if (size == capacity) {
        // this->member for methods and variables is expicit but the compiler can understand without it
        capacity = (capacity == 0) ? 1 : capacity * 2;
        // if condition is true use ? value
        // if condition is false use : value
        // condition in parenthesis
        // benifit = 1 line, set equal variable capcity right away, dont need to write if

        resize(capacity);
    }

    // your never setting an address, your always setting a value at that address
    // a pointer is just a value which is an address
    // your setting this address, with this offset, to this value
    // machine code compilation converts the size offset to bytes
    // in the data field it is still just an address storing a value
    // this is the value data stores + offset which is being set to value
    data[size] = value;
    size++;
}

// :: = for the compiler (what is the best way to explain it?)
void DynamicArray::remove(int index) {
    // key = replace left not actually remove
    for (int i = index; i < size; i++) {
        // i is needed for for loop syntax for the compiler
        // last index (offset) is always 1 below than size counter
        data[i] = data[i+1];
    }
    size --;
}

int DynamicArray::get(int index) const {
    // void means no return
    // more explicit way to get a class member
    return this->data[index]; // offset index many ints (4 bytes handled by compiler) from the address data 
}

// getter methods use const to block member edit
int DynamicArray::get_capacity() const {
    return this->capacity;
}

int DynamicArray::get_size() const {
    return this->size;
}

void DynamicArray::set(int index, int value) {
    data[index] = value;
}

// what does memory hold for null?
// pass in an array?
void DynamicArray::insert(int index, int value) {
    // if size is 0 and index is 0 insert is valid, if index is not 0 then its an invalid insert
    // if index equals size then its valid at end
    // if its farhter than size its no longer consecutive
    // mistake negative index could be a passed in argument
    // size as 0 is the same as pushing to end so it shares the same validation as index==size
    if (index > size || index<0) {
        return;
    }
    
    // you are checking size after the result of the last insert, if they are not equal you have room for an insert
    // size and capacity align, both are 1 based index counter and cap
    // the offset is where an element starts, the first element starts at the address in data, the next one is offset 1 int (4 bytes) from the address in data
    // int[] uses offsets from data address to create the 1s based capacity
    // index uses offsets to get to a specific element from the address data
    // key mistake was forgetting capacity and size are 1s based and trying to check size to capacity after this insert instead of just checking is ther room for 1 insert
    // mistake: forgetting resize updated capacity, keep resize in control of updating the capacity member so the member is only ever set in teh same place, regardless of where it is calculated at
    if (size == capacity) {
        int new_capacity = (capacity == 0) ? 1 : capacity * 2;
        resize(new_capacity);
    }
    
    // shift first to open up the index to insert
    // >= includes the floor
    for (int i = size-1; i >= index; i--) {
        data[i+1] = data[i];
    }

    // index and index + 1 would have the same value
    // now replace index with insert value
    data[index] = value;
    size++;
}

// same mechanism as deleting when allocating heap
DynamicArray::~DynamicArray() {
    delete[] data;
}