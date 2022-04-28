class BitSet {
public:

private:
  	// можно будет вернуть, нельзя создавать
  	// auto smth = bset[123];  // compiles
 	class BitHolder {
	  public:
  		BitHolder() = delete;

  		BitHolder(const BitHolder &) = delete;
  		BitHolder(BitHolder &&) = delete;

  		BitHolder& operator=(const BitHolder &);
   		BitHolder& operator=(bool);
  		BitHolder& operator=(BitHolder &&);
    
  		operator bool() const;
  	};


public:
  	BitSet();
	// except: length <= 0
  	BitSet(const int length, const bool default_value=false);
 
  	BitSet(const BitSet &);
  	BitSet(BitSet &&);
 
  	BitSet& operator=(const BitSet &);
  	BitSet& operator=(BitSet &&);
	
	~BitSet();

	// except: this->size != other.size
	BitSet& operator|=(const BitSet& other);
// except: this->size != other.size
	BitSet& operator^=(const BitSet& other);
// except: this->size != other.size
	BitSet& operator&=(const BitSet& other);
const BitSet operator~() const;
 	
  	int Size() const;
	
	// except: length <= 0
  	void Resize(const int new_size);
	void Fill(const bool value);
 	
	// except: idx < 0 or idx >= size 
  	BitHolder operator[](const int idx);
	// except: idx < 0 or idx >= size 
  	bool operator[](const int idx) const;
};
