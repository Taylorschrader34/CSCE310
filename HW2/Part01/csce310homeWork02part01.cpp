/*
 * csce310homeWork02part01.cpp
 *
 *  Created on: Sep 28, 2018
 *      Author: Taylor
 */

#include "csce310homeWork02part01.h"

#include <vector>

using namespace std;

vector<int> placeNumbers(vector<int> nums, vector<char> signs) {

	vector<int> numsOut(nums.size());
	int numsAtLow = 0;
	int numsAtHigh = nums.size() -1;

	if(signs.at(0) == '>'){
		numsOut[0] = nums.at(numsAtHigh);
		numsAtHigh--;

		for(int i = 1; i < signs.size(); i++){
				if(signs.at(i-1) == '>' && signs.at(i) == '<'){
					numsOut[i] = nums.at(numsAtLow);
					numsAtLow++;
				}
				else if(signs.at(i-1) == '>' && signs.at(i) == '>'){
					numsOut[i] = nums.at(numsAtHigh);
					numsAtHigh--;
				}
				else if(signs.at(i-1) == '<' && signs.at(i) == '>'){
					numsOut[i] = nums.at(numsAtHigh);
					numsAtHigh--;
				}
				else if(signs.at(i-1) == '<' && signs.at(i) == '<'){
					numsOut[i] = nums.at(numsAtLow);
					numsAtLow++;
				}

			}

	}


	else if(signs.at(0) == '<'){
		numsOut[0] = nums.at(0);
		numsAtLow++;

		for(int i = 1; i < signs.size(); i++){
				if(signs.at(i-1) == '>' && signs.at(i) == '<'){
					numsOut[i] = nums.at(numsAtLow);
					numsAtLow++;
				}
				else if(signs.at(i-1) == '>' && signs.at(i) == '>'){
					numsOut[i] = nums.at(numsAtHigh);
					numsAtHigh--;
				}
				else if(signs.at(i-1) == '<' && signs.at(i) == '>'){
					numsOut[i] = nums.at(numsAtHigh);
					numsAtHigh--;
				}
				else if(signs.at(i-1) == '<' && signs.at(i) == '<'){
					numsOut[i] = nums.at(numsAtLow);
					numsAtLow++;
				}
			}
	}

	numsOut[numsOut.size()-1] = nums.at(numsAtLow);

	return numsOut;
}

