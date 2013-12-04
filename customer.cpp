//Names: Mathew Pollard, Rachel Miller, Andrea Moore
//Class:cs 53
//section: C
//date:11/3/2013
//Filename: customer.cpp

#include "product.h"
#include "customer.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>



using namespace std;

customer::customer()
{
  m_money=(rand()%MOD)+MONEY;
  m_numberp=0;
  m_happiness=rand()%HAPPY;
}

void customer::deathBeam(customer& neighbour)
{
  int spot;
  int place;
  product item;
  
  if(m_numberp>0)
  {
    
    spot=rand()%m_numberp;
    item=m_purchases[spot];
    for(int i=spot; i<m_numberp-1;i++)
    {
      place=i+1;
      m_purchases[spot]=m_purchases[place];
    }
    m_numberp--;
    neighbour.changeHappy(VICT);
    changeHappy(WINHIT);
    cout<<m_name<<" threw a " <<item<<" at "<<neighbour.getName() << endl;
  }
  else
    changeHappy(FAILHIT);
    
  return;
}


void customer::steal(customer& neighbour)
{ 
  int spot;
  int place;
  int win;
  product item;
  
  if(neighbour.getNumberp()>0 && m_numberp<BAG)
  {
    spot=rand()%neighbour.getNumberp();
    item=neighbour.getItem(spot);
    for(int i=spot;i<neighbour.getNumberp()-1;i++)
    {
      place=spot+1;
      neighbour.makeItem(neighbour.getItem(place), spot);
    }
    m_numberp++;
    m_purchases[m_numberp]=item;
    neighbour.changeHappy(VICT);
    win=0-FAILHIT;
    changeHappy(win);//fail hit was the same amount so I just reused it
    cout<<m_name<<" stole a" <<item<<" from "<<neighbour.getName();
  }
  else
  {
    win=0-WINHIT;
    changeHappy(win);//same amount as need so just reused
  }
  
  return;
}
  

bool customer::buySomething(product& item)
{
  bool transaction;
  bool buy;
  
  buy=rand()%BUY;
  if(buy==true)
  {
    if(m_money>=item.price && m_numberp<BAG)
    {
      m_purchases[m_numberp]=item;
      m_money-=item.price;
      m_numberp++;
      transaction=true;
      m_happiness+=BOUGHT;
    }
    if(m_money<item.price || m_numberp>BAG)
    {
      transaction=false;
      m_happiness-=POOR;
    }
  }
  else
    transaction=false;
  
  return transaction;
}

void customer::changeMoney(const float change)
{
  m_money+=change;
  return;
}

void customer::changeHappy(const int change)
{
  m_happiness+=change;
  return;
}

void customer::makeItem(const product change, const int spot)
{
  m_purchases[spot]=change;
  return;
}

void customer::setName(const string name)
{
  m_name=name;
  return;
}

void customer::setInclination(const int inc)
{
  m_inclination=inc;
  return;
}
  


ostream& operator << (ostream& stream, customer& person)
{
  cout<<person.m_name<<" With Happiness: "<<person.getHappy()
      <<" $"<<person.m_money<<" purchases:";
  for(int i=0;i<person.getNumberp();i++)
    cout<<" "<<person.m_purchases[i];
  cout<<endl;
  return stream;
}

  
