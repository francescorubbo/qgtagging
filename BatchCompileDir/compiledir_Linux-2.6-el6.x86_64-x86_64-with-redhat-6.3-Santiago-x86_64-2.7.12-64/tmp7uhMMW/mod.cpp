#include <Python.h>
#include <iostream>
#include "theano_mod_helper.h"
#include <math.h>
#include <numpy/arrayobject.h>
#include <numpy/arrayscalars.h>
#include <vector>
#include <algorithm>
//////////////////////
////  Support Code
//////////////////////


    namespace {
    struct __struct_compiled_op_419221d82e561ea699b5345cebc3c46d {
        PyObject* __ERROR;

        PyObject* storage_V3;
PyObject* storage_V5;
PyObject* storage_V7;
PyObject* storage_V9;
PyObject* storage_V11;
PyObject* storage_V13;
PyObject* storage_V15;
PyObject* storage_V17;
PyObject* storage_V19;
PyObject* storage_V21;
PyObject* storage_V23;
PyObject* storage_V25;
PyObject* storage_V27;
PyObject* storage_V29;
PyObject* storage_V1;
        

        __struct_compiled_op_419221d82e561ea699b5345cebc3c46d() {
            // This is only somewhat safe because we:
            //  1) Are not a virtual class
            //  2) Do not use any virtual classes in the members
            //  3) Deal with mostly POD and pointers

            // If this changes, we would have to revise this, but for
            // now I am tired of chasing segfaults because
            // initialization code had an error and some pointer has
            // a junk value.
            memset(this, 0, sizeof(*this));
        }
        ~__struct_compiled_op_419221d82e561ea699b5345cebc3c46d(void) {
            cleanup();
        }

        int init(PyObject* __ERROR, PyObject* storage_V3, PyObject* storage_V5, PyObject* storage_V7, PyObject* storage_V9, PyObject* storage_V11, PyObject* storage_V13, PyObject* storage_V15, PyObject* storage_V17, PyObject* storage_V19, PyObject* storage_V21, PyObject* storage_V23, PyObject* storage_V25, PyObject* storage_V27, PyObject* storage_V29, PyObject* storage_V1) {
            Py_XINCREF(storage_V3);
Py_XINCREF(storage_V5);
Py_XINCREF(storage_V7);
Py_XINCREF(storage_V9);
Py_XINCREF(storage_V11);
Py_XINCREF(storage_V13);
Py_XINCREF(storage_V15);
Py_XINCREF(storage_V17);
Py_XINCREF(storage_V19);
Py_XINCREF(storage_V21);
Py_XINCREF(storage_V23);
Py_XINCREF(storage_V25);
Py_XINCREF(storage_V27);
Py_XINCREF(storage_V29);
Py_XINCREF(storage_V1);
            this->storage_V3 = storage_V3;
this->storage_V5 = storage_V5;
this->storage_V7 = storage_V7;
this->storage_V9 = storage_V9;
this->storage_V11 = storage_V11;
this->storage_V13 = storage_V13;
this->storage_V15 = storage_V15;
this->storage_V17 = storage_V17;
this->storage_V19 = storage_V19;
this->storage_V21 = storage_V21;
this->storage_V23 = storage_V23;
this->storage_V25 = storage_V25;
this->storage_V27 = storage_V27;
this->storage_V29 = storage_V29;
this->storage_V1 = storage_V1;
            
















            this->__ERROR = __ERROR;
            return 0;
        }
        void cleanup(void) {
            __label_1:

double __DUMMY_1;
__label_3:

double __DUMMY_3;
__label_5:

double __DUMMY_5;
__label_7:

double __DUMMY_7;
__label_9:

double __DUMMY_9;
__label_11:

double __DUMMY_11;
__label_13:

double __DUMMY_13;
__label_15:

double __DUMMY_15;
__label_17:

double __DUMMY_17;
__label_19:

double __DUMMY_19;
__label_21:

double __DUMMY_21;
__label_23:

double __DUMMY_23;
__label_25:

double __DUMMY_25;
__label_27:

double __DUMMY_27;
__label_29:

double __DUMMY_29;
__label_32:

double __DUMMY_32;

            Py_XDECREF(this->storage_V3);
Py_XDECREF(this->storage_V5);
Py_XDECREF(this->storage_V7);
Py_XDECREF(this->storage_V9);
Py_XDECREF(this->storage_V11);
Py_XDECREF(this->storage_V13);
Py_XDECREF(this->storage_V15);
Py_XDECREF(this->storage_V17);
Py_XDECREF(this->storage_V19);
Py_XDECREF(this->storage_V21);
Py_XDECREF(this->storage_V23);
Py_XDECREF(this->storage_V25);
Py_XDECREF(this->storage_V27);
Py_XDECREF(this->storage_V29);
Py_XDECREF(this->storage_V1);
        }
        int run(void) {
            int __failure = 0;
            
    PyObject* py_V1;
    
        PyArrayObject* V1;
        
            typedef npy_float32 dtype_V1;
            
    PyObject* py_V3;
    
        PyArrayObject* V3;
        
            typedef npy_float32 dtype_V3;
            
    PyObject* py_V5;
    
        PyArrayObject* V5;
        
            typedef npy_float32 dtype_V5;
            
    PyObject* py_V7;
    
        PyArrayObject* V7;
        
            typedef npy_float32 dtype_V7;
            
    PyObject* py_V9;
    
        PyArrayObject* V9;
        
            typedef npy_float32 dtype_V9;
            
    PyObject* py_V11;
    
        PyArrayObject* V11;
        
            typedef npy_float32 dtype_V11;
            
    PyObject* py_V13;
    
        PyArrayObject* V13;
        
            typedef npy_float32 dtype_V13;
            
    PyObject* py_V15;
    
        PyArrayObject* V15;
        
            typedef npy_float32 dtype_V15;
            
    PyObject* py_V17;
    
        PyArrayObject* V17;
        
            typedef npy_float32 dtype_V17;
            
    PyObject* py_V19;
    
        PyArrayObject* V19;
        
            typedef npy_float32 dtype_V19;
            
    PyObject* py_V21;
    
        PyArrayObject* V21;
        
            typedef npy_float32 dtype_V21;
            
    PyObject* py_V23;
    
        PyArrayObject* V23;
        
            typedef npy_float32 dtype_V23;
            
    PyObject* py_V25;
    
        PyArrayObject* V25;
        
            typedef npy_float32 dtype_V25;
            
    PyObject* py_V27;
    
        PyArrayObject* V27;
        
            typedef npy_float32 dtype_V27;
            
    PyObject* py_V29;
    
        PyArrayObject* V29;
        
            typedef npy_float32 dtype_V29;
            
{

    py_V1 = PyList_GET_ITEM(storage_V1, 0);
    {Py_XINCREF(py_V1);}
    
        if (py_V1 == Py_None)
        {
            
        V1 = NULL;
        
        }
        else
        {
            
            V1 = NULL;
            if (py_V1 == Py_None) {
                // We can either fail here or set V1 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_2;}
            }
            if (!PyArray_Check(py_V1)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_2;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V1)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V1;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V1),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_2;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V1) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V1));
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_2;}
            }
            
        V1 = (PyArrayObject*)(py_V1);
        Py_XINCREF(V1);
        
        }
        
