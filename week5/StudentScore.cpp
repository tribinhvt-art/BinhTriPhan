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
      for ( i = 1; i < N ; i++ ) {
        cout << "Nhap Diem student " << i << " : " "\n";
        cin >> studentPoints[i];
      }

      int Passed;
      int Failures;

      // loop through every student to print failures and successful students
      for ( i = 1; i <  N ; i++) {
        if (studentPoints[i] < 5) {
          cout << "Student" << i << " : Failure! "; 
          Failures = Failures + 1;
        } else if (studentPoints[i] > 5 ) {
          cout << "Student" << i << " : Passed! "; 
          Passed = Passed + 1;
        } 
      }

      cout << "====== Statistics ======" ;
      cout << "                        " ;
      cout << "Passed: " << Passed << "Students";
      cout << "Failed: " << Failures << "Students";

      // loop through every student to find highest score and lowest score 
      int highest = 0;
      int lowest = 10;
      for ( i = 1; i <  N ; i++) {
        if (studentPoints[i] > highest) {
          highest = studentPoints[i];
        } 
        if (studentPoints[i] < lowest) {
          lowest = studentPoints[i];
        } 
      }
      
    } else { cout << "Invalid must be between 2 and 20 "; }
}