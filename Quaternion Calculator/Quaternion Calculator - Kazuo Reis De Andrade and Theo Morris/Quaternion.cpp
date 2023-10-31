#include "Quaternion.h"

Quaternion::~Quaternion()
{
}
Quaternion::Quaternion(int a, int b, int c, int d)
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

    std::string line;
    char real = 0;
    char i = 0;
    char j = 0;
    char k = 0; 
    std::getline(file, line, '\n');
    char prev = 'z';
    if (_ValueType == QuaternionB) {
        std::getline(file, line, '\n');
        std::getline(file, line, '\n');
        //skips 2 lines
    }
        for (int a = 0; a < line.size(); a++)
        {
           
            switch (line[a])
            {
                
            case 'i':
                if(prev != ' '){
                    i = prev;
                    real = line[a - 5];
                }
                else {
                    i = 1; 
                    real = line[a - 4];
                }
                break;
            case 'j':
                j = prev == ' ' ? 1 : prev;
                break;
            case 'k':
                k = prev == ' ' ? 1 : prev;
                break;
            default:
                break;
            }
            prev = line[a];
            
        }
    
    Quaternion q(real - '0', i - '0', j - '0', k - '0');
    *this = q;
   
    m_QuaternionArray[0] = (real== 1)? real : real - '0';
    m_QuaternionArray[1] = (i == 1) ? i : i - '0';;
    m_QuaternionArray[2] = (j == 1) ? j : j - '0';
    m_QuaternionArray[3] = (k == 1) ? k : k - '0';
    file.close();
}