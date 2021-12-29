#include <iostream>
#include <cmath>

class Point {
    int x, y;

public:
    Point(int a, int b) {
        x = a;
        y = b;
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

class Geometry {
private:
    Point* point_array[100];
    int num_points;

public:
    Geometry() { num_points = 0; }

    void addPoint(const Point& point) {
        point_array[num_points++] = new Point(point.getX(), point.getY());
    }

    void printDistance();
    void printNumMeets();

    double getDistance(const Point& p1, const Point& p2);
};

double Geometry::getDistance(const Point& p1, const Point& p2) {
    int a = p1.getX() - p2.getX();
    int b = p1.getY() - p2.getY();
    return sqrt((a*a) + (b*b));
}

void Geometry::printDistance() {
    double sum = 0.0f;
    for (int i=0, e=num_points-1; i<e; i++) {
        sum += getDistance(*point_array[i], *point_array[i+1]);
    }

    std::cout << "total distance is " << sum << std::endl;
}

int main() {
    Geometry geo;
    Point pos1(1, 2), pos2(3, 1), pos3(-1, -4), pos4(5, 2);
    geo.addPoint(pos1);
    geo.addPoint(pos2);
    geo.addPoint(pos3);
    geo.addPoint(pos4);
    geo.printDistance();

    return 0;
}
