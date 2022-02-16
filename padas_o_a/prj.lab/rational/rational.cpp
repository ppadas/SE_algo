#include "rational.h"

int Rational::getNumerator() const {
    return numerator;
}

int Rational::getDenominator() const {
    return denominator;
}

Rational& Rational::operator+=(const Rational& right) {
    numerator = right.denominator * numerator + right.numerator * denominator;
    denominator = right.denominator * denominator;
    normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& right) {
    numerator = right.denominator * numerator - right.numerator * denominator;
    denominator = right.denominator * denominator;
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& right) {
    if (right == Rational(0)) {
        throw rationalException("Devision to 0");
    }
    numerator = right.denominator * numerator;
    denominator = right.numerator * denominator;
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& right) {
    numerator = right.numerator * numerator;
    denominator = right.denominator * denominator;
    normalize();
    return *this;
}

bool Rational::operator==(const Rational& right) const {
    return numerator == right.numerator && denominator == right.denominator;
}

bool Rational::operator<(const Rational& right) const {
    return (*this - right).signum() == -1;
}

bool Rational::operator>(const Rational& right) const {
    return right < *this;
}

bool Rational::operator!=(const Rational& right) const {
    return !(*this == right);
}

bool Rational::operator<=(const Rational& right) const {
    return !(*this > right);
}

bool Rational::operator>=(const Rational& right) const {
    return !(*this < right);
}

Rational& Rational::operator-() {
    numerator *= -1;
    return *this;
}

Rational& Rational::operator++() {
    numerator += denominator;
    normalize();
    return *this;
}

Rational& Rational::operator--() {
    numerator -= denominator;
    normalize();
    return *this;
}

Rational Rational::operator++(int) {
    Rational old_value = *this;
    ++(*this);
    return old_value;
}

Rational Rational::operator--(int) {
    Rational old_value = *this;
    --(*this);
    return old_value;
}


int Rational::gcd (const int a, const int b) const {
    int bigger = std::max(a, b);
    int smaller = std::min(a, b);
    while (smaller != 0) {
        bigger %= smaller;
        std::swap(bigger, smaller);
    }
    return bigger;
}

void Rational::normalize() {
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    int gcd_value = gcd(std::abs(numerator), denominator);
    denominator /= gcd_value;
    numerator /= gcd_value;
}

int Rational::signum() const {
    if (numerator == 0) {
        return 0;
    }
    return numerator > 0 ? 1 : -1;
}

void Rational::updateWith(const int num, const int den) {
    numerator = num;
    denominator = den;
}

Rational operator+(const Rational& left, const Rational& right) {
    return Rational(left) += right;
}

Rational operator-(const Rational& left, const Rational& right) {
    return Rational(left) -= right;
}

Rational operator*(const Rational& left, const Rational& right) {
    return Rational(left) *= right;
}

Rational operator/(const Rational& left, const Rational& right) {
    return Rational(left) /= right;
}

std::istream& operator>>(std::istream& in, Rational& value) {
    int numerator = 0;
    int denominator = 1;
    in >> numerator >> denominator;
    value.updateWith(numerator, denominator);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Rational& value) {
    out << value.getNumerator() << '\\' << value.getDenominator();
    return out;
}