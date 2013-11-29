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
  for(int i=0;i<BAG;i++)
    m_purchases[i]=" ";
  m_money=(rand()%MOD)+MONEY;
  m_numberp=0;
  m_happiness=rand()%HAPPY;
}

customer::customer(const string name, const float money)
{
  m_name=name;
  m_money=money;
  for(int i=0;i<BAG;i++)
    m_purchases[i]=" ";
  m_numberp=0;
  m_happiness=rand()%HAPPY;
}

bool customer::buySomething(business& shop)
{
  bool transaction;
  bool buy;
  int choice;
  product item;
  
  buy=rand()%BUY;
  if(buy==true)
  {
    choice=rand()%STOCK+1;
    item=shop.getProduct(choice)
    if(m_money>=item.price && m_numberp<BAG)
    {
      m_purchases[m_numberp]=item;
      m_money-=COST;
      m_numberp++;
      transaction=true;
      m_happiness+=BOUGHT;
    }
    if(m_money<COST || m_numberp>BAG)
    {
      transaction=false;
      m_happiness-=POOR;
  }
  else
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

  