{

    py_V3 = PyList_GET_ITEM(storage_V3, 0);
    {Py_XINCREF(py_V3);}
    
            V3 = NULL;
            if (py_V3 == Py_None) {
                // We can either fail here or set V3 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_4;}
            }
            if (!PyArray_Check(py_V3)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_4;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V3)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V3;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V3),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_4;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V3) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V3));
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_4;}
            }
            
        V3 = (PyArrayObject*)(py_V3);
        Py_XINCREF(V3);
        
{

    py_V5 = PyList_GET_ITEM(storage_V5, 0);
    {Py_XINCREF(py_V5);}
    
            V5 = NULL;
            if (py_V5 == Py_None) {
                // We can either fail here or set V5 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_6;}
            }
            if (!PyArray_Check(py_V5)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_6;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V5)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V5;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V5),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_6;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V5) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V5));
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_6;}
            }
            
        V5 = (PyArrayObject*)(py_V5);
        Py_XINCREF(V5);
        
{

    py_V7 = PyList_GET_ITEM(storage_V7, 0);
    {Py_XINCREF(py_V7);}
    
            V7 = NULL;
            if (py_V7 == Py_None) {
                // We can either fail here or set V7 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 8;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_8;}
            }
            if (!PyArray_Check(py_V7)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 8;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_8;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V7)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V7;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V7),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 8;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_8;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V7) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V7));
                {
        __failure = 8;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_8;}
            }
            
        V7 = (PyArrayObject*)(py_V7);
        Py_XINCREF(V7);
        
{

    py_V9 = PyList_GET_ITEM(storage_V9, 0);
    {Py_XINCREF(py_V9);}
    
            V9 = NULL;
            if (py_V9 == Py_None) {
                // We can either fail here or set V9 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 10;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_10;}
            }
            if (!PyArray_Check(py_V9)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 10;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_10;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V9)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V9;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V9),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 10;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_10;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V9) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V9));
                {
        __failure = 10;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_10;}
            }
            
        V9 = (PyArrayObject*)(py_V9);
        Py_XINCREF(V9);
        
{

    py_V11 = PyList_GET_ITEM(storage_V11, 0);
    {Py_XINCREF(py_V11);}
    
            V11 = NULL;
            if (py_V11 == Py_None) {
                // We can either fail here or set V11 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 12;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_12;}
            }
            if (!PyArray_Check(py_V11)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 12;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_12;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V11)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V11;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V11),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 12;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_12;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V11) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V11));
                {
        __failure = 12;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_12;}
            }
            
        V11 = (PyArrayObject*)(py_V11);
        Py_XINCREF(V11);
        
{

    py_V13 = PyList_GET_ITEM(storage_V13, 0);
    {Py_XINCREF(py_V13);}
    
            V13 = NULL;
            if (py_V13 == Py_None) {
                // We can either fail here or set V13 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 14;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_14;}
            }
            if (!PyArray_Check(py_V13)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 14;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_14;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V13)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V13;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V13),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 14;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_14;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V13) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V13));
                {
        __failure = 14;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_14;}
            }
            
        V13 = (PyArrayObject*)(py_V13);
        Py_XINCREF(V13);
        
{

    py_V15 = PyList_GET_ITEM(storage_V15, 0);
    {Py_XINCREF(py_V15);}
    
            V15 = NULL;
            if (py_V15 == Py_None) {
                // We can either fail here or set V15 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 16;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_16;}
            }
            if (!PyArray_Check(py_V15)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 16;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_16;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V15)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V15;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V15),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 16;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_16;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V15) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V15));
                {
        __failure = 16;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_16;}
            }
            
        V15 = (PyArrayObject*)(py_V15);
        Py_XINCREF(V15);
        
