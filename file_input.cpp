#include <iostream> 
#include <fstream> 
#include <map> 
#include <string> 
using namespace std; 
int main() { 
string filename; 
cout << "Enter filename : "; 
cin >> filename; 
cin.ignore(); // Clear newline buffer 
// 1. Create and write to the file 
ofstream outFile(filename); 
cout << "Enter a sentence to write into the file: "; 
string sentence; 
getline(cin, sentence); // Get full sentence including spaces 
outFile << sentence; 
outFile.close(); 
// 2. Open file for reading 
ifstream inFile(filename); 
if (!inFile) { 
cout << "Failed to open file." << endl; 
return 1; 
} 
// 3. Determine file length 
inFile.seekg(0, ios::end); // Move read pointer to the end 
cout << "\nFile Length: " << inFile.tellg() << " bytes\n"; // Get position (length) 
inFile.seekg(0, ios::beg); // Reset read pointer back to the beginning 
// 4. Count word occurrences using a map 
map<string, int> wordCount; // Map stores word (key) and its frequency (value) 
string word; 
while (inFile >> word) {  
// Read file word by word 
wordCount[word]++;    
} 
// 5. Display the occurrences 
cout << "Word occurrences:\n"; 
for (const auto& pair : wordCount) { 
cout << "\"" << pair.first << "\" - " << pair.second << " times\n"; 
} 
inFile.close(); 
return 0; 
}