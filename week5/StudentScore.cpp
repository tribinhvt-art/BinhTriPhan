#include <iostream>
using namespace std;

int main() {
    int N = 0;
     
    cout << "How many students? ";

    // Checking if valid
    if (N > 2 && N < 20) {
      cout << "Valid";

      int studentPoints[N];
      int i;
      for ( i = 0; i < N ; i++ ) {
        cout << "Nhap Diem studen " << i ;
        cin >> studentPoints[i];
      }
      
    } else { cout << "Invalid must be between 2 and 20 "; }
}