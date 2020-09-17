#include "csce310homeWork01part01.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main( int argc , char* argv[] ){
  string num;
  cin >> num;

  try{
    fprintf( stdout , "The quantity of %s is %llu.\n" , num.c_str() , fromBaseFive( num ) );
  }
  catch( exception e ){
    cerr << "An error occurred." << endl;
  }
}