{

    py_V17 = PyList_GET_ITEM(storage_V17, 0);
    {Py_XINCREF(py_V17);}
    
            V17 = NULL;
            if (py_V17 == Py_None) {
                // We can either fail here or set V17 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 18;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_18;}
            }
            if (!PyArray_Check(py_V17)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 18;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_18;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V17)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V17;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V17),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 18;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_18;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V17) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V17));
                {
        __failure = 18;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_18;}
            }
            
        V17 = (PyArrayObject*)(py_V17);
        Py_XINCREF(V17);
        
{

    py_V19 = PyList_GET_ITEM(storage_V19, 0);
    {Py_XINCREF(py_V19);}
    
            V19 = NULL;
            if (py_V19 == Py_None) {
                // We can either fail here or set V19 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 20;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_20;}
            }
            if (!PyArray_Check(py_V19)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 20;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_20;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V19)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V19;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V19),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 20;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_20;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V19) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V19));
                {
        __failure = 20;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_20;}
            }
            
        V19 = (PyArrayObject*)(py_V19);
        Py_XINCREF(V19);
        
{

    py_V21 = PyList_GET_ITEM(storage_V21, 0);
    {Py_XINCREF(py_V21);}
    
            V21 = NULL;
            if (py_V21 == Py_None) {
                // We can either fail here or set V21 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 22;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_22;}
            }
            if (!PyArray_Check(py_V21)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 22;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_22;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V21)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V21;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V21),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 22;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_22;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V21) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V21));
                {
        __failure = 22;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_22;}
            }
            
        V21 = (PyArrayObject*)(py_V21);
        Py_XINCREF(V21);
        
{

    py_V23 = PyList_GET_ITEM(storage_V23, 0);
    {Py_XINCREF(py_V23);}
    
            V23 = NULL;
            if (py_V23 == Py_None) {
                // We can either fail here or set V23 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 24;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_24;}
            }
            if (!PyArray_Check(py_V23)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 24;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_24;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V23)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V23;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V23),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 24;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_24;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V23) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V23));
                {
        __failure = 24;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_24;}
            }
            
        V23 = (PyArrayObject*)(py_V23);
        Py_XINCREF(V23);
        
{

    py_V25 = PyList_GET_ITEM(storage_V25, 0);
    {Py_XINCREF(py_V25);}
    
            V25 = NULL;
            if (py_V25 == Py_None) {
                // We can either fail here or set V25 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 26;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_26;}
            }
            if (!PyArray_Check(py_V25)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 26;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_26;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V25)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V25;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V25),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 26;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_26;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V25) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V25));
                {
        __failure = 26;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_26;}
            }
            
        V25 = (PyArrayObject*)(py_V25);
        Py_XINCREF(V25);
        
{

    py_V27 = PyList_GET_ITEM(storage_V27, 0);
    {Py_XINCREF(py_V27);}
    
            V27 = NULL;
            if (py_V27 == Py_None) {
                // We can either fail here or set V27 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 28;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_28;}
            }
            if (!PyArray_Check(py_V27)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 28;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_28;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V27)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V27;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V27),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 28;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_28;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V27) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V27));
                {
        __failure = 28;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_28;}
            }
            
        V27 = (PyArrayObject*)(py_V27);
        Py_XINCREF(V27);
        
{

    py_V29 = PyList_GET_ITEM(storage_V29, 0);
    {Py_XINCREF(py_V29);}
    
            V29 = NULL;
            if (py_V29 == Py_None) {
                // We can either fail here or set V29 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 30;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_30;}
            }
            if (!PyArray_Check(py_V29)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 30;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_30;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V29)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V29;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V29),
                             (long int) PyArray_NDIM(tmp),
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1,
                             (long int) PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1,
                             (long int) PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1,
                             (long int) PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1
            );
                {
        __failure = 30;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_30;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V29) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V29));
                {
        __failure = 30;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_30;}
            }
            
        V29 = (PyArrayObject*)(py_V29);
        Py_XINCREF(V29);
        
