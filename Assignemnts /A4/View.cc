// Mihir Gupta
// 101172281

#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice)
{
  int numOptions = 4;

  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Print reservations" << endl;
  cout << "  (2) Print room information" << endl;
  cout << "  (3) Print guest information" << endl;
  cout << "  (4) Print event records" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}



