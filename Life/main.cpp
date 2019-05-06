//
// Created by cenicol on 5/4/19.
//

#include "general.hpp"
#include "libdef.hpp"
#include "calls.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    int row;
    int col;
    //Grid_type map;          // Current generation
    //Grid_type newmap;       // Next generation
    Map_type map{};           // Current generation
    Map_type newmap{};        // Next generation

    if(argc == 1 || argc > 2) {
        cerr << "Usage: Life filename\n";
        return(-1);
    }

    // Initialization
    Initialize(argv[1], map);
    WriteMap(map);

#if 1
    // Calculate Changes
    do {
        cout << "Top of loop" << endl;
        for (row = 0; row < MAXROW; row++) {
            for (col = 0; col < MAXCOL; col++) {
                switch (NeighborCount(row, col, map)) {
                    case 0:
                    case 1:
                        newmap[row][col] = DEAD;
                        break;
                    case 2:
                        newmap[row][col] = map[row][col];
                        break;
                    case 3:
                        newmap[row][col] = ALIVE;
                        break;
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        newmap[row][col] = DEAD;
                        break;
                    default:
                        __throw_out_of_range("Invalid map file.");
                }
            }
        }
        CopyMap(map, newmap);
        WriteMap(map);
        cout << "Bottom of loop" << endl;
    } while (Enquire());
#endif

    // End program
    return (0);
}

void CopyMap(Map_type& map_out, Map_type& map_in) {
    for (int row = 0; row < MAXROW; row++) {
        for (int col = 0; col < MAXCOL; col++) {
            map_out[row][col] = map_in[row][col];
        }
    }
}

bool Enquire()
{
    return false;
}

void Initialize(char const * filename, Map_type &map)
{
    assert(nullptr!= filename);
    cout << "Reading " << filename << endl;
    ifstream file(filename);
    assert(file.is_open());
    int maxrow;
    int maxcol;
    int value;

    // Read map boundaries from file
    file >> maxrow;
    file >> maxcol;

    // Ensure the map has proper boundaries
    assert(maxrow > 0);
    assert(maxcol > 0);
    assert(maxrow <= MAXROW);
    assert(maxcol <= MAXCOL);

    // Set the map boundaries
    map.maxrow = maxrow;
    map.maxcol = maxcol;

    // not needed if all entries are in the file
#if 0
    // Set all map entries to DEAD
    for(int row=0; row < MAXROW; ++row) {
        for (int col = 0; col < MAXCOL; ++col) {
            map[row][col] = DEAD;
        }
    }
#endif

    // Load map entries from file
    for(int row=0; row < maxrow; ++row) {
        for(int col=0; col < maxcol; ++col) {
            file >> value;
            switch(value)
            {
                case 0:
                    map[row][col] = DEAD;
                    break;
                case 1:
                    map[row][col] = ALIVE;
                    break;
                default:
                    __throw_out_of_range("Invalid map file.");
                    break;
            }
        }
    }
}

int NeighborCount(int, int, Map_type&)
{
    return 0;
}

void WriteMap(Map_type & map)
{
    for(int row=0; row < map.maxrow; row++) {
        for(int col=0; col < map.maxcol; col++) {
            cout << map[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
