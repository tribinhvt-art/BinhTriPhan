#include <iostream>
using namespace std;

int main() {
    int N = 0;
     
    cout << "How many students? ";
    if (N > 2 && N < 20) {
      cout << "Valid";
      
    } else { cout << "Invalid must be between 2 and 20 "; }
}