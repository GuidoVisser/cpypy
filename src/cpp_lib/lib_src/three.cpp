#include "three.h"

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

py::array_t<double> scale_by_three(py::array_t<double> input) {
    auto buf = input.request();

    if (buf.ndim != 1)
        throw std::runtime_error("Only 1D arrays are supported");

    auto result = py::array_t<double>(buf.size);
    auto res_buf = result.request();

    double* ptr_in = static_cast<double*>(buf.ptr);
    double* ptr_out = static_cast<double*>(res_buf.ptr);

    for (ssize_t i = 0; i < buf.size; i++)
        ptr_out[i] = 3.0 * ptr_in[i];

    return result;
}
