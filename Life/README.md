#Life

##Definitions
Life is really a simulation, not a game with players. It takes place
on an unbounded rectangular grid in which each cell can either be occupied by an organism or not
Occupied cells are called ``alive``; unoccupied cells are ```dead```.
Which cells are alive changes from generation to generation according to the number of neighboring cella that are alive.

## Transition Rules
1. The neighbors of a given cell are eight cells that touch it vertically, horizontally, or diagonally.
2. If a cell is alive, but either has no neighboring cells alive or only one alive, then in the next generation, the
cell dies of loneliness.
3. If a cell is alive and has four or more neighboring cells also alive, then in the next generation, the cell dies of 
overcrowding.
4. A living cell with either two or three living neighbors remains alive in the next generation.
5. If a cell is dead, then in the next generation, it will become alive if it has exactly three neighboring cells, no 
more or fewer, that are already alive. All other dead cells remain dead in the next generation.
6. All births and deaths take place at exactly the same time, so that dying cells can help to give birth to another, but
cannot prevent the death of others by reducing overcrowding, nor can cells being born either preserve or kill cells 
living in the previous generation.

