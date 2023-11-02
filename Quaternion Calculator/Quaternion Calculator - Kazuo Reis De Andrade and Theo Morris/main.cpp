#include "Quaternion.h"
#include "Calculator.h"

int main() {
	Calculator MainCalculator;
	Quaternion q1(0,0,0,0);
	q1.LoadFromFile("Quaternion.txt", QuaternionA);
	Quaternion q2(0, 0, 0, 0);
	q2.LoadFromFile("Quaternion.txt", QuaternionB);
	std::ifstream file("Quaternion.txt");
	int Scalar = 2;
	//Quaternion q2(0,0,0,0);
	std::cout << "q1: ";
	q1.PrintQuaternion();
	std::cout << "\nq2: ";
	q2.PrintQuaternion();
	std::cout << "Scalar:" << Scalar << "\n\n";
	std::cout << "Addition" << "\n";
	MainCalculator.Addition(q1, q2).PrintQuaternion();
	std::cout << "Subtraction" << "\n";
	MainCalculator.Subtraction(q1, q2).PrintQuaternion();
	std::cout << "SubtractionReverse" << "\n";
	MainCalculator.SubtractionReverse(q1, q2).PrintQuaternion();
	std::cout << "Multiplication" << "\n";
	MainCalculator.Multiplication(q1, q2).PrintQuaternion();
	std::cout << "MultiplicationReverse" << "\n";
	MainCalculator.MultiplicationReverse(q1, q2).PrintQuaternion();
	std::cout << "DotProduct" << "\n";
	MainCalculator.DotProduct(q1, q2).PrintQuaternion();
	std::cout << "Conjugate of q1" << "\n";
	MainCalculator.Conjugate(q1).PrintQuaternion();
	std::cout << "Conjugate of q2" << "\n";
	MainCalculator.Conjugate(q2).PrintQuaternion();
	std::cout << "Inverse of q1" << "\n";
	MainCalculator.Inverse(q1).PrintQuaternion();
	std::cout << "Inverse of q2" << "\n";
	MainCalculator.Inverse(q2).PrintQuaternion();
	std::cout << "Scalar Multiplication q1" << "\n";
	MainCalculator.ScalarMultiplication(q1, Scalar).PrintQuaternion();
	std::cout << "Scalar Multiplication q2" << "\n";
	MainCalculator.ScalarMultiplication(q2, Scalar).PrintQuaternion();
}