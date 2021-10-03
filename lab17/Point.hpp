#include <iostream>
#include <math.h>
#ifndef Point_hpp
#define Point_hpp

class Point {
private:
	int x;
	int y;
	int z;
public:
	Point() {
		x = 0;
		y = 0;
		z = 0;
	}

	~Point() {
	}

	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Point& operator=(Point& a) {
		if (this == &a) {
			return *this;
		}
		x = a.x;
		y = a.y;
		z = a.z;
		return *this;
	}

	bool operator<(Point a) {
		double a1 = sqrt(x * x + y * y + z * z);
		double a2 = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
		return a1 < a2;
	}

	friend std::ostream& operator<<(std::ostream& out, const Point a) {
		out << "(" << a.x << "," << a.y << "," << a.z << ")";
		return out;
	}
};
	
#endif