#include <string>

using namespace std;

string hashMe(const string& input, int modulus) {
    string result;
    string pepperedInput = input + 'M';

    for (char c : pepperedInput) {
        int asciiValue = static_cast<int>(c); // Convert character to ASCII
        int modValue = asciiValue % modulus; // Apply the modulo operation
        result += to_string(modValue);       // Append the result as a string
    }

    return result;
}

