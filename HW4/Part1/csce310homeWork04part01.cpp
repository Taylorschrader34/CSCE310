/*
 * csce310homeWork03part04.cpp
 *
 *  Created on: Oct 31, 2018
 *      Author: Taylor
 */
#include "csce310homeWork04part01.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int collectWithLoss( vector< vector<int> > grid ){

	int maxValue = 0;
	int cols = grid.size();
	int rows = grid[0].size();

	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){
			if(grid[col][row] < 0){
				grid[col][row] = 0;
			}else if(row == 0 && col != 0){
				grid[col][row] = max(grid[col][row],grid[col][row] + grid[col-1][row]);
			}else if(row != 0 && col == 0){
				grid[col][row] = max(grid[col][row],grid[col][row] + grid[col][row-1]);
			}else if(row != 0 && col != 0){
				grid[col][row] = max(max(grid[col][row],grid[col][row] + grid[col-1][row])
						, grid[col][row] + grid[col][row-1]);
			}

		}
	}

	maxValue = grid[cols-1][rows-1];

	return maxValue;
}
