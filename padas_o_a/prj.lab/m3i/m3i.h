

class M3I {
public:
    M3I() = default;
    M3I(const int x, const int y, const int z);
    M3I(const M3I&); //конструктор копирования
    M3I& operator=(const M3I&); //присваивание копированием
    M3I(M3I&&); //конструктор перемещения
    M3I& operator=(M3I&&); //присваивание перемещением

    ~M3I();

    M3I clone() const;

    M3I& resize(const int x, const int y, const int z);

    int at(const int x, const int y, const int z) const;
    int& at(const int x, const int y, const int z);

    int size(const int dim) const;
    void fill(const int value);

private:
    int* values = nullptr;
    int shape[3] = {0, 0, 0};
    int* ref_counter;

    void deleteCurrent();
};