{
// Op class Elemwise

        npy_float32* V3_iter;
        
                npy_intp V3_n0;
                ssize_t V3_stride0;
                int V3_jump0_0;
                
                npy_intp V3_n1;
                ssize_t V3_stride1;
                int V3_jump1_1;
                
        npy_float32* V5_iter;
        
                int V5_jumpx_0;
                
                int V5_jumpx_1;
                
        npy_float32* V7_iter;
        
                int V7_jumpx_0;
                
                int V7_jumpx_1;
                
        npy_float32* V9_iter;
        
                int V9_jumpx_0;
                
                int V9_jumpx_1;
                
        npy_float32* V11_iter;
        
                int V11_jumpx_0;
                
                int V11_jumpx_1;
                
        npy_float32* V13_iter;
        
                npy_intp V13_n0;
                ssize_t V13_stride0;
                int V13_jump0_0;
                
                int V13_jumpx_1;
                
        npy_float32* V15_iter;
        
                npy_intp V15_n0;
                ssize_t V15_stride0;
                int V15_jump0_0;
                
                npy_intp V15_n1;
                ssize_t V15_stride1;
                int V15_jump1_1;
                
        npy_float32* V17_iter;
        
                int V17_jumpx_0;
                
                int V17_jumpx_1;
                
        npy_float32* V19_iter;
        
                int V19_jumpx_0;
                
                int V19_jumpx_1;
                
        npy_float32* V21_iter;
        
                int V21_jumpx_0;
                
                int V21_jumpx_1;
                
        npy_float32* V23_iter;
        
                npy_intp V23_n0;
                ssize_t V23_stride0;
                int V23_jump0_0;
                
                npy_intp V23_n1;
                ssize_t V23_stride1;
                int V23_jump1_1;
                
        npy_float32* V25_iter;
        
                npy_intp V25_n0;
                ssize_t V25_stride0;
                int V25_jump0_0;
                
                npy_intp V25_n1;
                ssize_t V25_stride1;
                int V25_jump1_1;
                
        npy_float32* V27_iter;
        
                npy_intp V27_n0;
                ssize_t V27_stride0;
                int V27_jump0_0;
                
                npy_intp V27_n1;
                ssize_t V27_stride1;
                int V27_jump1_1;
                
        npy_float32* V29_iter;
        
                int V29_jumpx_0;
                
                int V29_jumpx_1;
                

            if (PyArray_NDIM(V3) < 2) {
                PyErr_SetString(PyExc_ValueError, "Not enough dimensions on input.");
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
                V3_n1 = PyArray_DIMS(V3)[1];
                V3_stride1 = PyArray_STRIDES(V3)[1] / sizeof(npy_float32);
                V3_jump1_1 = (V3_stride1) - (0);
                //printf("V3_jump1_1 is:");
                //std::cout << V3_jump1_1 << std::endl;
                
                V3_n0 = PyArray_DIMS(V3)[0];
                V3_stride0 = PyArray_STRIDES(V3)[0] / sizeof(npy_float32);
                V3_jump0_0 = (V3_stride0) - (V3_n1*V3_stride1);
                //printf("V3_jump0_0 is:");
                //std::cout << V3_jump0_0 << std::endl;
                
                V5_jumpx_1 = -(0);
                //printf("V5_jumpx_1 is:");
                //std::cout << V5_jumpx_1 << std::endl;
                
                V5_jumpx_0 = -(0);
                //printf("V5_jumpx_0 is:");
                //std::cout << V5_jumpx_0 << std::endl;
                
                V7_jumpx_1 = -(0);
                //printf("V7_jumpx_1 is:");
                //std::cout << V7_jumpx_1 << std::endl;
                
                V7_jumpx_0 = -(0);
                //printf("V7_jumpx_0 is:");
                //std::cout << V7_jumpx_0 << std::endl;
                
                V9_jumpx_1 = -(0);
                //printf("V9_jumpx_1 is:");
                //std::cout << V9_jumpx_1 << std::endl;
                
                V9_jumpx_0 = -(0);
                //printf("V9_jumpx_0 is:");
                //std::cout << V9_jumpx_0 << std::endl;
                
                V11_jumpx_1 = -(0);
                //printf("V11_jumpx_1 is:");
                //std::cout << V11_jumpx_1 << std::endl;
                
                V11_jumpx_0 = -(0);
                //printf("V11_jumpx_0 is:");
                //std::cout << V11_jumpx_0 << std::endl;
                
            if (PyArray_NDIM(V13) < 1) {
                PyErr_SetString(PyExc_ValueError, "Not enough dimensions on input.");
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
                V13_jumpx_1 = -(0);
                //printf("V13_jumpx_1 is:");
                //std::cout << V13_jumpx_1 << std::endl;
                
                V13_n0 = PyArray_DIMS(V13)[0];
                V13_stride0 = PyArray_STRIDES(V13)[0] / sizeof(npy_float32);
                V13_jump0_0 = (V13_stride0) - (0);
                //printf("V13_jump0_0 is:");
                //std::cout << V13_jump0_0 << std::endl;
                
            if (PyArray_NDIM(V15) < 2) {
                PyErr_SetString(PyExc_ValueError, "Not enough dimensions on input.");
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
                V15_n1 = PyArray_DIMS(V15)[1];
                V15_stride1 = PyArray_STRIDES(V15)[1] / sizeof(npy_float32);
                V15_jump1_1 = (V15_stride1) - (0);
                //printf("V15_jump1_1 is:");
                //std::cout << V15_jump1_1 << std::endl;
                
                V15_n0 = PyArray_DIMS(V15)[0];
                V15_stride0 = PyArray_STRIDES(V15)[0] / sizeof(npy_float32);
                V15_jump0_0 = (V15_stride0) - (V15_n1*V15_stride1);
                //printf("V15_jump0_0 is:");
                //std::cout << V15_jump0_0 << std::endl;
                
                V17_jumpx_1 = -(0);
                //printf("V17_jumpx_1 is:");
                //std::cout << V17_jumpx_1 << std::endl;
                
                V17_jumpx_0 = -(0);
                //printf("V17_jumpx_0 is:");
                //std::cout << V17_jumpx_0 << std::endl;
                
                V19_jumpx_1 = -(0);
                //printf("V19_jumpx_1 is:");
                //std::cout << V19_jumpx_1 << std::endl;
                
                V19_jumpx_0 = -(0);
                //printf("V19_jumpx_0 is:");
                //std::cout << V19_jumpx_0 << std::endl;
                
                V21_jumpx_1 = -(0);
                //printf("V21_jumpx_1 is:");
                //std::cout << V21_jumpx_1 << std::endl;
                
                V21_jumpx_0 = -(0);
                //printf("V21_jumpx_0 is:");
                //std::cout << V21_jumpx_0 << std::endl;
                
            if (PyArray_NDIM(V23) < 2) {
                PyErr_SetString(PyExc_ValueError, "Not enough dimensions on input.");
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
                V23_n1 = PyArray_DIMS(V23)[1];
                V23_stride1 = PyArray_STRIDES(V23)[1] / sizeof(npy_float32);
                V23_jump1_1 = (V23_stride1) - (0);
                //printf("V23_jump1_1 is:");
                //std::cout << V23_jump1_1 << std::endl;
                
                V23_n0 = PyArray_DIMS(V23)[0];
                V23_stride0 = PyArray_STRIDES(V23)[0] / sizeof(npy_float32);
                V23_jump0_0 = (V23_stride0) - (V23_n1*V23_stride1);
                //printf("V23_jump0_0 is:");
                //std::cout << V23_jump0_0 << std::endl;
                
            if (PyArray_NDIM(V25) < 2) {
                PyErr_SetString(PyExc_ValueError, "Not enough dimensions on input.");
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
                V25_n1 = PyArray_DIMS(V25)[1];
                V25_stride1 = PyArray_STRIDES(V25)[1] / sizeof(npy_float32);
                V25_jump1_1 = (V25_stride1) - (0);
                //printf("V25_jump1_1 is:");
                //std::cout << V25_jump1_1 << std::endl;
                
                V25_n0 = PyArray_DIMS(V25)[0];
                V25_stride0 = PyArray_STRIDES(V25)[0] / sizeof(npy_float32);
                V25_jump0_0 = (V25_stride0) - (V25_n1*V25_stride1);
                //printf("V25_jump0_0 is:");
                //std::cout << V25_jump0_0 << std::endl;
                
            if (PyArray_NDIM(V27) < 2) {
                PyErr_SetString(PyExc_ValueError, "Not enough dimensions on input.");
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
                V27_n1 = PyArray_DIMS(V27)[1];
                V27_stride1 = PyArray_STRIDES(V27)[1] / sizeof(npy_float32);
                V27_jump1_1 = (V27_stride1) - (0);
                //printf("V27_jump1_1 is:");
                //std::cout << V27_jump1_1 << std::endl;
                
                V27_n0 = PyArray_DIMS(V27)[0];
                V27_stride0 = PyArray_STRIDES(V27)[0] / sizeof(npy_float32);
                V27_jump0_0 = (V27_stride0) - (V27_n1*V27_stride1);
                //printf("V27_jump0_0 is:");
                //std::cout << V27_jump0_0 << std::endl;
                
                V29_jumpx_1 = -(0);
                //printf("V29_jumpx_1 is:");
                //std::cout << V29_jumpx_1 << std::endl;
                
                V29_jumpx_0 = -(0);
                //printf("V29_jumpx_0 is:");
                //std::cout << V29_jumpx_0 << std::endl;
                
            if (V3_n0 != V13_n0)
            {
                PyErr_Format(PyExc_ValueError, "Input dimension mis-match. (input[%i].shape[%i] = %i, input[%i].shape[%i] = %i)",
                   0,
                   0,
                   V3_n0,
                   5,
                   0,
                   V13_n0
                );
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
            if (V3_n0 != V15_n0)
            {
                PyErr_Format(PyExc_ValueError, "Input dimension mis-match. (input[%i].shape[%i] = %i, input[%i].shape[%i] = %i)",
                   0,
                   0,
                   V3_n0,
                   6,
                   0,
                   V15_n0
                );
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
            if (V3_n0 != V23_n0)
            {
                PyErr_Format(PyExc_ValueError, "Input dimension mis-match. (input[%i].shape[%i] = %i, input[%i].shape[%i] = %i)",
                   0,
                   0,
                   V3_n0,
                   10,
                   0,
                   V23_n0
                );
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
            if (V3_n0 != V25_n0)
            {
                PyErr_Format(PyExc_ValueError, "Input dimension mis-match. (input[%i].shape[%i] = %i, input[%i].shape[%i] = %i)",
                   0,
                   0,
                   V3_n0,
                   11,
                   0,
                   V25_n0
                );
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
            if (V3_n0 != V27_n0)
            {
                PyErr_Format(PyExc_ValueError, "Input dimension mis-match. (input[%i].shape[%i] = %i, input[%i].shape[%i] = %i)",
                   0,
                   0,
                   V3_n0,
                   12,
                   0,
                   V27_n0
                );
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
            if (V3_n1 != V15_n1)
            {
                PyErr_Format(PyExc_ValueError, "Input dimension mis-match. (input[%i].shape[%i] = %i, input[%i].shape[%i] = %i)",
                   0,
                   1,
                   V3_n1,
                   6,
                   1,
                   V15_n1
                );
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
            if (V3_n1 != V23_n1)
            {
                PyErr_Format(PyExc_ValueError, "Input dimension mis-match. (input[%i].shape[%i] = %i, input[%i].shape[%i] = %i)",
                   0,
                   1,
                   V3_n1,
                   10,
                   1,
                   V23_n1
                );
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
            if (V3_n1 != V25_n1)
            {
                PyErr_Format(PyExc_ValueError, "Input dimension mis-match. (input[%i].shape[%i] = %i, input[%i].shape[%i] = %i)",
                   0,
                   1,
                   V3_n1,
                   11,
                   1,
                   V25_n1
                );
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            
            if (V3_n1 != V27_n1)
            {
                PyErr_Format(PyExc_ValueError, "Input dimension mis-match. (input[%i].shape[%i] = %i, input[%i].shape[%i] = %i)",
                   0,
                   1,
                   V3_n1,
                   12,
                   1,
                   V27_n1
                );
                {
        __failure = 31;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_31;}
            }
            

            if (V1) {
                Py_XDECREF(V1);
            }
            V1 = V3;
            Py_XINCREF(V1);
            
{

    std::vector< std::pair<int, int> > V3_loops(2);
    std::vector< std::pair<int, int> >::iterator V3_loops_it = V3_loops.begin();
    
            V3_loops_it->first = abs(PyArray_STRIDES(V3)[0]);
            
        V3_loops_it->second = 0;
        ++V3_loops_it;
        
            V3_loops_it->first = abs(PyArray_STRIDES(V3)[1]);
            
        V3_loops_it->second = 1;
        ++V3_loops_it;
        
    // rbegin and rend are reversed iterators, so this sorts in decreasing order
    std::sort(V3_loops.rbegin(), V3_loops.rend());
    

    int init_totals[2] = {V3_n0, V3_n1};
    
    V3_loops_it = V3_loops.begin();
    
        int TOTAL_0 = init_totals[V3_loops_it->second];
        ++V3_loops_it;
        
        int TOTAL_1 = init_totals[V3_loops_it->second];
        ++V3_loops_it;
        

    int init_strides[14][2] = {
        V3_stride0, V3_stride1, 
0, 0, 
0, 0, 
0, 0, 
0, 0, 
V13_stride0, 0, 
V15_stride0, V15_stride1, 
0, 0, 
0, 0, 
0, 0, 
V23_stride0, V23_stride1, 
V25_stride0, V25_stride1, 
V27_stride0, V27_stride1, 
0, 0
    };
    std::vector< std::pair<int, int> >::reverse_iterator V3_loops_rit;
    
        V3_loops_rit = V3_loops.rbegin();
            int V3_stride_l1 = init_strides[0][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V3_stride_l0 = init_strides[0][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V5_stride_l1 = init_strides[1][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V5_stride_l0 = init_strides[1][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V7_stride_l1 = init_strides[2][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V7_stride_l0 = init_strides[2][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V9_stride_l1 = init_strides[3][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V9_stride_l0 = init_strides[3][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V11_stride_l1 = init_strides[4][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V11_stride_l0 = init_strides[4][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V13_stride_l1 = init_strides[5][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V13_stride_l0 = init_strides[5][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V15_stride_l1 = init_strides[6][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V15_stride_l0 = init_strides[6][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V17_stride_l1 = init_strides[7][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V17_stride_l0 = init_strides[7][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V19_stride_l1 = init_strides[8][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V19_stride_l0 = init_strides[8][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V21_stride_l1 = init_strides[9][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V21_stride_l0 = init_strides[9][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V23_stride_l1 = init_strides[10][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V23_stride_l0 = init_strides[10][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V25_stride_l1 = init_strides[11][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V25_stride_l0 = init_strides[11][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V27_stride_l1 = init_strides[12][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V27_stride_l0 = init_strides[12][V3_loops_rit->second];
            ++V3_loops_rit;
            
        V3_loops_rit = V3_loops.rbegin();
            int V29_stride_l1 = init_strides[13][V3_loops_rit->second];
            ++V3_loops_rit;
            
            int V29_stride_l0 = init_strides[13][V3_loops_rit->second];
            ++V3_loops_rit;
            
V3_iter = (npy_float32*)(PyArray_DATA(V3));
V5_iter = (npy_float32*)(PyArray_DATA(V5));
V7_iter = (npy_float32*)(PyArray_DATA(V7));
V9_iter = (npy_float32*)(PyArray_DATA(V9));
V11_iter = (npy_float32*)(PyArray_DATA(V11));
V13_iter = (npy_float32*)(PyArray_DATA(V13));
V15_iter = (npy_float32*)(PyArray_DATA(V15));
V17_iter = (npy_float32*)(PyArray_DATA(V17));
V19_iter = (npy_float32*)(PyArray_DATA(V19));
V21_iter = (npy_float32*)(PyArray_DATA(V21));
V23_iter = (npy_float32*)(PyArray_DATA(V23));
V25_iter = (npy_float32*)(PyArray_DATA(V25));
V27_iter = (npy_float32*)(PyArray_DATA(V27));
V29_iter = (npy_float32*)(PyArray_DATA(V29));


        for(int ITER_0 = 0; ITER_0<TOTAL_0; ITER_0++)
        { // begin loop 0
            
            
        for(int ITER_1 = 0; ITER_1<TOTAL_1; ITER_1++)
        { // begin loop 1
            npy_float32 &V3_i = * ( V3_iter+V3_stride_l1*ITER_1+V3_stride_l0*ITER_0);
npy_float32 &V5_i = * ( V5_iter+V5_stride_l1*ITER_1+V5_stride_l0*ITER_0);
npy_float32 &V7_i = * ( V7_iter+V7_stride_l1*ITER_1+V7_stride_l0*ITER_0);
npy_float32 &V9_i = * ( V9_iter+V9_stride_l1*ITER_1+V9_stride_l0*ITER_0);
npy_float32 &V11_i = * ( V11_iter+V11_stride_l1*ITER_1+V11_stride_l0*ITER_0);
npy_float32 &V13_i = * ( V13_iter+V13_stride_l1*ITER_1+V13_stride_l0*ITER_0);
npy_float32 &V15_i = * ( V15_iter+V15_stride_l1*ITER_1+V15_stride_l0*ITER_0);
npy_float32 &V17_i = * ( V17_iter+V17_stride_l1*ITER_1+V17_stride_l0*ITER_0);
npy_float32 &V19_i = * ( V19_iter+V19_stride_l1*ITER_1+V19_stride_l0*ITER_0);
npy_float32 &V21_i = * ( V21_iter+V21_stride_l1*ITER_1+V21_stride_l0*ITER_0);
npy_float32 &V23_i = * ( V23_iter+V23_stride_l1*ITER_1+V23_stride_l0*ITER_0);
npy_float32 &V25_i = * ( V25_iter+V25_stride_l1*ITER_1+V25_stride_l0*ITER_0);
npy_float32 &V27_i = * ( V27_iter+V27_stride_l1*ITER_1+V27_stride_l0*ITER_0);
npy_float32 &V29_i = * ( V29_iter+V29_stride_l1*ITER_1+V29_stride_l0*ITER_0);

            
        {
            #define V1_i V3_i
            {
npy_float32 V31_tmp1;
V31_tmp1 = V29_i - V3_i;
npy_float32 V31_tmp2;
V31_tmp2 = V17_i * V19_i * V21_i * V27_i;
npy_float32 V31_tmp3;
V31_tmp3 = V11_i * V13_i * V25_i * V3_i;
npy_float32 V31_tmp4;
V31_tmp4 = V17_i * V19_i * V21_i * V23_i;
npy_float32 V31_tmp5;
V31_tmp5 = V9_i * V11_i * V13_i * V15_i * V3_i;
npy_int8 V31_tmp6;
V31_tmp6 = (V3_i <= V7_i);
npy_int8 V31_tmp7;
V31_tmp7 = (V3_i >= V5_i);
npy_float32 V31_tmp8;
V31_tmp8 = V31_tmp3 / V31_tmp2;
npy_float32 V31_tmp9;
V31_tmp9 = V31_tmp5 / V31_tmp4;
npy_int8 V31_tmp10;
V31_tmp10 = (V31_tmp7 & V31_tmp6);
npy_float32 V31_tmp11;
V31_tmp11 = V31_tmp9 + V31_tmp8;
V1_i = V31_tmp10 * V31_tmp11 * V31_tmp1;
}

            #undef V1_i
        }
        
        } // end loop 1
        
        } // end loop 0
        
}
__label_31:

double __DUMMY_31;

}
__label_30:

        if (V29) {
            Py_XDECREF(V29);
        }
        
    {Py_XDECREF(py_V29);}
    
double __DUMMY_30;

}
__label_28:

        if (V27) {
            Py_XDECREF(V27);
        }
        
    {Py_XDECREF(py_V27);}
    
double __DUMMY_28;

}
__label_26:

        if (V25) {
            Py_XDECREF(V25);
        }
        
    {Py_XDECREF(py_V25);}
    
double __DUMMY_26;

}
__label_24:

        if (V23) {
            Py_XDECREF(V23);
        }
        
    {Py_XDECREF(py_V23);}
    
double __DUMMY_24;

}
__label_22:

        if (V21) {
            Py_XDECREF(V21);
        }
        
    {Py_XDECREF(py_V21);}
    
double __DUMMY_22;

}
__label_20:

        if (V19) {
            Py_XDECREF(V19);
        }
        
    {Py_XDECREF(py_V19);}
    
double __DUMMY_20;

}
__label_18:

        if (V17) {
            Py_XDECREF(V17);
        }
        
    {Py_XDECREF(py_V17);}
    
double __DUMMY_18;

}
__label_16:

        if (V15) {
            Py_XDECREF(V15);
        }
        
    {Py_XDECREF(py_V15);}
    
double __DUMMY_16;

}
__label_14:

        if (V13) {
            Py_XDECREF(V13);
        }
        
    {Py_XDECREF(py_V13);}
    
double __DUMMY_14;

}
__label_12:

        if (V11) {
            Py_XDECREF(V11);
        }
        
    {Py_XDECREF(py_V11);}
    
double __DUMMY_12;

}
__label_10:

        if (V9) {
            Py_XDECREF(V9);
        }
        
    {Py_XDECREF(py_V9);}
    
double __DUMMY_10;

}
__label_8:

        if (V7) {
            Py_XDECREF(V7);
        }
        
    {Py_XDECREF(py_V7);}
    
double __DUMMY_8;

}
__label_6:

        if (V5) {
            Py_XDECREF(V5);
        }
        
    {Py_XDECREF(py_V5);}
    
double __DUMMY_6;

}
__label_4:

        if (V3) {
            Py_XDECREF(V3);
        }
        
    {Py_XDECREF(py_V3);}
    
double __DUMMY_4;

}
__label_2:

    if (!__failure) {
      
        {Py_XDECREF(py_V1);}
        if (!V1) {
            Py_INCREF(Py_None);
            py_V1 = Py_None;
        }
        else if ((void*)py_V1 != (void*)V1) {
            py_V1 = (PyObject*)V1;
        }

        {Py_XINCREF(py_V1);}

        if (V1 && !PyArray_ISALIGNED((PyArrayObject*) py_V1)) {
            PyErr_Format(PyExc_NotImplementedError,
                         "c_sync: expected an aligned array, got non-aligned array of type %ld"
                         " with %ld dimensions, with 3 last dims "
                         "%ld, %ld, %ld"
                         " and 3 last strides %ld %ld, %ld.",
                         (long int) PyArray_TYPE((PyArrayObject*) py_V1),
                         (long int) PyArray_NDIM(V1),
                         (long int) PyArray_NDIM(V1) >= 3 ?
        PyArray_DIMS(V1)[PyArray_NDIM(V1)-3] : -1,
                         (long int) PyArray_NDIM(V1) >= 2 ?
        PyArray_DIMS(V1)[PyArray_NDIM(V1)-2] : -1,
                         (long int) PyArray_NDIM(V1) >= 1 ?
        PyArray_DIMS(V1)[PyArray_NDIM(V1)-1] : -1,
                         (long int) PyArray_NDIM(V1) >= 3 ?
        PyArray_STRIDES(V1)[PyArray_NDIM(V1)-3] : -1,
                         (long int) PyArray_NDIM(V1) >= 2 ?
        PyArray_STRIDES(V1)[PyArray_NDIM(V1)-2] : -1,
                         (long int) PyArray_NDIM(V1) >= 1 ?
        PyArray_STRIDES(V1)[PyArray_NDIM(V1)-1] : -1
        );
            {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_2;}
        }
        
      PyObject* old = PyList_GET_ITEM(storage_V1, 0);
      {Py_XINCREF(py_V1);}
      PyList_SET_ITEM(storage_V1, 0, py_V1);
      {Py_XDECREF(old);}
    }
    
        if (V1) {
            Py_XDECREF(V1);
        }
        
    {Py_XDECREF(py_V1);}
    
double __DUMMY_2;

}

            
        if (__failure) {
            // When there is a failure, this code puts the exception
            // in __ERROR.
            PyObject* err_type = NULL;
            PyObject* err_msg = NULL;
            PyObject* err_traceback = NULL;
            PyErr_Fetch(&err_type, &err_msg, &err_traceback);
            if (!err_type) {err_type = Py_None;Py_INCREF(Py_None);}
            if (!err_msg) {err_msg = Py_None; Py_INCREF(Py_None);}
            if (!err_traceback) {err_traceback = Py_None; Py_INCREF(Py_None);}
            PyObject* old_err_type = PyList_GET_ITEM(__ERROR, 0);
            PyObject* old_err_msg = PyList_GET_ITEM(__ERROR, 1);
            PyObject* old_err_traceback = PyList_GET_ITEM(__ERROR, 2);
            PyList_SET_ITEM(__ERROR, 0, err_type);
            PyList_SET_ITEM(__ERROR, 1, err_msg);
            PyList_SET_ITEM(__ERROR, 2, err_traceback);
            {Py_XDECREF(old_err_type);}
            {Py_XDECREF(old_err_msg);}
            {Py_XDECREF(old_err_traceback);}
        }
        // The failure code is returned to index what code block failed.
        return __failure;
        
        }
    };
    }
    

        static int __struct_compiled_op_419221d82e561ea699b5345cebc3c46d_executor(__struct_compiled_op_419221d82e561ea699b5345cebc3c46d* self) {
            return self->run();
        }

        static void __struct_compiled_op_419221d82e561ea699b5345cebc3c46d_destructor(void* executor, void* self) {
            delete ((__struct_compiled_op_419221d82e561ea699b5345cebc3c46d*)self);
        }
        
//////////////////////
////  Functions
//////////////////////
static PyObject * instantiate(PyObject * self, PyObject *argtuple) {
  assert(PyTuple_Check(argtuple));
  if (16 != PyTuple_Size(argtuple)){ 
     PyErr_Format(PyExc_TypeError, "Wrong number of arguments, expected 16, got %i", (int)PyTuple_Size(argtuple));
     return NULL;
  }
  __struct_compiled_op_419221d82e561ea699b5345cebc3c46d* struct_ptr = new __struct_compiled_op_419221d82e561ea699b5345cebc3c46d();
  if (struct_ptr->init( PyTuple_GET_ITEM(argtuple, 0),PyTuple_GET_ITEM(argtuple, 1),PyTuple_GET_ITEM(argtuple, 2),PyTuple_GET_ITEM(argtuple, 3),PyTuple_GET_ITEM(argtuple, 4),PyTuple_GET_ITEM(argtuple, 5),PyTuple_GET_ITEM(argtuple, 6),PyTuple_GET_ITEM(argtuple, 7),PyTuple_GET_ITEM(argtuple, 8),PyTuple_GET_ITEM(argtuple, 9),PyTuple_GET_ITEM(argtuple, 10),PyTuple_GET_ITEM(argtuple, 11),PyTuple_GET_ITEM(argtuple, 12),PyTuple_GET_ITEM(argtuple, 13),PyTuple_GET_ITEM(argtuple, 14),PyTuple_GET_ITEM(argtuple, 15) ) != 0) {
    delete struct_ptr;
    return NULL;
  }
  PyObject* thunk = PyCObject_FromVoidPtrAndDesc((void*)(&__struct_compiled_op_419221d82e561ea699b5345cebc3c46d_executor), struct_ptr, __struct_compiled_op_419221d82e561ea699b5345cebc3c46d_destructor);
  return thunk; }

//////////////////////
////  Module init
//////////////////////
static PyMethodDef MyMethods[] = {
	{"instantiate", instantiate, METH_VARARGS, "undocumented"} ,
	{NULL, NULL, 0, NULL}
};
PyMODINIT_FUNC init419221d82e561ea699b5345cebc3c46d(void){
   import_array();
   (void) Py_InitModule("419221d82e561ea699b5345cebc3c46d", MyMethods);
}
