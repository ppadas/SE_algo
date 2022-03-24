

class M3i {
public:
    M3i() = default;
    M3i(const int x, const int y, const int z);
    M3i(const M3i&); //конструктор копирования
    M3i& operator=(const M3i&); //присваивание копированием
    M3i(M3i&&); //конструктор перемещения
    M3i& operator=(M3i&&); //присваивание перемещением

    ~M3i();

    M3i clone() const;

    M3i& resize(const int x, const int y, const int z);

    int at(const int x, const int y, const int z) const;
    int& at(const int x, const int y, const int z);

    int size(const int dim) const;
    void fill(const int value);

private:
    struct Data {
        Data() = default;
        Data(int* values, int* shape_other, int ref_counter) : values(values), ref_counter(ref_counter) {
            shape[0] = shape_other[0];
            shape[1] = shape_other[1];
            shape[2] = shape_other[2];
        }
        int* values = nullptr;
        int shape[3] = {0, 0, 0};
        int ref_counter;
    };
    
    Data* data;

    void deleteCurrent();
};