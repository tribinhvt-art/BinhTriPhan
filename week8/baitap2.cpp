#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    
    // 1. Read a sentence from the user
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // 2. Display its length
    cout << "Length: " << sentence.length() << endl;

    // 3. Find the position of a word
    string word = "C++";
    size_t pos = sentence.find(word);

    if (pos != string::npos) {
        cout << "\"C++\" found at position: " << pos << endl;
    } else {
        cout << "\"C++\" not found." << endl;
    }

    // 4. Extract and display part of the sentence
    if (pos != string::npos) {
        string part = sentence.substr(pos, word.length());
        cout << "Extracted part: " << part << endl;
    }

    // 5. Replace a word with a new word
    string newWord;
    cout << "Enter a new word to replace C++: ";
    cin >> newWord;

    if (pos != string::npos) {
        sentence.replace(pos, word.length(), newWord);
    }

    // 6. Show the final result
    cout << "Final sentence: " << sentence << endl;

    return 0;
}