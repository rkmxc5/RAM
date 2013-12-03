//------------------------------driver.cpp-------------------------------------
// Programmer: Andrea Moore
// Class: CSc53 Section C
// Duet Date: 12/04/13
//-----------------------------------------------------------------------------
//Program Description: Program runs the real world business venture simulation.
// It will have customers enter businesses, make purchases and interact in not 
// so friendly manners with one another. Some will go crazy and have to leave 
// the "beautiful" town of Springfield while others will be forced to stay in 
// this godforsaken place! Woohoo! At the end the group who is happiest (people
// who left vs. people who stayed) will be declared the winner!

#include "business.h"
#include "customer.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

const int NUM_PEOPLE = 20;

int main()
{
  //seed random number generator
  srand(time(NULL));

  //Variable declarations
  ifstream fin;
  string name;
  int counter = 0; //counts # of times loop has been run
  int stay_happy = 0; //happiness of people who stay in Sprinfield
  int leave_happy =0; //happiness of people who leave Springfield
  int inclination; //stores the inclination of the customers
  int goodbye_people = NUM_PEOPLE;
  int hold_rand; //holds random number
  customer hold_cust; //holds customer as array is shuffled
  customer street1[NUM_PEOPLE];//putting the people back into street 
  customer street2[NUM_PEOPLE];//putting the people back into street

  //Create two businesses. Comic book shop and Moe's Bar
  business store1;
  store1 = business("Comic Book Shop", 699.00);
  business store2;
  store2 = business("Moe's Bar", 450.25);

  //Create array of customers and fill from text file
  customer springfield_residents[NUM_PEOPLE];
  fin.open("people.txt");

  for(int i=0; i < NUM_PEOPLE; i++)
  {
    getline(fin, name, ',');
    fin >> inclination;
    springfield_residents[i] = customer();
    springfield_residents[i].setName(name);
    springfield_residents[i].setInclination(inclination);
  }
  
  fin.close();

  //outputs the initial array of customers
  for(int i=0; i < NUM_PEOPLE; i++)
  {
    cout << springfield_residents[i];
  }

  
 do
 {
  //Have customers enter store they prefer
  for(int i=0; i < NUM_PEOPLE; i++)
  {
    if(springfield_residents[i].getInclination() == -1)
    {
      store2.addCustomer(springfield_residents[i]);
    }
    else
    {
      store1.addCustomer(springfield_residents[i]);
    }
  }
   //Have both stores make sales for all customers
   store1.sellStuff();
   store2.sellStuff();

  //customers leave store
  int spot=0;
  int place=0;
  spot=store1.getNumberPeople();
  place=store2.getNumberPeople();
  store1.customersLeave(street1, spot);
  store2.customersLeave(street2, place);
  for(int i=0; i<spot;i++)
  { 
   springfield_residents[i]=street1[i];
  }
  place+=spot;
  for(int i=spot; i<place;i++)
  { 
   springfield_residents[i]=street2[i-spot];
  }
  
  //Shuffles array
   for(int i=0; i < goodbye_people; i++)
   {
     hold_rand = rand() % goodbye_people;
     hold_cust = springfield_residents[i];
     springfield_residents[i] = springfield_residents[hold_rand];
     springfield_residents[hold_rand] = hold_cust;
   }

   //Make the people interact
   for(int i=0; i < goodbye_people; i++)
   {
     hold_rand = rand() % goodbye_people;
     if(springfield_residents[i].getInclination() == 
   	    springfield_residents[hold_rand].getInclination() )
     {
       springfield_residents[i].steal(springfield_residents[hold_rand]);	
     }
     else
     {
       springfield_residents[i].deathBeam(springfield_residents[hold_rand]);
     }
   }

   //Goes through array and removes them if happiness is below 10 and above 90
   for(int i=0; i < goodbye_people; i++)
   {
     if(springfield_residents[i].getHappy() < 10 || 
     	springfield_residents[i].getHappy() > 90)
     {
       hold_cust = springfield_residents[i];
       springfield_residents[i] = springfield_residents[goodbye_people];
       springfield_residents[goodbye_people] = hold_cust;
       goodbye_people--;
       i--;
       cout << springfield_residents[i].getName();
       cout << " has gone bonkers and have been shipped to ";
       cout << " Shelbyville's House of crazies for your protection." << endl;
     }
     else
     {
       cout << "Hey! " << springfield_residents[i].getName() << " isn't crazy!";
       cout << endl;
     }
   }

   counter++;
 } while(goodbye_people > 1 && counter < 20);

 //tallies up happiness for people who stayed in springfield
 for(int i=0; i < goodbye_people; i++)
 {
   stay_happy += springfield_residents[i].getHappy();
 }

 //tallies up happiness for people who left springfield
 for(int i=goodbye_people; i < NUM_PEOPLE; i++)
 {
   leave_happy += springfield_residents[i].getHappy();
 }

 //Output results of which group has the highest total happiness
 if(stay_happy > leave_happy)
 {
   cout << "The people who stayed in Springfield are the happiest!" << endl;
   cout << "They have won the Real World Business Adventure!!!" << endl;
   cout << "-Throws confetti sarcastically-";
 }
 else
 {
   cout << "The people who left Springfield are the happiest!" << endl;
   cout << "But they're crazy, so who cares?!";
   cout << "They have won the Real World Business Adventure!" << endl;
   cout << "-Throws confetti sarcastically-";
 }
  return 0;
}

