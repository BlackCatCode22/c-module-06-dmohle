#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    cout << "\n **** Welcome to Parsing Animal Names With Vectors! ******" << endl;

    string myStr = "";
    string fileName = "C:/Users/BE129/dataFiles/animalNames.txt";  // Corrected file path

    // Open the file for reading.
    ifstream myAnimalFile(fileName);

    // Check if the file opened correctly.
    if (!myAnimalFile) {
        cerr << "Error: Could not open the file at " << fileName << endl;
        return 1;  // Exit if the file could not be opened.
    }

    // Vectors to hold names of each species.
    vector<string> hyenaNames;
    vector<string> lionNames;
    vector<string> bearNames;
    vector<string> tigerNames;

    vector<string>* currentVector = nullptr;  // Pointer to the current species vector.

    // Read the file one line at a time.
    while (getline(myAnimalFile, myStr)) {
        // Find the first non-space character and check if it's a valid position
        size_t firstNonSpace = myStr.find_first_not_of(" ");
        if (firstNonSpace != string::npos) {
            // Trim leading spaces if needed
            myStr = myStr.substr(firstNonSpace);

            // Check if we're starting a new species section.
            if (myStr.find("Hyena Names:") != string::npos) {
                currentVector = &hyenaNames;
            } else if (myStr.find("Lion Names:") != string::npos) {
                currentVector = &lionNames;
            } else if (myStr.find("Bear Names:") != string::npos) {
                currentVector = &bearNames;
            } else if (myStr.find("Tiger names:") != string::npos) {
                currentVector = &tigerNames;
            } else if (currentVector != nullptr && !myStr.empty()) {
                // Process names if we're in a species section.
                stringstream ss(myStr);
                string name;
                while (getline(ss, name, ',')) {
                    // Trim any leading spaces in the name and push it to the current vector.
                    size_t firstChar = name.find_first_not_of(" ");
                    if (firstChar != string::npos) {
                        name = name.substr(firstChar);
                    }
                    currentVector->push_back(name);
                }
            }
        }
    }

    // Close the file
    myAnimalFile.close();

    // Output the contents of each vector (species list)
    cout << "\n**** Hyena Names ****\n";
    for (const auto& name : hyenaNames) {
        cout << name << endl;
    }

    cout << "\n**** Lion Names ****\n";
    for (const auto& name : lionNames) {
        cout << name << endl;
    }

    cout << "\n**** Bear Names ****\n";
    for (const auto& name : bearNames) {
        cout << name << endl;
    }

    cout << "\n**** Tiger Names ****\n";
    for (const auto& name : tigerNames) {
        cout << name << endl;
    }

    return 0;
}
