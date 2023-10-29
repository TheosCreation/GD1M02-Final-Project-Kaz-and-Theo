#include "Quaternion.h"

Quaternion::~Quaternion()
{
}

void Quaternion::PrintQuaternion()
{
    std::cout << "[" << m_QuaternionArray[0] << ", " << m_QuaternionArray[1] << "i, " << m_QuaternionArray[2] << "j, " << m_QuaternionArray[3] << "k]" << std::endl;
}

void Quaternion::LoadFromFile(const char* _Filename, LoadedValues _ValueType) {
    std::ifstream file(_Filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double real, i, j, k;
        char plus_minus; // To read the '+' or '-' symbols

        if (_ValueType == QuaternionA) {
            iss >> real >> plus_minus >> i >> plus_minus >> j >> plus_minus >> k;
        }
        else if (_ValueType == QuaternionB) {
            iss >> real;
            i = 0.0;
            j = 0.0;
            k = 0.0;
        }
        else {
            std::cerr << "Error: Invalid value type specified." << std::endl;
            return;
        }

        if (iss) {
            // Successfully read the values from the line
            // Now, create a Quaternion using these values
            Quaternion q(real, i, j, k);
            *this = q;
            // Do something with the loaded Quaternion, e.g., store it in a container
        }
        else {
            std::cerr << "Error: Invalid line format in the file." << std::endl;
        }
    }

    file.close();
}