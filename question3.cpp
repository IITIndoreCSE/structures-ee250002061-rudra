#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

struct Point {
    double x;
    double y;
};

void print_point_rotation(double x_before, double y_before,
                          double theta, double x_after, double y_after) {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Before rotation: (x=" << x_before << ", y=" << y_before << ")\n";
    std::cout << "After rotation (θ=" << theta << " rad): "
              << "(x=" << x_after << ", y=" << y_after << ")\n";
}

Point rotate_point(const Point& p, const Point& pivot, double theta) {
    Point rotated;
    rotated.x = pivot.x + (p.x - pivot.x) * std::cos(theta) - (p.y - pivot.y) * std::sin(theta);
    rotated.y = pivot.y + (p.x - pivot.x) * std::sin(theta) + (p.y - pivot.y) * std::cos(theta);
    return rotated;
}

int main() {
    std::ifstream infile("point_input.txt");
    if (!infile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    Point p, pivot;
    double theta;

    infile >> p.x >> p.y >> theta >> pivot.x >> pivot.y;

    Point p_rotated = rotate_point(p, pivot, theta);

    print_point_rotation(p.x, p.y, theta, p_rotated.x, p_rotated.y);

    return 0;
}

