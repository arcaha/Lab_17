#include <iostream>
#include "sorted_array.hpp"
#include "Point.hpp"
int main() {

	Sorted_Array<int> ob1(5);
	Sorted_Array<char> ob2(4);
	Sorted_Array<Point> ob3(4);
	Point p1{ 1,2,3 }, p2{ 1,1,1 }, p3{ -3,-1,-4 }, p4{ 3,1,4 };
	try {
		std::cout << "Array int:\n";
		ob1.push(2);
		ob1.push(-2);
		ob1.push(1);
		ob1.push(6);
		ob1.watch();
		//		ob1.at(6);
		std::cout << "Change 1 elements:\n";
		ob1[1] = 3;
		ob1.watch();
		ob1.push(2);
		ob1.watch();
		std::cout << "Array char:\n";
		ob2.push('a');
		ob2.push('l');
		ob2.push('c');
		ob2.watch();
		std::cout << "Erase 1 elements:\n";
		ob2.erase(1);
		ob2.watch();
		std::cout << "Array point:\n";
		ob3.push(p3);
		ob3.push(p1);
		ob3.push(p4);
		ob3.push(p2);
		ob3.watch();
	}
	catch (int) {
		std::cout << "Error, out of bounds of array" << std::endl;
	}
	return 0;

}