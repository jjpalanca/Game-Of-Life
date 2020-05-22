/*
 * GameOfLife.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: Rick Mercer and Jessmer John Palanca
 *
 * This class models a society of cells growing according
 * to the rules of John Conway's Game of Life.
 *
 */
#ifndef GAMEOFLIFE_HPP_
#define GAMEOFLIFE_HPP_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// This class allows a society of cells to grow according
// to the rules from John Conway's Game of Life
class GameOfLife {

// --Data Member(s)
private:
    std::vector<std::vector<bool>> theSociety;

public:
    // Construct a board that is rows by cols size
    // with all elements set to false
    GameOfLife(unsigned long rows, unsigned long cols) {
        vector<vector<bool>> grid(rows, vector<bool>(cols, false));
        for (int i = 0; i < grid.size(); i++) {
            vector<bool> vec;
            for (int j = 0; j < grid[0].size(); j++) {
                vec.push_back(grid[i][j]);
            }
            theSociety.push_back(vec);
        }
    }

    // Grow a cell at the given location
    void growCellAt(unsigned long row, unsigned long col) {
        theSociety[row][col] = true;
    }

    // Check to see if a cell is at the given location
    bool cellAt(unsigned long row, unsigned long col) const {
        return theSociety.at(row).at(col);
    }

    // Returns the colony as one big string
    std::string toString() const {
        string colony;
        for (auto i = 0; i < theSociety.size(); i++) {
            for (auto j = 0; j < theSociety[0].size(); j++) {
                string str;
                if (cellAt(i, j) == 1) {
                    str = "O";
                } else {
                    str = ".";
                }
                colony += str;
            }
            colony += "\n";
        }
        // cout << colony;
        return colony;
    }

