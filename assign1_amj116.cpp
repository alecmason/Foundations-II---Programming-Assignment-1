/*
File name: assign1_amj116.cpp
Author: Alec (Mason) Jones
Date: 2016-09-13
Assignment Number: 1
CS 2308.001 Fall 2016
Instructor: Jill Seaman

Description: Burger Cafe. Display food item and corresponding prices.
Accept input from user and print to screen total amount with tax.
*/



#include <iostream>
#include <iomanip>

using namespace std;

struct Menu {
  string foodItem;
  float itemPrice; 
};

// Only displays order number+1, food item, and food item price
void showMenu(Menu menuItems[]) {

  cout << endl;
  
  for (int i = 0; i < 5; i++) {
    cout << i + 1 << " "
	 << setw(15) << left  << menuItems[i].foodItem << " "
	 << fixed << setprecision(2) << "$"
	 << menuItems[i].itemPrice << endl;
  }
  cout << "Make your selections by number." << endl;
  cout << "Enter a number more than once to place multiple orders." << endl;
  cout << "When you are done, type '0'" << endl;
  cout << endl;
}

// accepts user's integer input as string, then converts and places
// into the order[] array
void getOrder(int order[]) {
  
  string customerOrder = " ";
  cin >> customerOrder;

  for (int i = 0; i < customerOrder.length(); i++)
    order[i] = customerOrder[i] - '0';
}

// outputs the user's order and calculates total amount + tax
void printCheck(Menu menuItems[], int order[], float TAX) {
  float amountDue, calcTax = 0.00;
  
  cout << "Order Receipt:" << endl;
  cout << endl;

  for (int i = 0; order[i]; ++i) {
    cout << setw(15) << left << menuItems[order[i]-1].foodItem << " "
	 << fixed << setprecision(2) << "$"
	 << menuItems[order[i]-1].itemPrice
	 << endl;
    amountDue += menuItems[order[i]-1].itemPrice;
      }

  calcTax = TAX * amountDue;

  
  cout << "Tax: $"
       << calcTax << endl;
  cout << "Amount due: $"
       << amountDue + calcTax << endl;
}

int main () {

  const float TAX = 0.08;
  
  Menu menuItems[5] = {
    {"Cheeseburger", 2.65},
    {"Hamburger", 2.25},
    {"French Fries", 1.35},
    {"Coke", 1.75},
    {"Beer", 3.00}
  };

  int order[] = {};
  
  cout << "Burger Cafe Menu" << endl;
  showMenu(menuItems);
  getOrder(order);
  printCheck(menuItems, order, TAX);

   return 0;
}
