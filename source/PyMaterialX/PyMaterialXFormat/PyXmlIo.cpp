//
// TM & (c) 2017 Lucasfilm Entertainment Company Ltd. and Lucasfilm Ltd.
// All rights reserved.  See LICENSE.txt for license.
//

#include <PyMaterialX/PyMaterialX.h>

#include <MaterialXFormat/XmlIo.h>
#include <MaterialXCore/Document.h>

namespace py = pybind11;
namespace mx = MaterialX;

void bindPyXmlIo(py::module& mod)
{
    py::class_<mx::XmlReadOptions>(mod, "XmlReadOptions")
        .def(py::init())
        .def_readwrite("readXIncludeFunction", &mx::XmlReadOptions::readXIncludeFunction)
        .def_readwrite("readComments", &mx::XmlReadOptions::readComments)
        .def_readwrite("parentXIncludes", &mx::XmlReadOptions::parentXIncludes);

    py::class_<mx::XmlWriteOptions>(mod, "XmlWriteOptions")
        .def(py::init())
        .def_readwrite("writeXIncludeEnable", &mx::XmlWriteOptions::writeXIncludeEnable)
        .def_readwrite("elementPredicate", &mx::XmlWriteOptions::elementPredicate);

    py::class_<mx::XmlExportOptions>(mod, "XmlExportOptions")
        .def(py::init())
        .def_readwrite("mergeLooks", &mx::XmlExportOptions::mergeLooks)
        .def_readwrite("lookGroupToMerge", &mx::XmlExportOptions::lookGroupToMerge);

    mod.def("readFromXmlFileBase", &mx::readFromXmlFile,
        py::arg("doc"), py::arg("filename"), py::arg("searchPath") = mx::FileSearchPath(), py::arg("readOptions") = (mx::XmlReadOptions*) nullptr);
    mod.def("readFromXmlString", &mx::readFromXmlString,
        py::arg("doc"), py::arg("str"), py::arg("readOptions") = (mx::XmlReadOptions*) nullptr);
    mod.def("writeToXmlFile", mx::writeToXmlFile,
        py::arg("doc"), py::arg("filename"), py::arg("writeOptions") = (mx::XmlWriteOptions*) nullptr);
    mod.def("writeToXmlString", mx::writeToXmlString,
        py::arg("doc"), py::arg("writeOptions") = nullptr);
    mod.def("exportToXmlFile", mx::exportToXmlFile,
        py::arg("doc"), py::arg("filename"), py::arg("exportOptions") = (mx::XmlExportOptions*) nullptr);
    mod.def("exportToXmlString", mx::exportToXmlString,
        py::arg("doc"), py::arg("exportOptions") = nullptr);
    mod.def("prependXInclude", mx::prependXInclude);

    py::register_exception<mx::ExceptionParseError>(mod, "ExceptionParseError");
    py::register_exception<mx::ExceptionFileMissing>(mod, "ExceptionFileMissing");
}
