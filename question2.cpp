#include <iostream>
#include <fstream>
#include <string>

struct Rectangle {
    double width;
    double height;
    double thickness;
    double density;
    std::string material;
};

void print_plate(int index, double width, double height,
                 double density, double mass, const char* material) {
    std::cout << "Plate[" << index << "]: "
              << "width=" << width << ", "
              << "height=" << height << ", "
              << "density=" << density << ", "
              << "mass=" << mass << ", "
              << "material=" << material << "\n";
}

int main() {
    std::ifstream infile("plates.txt");
    if (!infile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    int n;
    infile >> n;
    infile.ignore();  // Ignore newline after number

    Rectangle* plates = new Rectangle[n];

    for (int i = 0; i < n; ++i) {
        infile >> plates[i].width;
        infile >> plates[i].height;
        infile >> plates[i].thickness;
        infile >> plates[i].density;
        infile.ignore();  // Ignore newline before reading material
        std::getline(infile, plates[i].material);
    }

    for (int i = 0; i < n; ++i) {
        double mass = plates[i].width * plates[i].height * plates[i].thickness * plates[i].density;
        print_plate(i,
                    plates[i].width,
                    plates[i].height,
                    plates[i].density,
                    mass,
                    plates[i].material.c_str());
    }

    delete[] plates;
    return 0;
}
