/*
 * csce310homeWork02part03.cpp
 *
 *  Created on: Sep 30, 2018
 *      Author: Taylor
 */

#include <vector>
#include "csce310homeWork02part03.h"
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

bool sumToN( vector<int> number , int value ){

	bool out = false;
	int finder = 0;
	for(int i = 0; i < number.size(); i++){
		finder =  value - number.at(i);
		if(binary_search(number.begin(), number.end(), finder)){
			out = true;
		}
	}
  return out;
}

