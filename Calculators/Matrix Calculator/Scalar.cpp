#include "Scalar.h"

Scalar::Scalar(const char* _Filename)
{
	std::ifstream file(_Filename);
	std::string temp;
	if (!file.is_open()) {
		std::cerr << "Error: Unable to open the file." << std::endl;
		return;
	}
	for (int i = 0; i < 32; i++)
	{
		file >> temp;
	
	}
	file >> m_Scalar;

}

Scalar::~Scalar()
{
}
