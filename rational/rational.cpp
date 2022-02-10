

class Rational{
public:
    Rational() = default;
    Rational(const Rational&) = default;
    Rational(const int numerator, const int denominator = 1)
    : numerator(numerator), denominator(denominator) {
        //проверка на 0 знаменателя + сократить на Нод
        if (0 == denominator) {
            //throw
        }
    }

    ~Rational() = default;
    //Хочу конструктор перемещения
    //Хочу получение полей

    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator/=(const Rational& right);
    Rational& operator*=(const Rational& right);
    bool operator<(const Rational& other) const;
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    Rational& operator-();
    Rational& operator++();
    Rational& operator--();
    Rational operator++(int);
    Rational operator--(int);

private:
    void normalize() {

    }

    //взаимно простые числитель и знаменатель
    int numerator = 0;
    //натуральное число
    int denominator = 1;
};

std::istream& operator>>(std::istream& in, Rational& bigInt);
std::ostream& operator<<(std::ostream& out, const Rational& bigInt);

Rational operator+(const Rational& left, const Rational& right) {
    return Rational(left) += right;
}