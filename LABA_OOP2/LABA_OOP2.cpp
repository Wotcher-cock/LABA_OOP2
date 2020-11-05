#include <iostream>
#include <conio.h>


class Point 
{
protected:
    int x, y;
public:
    Point() {
        printf("Point()\n");
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        printf("Point(int x, int y)\n");
        this->x = x;
        this->y = y;
    }
    Point(const Point &p) {
        printf("Point(const Point &p)\n");
        x = p.x;
        y = p.y;
    }
    ~Point() {
        printf("%d, %d\n", x, y);
        printf("~Point()\n");
    }
    void move(int dx, int dy) {
        x = x + dx;
        y = y + dy;
    }
    void reset();
};


void Point::reset() 
{
    x = 0;
    y = 0; 
}


class ColoredPoint: public Point
{
protected:
    int color;
public:
    ColoredPoint() : Point(){
        printf("ColoredPoint()\n");
        color = 0;
    }
    ColoredPoint(int x, int y, int color) : Point(x,y){
        printf("ColoredPoint(int x, int y)\n");
        this->color = color;
    }
    ColoredPoint(const ColoredPoint& p) {
        printf("ColoredPoint(const Point &p)\n");
        color = p.color;
        x = p.x;
        y = p.y;
    }
    ~ColoredPoint() {
        printf("%d, %d, color=%d\n", x, y, color);
        printf("~ColoredPoint()\n");
    }
    void change_color(int new_color) {
        color = new_color;
    }
};

class Section
{
protected:
    Point *p1;
    Point *p2;
public:
    Section() {
        printf("Section()\n");
        p1 = new Point;
        p2 = new Point;
    }
    Section(int x1, int y1, int x2, int y2) {
        printf("Section(int x1, int y1, int x2, int y2)\n");
        p1 = new Point(x1,y1);
        p2 = new Point(x2,y2);
    }
    Section(const Section& s) {
        printf("Section(const Section &s)\n");
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
    Section *s1 = new Section;
    Section *s2 = new Section(*s1);

    delete s1;
    delete s2;

    return 0;
}