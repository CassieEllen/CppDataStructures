//
// Created by cenicol on 5/4/19.
//

#ifndef ARRAY_TUTORIAL_LIBDEF_HPP
#define ARRAY_TUTORIAL_LIBDEF_HPP

//const int MAXROW = 50;      // Maximum number of rows
//const int MAXCOL = 80;      // Maximum number of columns
const int MAXROW = 3;      // Maximum number of rows
const int MAXCOL = 6;      // Maximum number of columns

typedef enum status_tag {DEAD, ALIVE} Status_type;

typedef Status_type Grid_type[MAXROW][MAXCOL];

struct Map_type {
    int maxcol;
    int maxrow;
    Grid_type map;

    // class Proxy is needed to to make a two dimensional operator map[][]
    // Proxy is instantiated with a pointer to the first element in the column array.
    // operator[] returns the element at the column index.
    class Proxy {
    public:
        explicit Proxy(Status_type *_array) : _array(_array)
        {}

        Status_type & operator[](size_t index) {
            return _array[index];
        }
    private:
        Status_type * _array;
    };

    // operator[] returns an instance of the Proxy class which is essentially the column array
    // The Proxy class is used to index into the column array
    Proxy operator[](size_t index) {
        return Proxy(map[index]);
    }
};


#endif //ARRAY_TUTORIAL_LIBDEF_HPP
