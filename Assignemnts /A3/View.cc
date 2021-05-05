// Mihir Gupta
// 101172281
#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice)
{
  int numOptions = 3;

  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Compute matches" << endl;
  cout << "  (2) Print animals" << endl;
  cout << "  (3) Print clients" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;

  while (choice < 0 || choice > numOptions) {
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



