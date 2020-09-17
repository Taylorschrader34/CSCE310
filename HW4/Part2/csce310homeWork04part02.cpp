/*
 * csce310homeWork04part02.cpp
 *
 *  Created on: Oct 31, 2018
 *      Author: Taylor
 */
#include "csce310homeWork04part02.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

unsigned long long int lucasNumber( unsigned long long int n ){

	unsigned long long int Back_two = 2;
	unsigned long long int Back_one = 1;
	unsigned long long int Newest = 1;

	for( unsigned long long int k = 3; k <= n +1; k++){
		Newest = Back_one + Back_two;
		Back_two = Back_one;
		Back_one = Newest;
	}
	return Newest;
}
