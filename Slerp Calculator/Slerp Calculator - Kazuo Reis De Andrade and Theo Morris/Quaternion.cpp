#include "Quaternion.h"

Quaternion::~Quaternion()
{
}
Quaternion::Quaternion(float a, float b, float c, float d)
{
    m_QuaternionArray[0] = a;
    m_QuaternionArray[1] = b;
    m_QuaternionArray[2] = c;
    m_QuaternionArray[3] = d;
}

void Quaternion::PrintQuaternion()
{

    std::cout << m_QuaternionArray[0];

    if (m_QuaternionArray[1] >= 0)
        std::cout << " + " << m_QuaternionArray[1] << "i";
    else
        std::cout << " - " << -m_QuaternionArray[1] << "i";

    if (m_QuaternionArray[2] >= 0)
        std::cout << " + " << m_QuaternionArray[2] << "j";
    else
        std::cout << " - " << -m_QuaternionArray[2] << "j";

    if (m_QuaternionArray[3] >= 0)
        std::cout << " + " << m_QuaternionArray[3] << "k";
    else
        std::cout << " - " << -m_QuaternionArray[3] << "k";

    std::cout << std::endl;
}


void Quaternion::LoadFromFile(const char* _Filename, LoadedValues _ValueType) {
    std::ifstream file(_Filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }

    float real = 0.0f;
    float i = 0.0f;
    float j = 0.0f;
    float k = 0.0f;

    for (int lineNum = 0; lineNum < 2 + (_ValueType == QuaternionB); lineNum++) {
        std::string line;
        if (!std::getline(file, line)) {
            break;
        }

        std::istringstream iss(line);
        char plus_minus;
        float value;
        
        iss >> real;

        while (iss >> plus_minus >> value) {
            char component;
            iss >> component;
            std::cout << component;

            if (component == 'i') {
                i = value;
            }
            else if (component == 'j') {
                j = value;
            }
            else if (component == 'k') {
                k = value;
            }
        }
        
    }

    Quaternion q(real, i, j, k);
    *this = q;

    m_QuaternionArray[0] = real;
    m_QuaternionArray[1] = i;
    m_QuaternionArray[2] = j;
    m_QuaternionArray[3] = k;

    file.close();
}