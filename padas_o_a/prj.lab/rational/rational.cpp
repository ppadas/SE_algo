#include <rational.h>
#include <string>

int Rational::num() const {
    return numerator;
}

int Rational::denum() const {
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

std::istream& Rational::read_from(std::istream& istrm) {
    std::string str;
    bool only_digit = false;
    istrm >> str;
    int slash_position = -1;
    int offset = str[0] == '-' ? 1 : 0;
    for (size_t i = offset; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            if(only_digit) {
                istrm.setstate(std::ios_base::failbit);
                return istrm;
            }
            if (str[i] == '/') {
                if (i == 0 || i == (str.length() - 1)) {
                    istrm.setstate(std::ios_base::failbit);
                    return istrm;
                }
                only_digit = true;
                slash_position = i;
            } else {
                istrm.setstate(std::ios_base::failbit);
                return istrm;
            }
        }
    }
    if (slash_position == -1) {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    numerator = std::stoi(str.substr(0, slash_position));
    denominator = std::stoi(str.substr(slash_position + 1, str.length()));
    if (denominator == 0 || denominator < 0) {
        //более аккуратно не eof;
        istrm.setstate(std::ios_base::failbit);
    }
    normalize();
    return istrm;
}

std::ostream& Rational::write_to(std::ostream& ostrm) const {
    ostrm << numerator << "/" << denominator;
    return ostrm;
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
    if (numerator == 0) {
        denominator = 1;
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
    return value.read_from(in);
}

std::ostream& operator<<(std::ostream& out, const Rational& value) {
    return value.write_to(out);
}