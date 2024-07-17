// example.cpp
#include "../libs/pybind11/pybind11.h"

namespace py = pybind11;

// Simple class definition
class Pet {
public:
    Pet(const std::string &name) : name(name) {}

    void setName(const std::string &name) { this->name = name; }
    std::string getName() const { return name; }

private:
    std::string name;
};

// Function to add two numbers
int add(int i, int j) {
    return i + j;
}

// Module definition
PYBIND11_MODULE(example, m) {
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())  // Constructor
        .def("setName", &Pet::setName)         // Method to set name
        .def("getName", &Pet::getName);        // Method to get name
    m.def("add", &add, "A function that adds two numbers");
}

