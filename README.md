# Lab_rabota_1
Лабораторная работа 1 ИСРПО
#include <iostream>
class ObjectArray;
class IPrint{
public:
    virtual void print(void)=0;
};
class Vector {
private:
	double _coordinate[2];
public:
	Vector(double x = 0, double y = 0) {
		this->_coordinate[0] = x;
		this->_coordinate[1] = y;
		///std::cout << "point created in coordinates : " << this->_coordinate[0] << " | " << this->_coordinate[1] << std::endl;
	}
	int operator[](int i) {
		return this->_coordinate[i];
	}

	Vector(Vector* v) {
		this->_coordinate[0] = v->_coordinate[0];
		this->_coordinate[1] = v->_coordinate[1];
	}
	friend std::ostream& operator <<(std::ostream& out, const Vector& v) {
		out << "[ "<< v._coordinate[0] << " ; " << v._coordinate[1]<<" ]";
		return out;
	}
};

class Point : public IPrint {
private:
	Vector* _point;
	double _radius; 
public:
	Point(const Vector& points, double radius = 0) {
		this->_point = new Vector(points);
		this->_radius = radius;
	}
	Point(Point* p) {
		this->_point = p->_point;
		this->_radius = p->_radius;
	}
    double get_r(void){
        return this->_radius;
    }
	void print(void)override {
		std::cout << "point created in coordinates : " << this->_point[0] << " with radius : " << this->_radius << std::endl;
	}
};

class Circle : public IPrint {
private:
	Point* _p;
	double _radius;
    double _diameter;
public:
    Circle(const Point& p, double radius){
        this->_p=new Point(p);
        this->_radius=radius;
        this->_diameter = (this->_radius+this->_radius);
    }
    Circle(Point* p){
        this->_p= new Point(p);
        this->_radius = p->get_r();
    }
    void print()override{
        std::cout<<"Circle : \n";
        this->_p->print();
        std::cout<<"Circle Radius "<<_radius <<" diameter : "<<_diameter <<std::endl;
    }

    void set_r(double r){
        this->_radius=r;
    }
    void set_d(double d){
        this->_diameter=d;
    }
    double get_r(){
        return this->_radius;
    }
    double get_d(){
        return this->_diameter;
    }
};

struct Node {
    Circle data;
    Node* pPrev;
    Node* pNext;

};
class ObjectArray{
private:
    Node* _Head;
    Node* _Tail;
public:
    ObjectArray(): _Head(NULL),_Tail(NULL){};
    ~ObjectArray(){
        while(_Head)
        {
            _Tail = _Head->pNext;
            delete _Head;
            _Head = _Tail;
        }
    }

    void Add(Circle object){
        Node* temp;
        temp->pNext = NULL;
        temp->data = object;
        if(_Head != NULL){
            temp->pPrev = _Tail;
            _Tail->pNext = temp;
            _Tail = temp;
        }
        else{
            temp->pPrev = NULL;
            _Head = _Tail = temp;
        }
    }
    void Show(bool isTail){
        if(isTail){
            Node* temp =_Tail;
            while(temp !=NULL){
                temp->data.print();
                temp = temp->pPrev;
            }
            std::cout<<"\n";
        }
        else{
            Node* temp = _Head;
            while(temp !=NULL){
                temp->data.print();
                temp = temp->pNext;
            }
            std::cout<<"\n";

        }
    }
    int length(Node* f){
        auto* p = f;
        auto length = 0;
        while(p !=nullptr)
        {
            length++;
            p = p->pNext;
        }
        return length;
    }

};
int main() {
	auto* v = new Vector(2.2, 5.6);
	auto* point = new Point(v, 5);
	///point->print();
    Circle c(point,6);
    ///c.print();
    auto* list = new ObjectArray();
    list->Add(c);
    list->Show(true);
    ///list->Show(false);
	system("pause");
	return 0;
}
