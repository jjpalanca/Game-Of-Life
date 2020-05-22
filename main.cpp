#include <iostream>
#include "GameOfLife.hpp"
int main() {
    GameOfLife object(5,7);
    //object.growCellAt(0,0);
    object.growCellAt(1,2);
    object.growCellAt(1,4);
    //object.growCellAt(1,0);
    //object.growCellAt(1,1);
    //object.growCellAt(1,2);
    object.growCellAt(2,4);
    object.growCellAt(2,3);
    object.growCellAt(2,2);

    //object.growCellAt(1,1);
    //object.growCellAt(4,6);
    object.toString();
    /*
    cout << endl;
    for (auto i = 0; i < 5; i++){
        for (auto j = 0; j < 7; j++){
            cout << object.neighborCount(i,j);
        }
        cout << endl;
    }*/
    cout << endl;

    //cout << object.cellAt(2,3) << endl;
    //cout << object.cellAt(1,4)<<endl;
    //cout << object.neighborCount(0,2) << endl;
    //cout << object.neighborCount(2,3) << endl;
    //cout << object.neighborCount(2,4) << endl;
    //cout << object.cellAt(2,4)<<": " << object.neighborCount(2,4);
    object.update();
    object.toString();
    //cout << endl;
    //object.toString();
    //cout << object.cellAt(2,3) << endl;
    //cout << "no of neighbors: " << object.neighborCount(1,1);
    return 0;
}