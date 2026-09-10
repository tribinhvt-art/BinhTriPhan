#include <iostream>
using namespace std;

// functions //


// loop through every student to get data
void gettingdata (double studentPoints[], int N) {
  int i = 0;
  for ( i = 0; i < N ; i++ ) {    
      cout << "Nhap Diem student " << i << " : " "\n";
      cin >> studentPoints[i];
  }
}


// loop through every student to find highest score and lowest score 
void highestandlowest(int highest, int lowest,  double studentPoints[], int N) {
 int i = 0;
 for ( i = 0; i <  N ; i++) {
      if (studentPoints[i] > highest) {
        highest = studentPoints[i];
      } 
      if (studentPoints[i] < lowest) {
        lowest = studentPoints[i];
      }   
  }
  cout << "Highest score: " << highest "\n";
  cout << "Lowest score: " << lowest "\n";
}

// failed and passed
void failnpass(double studentPoints[], int N, int Failures, int Passed) {
 int i;
 for ( i = 0; i <  N ; i++) {
    if (studentPoints[i] < 5) {
      cout << "Student " << i << " : Failure! \n"; 
          Failures = Failures + 1;
    } else if (studentPoints[i] > 5 ) {
      cout << "Student " << i << " : Passed! \n"; 
          Passed = Passed + 1;
    } 
  }
}

// loop through every student to classify
void Classify(double studentPoints[], int N, int Excel_Student) {
  int i = 0;
  for ( i = 0; i <  N ; i++) {
        if (studentPoints[i] > 9 && studentPoints[i] < 10) {
          cout << "student " << i << " Excellence\n";
          Excel_Student = Excel_Student + 1;
        } 
        if (studentPoints[i] > 8 && studentPoints[i] < 9) {
          cout << "student " << i << " Very Good\n";
        } 
        if (studentPoints[i] > 6.5 && studentPoints[i] < 8) {
          cout << "student " << i << " Good\n";
        } 
        if (studentPoints[i] > 5 && studentPoints[i] < 6.5) {
          cout << "student " << i << " Average\n";
        } 
        if (studentPoints[i] < 5) {
          cout << "student " << i << " Fail\n";
        } 
      }
  if (Excel_Student == 0) {
    cout << "IMAGINE NO EXCELLENT STUDENT AHAHAHAHA\n";
  }    
  cout << "Number of excellent students: " << Excel_Student << "\n";    
}

void aboveAverage(double studentPoints[], int N) {

    double total = 0;

    // Calculate total
    for (int i = 0; i < N; i++) {
        total = total + studentPoints[i];
    }

    double average = total / N;

    cout << "\nAverage score: " << average << "\n";

    cout << "Students above average:\n";

    for (int i = 0; i < N; i++) {

        if (studentPoints[i] > average) {

            cout << "Student "
                 << i + 1
                 << ": "
                 << studentPoints[i]
                 << "\n";
        }
    }
}

void secondHighest(double studentPoints[], int N) {

    double highest = -1;
    double second = -1;

    for (int i = 0; i < N; i++) {

        if (studentPoints[i] > highest) {

            second = highest;
            highest = studentPoints[i];
        }

        else if (studentPoints[i] > second &&
                 studentPoints[i] < highest) {

            second = studentPoints[i];
        }
    }

    cout << "\nHighest score: " << highest << "\n";
    cout << "Second highest score: " << second << "\n";
}

void scoreFrequency(double studentPoints[], int N) {

    double x;

    cout << "\nEnter score: ";
    cin >> x;

    int count = 0;

    for (int i = 0; i < N; i++) {

        if (studentPoints[i] == x) {
            count++;
        }
    }

    cout << "Score "
         << x
         << " appears "
         << count
         << " times.\n";
}

void searchScore(double studentPoints[], int N) {

    double search;

    cout << "\nEnter score to search: ";
    cin >> search;

    bool found = false;

    cout << "Found at:\n";

    for (int i = 0; i < N; i++) {

        if (studentPoints[i] == search) {

            cout << "Student " << i + 1 << "\n";

            found = true;
        }
    }

    if (found == false) {
        cout << "Score not found!\n";
    }
}

