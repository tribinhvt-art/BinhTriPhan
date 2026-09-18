#include <iostream>
#include <string>
using namespace std;

int main() {
    // ========================================
    // BÀI 1: INSERT A STRING
    // ========================================

    string text1;
    string insertText;
    int position;

    cout << "===== BAI 1: INSERT =====" << endl;

    cout << "Enter original string: ";
    getline(cin, text1);

    cout << "Enter string to insert: ";
    getline(cin, insertText);

    cout << "Enter position: ";
    cin >> position;
    cin.ignore();

    text1.insert(position, insertText);

    cout << "Result: " << text1 << endl;


    // ========================================
    // BÀI 2: FIND A SUBSTRING
    // ========================================

    string text2;
    string sub;

    cout << "\n===== BAI 2: FIND =====" << endl;

    cout << "Enter text: ";
    getline(cin, text2);

    cout << "Enter substring to find: ";
    getline(cin, sub);

    size_t pos = text2.find(sub);

    if (pos != string::npos) {
        cout << "Found at position: " << pos << endl;
    }
    else {
        cout << "Substring not found." << endl;
    }


    // ========================================
    // BÀI 3: COUNT CHARACTERS
    // ========================================

    string text3;

    cout << "\n===== BAI 3: COUNT CHARACTERS =====" << endl;

    cout << "Enter text: ";
    getline(cin, text3);

    int countWithSpaces = text3.length();
    int countWithoutSpaces = 0;

    for (char c : text3) {
        if (c != ' ') {
            countWithoutSpaces++;
        }
    }

    cout << "Count with spaces: "
         << countWithSpaces << endl;

    cout << "Count without spaces: "
         << countWithoutSpaces << endl;


    // ========================================
    // BÀI 4: REPLACE A SUBSTRING
    // ========================================

    string text4;
    string oldWord;
    string newWord;

    cout << "\n===== BAI 4: REPLACE =====" << endl;

    cout << "Enter sentence: ";
    getline(cin, text4);

    cout << "Enter word to replace: ";
    getline(cin, oldWord);

    cout << "Enter new word: ";
    getline(cin, newWord);

    size_t replacePos = text4.find(oldWord);

    if (replacePos != string::npos) {
        text4.replace(
            replacePos,
            oldWord.length(),
            newWord
        );

        cout << "Result: " << text4 << endl;
    }
    else {
        cout << "Word not found." << endl;
    }


    // ========================================
    // BÀI 5: EXTRACT A SUBSTRING
    // ========================================

    string text5;
    int start;
    int length;

    cout << "\n===== BAI 5: EXTRACT =====" << endl;

    cout << "Enter text: ";
    getline(cin, text5);

    cout << "Enter start position: ";
    cin >> start;

    cout << "Enter length: ";
    cin >> length;

    string result = text5.substr(start, length);

    cout << "Result: " << result << endl;


    return 0;
}