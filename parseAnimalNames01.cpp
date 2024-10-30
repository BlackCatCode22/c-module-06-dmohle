#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    cout << "\n **** Welcome to parsing Animal Names ******" << endl;

    string myStr = "";
    string fileName = "";
    int myPause = 0;

    // Open a file for reading.
    ifstream myAnimalFile("C:/Users/BE129/dataFiles/animalNames.txt");1
    fileName = "animalNames.txt";

    // Check if the file opened correctly
    if (!myAnimalFile) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;  // Exit if the file could not be opened.
    }

    // Read the file one line at a time.
    while (getline(myAnimalFile, myStr) && myPause < 2) {
        cout << "\n  " << myStr;
        cout << " \n Enter 1 for next line, 2 to stop: ";
        cin >> myPause;
    }
    cout << "\n\n *********** end of while loop reading file a line at a time **********\n\n";

    // return to top of file
    myAnimalFile.clear();
    myAnimalFile.seekg(0);

    // Prove that clear() and seekg(0) worked.
    getline(myAnimalFile, myStr);
    cout << myStr;

    // Count the number of lines in the file
    int numOfLines = 0;  // Start with 0 instead of 1
    while (getline(myAnimalFile, myStr)) {
        numOfLines++;
    }
    cout << "\n  There are " << numOfLines << " lines in the file!";

    if (numOfLines == 0) {
        cerr << "Error: The file is empty!" << endl;
        return 1;  // Exit if the file is empty.
    }

    // Create an array to hold the lines of the file.
    string myAnimalFileArray[numOfLines];

    // Return to the top of the file and read each line into the array.
    myAnimalFile.clear();
    myAnimalFile.seekg(0);
    for (int i = 0; i < numOfLines; i++) {
        getline(myAnimalFile, myAnimalFileArray[i]);
    }

    // let's see how our animal names look in an array...
    cout << "\n********* The Animal Name File Array *********\n";
    for (int i = 0; i < numOfLines; i++) {
        cout << endl << myAnimalFileArray[i];
    }

    cout << "\n\n\n";

    // create two variables needed for array searching
    string speciesName = "";
    string arrayElementFirstWord = "";

    // Find the Hyena Names
    speciesName = "Hyena";
    // find the first blank space in the array element
    int firstSpace = myAnimalFileArray[0].find(" ");
    cout << "\n the first space is at ..." << firstSpace;

    if (firstSpace != string::npos) {
        arrayElementFirstWord = myAnimalFileArray[0].substr(0, firstSpace);
    } else {
        arrayElementFirstWord = myAnimalFileArray[0];  // If no space, take the whole word
    }

    cout << "\n arrayElementFirstWord = " << arrayElementFirstWord;

    // Compare strings directly using the C++ string comparison operator
    if (speciesName == arrayElementFirstWord) {
        cout << "\n strings are equal!";
    } else {
        cout << "\n strings are NOT NOT NOT equal!";
    }

    // Return to top of file
    myAnimalFile.clear();
    myAnimalFile.seekg(0);

    // Close the file
    myAnimalFile.close();

    return 0;
}
