#ifndef __RATIONAL_LAB_H__
#define __RATIONAL_LAB_H__

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
    Rational(const Rational&) = default; //конструктор копирования
    Rational& operator=(const Rational&) = default; //присваивание копированием
    Rational(Rational&&) = default; //конструктор перемещения
    Rational& operator=(Rational&&) = default; //присваивание перемещением
    Rational(const int numerator, const int denominator = 1) //конструктор
    : numerator(numerator), denominator(denominator) {
        if (0 == denominator) {
            throw rationalException("Denominator can't be 0");
        }
        normalize();
    }

    ~Rational() = default;
    //Хочу конструктор перемещения

    int num() const;
    int denum() const;

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

    std::istream& read_from(std::istream& istrm);
    std::ostream& write_to(std::ostream& ostrm) const;

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

std::istream& operator>>(std::istream& in, Rational& value);
std::ostream& operator<<(std::ostream& out, const Rational& value);

#endif //__RATIONAL_LAB_H__