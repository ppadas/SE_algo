#include <vector>
#include <iostream>

class BitSet {
public:

private:
 	class BitHolder;


public:
  	BitSet() = default;
  	BitSet(const BitSet &) = default;
  	BitSet(BitSet &&) = default;
	
	BitSet(const int length, const bool default_value=false);
 
  	BitSet& operator=(const BitSet &) = default;
  	BitSet& operator=(BitSet &&) = default;
	
	~BitSet() = default;

	BitSet& operator|=(const BitSet& other);
	BitSet& operator^=(const BitSet& other);
	BitSet& operator&=(const BitSet& other);
	const BitSet operator~() const;
 	
  	int Size() const;
	
  	void Resize(const int new_size);
	void Fill(const bool value);
 	
  	BitHolder operator[](const int idx);
  	bool operator[](const int idx) const;

private:
	std::vector<uint8_t> data;
	int size = 0;
	const int block_size = 16;

	class BitHolder {
	public:
  		BitHolder() = delete;
  		BitHolder(const BitHolder &) = default;
  		BitHolder(BitHolder &&) = default;
		BitHolder(BitSet& owner, const int offset) : owner(owner), offset(offset) {}

  		BitHolder& operator=(const BitHolder &) = default;
   		BitHolder& operator=(bool);
  		BitHolder& operator=(BitHolder &&) = default;
    
  		operator bool() const;
	private:
		BitSet& owner;
		int offset = 0;
  	};
};


const BitSet operator|(const BitSet& first, const BitSet& second);
const BitSet operator&(const BitSet& first, const BitSet& second);
const BitSet operator^(const BitSet& first, const BitSet& second);

std::istream& operator>>(std::istream& istrm, BitSet& bs);
std::ostream& operator<<(std::ostream& ostrm, const BitSet& bs);
