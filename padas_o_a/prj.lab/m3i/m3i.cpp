#include "m3i.h"

M3I::M3I(const int x, const int y, const int z) {
    shape[0] = x;
    shape[1] = y;
    shape[2] = z;
    values = new int[x * y * z];
    ref_counter = new int[1];
    *ref_counter = 1;
}

M3I::M3I(const M3I& other) {
    shape[0] = other.size(0);
    shape[1] = other.size(1);
    shape[2] = other.size(2);
    values = other.values;
    ref_counter = other.ref_counter;
    ++*ref_counter;
}

M3I& M3I::operator=(const M3I& other) {
    deleteCurrent();
    shape[0] = other.size(0);
    shape[1] = other.size(1);
    shape[2] = other.size(2);
    values = other.values;
    ref_counter = other.ref_counter;
    ++*ref_counter;
    return *this;
}

M3I::M3I(M3I&& other) {
    shape[0] = other.size(0);
    shape[1] = other.size(1);
    shape[2] = other.size(2);
    values = other.values;
    ref_counter = other.ref_counter;
    other.values = nullptr;
    other.ref_counter = nullptr;
}

M3I& M3I::operator=(M3I&& other) {
    deleteCurrent();
    shape[0] = other.size(0);
    shape[1] = other.size(1);
    shape[2] = other.size(2);
    values = other.values;
    ref_counter = other.ref_counter;
    other.values = nullptr;
    other.ref_counter = nullptr;
    return *this;
}

M3I::~M3I() {
    deleteCurrent();
}

M3I M3I::clone() const {
    M3I copy(shape[0], shape[1], shape[2]);
    for (int x = 0; x < shape[0]; ++x) {
        for (int y = 0; y < shape[1]; ++y) {
            for (int z = 0; z < shape[2]; ++z) {
                copy.at(x, y, z) = at(x, y, z);
            }
        }
    }
    return copy;
}

M3I& M3I::resize(const int x, const int y, const int z) {
    int* old_values = values;
    int old_shape[3] = {shape[0], shape[1], shape[2]};
    shape[0] = x;
    shape[1] = y;
    shape[2] = z;
    values = new int[x * y * z];
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                if (i >= old_shape[0] || j >= old_shape[1] || k >= old_shape[2]) {
                    at(i, j, k) = 0; 
                } else {
                    at(i, j, k) = old_values[i * old_shape[1] * old_shape[2] + j * old_shape[2] + k];
                }
            }
        }
    }
    delete[] old_values;
    return *this;
}

int M3I::at(const int x, const int y, const int z) const {
    return values[x * (shape[1] * shape[2]) + y * shape[2] + z];
}

int& M3I::at(const int x, const int y, const int z) {
    return values[x * (shape[1] * shape[2]) + y * shape[2] + z];
}

int M3I::size(const int dim) const {
    if (dim > 2 || dim < 0) {
        //throw;
    }
    return shape[dim];
}

void M3I::fill(const int value) {
    for (int x = 0; x < size(0); ++x) {
        for (int y = 0; y < size(1); ++y) {
            for (int z = 0; z < size(2); ++z) {
                at(x, y, z) = 0;
            }
        }
    }
}

void M3I::deleteCurrent() {
    if (ref_counter != nullptr) {
        --*ref_counter;
        if (*ref_counter == 0) {
            if (values != nullptr) {
                delete[] values;
            }
            delete ref_counter;
        }
    }
}