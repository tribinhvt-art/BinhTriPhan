#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;

    // 1. Ask the user to enter a sentence
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // 2. Display the length of the sentence
    cout << "Length: " << sentence.length() << endl;

    // 3. Find the position of "C++"
    size_t pos = sentence.find("C++");

    if (pos != string::npos) {

        // 4. Print the word starting from that position using substr()
        string word = sentence.substr(pos, 3);
        cout << "Found at position: " << pos << endl;
        cout << "Word: " << word << endl;

        // 5. Change "C++" to "Programming"
        sentence.replace(pos, 3, "Programming");

        // Display the new sentence
        cout << "New sentence: " << sentence << endl;

    } else {
        cout << "\"C++\" was not found." << endl;
    }

    return 0;
}