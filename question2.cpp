#include <iostream>
#include <vector>
#include <string>

// Define the Rectangle struct
struct Rectangle {
    double width;
    double height;
    double thickness;
    double density;
    std::string material; // Using std::string for material name
    double mass;
};

// Function to print plate information
void print_plate(int index, double width, double height,
                 double density, double mass, const std::string& material) {
    std::cout << "Plate[" << index << "]: "
              << "width=" << width << ", "
              << "height=" << height << ", "
              << "density=" << density << ", "
              << "mass=" << mass << ", "
              << "material=" << material << "\n";
}

int main() {
    // Vector to store Rectangle objects
    std::vector<Rectangle> plates;

    // --- Plate 1 ---
    Rectangle plate1;
    plate1.width = 2.0;
    plate1.height = 3.0;
    plate1.thickness = 0.01;
    plate1.density = 7850; // kg/m^3 for Steel
    plate1.material = "Steel";
    plate1.mass = plate1.width * plate1.height * plate1.thickness * plate1.density;
    plates.push_back(plate1);

    // --- Plate 2 ---
    Rectangle plate2;
    plate2.width = 1.5;
    plate2.height = 2.5;
    plate2.thickness = 0.02;
    plate2.density = 2700; // kg/m^3 for Aluminium
    plate2.material = "Aluminium";
    plate2.mass = plate2.width * plate2.height * plate2.thickness * plate2.density;
    plates.push_back(plate2);

    // Print the information for each plate
    for (int i = 0; i < plates.size(); ++i) {
        print_plate(i, plates[i].width, plates[i].height,
                    plates[i].density, plates[i].mass, plates[i].material);
    }

    return 0;
}

