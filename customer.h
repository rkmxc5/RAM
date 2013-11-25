//Name: Mathew Pollard
//Class:cs 53
//section: C
//date:11/3/2013
//This program is the customer class

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#ifndef CUSTOMER_H
#define CUSTOMER_H

const int BAG=20;//size of the customers bag
const int MOD=247;//mod for amount of money
const int MONEY=4;//shift for money amount

using namespace std;

class customer
{
  private:
  string m_purchases[BAG];
  short m_numberp;//number of purchases
  float m_money;
  string m_name;
  
  public:
  //desc: adds a string to the purchases and number of purchases
  //pre:none
  //post:returns a bool if the purchase was successful,
  //     and adds the purchase to purchases and adds one to numberp
  bool purchase(const string& item);
 
  //desc: setters for name and money members
  //pre: none
  //post: setts a value in the money and name member
  string getName() const {return m_name;}
  float getMoney() const {return m_money;}
  
  //desc: mutator for money, alters the money amount
  //pre:none
  //post:changes the value of money
  void changeMoney(const float change);
  
  //desc:prints the class
  //pre:none
  //post: outputs the class to the screen
  void print();
  
  //desc:constructors for customer
  //pre:none
  //post: gives values to the private members of customer
  customer ();
  customer (const string name, const float money);
  
};
  
  

#endif