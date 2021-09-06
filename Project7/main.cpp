#include <iostream>
 
class Vector {
private:
	double _coordinate[2];
public:
	Vector(double x, double y) {
		this->_coordinate[0] = x;
		this->_coordinate[1] = y;
		std::cout << "point created in coordinates : " << this->_coordinate[0] << " | " << this->_coordinate[1] << std::endl;
	}
	int operator[](int i) {
		return this->_coordinate[i];
	}

	Vector(const Vector& v) {
		this->_coordinate[0] = v._coordinate[0];
		this->_coordinate[1] = v._coordinate[1];
	}
	friend std::ostream& operator <<(std::ostream& out, const Vector& v) {
		out <<  v._coordinate[0] << " " << v._coordinate[1];
		
		return out;
	}
};

class Point  {
private:
	Vector* _point;
	double _radius; 
public:
	Point(const Vector& points, double radius) {
		this->_point = new Vector(points);
		this->_radius = radius;
	}
	Point(const Point& p) {
		this->_point = p._point;
		this->_radius = p._radius;
	}
	void print() {
		std::cout << "point created in coordinates : " << this->_point[0] << this->_radius <<" radius"<< std::endl;
	}
};

class Circle {
private:
	Point* p;
	double radius;
public:
};
int main() {
	Vector v (2.2, 5.6);
	Point* point = new Point(v, 5);
	point->print();
	system("pause");
	return 0;
}