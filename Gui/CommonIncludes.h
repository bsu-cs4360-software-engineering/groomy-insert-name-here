#pragma once

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstring>

#include "bcrypt.h"
#include <filesystem>

using namespace std;
using json = nlohmann::json;


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