    // Count the neighbors around the given location.
    // Use wraparound. A cell in row 0 has neighbors in
    // the last row if a cell is in the same column, or
    // the column to the left or right. In this example,
    // cell 0,5 has two neighbors in the last row, cell 2,8
    // has four neighbors, cell 2,0 has four neighbors,
    // cell 1,0 has three neighbors. The cell at 3,8 has
    // 3 neighbors. The potential location for a cell at 4,8
    // would have three neighbors.
    //
    // .....O..O
    // O........
    // O.......O
    // O.......O
    // ....O.O..
    //
    // The return values should always be in the range of 0 through 8.
    // return the number of neighbors around any cell using wrap around.
    int neighborCount(int row, int col) const {
        int lowerEdge = (theSociety.size() - 1);
        int rightEdge = (theSociety.at(0).size() - 1);
        int alive;
        int numNeighbors = 0;
        //inside the edge
        if (row > 0 && row < lowerEdge && col > 0 && col < rightEdge) {
            //upper left
            if (theSociety[row - 1][col - 1] == 1) {
                numNeighbors++;
            }
            //up
            if (theSociety[row - 1][col] == 1) {
                numNeighbors++;
            }
            //upper right
            if (theSociety[row - 1][col + 1] == 1) {
                numNeighbors++;
            }
            //left
            if (theSociety[row][col - 1] == 1) {
                numNeighbors++;
            }
            //right
            if (theSociety[row][col + 1] == 1) {
                numNeighbors++;
            }
            //lower left
            if (theSociety[row + 1][col - 1] == 1) {
                numNeighbors++;
            }
            //down
            if (theSociety[row + 1][col] == 1) {
                numNeighbors++;
            }
            //lower right
            if (theSociety[row + 1][col + 1] == 1) {
                numNeighbors++;
            }
        }
            //upper edge but not corner
        else if (row == 0 && col > 0 && col < rightEdge) {
            //upper left
            if (theSociety[lowerEdge][col - 1] == 1) {
                numNeighbors++;
            }
            //up
            if (theSociety[lowerEdge][col] == 1) {
                numNeighbors++;
            }
            //upper right
            if (theSociety[lowerEdge][col + 1] == 1) {
                numNeighbors++;
            }
            //left
            if (theSociety[row][col - 1] == 1) {
                numNeighbors++;
            }
            //right
            if (theSociety[row][col + 1] == 1) {
                numNeighbors++;
            }
            //lower left
            if (theSociety[row + 1][col - 1] == 1) {
                numNeighbors++;
            }
            //down
            if (theSociety[row + 1][col] == 1) {
                numNeighbors++;
            }
            //lower right
            if (theSociety[row + 1][col + 1] == 1) {
                numNeighbors++;
            }
        }
            //lower edge but not corner
        else if (row == lowerEdge && col > 0 && col < rightEdge) {
            //upper left
            if (theSociety[row - 1][col - 1] == 1) {
                numNeighbors++;
            }
            //up
            if (theSociety[row - 1][col] == 1) {
                numNeighbors++;
            }
            //upper right
            if (theSociety[row - 1][col + 1] == 1) {
                numNeighbors++;
            }
            //left
            if (theSociety[row][col - 1] == 1) {
                numNeighbors++;
            }
            //right
            if (theSociety[row][col + 1] == 1) {
                numNeighbors++;
            }
            //lower left
            if (theSociety[0][col - 1] == 1) {
                numNeighbors++;
            }
            //down
            if (theSociety[0][col] == 1) {
                numNeighbors++;
            }
            //lower right
            if (theSociety[0][col + 1] == 1) {
                numNeighbors++;
            }
        }
            //left edge but not corner
        else if (row > 0 && row < lowerEdge && col == 0) {
            //upper left
            if (theSociety[row - 1][rightEdge] == 1) {
                numNeighbors++;
            }
            //up
            if (theSociety[row - 1][col] == 1) {
                numNeighbors++;
            }
            //upper right
            if (theSociety[row - 1][col + 1] == 1) {
                numNeighbors++;
            }
            //left
            if (theSociety[row][rightEdge] == 1) {
                numNeighbors++;
            }
            //right
            if (theSociety[row][col + 1] == 1) {
                numNeighbors++;
            }
            //lower left
            if (theSociety[row + 1][rightEdge] == 1) {
                numNeighbors++;
            }
            //down
            if (theSociety[row + 1][col] == 1) {
                numNeighbors++;
            }
            //lower right
            if (theSociety[row + 1][col + 1] == 1) {
                numNeighbors++;
            }
        }
            //right edge but not corner
        else if (row > 0 && row < lowerEdge && col == rightEdge) {
            //upper left
            if (theSociety[row - 1][(col - 1)] == 1) {
                numNeighbors++;
            }
            //up
            if (theSociety[row - 1][col] == 1) {
                numNeighbors++;
            }
            //upper right
            if (theSociety[row - 1][0] == 1) {
                numNeighbors++;
            }
            //left
            if (theSociety[row][(col - 1)] == 1) {
                numNeighbors++;
            }
            //right
            if (theSociety[row][0] == 1) {
                numNeighbors++;
            }
            //lower left
            if (theSociety[row + 1][(col - 1)] == 1) {
                numNeighbors++;
            }
            //down
            if (theSociety[row + 1][col] == 1) {
                numNeighbors++;
            }
            //lower right
            if (theSociety[row + 1][0] == 1) {
                numNeighbors++;
            }
        }
            //upper left corner
        else if (row == 0 && col == 0) {
            //upper left
            if (theSociety[lowerEdge][rightEdge] == 1) {
                numNeighbors++;
            }
            //up
            if (theSociety[lowerEdge][col] == 1) {
                numNeighbors++;
            }
            //upper right
            if (theSociety[lowerEdge][col + 1] == 1) {
                numNeighbors++;
            }
            //left
            if (theSociety[row][rightEdge] == 1) {
                numNeighbors++;
            }
            //right
            if (theSociety[row][col + 1] == 1) {
                numNeighbors++;
            }
            //lower left
            if (theSociety[row + 1][rightEdge] == 1) {
                numNeighbors++;
            }
            //down
            if (theSociety[row + 1][col] == 1) {
                numNeighbors++;
            }
            //lower right
            if (theSociety[row + 1][col + 1] == 1) {
                numNeighbors++;
            }
        }
            //upper right corner
        else if (row == 0 && col == rightEdge) {
            //upper left
            if (theSociety[lowerEdge][col - 1] == 1) {
                numNeighbors++;
            }
            //up
            if (theSociety[lowerEdge][col] == 1) {
                numNeighbors++;
            }
            //upper right
            if (theSociety[lowerEdge][0] == 1) {
                numNeighbors++;
            }
            //left
            if (theSociety[row][col - 1] == 1) {
                numNeighbors++;
            }
            //right
            if (theSociety[row][0] == 1) {
                numNeighbors++;
            }
            //lower left
            if (theSociety[row + 1][col - 1] == 1) {
                numNeighbors++;
            }
            //down
            if (theSociety[row + 1][col] == 1) {
                numNeighbors++;
            }
            //lower right
            if (theSociety[row + 1][0] == 1) {
                numNeighbors++;
            }
        }
            //lower left corner
        else if (row == lowerEdge && col == 0) {
            //upper left
            if (theSociety[row - 1][rightEdge] == 1) {
                numNeighbors++;
            }
            //up
            if (theSociety[row - 1][col] == 1) {
                numNeighbors++;
            }
            //upper right
            if (theSociety[row - 1][col + 1] == 1) {
                numNeighbors++;
            }
            //left
            if (theSociety[row][rightEdge] == 1) {
                numNeighbors++;
            }
            //right
            if (theSociety[row][col + 1] == 1) {
                numNeighbors++;
            }
            //lower left
            if (theSociety[0][rightEdge] == 1) {
                numNeighbors++;
            }
            //down
            if (theSociety[0][col] == 1) {
                numNeighbors++;
            }
            //lower right
            if (theSociety[0][col + 1] == 1) {
                numNeighbors++;
            }
        }
            //lower right corner
        else if (row == lowerEdge && col == rightEdge) {
            //upper left
            if (theSociety[row - 1][col - 1] == 1) {
                numNeighbors++;
            }
            //up
            if (theSociety[row - 1][col] == 1) {
                numNeighbors++;
            }
            //upper right
            if (theSociety[row - 1][0] == 1) {
                numNeighbors++;
            }
            //left
            if (theSociety[row][col - 1] == 1) {
                numNeighbors++;
            }
            //right
            if (theSociety[row][0] == 1) {
                numNeighbors++;
            }
            //lower left
            if (theSociety[0][col - 1] == 1) {
                numNeighbors++;
            }
            //down
            if (theSociety[0][col] == 1) {
                numNeighbors++;
            }
            //lower right
            if (theSociety[0][0] == 1) {
                numNeighbors++;
            }
        }

        return numNeighbors;
    }

