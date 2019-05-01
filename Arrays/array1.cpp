//
// Created by cenicol on 5/1/19.
//

#include "array1.hpp"

#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, char* argv[])
{
    // To define an array, you use the number of elements in the array.
    // Making an array of 5 integers
    int ary1[5];

    // Arrays are Zero indexed. So the array above contains elements ary1[0] to ary1[4]
    // Here is a simple loop to fill the array with numbers 1 to 5
    for(int i=0; i < 5; i++) {
        ary1[i] = i + 1;
    }

    cout << "Print the content of the array using indices" << endl;
    for(int i=0; i < 5; i++) {
        cout << "ary1[" << i << "] = " << ary1[i] << endl;
    }
    cout << endl;

    // C/C++ uses the idea of one past the end of the array. It can be tested
    // not used.
    // sizeof(ary1) returns the length of the array in characters. You can get
    // the number of items in an array by dividing the length of the array by
    // the size of the the array element.
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(ary1): " << sizeof(ary1) << endl;

    size_t ary1Len = sizeof(ary1) / sizeof(int);
    int* pBegin = ary1;
    int* pEnd = ary1 + ary1Len;

    cout << "ary1Len: " << ary1Len << endl;
    cout << ary1 << " the beginning of the array" << endl;
    cout << pEnd << " the address one past the end of ary1 " << endl;
    cout << endl;

    cout << "Print the contents of the array using pointers" << endl;
    for(int *p = pBegin; p < pEnd; ++p) {
        cout << p << ": " << *p << endl;
    }
    std::cout << endl;

    // Printing using C++ and STL

    // Print using the copy algorithm. This section shows that pointers to
    // arrays can function as STL containers.
    cout << "Printing using the copy algorithm" << endl;
    std::copy(pBegin,
              pEnd,
              ostream_iterator<int>(std::cout,",")
    );
    std::cout << endl;

    return 0;
}