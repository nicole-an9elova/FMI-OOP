#include <iostream>

//9.2
struct Point {
    double x;
    double y;
};

class Line {
public:
    Point point1;
    Point point2;

    Line();
    Line(Point p1, Point p2);

    void setPoint1(Point p);
    void setPoint2(Point p);

    bool areLinesParallel(Line other);
    bool isPointOnTheLine(Point point);
    //приемаа се, че правите не са успоредни
    Point intersectionPoint(Line other);
};

int main()
{
    Point p1 = { 5, -3 }, p2 = { 1, -3 }, p3 = { 4, -1 }, p4 = { 2, -1 };
    Point pp1 = { 1, 2 }, pp2 = { 1, 1 }, pp3 = { 1, 4 }, pp4 = { 4, 1 };
    Line l1 = Line(p1, p2),
         l2 = Line(p3, p4);
    Line l3 = Line(pp1, pp2),
        l4 = Line(pp3, pp4);


    std::cout << std::boolalpha << l1.areLinesParallel(l2) << std::endl;
    std::cout << std::boolalpha << l3.areLinesParallel(l4) << std::endl;

    std::cout << std::boolalpha << l1.isPointOnTheLine(p1) << std::endl;

    return 0;
}

Line::Line()
{
    setPoint1({ 0,0 });
    setPoint2({ 1,1 });
}

Line::Line(Point p1, Point p2)
{
    setPoint1(p1);
    setPoint2(p2);
}

void Line::setPoint1(Point p) {
    this->point1.x = p.x;
    this->point1.y = p.y;
}
void Line::setPoint2(Point p) {
    this->point2.x = p.x;
    this->point2.y = p.y;
}

bool Line::areLinesParallel(Line other)
{
    if (abs(this->point1.x - other.point1.x) == abs(this->point2.x - other.point2.x) &&
        abs(this->point1.y - other.point1.y) == abs(this->point2.y - other.point2.y)){
        return true;
    }
    return false;
}

bool Line::isPointOnTheLine(Point point)
{
    if (point.x <= std::max(this->point1.x, this->point2.x) &&
        point.x >= std::min(this->point1.x, this->point2.x) &&
        point.y <= std::max(this->point1.y, this->point2.y) &&
        point.y >= std::min(this->point1.y, this->point2.y))
        return true;
    return false;
}

Point Line::intersectionPoint(Line other)
{
    //довърши!!!!
    return Point();
}
