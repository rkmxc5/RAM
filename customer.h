//Name: Mathew Pollard
//Class:cs 53
//section: C
//date:11/3/2013
//This program is the customer class


#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "product.h"

const int BAG=20;//size of the customers bag
const int HAPPY=101;//mod for the happiness variable
const int MOD=247;//mod for amount of money
const int MONEY=4;//shift for money amount
const int BUY=2;//mod if the customer will buy something or not
const int BOUGHT=15;//increment to happiness if they buy an item
const int POOR=10;//increment if they could not afford to buy something
const int VICT=-20;//increment if they get hit by something or something stole
const int WINHIT=5;//increment if they hit someone
const int FAILHIT=-25;//increment if they can not throw


using namespace std;

class customer
{
  private:
  int m_happiness;
  bool m_inclination;//false is bar, true is comic book shop
  product m_purchases[BAG];
  short m_numberp;//number of purchases
  float m_money;
  string m_name;
  
  public:
  //desc: adds a string to the purchases and number of purchases
  //pre:none
  //post:returns a bool if the purchase was successful,
  //     and adds the purchase to purchases and adds one to numberp
  bool buySomething(product& item);
 
  //desc: setters for name and money members
  //pre: none
  //post: setts a value in the money and name member
  string getName() const {return m_name;}
  float getMoney() const {return m_money;}
  int getHappy() const {return m_happiness;}
  bool getInclination() const {return m_inclination;}
  short getNumberp() const {return m_numberp;}
  product getItem(const int spot) const {return m_purchases[spot];}
  
  //desc: mutators for member variables
  //pre:none
  //post:changes the value the member variable
  void changeHappy(const int change);
  void changeMoney(const float change);
  void makeItem(const product change, const int spot);
  void setName(const float name);
  void setInclination(const bool inc);
  
  //desc:simulates throwing a product at another customer (or self)
  //pre:none
  //post:removes the item from inventory and changes happiness based on success
  void deathBeam(customer& neighbour);//made it deathBeam because throw is taken and because
  
  //desc: simulates stealing a product from another customer
  //pre:none
  //post: adds an item to inventory and removes one from the given
  //    : changes happiness
  void steal(customer& neighbour);
  //desc:constructors for customer
  //pre:none
  //post: gives values to the private members of customer
  customer ();

  //desc: overloading of insertion operator
  //pre:none
  //post: allows for use of << operator
  friend ostream& operator << (ostream& stream, customer& person);
  
  
};
  
  

#endif