    // Change the state to the next society of cells
    void update() {
        vector<vector<bool>> newGrid;
        for (unsigned long row = 0; row < theSociety.size(); row++) {
            vector<bool> tempVec;
            for (unsigned long col = 0; col < theSociety.at(0).size(); col++) {
                auto cell = theSociety[row][col];
                bool alive;
                if (cellAt(row, col) == 0 and (neighborCount(row, col) == 3)) {
                    alive = true;
                    tempVec.push_back(alive);
                } else if (cellAt(row, col) == 1 &&
                           ((neighborCount(row, col) == 2) or (neighborCount(row, col) == 3))) {
                    alive = true;
                    tempVec.push_back(alive);
                } else if (cellAt(row, col) == 1 && neighborCount(row, col) < 2) {
                    alive = false;
                    tempVec.push_back(alive);
                } else if (cellAt(row, col) == 1 && neighborCount(row, col) > 3) {
                    alive = false;
                    tempVec.push_back(alive);
                } else {
                    alive = false;
                    tempVec.push_back(alive);
                }
            }
            newGrid.push_back(tempVec);

        }
        for (auto row = 0; row < newGrid.size(); row++) {
            for (auto col = 0; col < newGrid[0].size(); col++) {
                theSociety[row][col] = newGrid[row][col];
            }
        }
    }

};

#endif
