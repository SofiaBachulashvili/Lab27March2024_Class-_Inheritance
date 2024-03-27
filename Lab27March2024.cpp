#include <stdlib.h>
#include <iostream>
using namespace std;

// Базовый класс - "Точка на плоскости"
class Point2D {
	//1. Координаты точки
protected:
	double x, y;
public:
	// 2. Конструктор для инициализации полей
	Point2D(double x, double y) {
		this->x = x; this->y = y;
	}
	// 3. Метод для печати полей (виртуальный)
	virtual void print() { // Метод для печати полей (виртуальный)
		// cout << "\nx = " << x << "	" << "y = " << y; // Печатаем значения полей
		cout << "\nx = " << x << "\t y = " << y;
	}
};

// Производный класс - "Точка в пространстве"
class Point3D : public Point2D {
	double z; // Новое поле - координата z
public:
	// Конструктор
	Point3D(double x, double y, double z):
		Point2D(x, y){ // Явный вызов конструктора базового класса
		this->z = z;
	}

	// Переопределенный метод print
	void print(){
		Point2D::print(); // Вызов в переопределенном методе метод базового класса
		cout << "\t  z = " << z; // Допечатывает поле z
		cout << "\n\n";
	}
};

int main(int argc, char* argv[]){
	//Создание объектов  с вызовом конструктора
	Point2D p1(22, 2); 
	Point3D p3(93, 72, 64);

	cout << "Point in the plane:	";
	Point2D* pp; // Указатель типа базового класса
	pp = &p1; // Настраиваем на объект базового класса

	//cout << "Point in space:	";
	pp->print(); // Вызов метода через указатель
	pp = &p3; // Настриваем указатель на объект производного класса 
	// (преобразование типа допустимо)

	cout << "\n\nPoint in space:	";
	pp->print(); // Вызов метода через указатель, вызывается метод класса Point3D
	// Если метод print в классе point был объявлен без virtual, 
	// то вызывался бы метод print класс Point2D
	system("pause"); // Останавливаем программу до нажатия любой клавиши
	return 0;
}

