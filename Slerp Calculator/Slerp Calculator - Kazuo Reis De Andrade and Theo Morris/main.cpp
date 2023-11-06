#include "Quaternion.h"
#include "Slerp.h"

int main() {
	Quaternion q1(0, 0, 0, 0);
	q1.LoadFromFile("Slerp.txt", QuaternionA);
	//end 
	// 
	//q2 init
	Quaternion q2(0, 0, 0, 0);
	q2.LoadFromFile("Slerp.txt", QuaternionB);
	
	float t = 0.0f;
	std::ifstream file("Slerp.txt");
	std::string line;

	// Read the last line in the file and sets a float as the last line
	while (std::getline(file, line)) {
		// Loop through the file until you reach the last line
	}
	t = std::stof(line);
	

	//prints everything
	std::cout << "q1: ";
	q1.PrintQuaternion();
	std::cout << "\nq2: ";
	q2.PrintQuaternion();

	std::cout << "t:" << t << "\n\n";
}