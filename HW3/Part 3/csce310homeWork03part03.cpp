/*
 * csce310homeWork03part03.cpp
 *
 *  Created on: Oct 11, 2018
 *      Author: Taylor
 */

#include <vector>
#include "csce310homeWork03part03.h"
#include <cmath>
#include <iostream>

using namespace std;

vector< vector<double> > allPairsSP( vector< vector<double> > adjacencyMatrix , int p ){

	vector< vector<double> > Temp(adjacencyMatrix.size(), vector<double>(adjacencyMatrix.size()) );

	//Sets all -1 to INF
	for(int s = 0; s< adjacencyMatrix.size(); s++){
		for(int t = 0; t<adjacencyMatrix[s].size(); t++){
			if(adjacencyMatrix[s][t] == -1){
				adjacencyMatrix[s][t] = 2147483645;
			}
		}
	}

	//Iteration loop
	for(int k = 0; k < p; k++){
		//copies the iteration row and col of adjacencyMatrix to Temp
		for(int m = 0; m< adjacencyMatrix[k].size(); m++){
			Temp[k][m] = adjacencyMatrix[k][m];
			Temp[m][k] = adjacencyMatrix[m][k];
		}

		//loops through and performed Floyds Algorithm: j = col, i = row
		//Based on algorithm learned in 235H
		for(int j = 0; j< Temp.size(); j++){

			//checks to see if we are at the iteration col and if so skips
			if( j == k){
				continue;
			}

			for(int i = 0; i< Temp.size(); i++){
				//checks to see if we are at the iteration row and if so skips
				if(i == k){
					continue;
				}
				//checks to see if there is a more efficient route and if so adds it to temp
				else if(adjacencyMatrix[j][i] > adjacencyMatrix[j][k] + adjacencyMatrix[k][i]){
					Temp[j][i] = adjacencyMatrix[j][k] + adjacencyMatrix[k][i];
				}
				//If none of that adds the current spot in adjacencyMatrix to Temp
				else{
					Temp[j][i] = adjacencyMatrix[j][i];
				}
			}
		}

		//Copies Temp to adjacencyMatrix
		for(int r = 0; r< adjacencyMatrix.size(); r++){
				for(int t = 0; t< adjacencyMatrix[r].size(); t++){
					adjacencyMatrix[r][t] = Temp[r][t];
				}
			}
	}
  return adjacencyMatrix;
}
