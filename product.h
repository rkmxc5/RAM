#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
using namespace std;
struct product
{
  string name;
  float price;

  //desc: overloading of insertion operator
  //pre:none
  //post: allows for use of << operator
  friend ostream& operator << (ostream& stream, product& p);
  
   //desc: overloading of insertion operator
  //pre:none
  //post: allows for use of >> operator
  //friend ifstream& operator >> (ifstream& stream, product& p);
  
};
#endif