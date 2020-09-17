/*
 * csce310homeWork02part02.cpp
 *
 *  Created on: Sep 28, 2018
 *      Author: Taylor
 */

#include <vector>
#include "csce310homeWork02part02.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

int overlappingIntervals( vector<int> start , vector<int> end ){

	vector<char> tester;
	vector<int> tRay;
	int variable = 0;
	int max = 0;

	for(int m = 0; m < start.size(); m++){
		tRay.push_back(start.at(m));
		tRay.push_back(end.at(m));
	}

	sort(tRay.begin(), tRay.end());

	for( int n = 0; n < tRay.size(); n++){

		if( binary_search(start.begin(),start.end(), tRay.at(n))){
			tester.push_back('S');
		}
		else {
			tester.push_back('E');
		}

	}

	for(int p = 0 ; p < tester.size(); p++){
		if( tester.at(p) == 'S'){
			variable++;
		}
		else{
			variable--;
		}

		if(variable > max){
			max = variable;
		}
	}

  return max;
}

