#include <iostream>
#include <string>
#include <fstream>
#include "product.h"

using namespace std;


ostream& operator << (ostream& stream, product& p)
{
  cout<<p.name<<"($"<<p.price<<")"<<endl;
  return stream;
}

/*ifstream& operator >> (ifstream& stream, product& p)
{
  string stream;
  g*/
