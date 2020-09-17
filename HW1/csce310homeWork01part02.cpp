#include "csce310homeWork01part02.h"
#include <iostream>
#include <math.h>

using namespace std;

void printPrimes( unsigned short int num )
{
	
	int total [num];
	for(int i = 2; i <=num + 1; i++){
		total[i-2] = i;
	}
	
	int total_size = sizeof(total) / sizeof(total[0]);
	
	for(int j = 0; j<= total_size - 1; j++){
		if( total[j] != 0){
			for(int k = j + 1; k <= total_size -1; k++){
				if(total[k] % total[j] == 0){
					total[k] = 0;
				}
			}
		}
	}
	
	for(int l = 0; l < total_size -1; l++){
		if(total[l] != 0){
			cout << total[l] << endl;
		}
	}
	
	
  return;
}