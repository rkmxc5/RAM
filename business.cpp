//Name: Mathew Pollard
//Class:cs 53
//section: C
//date:11/3/2013
//This program is the business class

#include "product.h"
#include "business.h"
#include "customer.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;


void business::print()
{
  cout<<"Business name: "<<m_name<<endl;
  cout<<"Money in register: "<<m_money<<endl;
  cout<<"Inventory: ";
  for(int i=0;i<m_numberInvent;i++)
    cout<<m_inventory[i]<<" ";
  cout<<endl;
  
}

void business::addCustomer(customer& sucker)
{
  m_people[m_numberPeople]=sucker;
  m_numberPeople++;
  return;
}

void business::sellStuff()
{
  bool sale;
  product item;
  int choice;
  
  choice=rand()%m_numberInvent;
  item=m_inventory[choice];
  for(int i=0; i<m_numberPeople;i++)
  {
    sale=m_people[i].buySomething(item);
    if(sale==true)
    {
      m_money+=item.price;
    }
  }
  return;
}

void business::customersLeave(customer street[], const int numberPeople)
{
  for(int i=0; i<numberPeople; i++)
    street[i]=m_people[i];
  
  return;
}


business:: business()
{
  customer sucker;
  m_name=" ";
  m_money=0;
  m_numberPeople=0;
  m_numberInvent=STOCK;
  for(int i=0;i<COP;i++)
    m_people[i]=sucker; //just used sucker for the default empty spot name just because
}

business:: business(const string name, const float money)
{
  customer sucker;
  m_name=name;
  m_money=money;
  m_numberPeople=0;
  m_numberInvent=STOCK;
  for(int i=0;i<COP;i++)
    m_people[i]=sucker;
}


  
    
    