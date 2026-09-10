#include <iostream>
using namespace std;

// ================= FUNCTIONS =================

// Get student scores
void gettingdata(double studentPoints[], int N) {
    for (int i = 0; i < N; i++) {
        cout << "Nhap diem Student " << i + 1 << ": ";
        cin >> studentPoints[i];
    }
}


// Passed / Failed
void failnpass(double studentPoints[], int N) {
    int Passed = 0;
    int Failures = 0;

    for (int i = 0; i < N; i++) {

        if (studentPoints[i] < 5) {
            cout << "Student " << i + 1 << ": Failure!\n";
            Failures++;
        }
        else {
            cout << "Student " << i + 1 << ": Passed!\n";
            Passed++;
        }
    }

    cout << "\nPassed: " << Passed << " students\n";
    cout << "Failed: " << Failures << " students\n";
}


// Highest and lowest
void highestandlowest(double studentPoints[], int N) {

    double highest = studentPoints[0];
    double lowest = studentPoints[0];

    for (int i = 1; i < N; i++) {

        if (studentPoints[i] > highest) {
            highest = studentPoints[i];
        }

        if (studentPoints[i] < lowest) {
            lowest = studentPoints[i];
        }
    }

    cout << "Highest score: " << highest << "\n";
    cout << "Lowest score: " << lowest << "\n";
}


// Exercise 1 - Count excellent students
void excellentStudents(double studentPoints[], int N) {

    int count = 0;

    for (int i = 0; i < N; i++) {

        if (studentPoints[i] >= 9.0) {
            count++;
        }
    }

    cout << "Number of excellent students: " << count << "\n";
}


// Exercise 2 - Students in range
void scoreRange(double studentPoints[], int N) {

    double MINIMUM;
    double MAXIMUM;

    cout << "\nEnter minimum score: ";
    cin >> MINIMUM;

    cout << "Enter maximum score: ";
    cin >> MAXIMUM;

    int student_in_Range = 0;

    for (int i = 0; i < N; i++) {

        if (studentPoints[i] >= MINIMUM &&
            studentPoints[i] <= MAXIMUM) {

            student_in_Range++;
        }
    }

    cout << "Students in range: "
         << student_in_Range << "\n";
}


// ==================================================
// EXERCISE 3
// Find students above average
// ==================================================

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


// ==================================================
// EXERCISE 4
// Find second highest score
// ==================================================

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


// ==================================================
// EXERCISE 5
// Search for a score
// ==================================================

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


// ==================================================
// EXERCISE 6
// Count score frequency
// ==================================================

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


// ==================================================
// EXERCISE 7
// Find first failing student
// ==================================================

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


// ==================================================
// EXERCISE 8
// Compare adjacent students
// ==================================================

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


// ==================================================
// EXERCISE 9
// Longest pass streak
// ==================================================

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


// ==================================================
// EXERCISE 10
// Score distribution
// ==================================================

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


// ================= MAIN =================

int main() {

    int N;

    cout << "How many students? ";
    cin >> N;

    if (N > 2 && N <= 20) {

        cout << "Valid\n\n";

        // Maximum 20 students
        double studentPoints[20];

        gettingdata(studentPoints, N);


        cout << "\n====== Basic Statistics ======\n";

        failnpass(studentPoints, N);

        highestandlowest(studentPoints, N);

        excellentStudents(studentPoints, N);

        scoreRange(studentPoints, N);


        cout << "\n\n====== EXERCISE 3 ======\n";
        aboveAverage(studentPoints, N);


        cout << "\n\n====== EXERCISE 4 ======\n";
        secondHighest(studentPoints, N);


        cout << "\n\n====== EXERCISE 5 ======\n";
        searchScore(studentPoints, N);


        cout << "\n\n====== EXERCISE 6 ======\n";
        scoreFrequency(studentPoints, N);


        cout << "\n\n====== EXERCISE 7 ======\n";
        firstFailingStudent(studentPoints, N);


        cout << "\n\n====== EXERCISE 8 ======\n";
        compareAdjacent(studentPoints, N);


        cout << "\n\n====== EXERCISE 9 ======\n";
        longestPassStreak(studentPoints, N);


        cout << "\n\n====== EXERCISE 10 ======\n";
        scoreDistribution(studentPoints, N);
    }

    else {

        cout << "Invalid! Must be between 3 and 20.\n";
    }

    return 0;
}