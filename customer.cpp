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

void customer::deathBeam(customer& neighbour)
{
  int spot;
  product item;
  
  if(m_numberp>0)
  {
    spot=rand()%m_numberp;
    item=m_purchases[spot];
    m_purchases[spot]=0;
    neighbour.getHappy()-=HIT;
    getHappy()+=WINHIT;
  }
  else
    getHappy()-=FAILHIT;
    
  return;
}

void customer::steal(customer& neighbour)
{ 
  int spot;
  product item;
  
  if(neighbour.getNumberp()>0 && m_numberp<BAG)
  {
    spot=rand()%neighbour.getNumberp();
    item=neighbour.getItem(spot);
    neighbour.getItem(spot)=0;
    m_numberp++;
    m_inventory[m_numberp]=item;
    neightbour.getHappy()-=VICT;
    m_happiness+=FAILHIT;//fail hit was the same amount so I just reused it
  }
  else
    m_happiness-=WINHIT;//same amount as need so just reused
  
  return;
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

customer& operator << (ostream& stream, customer& person)
{
  cout<<m_name<<" $"<<m_money<<" purchases:";
  for(int i=0;i<m_numberp;i++)
    cout<<" "<<m_purchases[i];
  cout<<endl;
  return *this;
}

  
