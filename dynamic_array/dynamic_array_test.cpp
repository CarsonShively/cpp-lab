/*
unit tests
*/

#include "dynamic_array.h" // header is what exists, cpp is implementation of what exists
// header helps compiler understand the structure, the cpp is what is actually compiled to machine code
// compiler only needs to know that the calls are valid, in an include it doesnt need the implementation to compile
// only needs to know how to use the class, not how the class does it 

#include <string> // string object class, same as the dynamic array class
// no file tells compiler look in standard library for the class, this case the stirng class
// file headers already have global namespace so they dont need std::
// :: has 2 use cases 1 for napespace and another for member methods
// general :: use case is look inside the thing on the left for the thing on the right

#include <iostream>
// from std library use <> from project use "", compiler knows how find in global namespace and std libraries

// assert should print the result not return it
int assert_true(int expected_output, int output, const std::string& test) {  // similar to passing test string into the consturctor (my dynamic array doesnt do)
    // size counter to know element length (size-1)
    // offsets to find indexes
    // when its passed in as an arguemnet that is when it is put into memeory

    // std::string is like importing a dynamic array for chars
    // when reading use char size + char size counter + char sized offsets to get the string
    // if value is hardcoded compiler builds the object instead of running the dynamic array (dynaic array is for runtime)
    // & has 2 use cases, address or refernece
    // refference: when passing in an argument dont copy use the same adddress and value, best when the object takes sinificant memory like objects, not every value
    // const so you cant change it

    // if a string is small it could be stroed in the object instead of on heap with address
    // if its not an object its just an array on stack


    // cout is mapped to machine code that sends the static memory to stdout
    // cpu executes program (code memory, machine code) line by line
    // os manages stdout
    if (expected_output == output) {
        // how does stream work, how does stdout work?
        std::cout << "PASS: " << test << "\n"; // chain with <<
        return 1;
    } else {
        std::cout << "FAIL: " << test << "\n";
        return 0;
    }


    // stream buffer object is in static memory, the class of the buffer has determinsitic rules for wether to store it in the object or store a refernece to it
    // cout inherits access to the buffer object
    // flushing the buffer is machine code that writes the memory to stdout and sets the object state saying it can be overwritten
    // flush does not remove the bytes, it sets the state back to the beginning and overwrites (more effiecnt than emptying)
    // stream, buffer object sends request to os write(to where, starting address, how many bytes)
    // os then executes this request
    // os maps vm to process loctions in ram
    // os maps process locations to kernel locations in ram
    //cout flushes before a cin
    // some things can trigger a flush, \n can trigger a flush but not reliably, buffer being filled can trigger a flush, etc
    // build around definate flush points and use endl, if its not definate let it handle naturally
    // if its needed now use endl, if its needed at end or a checkpoint not immedietly let it flush natrually

    // later concepts: os bookeeping/mapping, kernel sub system
}

// if header uses no name space then it is gloabl name space
void test_push_back() {
    std::cout << "============ Test Push Back ==============\n";
    int pass = 0;
    int total = 3;
    DynamicArray test; // constructor is called automatically, declare it with a type
    std::string test_case = "first element";
    int input = 2;
    int expected_output = 2;
    test.push_back(input); // -> when you have a pointer to the object
    int output = test.get(0);
    pass += assert_true(expected_output, output, test_case);

    test_case = "second element";
    input = 4;
    expected_output = 4;
    test.push_back(input);
    output = test.get(1);
    pass += assert_true(expected_output, output, test_case);

    test_case = "third element";
    input = 100;
    expected_output = 100;
    test.push_back(input);
    output = test.get(2);
    pass += assert_true(expected_output, output, test_case);
    //needed destroyer
    std::cout << "Tests Passed: " << pass << "/" << total << "\n";
}

// add negative cases to next project
// test 1 main method, small improvements to test framework with each project, hardcode, add negative cases, loop, struct, framework
int main() {
    test_push_back();
    return 0; // status code for the os, did the program suceed or fail
}