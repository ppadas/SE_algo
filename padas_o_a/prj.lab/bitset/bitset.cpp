#include <bitset.h>
#include <stdexcept>
#include <vector>
#include <string>

BitSet::BitSet(const int length, const bool default_value) {
    if (length <= 0) {
        throw std::out_of_range("Length can't be <= 0");
    }
    size = length;
    data = std::vector<uint8_t>((length + block_size - 1) / block_size, default_value);
}

BitSet& BitSet::operator|=(const BitSet& other) {
    if (Size() != other.Size()) {
        throw std::out_of_range("Sizes must be the same");
    }
    for (long unsigned int i = 0; i < data.size(); ++i) {
        data[i] |= other.data[i];
    }
    return *this;
}

BitSet& BitSet::operator^=(const BitSet& other) {
    if (Size() != other.Size()) {
        throw std::out_of_range("Sizes must be the same");
    }
    for (long unsigned int i = 0; i < data.size(); ++i) {
        data[i] ^= other.data[i];
    }
    return *this;
}


BitSet& BitSet::operator&=(const BitSet& other) {
    if (Size() != other.Size()) {
        throw std::out_of_range("Sizes must be the same");
    }
    for (long unsigned int i = 0; i < data.size(); ++i) {
        data[i] &= other.data[i];
    }
    return *this;
}

const BitSet BitSet::operator~() const {
    BitSet inverted(size, false);
    std::cout << data.size() << " " << inverted.data.size() << "\n";
    for (long unsigned int i = 0; i < data.size(); ++i) {
        uint8_t result = ~data[i];
        inverted[i] = result;
    }
    return inverted;
}

int BitSet::Size() const {
    return size;
}

void BitSet::Resize(const int new_size) { 
    if (new_size <= 0) {
        throw std::out_of_range("Size must be >= 0");
    }
    size = new_size;
    data.resize((new_size + block_size - 1) / block_size, ~0);
}

void BitSet::Fill(const bool value) {
    uint8_t to_fill = value ? ~0 : 0; //попробовать 255
    for (long unsigned int i = 0; i < data.size(); ++i) {
        data[i] = to_fill;
    }
}

BitSet::BitHolder BitSet::operator[](const int idx) {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Invalid index");
    }
    return BitHolder(*this, idx);
}

bool BitSet::operator[](const int idx) const {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Invalid index");
    }
    int index = idx / block_size;
    int offset = idx - index * block_size;
    return (data[index] & (1 << offset));
}

BitSet::BitHolder& BitSet::BitHolder::operator=(bool value) {
    owner[offset] = value; // не должно работать
    return *this;
}

BitSet::BitHolder::operator bool() const {
    const BitSet copy = owner; //костыль
    return copy[offset];
}

const BitSet operator|(const BitSet& first, const BitSet& second) {
    if (first.Size() == second.Size()) {
        throw std::out_of_range("Sizes must be the same");
    }
    BitSet result = first;
    return result |= second;
}

const BitSet operator&(const BitSet& first, const BitSet& second) {
    if (first.Size() == second.Size()) {
        throw std::out_of_range("Sizes must be the same");
    }
    BitSet result = first;
    return result &= second;
}

const BitSet operator^(const BitSet& first, const BitSet& second) {
    if (first.Size() == second.Size()) {
        throw std::out_of_range("Sizes must be the same");
    }
    BitSet result = first;
    return result ^= second;
}

std::ostream& operator<<(std::ostream& ostrm, const BitSet& bs) {
    for(int i = 0; i < bs.Size(); ++i) {
        ostrm << bs[i];
    }
    return ostrm;
}

std::istream& operator>>(std::istream& istrm, BitSet& bs) {
    std::string input;
    istrm >> input;
    if (input.size() == 0) {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    bs.Resize(input.size());
    for (long unsigned int i = 0; i < input.size(); ++i) {
        if (input[i] != '0' || input[i] != '1') {
            istrm.setstate(std::ios_base::failbit);
            return istrm;
        }
        bs[i] = (input[i] == '1');
    }
    return istrm;
}