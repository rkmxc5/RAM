//Name: Mathew Pollard
//Class:cs 53
//section: C
//date:11/3/2013
//This program is the customer class

#include "customer.h"
#include "business.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>



using namespace std;

customer::customer()
{
  m_name="John Doe";
  for(int i=0;i<BAG;i++)
    m_purchases[i]=" ";
  m_money=(rand()%MOD)+MONEY;
  m_numberp=0;
}

customer::customer(const string name, const float money)
{
  m_name=name;
  m_money=money;
  for(int i=0;i<BAG;i++)
    m_purchases[i]=" ";
  m_numberp=0;
}

bool customer::purchase(const string& item)
{
  bool transaction;
  if(m_money>=COST && m_numberp<BAG)
  {
    m_purchases[m_numberp]=item;
    m_money-=COST;
    m_numberp++;
    transaction=true;
  }
  if(m_money<COST || m_numberp>BAG)
    transaction=false;
    
  return(transaction);
}

void customer::changeMoney(const float change)
{
  m_money+=change;
  return;
}

void customer::print()
{
  cout<<m_name<<" $"<<m_money<<" purchases:";
  for(int i=0;i<m_numberp;i++)
    cout<<" "<<m_purchases[i];
  cout<<endl;
  return;
}

  
