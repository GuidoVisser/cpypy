#include "lib_src/two.h"
#include "lib_src/three.h"

// 👇 THIS MUST MATCH `name = "cpp_lib"` in pyproject.toml
PYBIND11_MODULE(cpp_lib, m) {
    m.def("scale_by_two", &scale_by_two, "Multiply array by two");
    m.def("scale_by_three", &scale_by_three, "Multiply array by three");
}
