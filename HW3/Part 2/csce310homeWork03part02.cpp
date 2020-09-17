/*
 * csce310homeWork03part02.cpp
 *
 *  Created on: Oct 9, 2018
 *      Author: Taylor
 */
#include <vector>
#include "csce310homeWork03part02.h"
#include <cmath>
#include <iostream>

using namespace std;

vector<int> dijkstra( vector< vector<int> > adjacencyMatrix , int start ){

	vector<int> out(adjacencyMatrix[start].size());
	vector<int> testValues(adjacencyMatrix.size());

 	for(int i = 0; i<adjacencyMatrix[start].size(); i++){
		out[i] = adjacencyMatrix[start][i];
		if(out[i] > 0){
			testValues[i] = 1;
		}
		else if(out[i] == 0){
			testValues[i] = 2;
		}
		else{
			testValues[i] = 0;
		}
	}

 	for(int k = 0; k< 10; k++){
 		for(int i = 0; i<testValues.size(); i++ ){
 			if(testValues[i] == 1){
 				for(int j = 0; j< adjacencyMatrix[i].size(); j++){
 					if(out[i] + adjacencyMatrix[i][j] < out[j] || out[j] < 0){
 						if(adjacencyMatrix[i][j] == -1){
 						}
 						else{
 							out[j] = out[i] + adjacencyMatrix[i][j];
 						}
 					}
 				}
 			}
 			testValues[i] = 2;
 		}
 	}
	
  return out;
}
