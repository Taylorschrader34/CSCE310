#include "csce310homeWork01part02.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main( int argc , char* argv[] ){
  unsigned short int num;
  cin >> num;

  try{
    cout << "primes" << endl;
    printPrimes( num );
  }
  catch( exception e ){
    cerr << "An error occurred." << endl;
  }
}
