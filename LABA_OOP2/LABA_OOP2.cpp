#include <iostream>
#include <conio.h>
using namespace std;


class Point//Класс родитель
{
protected:
    int x, y;
public:
    Point() {//объект со статичным данными
        printf("Point()\n");//Вывод на экран того, что создался объект
        x = 0;
        y = 0;
    }
    Point(int x, int y) {//Объект с входными данными
        printf("Point(int x, int y)\n");//Вывод на экран того, что создался объект
        this->x = x;//x получает перваое значение и сохраняет его
        this->y = y;//y получает второе значение и сохраняет его
    }
    Point(const Point &p) {//Объект копировщик
        printf("Point(const Point &p)\n");//Вывод на экран того, что создался объект
        x = p.x;//копирует значение х другого объекта
        y = p.y;//копирует значение y другого объекта
    }
    ~Point() {//Деструктор
        printf("%d, %d\n", x, y);//Сначала показывает удаленные координаты
        printf("~Point()\n");//Удалился объект(якобы)
    }
    void move(int dx, int dy) {//функция передвижения точек
        x = x + dx;
        y = y + dy;
    }
    void reset();
};


void Point::reset() //функция обновления
{
    x = 0;
    y = 0; 
}


class ColoredPoint: public Point//Класс предок
{
protected:
    int color;
public:
    ColoredPoint() : Point(){//объект со статичным данными
        printf("ColoredPoint()\n");//Вывод на экран того, что создался объект
        color = 0;
    }
    ColoredPoint(int x, int y, int color) : Point(x,y){//Объект с входными данными
        printf("ColoredPoint(int x, int y)\n");//Вывод на экран того, что создался объект
        this->color = color;//color получает значение и сохраняет его
    }
    ColoredPoint(const ColoredPoint& p) {//Объект копировщик
        printf("ColoredPoint(const Point &p)\n");//Вывод на экран того, что создался объект
        color = p.color;
        x = p.x;
        y = p.y;
    }
    ~ColoredPoint() {//Деструктор
        printf("%d, %d, color=%d\n", x, y, color);
        printf("~ColoredPoint()\n");
    }
    void change_color(int new_color) {//функция замены значений
        color = new_color;
    }
};

class Section//класс для работы с наследниками
{
protected:
    Point *p1;
    Point *p2;
public:
    Section() {//объект со статичным данными
        printf("Section()\n");//Вывод на экран того, что создался объект
        p1 = new Point;
        p2 = new Point;
    }
    Section(int x1, int y1, int x2, int y2) {//Объект с входными данными
        printf("Section(int x1, int y1, int x2, int y2)\n");//Вывод на экран того, что создался объект
        p1 = new Point(x1,y1);
        p2 = new Point(x2,y2);
    }
    Section(const Section& s) {
        printf("Section(const Section &s)\n");//Вывод на экран того, что создался объект
        p1 = new Point(*(s.p1));
        p2 = new Point(*(s.p2));
    }
    ~Section() {
        //printf("%d, %d\n", x, y);
        delete p1;
        delete p2;
        printf("~Section()\n");
    }
};


int main()
{
    Point p;//вызываем создание объекта статически
    Point p2(10,10);
    Point p3(p2);
    cout << "\n";


    Point *dp = new Point;//вызываем создание динамического объекта
    Point *dp2 = new Point(9,11);
    Point *dp3 = new Point(*dp2);
    delete dp;
    delete dp2;
    delete dp3;
    cout << "\n";


    Point *a = new Point(2,2);//создание объектов и использование различных конструкторов
    a->reset();
    a->move(7,9);
    delete a;
    cout << "\n";


    Point* color1 = new ColoredPoint(1, 2, 33);//создание объектов-насследников
    delete color1;
    ColoredPoint* color2 = new ColoredPoint(1, 2, 33);
    delete color2;
    cout << "\n";


    Section *s1 = new Section;//композиция объектов
    Section *s2 = new Section(*s1);
    delete s1;
    delete s2;
    cout << "\n";


    return 0;
}