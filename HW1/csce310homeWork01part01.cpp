#include "csce310homeWork01part01.h"
#include <math.h>
#include <string>

using namespace std;

unsigned long long int fromBaseFive( string number ){
  unsigned long long int num = 0;
  int count = 0;
  int temp =0;
  for (int i=number.length() - 1; i>=0; i--){
	  temp = (number[i] - '0');
	  num = num + (temp * (pow(5, count)));
	  count = count + 1;
  }
  return num;
}