void firstFailingStudent(double studentPoints[], int N) {

    bool found = false;

    for (int i = 0; i < N; i++) {

        if (studentPoints[i] < 5) {

            cout << "\nFirst failing student:\n";

            cout << "Student "
                 << i + 1
                 << ": "
                 << studentPoints[i]
                 << "\n";

            found = true;

            break;
        }
    }

    if (found == false) {
        cout << "\nAll students pass!\n";
    }
}


void compareAdjacent(double studentPoints[], int N) {

    cout << "\nImproved students:\n";

    for (int i = 1; i < N; i++) {

        if (studentPoints[i] > studentPoints[i - 1]) {

            cout << "Student "
                 << i + 1
                 << " improved compared to Student "
                 << i
                 << "\n";
        }
    }
}

void longestPassStreak(double studentPoints[], int N) {

    int currentStreak = 0;
    int longestStreak = 0;

    for (int i = 0; i < N; i++) {

        if (studentPoints[i] >= 5) {

            currentStreak++;
        }

        else {

            currentStreak = 0;
        }

        if (currentStreak > longestStreak) {

            longestStreak = currentStreak;
        }
    }

    cout << "\nLongest pass streak: "
         << longestStreak
         << " students\n";
}

void scoreDistribution(double studentPoints[], int N) {

    int range1 = 0;
    int range2 = 0;
    int range3 = 0;
    int range4 = 0;
    int range5 = 0;

    for (int i = 0; i < N; i++) {

        if (studentPoints[i] < 5) {

            range1++;
        }

        else if (studentPoints[i] < 6.5) {

            range2++;
        }

        else if (studentPoints[i] < 8) {

            range3++;
        }

        else if (studentPoints[i] < 9) {

            range4++;
        }

        else {

            range5++;
        }
    }

    cout << "\n===== SCORE DISTRIBUTION =====\n";

    cout << "0 - <5   : "
         << range1 << "\n";

    cout << "5 - <6.5 : "
         << range2 << "\n";

    cout << "6.5 - <8 : "
         << range3 << "\n";

    cout << "8 - <9   : "
         << range4 << "\n";

    cout << "9 - 10   : "
         << range5 << "\n";
}

int main() {
    int N = 0;
     
    cout << "How many students? ";
    cin >> N;

    // Checking if valid
    if (N > 2 && N < 20) {
      cout << "Valid \n";

      double studentPoints[N];
      int i;

      // loop through every student to get data
      gettingdata(studentPoints, N);

      //loop through every student to print failures and successful students
      int Passed = 0 ;
      int Failures = 0 ;
      failnpass(studentPoints, N, Passed, Failures);
      
      cout << "\n====== Statistics ======\n";
      cout << "Passed: " << Passed << " Students\n";
      cout << "Failed: " << Failures << " Students\n";

      // loop through every student to find highest score and lowest score 
      int highest = 0;
      int lowest = 10;
      highestandlowest(highest,lowest,studentPoints,N);
      
      

      // loop through every student to classify
      int Excel_Student = 0;
      Classify(studentPoints, N, Excel_Student);
      
      int student_Range;
      int MINIMUM;
      int MAXIMUM;
      cout << "Enter a range of points in the following format MINIMUM < your number < MAXIMUM";
      cin >> MINIMUM;
      cin >> MAXIMUM;
      int i = 0;
      int student_in_Range;
      for (i = 0; i < N; i++ ) {
        if (studentPoints > MINIMUM && studentPoints < MAXIMUM) {
          student_in_Range = student_in_Range + 1;
        }
      }
      cout << "Students in Range: " << student_in_Range;

      secondHighest( studentPoints,  N);
      scoreFrequency(studentPoints, N);
      firstFailingStudent( studentPoints, N );
      compareAdjacent( studentPoints, N);
      longestPassStreak(studentPoints, N)
      scoreDistribution( studentPoints, N)
      
    } else { cout << "Invalid must be between 2 and 20 "; }
}