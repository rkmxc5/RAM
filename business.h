//Name: Mathew Pollard
//Class:cs 53
//section: C
//date:11/3/2013
//This program is the business class


#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "customer.h"
#include "product.h"
const int INVENT=10;//size of inventory 
const int COP=10;//capacity of the store
const int COST=40;//cost of purchase
const int STOCK=7;//items in inventory

using namespace std;


class business
{
  private:
  string m_name;
  float m_money;
  product m_inventory[INVENT];
  customer m_people[COP];
  short m_numberInvent;
  short m_numberPeople;
  
  public:
  //desc: getter for member variables
  //pre:none
  //post:returns member variable
  void getNumberPeople() const {return m_numberPeople;}
  
  //desc: prints the business class to the screen
  //pre: none
  //post: prints the business class to the screen
  void print();
  
  //desc:walks through the stores inventory and picks one of the items
  //pre:choice must be smaller than the size of the array (INVENT)
  //post: returns the product
  product getProduct(const int choice) {return(m_inventory[choice]);}
  
  //desc: adds a customer to the people array and increases the numberPeople
  //pre: none
  //post: changes the array of customer and numberPeople
  void addCustomer(customer& sucker);
  
  //desc: makes a sale to as many customers as possible
  //pre: none
  //post: adds an item to the customer class and adds money to the money
  void sellStuff();
  
  //desc: removes a customer to the people array and decreases the numberPeople
  //pre: none
  //post: changes the array of customer and numberPeople
  void customersLeave(customer street[], const int numberPeople);
  
  //desc:constructors for business
  //pre:file inventory.txt must be exit
  //post: gives values to the private members of business
  business(const string nameer, const float moneys);
  business();
  
};



#endif