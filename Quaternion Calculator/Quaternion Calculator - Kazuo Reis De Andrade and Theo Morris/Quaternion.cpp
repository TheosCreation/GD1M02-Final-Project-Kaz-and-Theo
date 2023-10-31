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
    double real, i, j, k;
    while (file >> line) {
        for (int a = 0; a < line.size(); a++)
        {
            switch (line[a])
            {
            case 'i':
                i = line[a - 1];
                real = line[a - 3];
                break;
            case 'j':
                j = line[a - 1];
                break;
            case 'k':
                k = line[a - 1];
                break;
            default:
                break;
            }
        }
    }
    Quaternion q(real, i, j, k);
    *this = q;

    file.close();
}