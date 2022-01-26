#include <iostream>
#include "polygon.h"


using std::vector;
std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
    vector<Point> l1 = lhs;
    vector<Point> r1 = rhs;
    for (const Point &l : l1)
    {
        bool verifica = false;
        for (const Point &r : r1)
            if (l.contains(r)){
                verifica = true;
                break;
            }
        if (!verifica)
            return false;
    }
    
    for (const Point &l : r1)
    {
        bool verifica = false;
        for (const Point &r : l1)
            if (l.contains(r)){
                verifica = true;
                break;
            }
        if (!verifica)
            return false;
    }
    return true;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
    bool retorno = false;
    int x[2] = {9999, -9999}, y[2] = {9999, -9999};
    
    for (const Point &limit : limits){
        if (limit.x > x[1]){
            x[1] = limit.x;
        }
        if (limit.x < x[0]){
            x[0] = limit.x;
        }
        if (limit.y > y[1]){
            y[1] = limit.y;
        }
        if (limit.y < y[0]){
            y[0] = limit.y;
        }
    }
    
    if (p.x >= x[1] || p.x <= x[0] || p.y >= y[1] || p.y <= y[0]){
        retorno = false;
    }
    else{
        retorno = true;
    }
    
    return retorno;  
}

Point::Point(int xx, int yy): x(xx), y(yy) {
    limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
    Point *p1 = new Point(x0,y0);
    Point *p2 = new Point(x0,y1);
    Point *p3 = new Point(x1,y0);
    Point *p4 = new Point(x1,y1);
    limits.push_back(*p1);
    limits.push_back(*p2);
    limits.push_back(*p3);
    limits.push_back(*p4);
}