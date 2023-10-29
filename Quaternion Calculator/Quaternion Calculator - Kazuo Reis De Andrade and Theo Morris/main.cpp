#include "Quaternion.h"

int main() {
	Quaternion q1(0,0,0,0);
	q1.LoadFromFile("Quaternion.txt", QuaternionA);
	q1.PrintQuaternion();
	Quaternion q2(0,0,0,0);
	q2.LoadFromFile("Quaternion.txt", QuaternionB);
	q2.PrintQuaternion();
}