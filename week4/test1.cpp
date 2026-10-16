#include <iostream>
using namespace std;

void inputStudent(string studentNames[], int studentIds[], int studentPhones[]) {
    int studentNum = 0;
    int i;
    
    cout << "Input amount of student";
    cin >> studentNum;

    if (studentNum > 0) {
      string studentNames[studentNum];
      int studentIds[studentNum];
      int studentPhones[studentNum];  
      for ( i = 0; i < studentNum; i++ ) {
        cout << "Nhap ten student " << i << " : " ;
        getline(cin, studentNames[i]);
        cout << "Nhap Id student " << i << " : " ;
        cin >> studentIds[i];
        cout << "Nhap Phone student " << i << " : " ;
        cin >> studentPhones[i];
      }
    }
}    


int main() {
  cout << "Hello C++";
  inputStudent( studentNames,  studentIds,  studentPhones);
}