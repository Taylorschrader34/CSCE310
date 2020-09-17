/*
 * csce310homeWork03part01.cpp
 *
 *  Created on: Oct 9, 2018
 *      Author: Taylor
 */

#include <vector>
#include "csce310homeWork03part01.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int minimumST( vector< vector<int> > adjacencyMatrix ){

	vector<bool> check(adjacencyMatrix.size(), false);
	int min = 2147483645;
	int x = 0;
	int y = 0;
	bool done = false;
	int minspan = 0;

	for(int i = 1; i < adjacencyMatrix.size(); i++){
		for (int j = 0; j <=i -1; j++){
			if( adjacencyMatrix[i][j] > 0 && adjacencyMatrix[i][j] < min ){

				min = adjacencyMatrix[i][j];
				x = i;
				y = j;
			}
		}
	 }

	 check[x] = true ;
	 check[y] = true ;
	 minspan = minspan + min ;
	 min = 2147483645;

	for(int k = 0; k < check.size() - 2; k++){
		for (int i = 0; i < check.size(); i++){
			if( check[i] == true ){
				for(int j = 0; j < adjacencyMatrix[i].size(); j++){
					if( adjacencyMatrix[i][j] > 0 &&
							adjacencyMatrix [i][j] < min &&
							( check[j] == false )){
						min = adjacencyMatrix[i][j];
						x = i;
						y = j;
					}
				}
			}
		}
		check[y] = true ;
		minspan = minspan + min ;
		min = 2147483645;
	}

	return minspan;
}


