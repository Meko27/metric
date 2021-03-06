#include "modules/mapping/DSPCC.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <vector>
#include <deque>

namespace py = pybind11;

template <typename RecType, typename Metric>
void register_wrapper_DSPCC(py::module& m) {
    using Mapping = metric::DSPCC<RecType, Metric>;
    using Matrix = std::vector<std::vector<RecType>>;
    using Queue = std::deque<std::vector<RecType>>;

    auto dspcc = py::class_<Mapping>(m, "DSPCC");
    dspcc.def(py::init<const std::vector<RecType>&, size_t, size_t, float, size_t>(),
        py::arg("training_dataset"),
        py::arg("n_features") = 1,
        py::arg("n_subbands") = 4,
        py::arg("time_freq_balance") = 0.5,
        py::arg("n_top_features") = 16
    );
    Matrix (Mapping::*encode) (const std::vector<RecType>&) = &Mapping::time_freq_PCFA_encode;
    dspcc.def("time_freq_PCFA_encode", encode);
    dspcc.def("time_freq_PCFA_decode", &Mapping::time_freq_PCFA_decode);
    dspcc.def("encode", &Mapping::encode);
    dspcc.def("decode", &Mapping::decode);
}

void export_metric_DSPCC(py::module& m) {
    register_wrapper_DSPCC<std::vector<double>, void>(m);
}
