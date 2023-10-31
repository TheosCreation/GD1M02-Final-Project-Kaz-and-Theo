#include "Quaternion.h"

Quaternion::~Quaternion()
{
}
Quaternion::Quaternion(int a, int b, int c, int d)
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
    char real = 0;
    char i = 0;
    char j = 0;
    char k = 0; 
    std::getline(file, line, '\n');
    char prev = 'z';

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
   
    m_QuaternionArray[0] = real;
    m_QuaternionArray[1] = i;
    m_QuaternionArray[2] = j;
    m_QuaternionArray[3] = k;

    
    std::cout << real << std::endl;
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    std::cout << k << std::endl;
    file.close();
}