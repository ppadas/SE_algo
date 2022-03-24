#include "m3i.h"

M3i::M3i(const int x, const int y, const int z) {
    int shape[3] = {x, y, z};
    data = new Data(new int[x * y * z], shape, 1);
}

M3i::M3i(const M3i& other) {
    data = other.data;
    data->ref_counter++;
}

M3i& M3i::operator=(const M3i& other) {
    deleteCurrent();
    data = other.data;
    data->ref_counter++;
    return *this;
}

M3i::M3i(M3i&& other) {
    data = other.data;
    other.data = nullptr;
}

M3i& M3i::operator=(M3i&& other) {
    deleteCurrent();
    data = other.data;
    other.data = nullptr;
    return *this;
}

M3i::~M3i() {
    deleteCurrent();
}

M3i M3i::clone() const {
    M3i copy(data->shape[0], data->shape[1], data->shape[2]);
    for (int x = 0; x < data->shape[0]; ++x) {
        for (int y = 0; y < data->shape[1]; ++y) {
            for (int z = 0; z < data->shape[2]; ++z) {
                copy.at(x, y, z) = at(x, y, z);
            }
        }
    }
    return copy;
}

M3i& M3i::resize(const int x, const int y, const int z) {
    int* old_values = data -> values;
    int old_shape[3] = {data -> shape[0], data -> shape[1], data -> shape[2]};
    data->shape[0] = x;
    data->shape[1] = y;
    data->shape[2] = z;
    data -> values = new int[x * y * z];
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

int M3i::at(const int x, const int y, const int z) const {
    return data -> values[x * (data -> shape[1] * data -> shape[2]) + y * data -> shape[2] + z];
}

int& M3i::at(const int x, const int y, const int z) {
    return data -> values[x * (data -> shape[1] * data -> shape[2]) + y * data -> shape[2] + z];
}

int M3i::size(const int dim) const {
    if (dim > 2 || dim < 0) {
        //throw;
    }
    return data -> shape[dim];
}

void M3i::fill(const int value) {
    for (int x = 0; x < size(0); ++x) {
        for (int y = 0; y < size(1); ++y) {
            for (int z = 0; z < size(2); ++z) {
                at(x, y, z) = 0;
            }
        }
    }
}

void M3i::deleteCurrent() {
    if (data -> ref_counter = 0) {
        --data -> ref_counter;
        if (data -> ref_counter == 0) {
            if (data -> values != nullptr) {
                delete[] data -> values;
            }
            delete data;
        }
    }
}