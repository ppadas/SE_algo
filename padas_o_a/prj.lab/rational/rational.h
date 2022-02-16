#include <iostream>
#include <algorithm>

class rationalException { 
public:
	rationalException(std::string error) : m_error(error) {}
 
	const char* getError() { 
        return m_error.c_str(); 
    }

private:
	std::string m_error;
};

class Rational{
public:
    Rational() = default;
    Rational(const Rational&) = default;
    Rational(const int numerator, const int denominator = 1)
    : numerator(numerator), denominator(denominator) {
        if (0 == denominator) {
            throw rationalException("Denominator can't be 0");
        }
        normalize();
    }

    ~Rational() = default;
    //Хочу конструктор перемещения

    int getNumerator() const;
    int getDenominator() const;

    friend std::istream& operator>>(std::istream& in, Rational& value);
    friend std::ostream& operator<<(std::ostream& out, const Rational& value);

    Rational& operator+=(const Rational& right);
    Rational& operator-=(const Rational& right);
    Rational& operator/=(const Rational& right);
    Rational& operator*=(const Rational& right);
    bool operator==(const Rational& right) const;
    bool operator<(const Rational& right) const;
    bool operator>(const Rational& right) const;
    bool operator!=(const Rational& right) const;
    bool operator<=(const Rational& right) const;
    bool operator>=(const Rational& right) const;
    Rational& operator-();
    Rational& operator++();
    Rational& operator--();
    Rational operator++(int);
    Rational operator--(int);

private:
    int gcd (const int a, const int b) const;
    void normalize();
    int signum() const;
    void updateWith(const int num, const int den);

    //взаимно простые числитель и знаменатель
    int numerator = 0;
    //натуральное число
    int denominator = 1;
};

Rational operator+(const Rational& left, const Rational& right);
Rational operator-(const Rational& left, const Rational& right);
Rational operator*(const Rational& left, const Rational& right);
Rational operator/(const Rational& left, const Rational& right);
