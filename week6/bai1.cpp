#include <iostream>
#include <string>
using namespace std;

void showWelcome() {
    cout << "==============================" << endl;
    cout << "  Welcome to Student Manager  " << endl;
    cout << "==============================" << endl;
}

void showMenu() {
    cout << "===== MENU =====" << endl;   
    cout << "Show Statistics" << endl;   
    cout << "Exit" << endl;
    cout << "================" << endl;
}


int main() {
  showWelcome();

  cout << "  Lets get started  " << endl;

  showMenu()
  return 0;
}