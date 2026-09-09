#include <iostream>
using namespace std;

int main() {
    int N = 0;
     
    cout << "How many students? ";
    cin >> N;

    // Checking if valid
    if (N > 2 && N < 20) {
      cout << "Valid \n";

      int studentPoints[N];
      int i;

      // loop through every student to get data
      for ( i = 0; i < N ; i++ ) {
        cout << "Nhap Diem student " << i << " : " "\n";
        cin >> studentPoints[i];
      }
      // loop through every student to print failures and successful students
      for ( i = 0; i <  N ; i++) {
        if (studentPoints[i] < 5) {
          cout << "Student" << i << " : Failure! "; 
        } else if (studentPoints[i] > 5 ) {
          cout << "Student" << i << " : Passed! "; 
        } 
      }


      
    } else { cout << "Invalid must be between 2 and 20 "; }
}