//Name: Mathew Pollard
//Class:cs 53
//section: C
//date:11/3/2013
//This program is the business class

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

void business::enterCustomer(const customer& sucker)
{
  m_people[m_numberPeople]=sucker;
  m_numberPeople++;
  return;
}

void business::makeAsale()
{
  int pick;
  bool sale;
  
  for(int i=0; i<m_numberPeople;i++)
  {
    pick=rand()%m_numberInvent;
    sale=m_people[i].purchase(m_inventory[pick]);
    if(sale==true)
      m_money+=COST;
  }
  return;
}

business:: business()
{
  customer sucker;
  m_name=" ";
  m_money=0;
  m_numberPeople=0;
  m_numberInvent=STOCK;
  for(int i=0; i<STOCK;i++)
    m_inventory[i]=" ";
  for(int i=0;i<COP;i++)
    m_people[i]=sucker; //just used sucker for the default empty spot name just because
}

business:: business(const string name, const float money)
{
  customer sucker;
  ifstream f1 ("inventory.txt");
  m_name=name;
  m_money=money;
  m_numberPeople=0;
  m_numberInvent=STOCK;
  for(int i=0; i<STOCK;i++)
    f1>>m_inventory[i];
  for(int i=0;i<COP;i++)
    m_people[i]=sucker;
  f1.close();
}

  
  
    
    