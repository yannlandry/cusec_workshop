#include <Python.h>

#include <stdio.h>


/*
    A. The division C function
 */
PyObject* division(PyObject* self, PyObject* args) {
    double a, b, result;

    if(!PyArg_ParseTuple(args, "dd", &a, &b)) {
        return NULL;
    }

    if(b == 0) {
        PyErr_SetString(PyExc_ValueError, "Cannot divide by zero.");
        return NULL;
    }

    result = a / b;
    return Py_BuildValue("d", result);
}


PyObject* addition(PyObject* self, PyObject* args) {
    double a, b, result;

    if(!PyArg_ParseTuple(args, "dd", &a, &b)) {
        return NULL;
    }

    result = a + b;
    return Py_BuildValue("d", result);
}


/*
    B. An array mapping C functions to python methods
 */
PyMethodDef yelp_arithmetic_methods[] = {
/*  example:
    {
        "python_method",            <-- python method name
        (PyCFunction)c_function,    <-- name of the corresponding C function
        METH_(NO|VAR)ARGS,          <-- NOARGS: no arg taken, VARARGS: 1+ args taken
        "what does it do"           <-- docstring for the python method
    }
*/
    {
        "division",
        (PyCFunction)division,
        METH_VARARGS,
        "Divides A and B."
    },

    {
        "addition",
        (PyCFunction)addition,
        METH_VARARGS,
        "Adds A and B."
    },

    // always add an empty value
    // to mark the end of the array
    {NULL, NULL, NULL, NULL}
};


/*
    C. The module definition
 */
struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,      // always use this value
    "yelp_arithmetic",          // name of the module
    "Does arithmetic. lol",     // docstring of the module
    -1,                         // for most cases, -1
    yelp_arithmetic_methods,    // function-method mappings
    NULL,
    NULL,
    NULL,       // functions to be called when/if the module is
    NULL        // garbage-collected/deallocated; not needed here
};


/*
    D. The initialization method, called when importing
       To always be called PyInit_module_name
 */
PyMODINIT_FUNC PyInit_yelp_arithmetic(void) {
    return PyModule_Create(&module);
}