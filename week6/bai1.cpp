#include <iostream>
#include <string>
using namespace std;

void showStudentName(string name) {
    cout << "Hello," << name << "!" << endl;
    cout << "Welcome to our class!" << endl;
}

void showStudentId(string studentId) {
    cout << "Student ID: " << studentId << "!" << endl;
}

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

void printStudentInfo (string studentName, string studentId, double score) {
    cout << "----------------------" << endl;
    cout << "Name:" << studentName << endl;
    cout << "Id:" << studentId << endl;
    cout << "----------------------" << endl;   
}

void showScore (string studentName, string studentId, double score) {
    cout << "----------------------" << endl;
    cout << "Name:" << studentName << endl;
    cout << "Id:" << studentId << endl;
    cout << "Score:" << score << endl;
    cout << "----------------------" << endl;   
}

int maxValue(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}


int main() {
  showWelcome();

  cout << "  Lets get started  " << endl;

  string studentName;
  string studentId;
  double score;

  cout << "Enter your name: " << endl;
  getline(cin, studentName);
  cout << "Enter student id: " << endl;
  cin >> studentId;
  cout << "Enter student score: " << endl;
  cin >> score;

  showMenu();
  showStudentName(studentName);
  showStudentId(studentId);  
  printStudentInfo(studentName, studentId);
  showScore(studentName, studentId, score);

  int a, b;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    int result = maxValue(a, b);

    cout << "Max value: " << result << endl;

  return 0;
}