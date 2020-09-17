/*
 * csce310homeWork04part03.cpp
 *
 *  Created on: Nov 11, 2018
 *      Author: Taylor
 */

#include "csce310homeWork04part03.h"
#include <math.h>

using namespace std;

double payLoan( int principal , double interest , int years ){
	double out = (ceil((((principal * interest * pow(1+interest, years) ) / (pow(1+interest,years) - 1))*100)))/100;
  return out;
}
