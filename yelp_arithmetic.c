#include <Python.h>


/*
    A. The division C function
 */

// TODO: define division method


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

    // TODO: add mappings

    // always add an empty value
    // to mark the end of the array
    {NULL, NULL, 0, NULL}
};


/*
    C. The module definition
       Already completed
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

// TODO: write init method