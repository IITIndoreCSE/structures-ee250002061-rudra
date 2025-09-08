#include <iostream>
#include <fstream>
#include <string>

struct Sensor {
    int id;
    double temperature;
    double voltage;
    std::string status;
};

void print_sensor(int index, int id, double temperature, double voltage, const char* status) {
    std::cout << "Sensor[" << index << "]: "
              << "id=" << id << ", "
              << "temperature=" << temperature << ", "
              << "voltage=" << voltage << ", "
              << "status=" << status << "\n";
}

int main() {
    std::ifstream infile("sensors.txt");
    if (!infile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    int n;
    infile >> n;
    infile.ignore();  // Consume the newline

    Sensor* sensors = new Sensor[n];

    for (int i = 0; i < n; ++i) {
        infile >> sensors[i].id;
        infile >> sensors[i].temperature;
        infile >> sensors[i].voltage;
        infile.ignore();  // Consume newline before reading status
        std::getline(infile, sensors[i].status);
    }

    Sensor* ptr = sensors;
    for (int i = 0; i < n; ++i, ++ptr) {
        print_sensor(i, ptr->id, ptr->temperature, ptr->voltage, ptr->status.c_str());
    }

    delete[] sensors;
    return 0;
}
