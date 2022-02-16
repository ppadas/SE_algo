#include "rational.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("creation") {
    Rational a(10, 7);
    CHECK(a.getNumerator() == 10);
    CHECK(a.getDenominator() == 7);

    a  = Rational(-10, 7);
    CHECK(a.getNumerator() == -10);
    CHECK(a.getDenominator() == 7);

    a = Rational(10, -7);
    CHECK(a.getNumerator() == -10);
    CHECK(a.getDenominator() == 7);

    a = Rational(-10, -7);
    CHECK(a.getNumerator() == 10);
    CHECK(a.getDenominator() == 7);

    a = Rational(10);
    CHECK(a.getNumerator() == 10);
    CHECK(a.getDenominator() == 1);

    a = Rational(-10);
    CHECK(a.getNumerator() == -10);
    CHECK(a.getDenominator() == 1);
    
    a = Rational(12, -16);
    CHECK(a.getNumerator() == -3);
    CHECK(a.getDenominator() == 4);
    
    int flag = false;
    try {
        a = Rational(0, 0);
    }
    catch (rationalException exp) {
        flag = true;
    }
    CHECK(flag);
}

TEST_CASE("arithmetic") {
    SUBCASE("multiplication"){
        Rational a(2, 7);
        Rational b(5, 3);
        CHECK(a * b == Rational(10, 21));
        CHECK((a *= b) == Rational(10, 21));
        CHECK(a == Rational(10, 21));
        a = Rational(-2, 7);
        CHECK(a * b == Rational(-10, 21));
    }

    SUBCASE("devision") {
        Rational a(2, 7);
        Rational b(5, 3);
        CHECK(a / b == Rational(6, 35));
        CHECK((a /= b) == Rational(6, 35));
        CHECK(a == Rational(6, 35));
        a = Rational(-2, 7);
        CHECK(a / b == Rational(-6, 35));
        int flag = false;
        try {
            b = Rational(0);
            a /= b;
        }
        catch (rationalException exp) {
            flag = true;
        }
        CHECK(flag);
    }

    SUBCASE("addition") {
        Rational a(2, 7);
        Rational b(5, 3);
        CHECK(a + b == Rational(41, 21));
        CHECK((a += b) == Rational(41, 21));
        CHECK(a == Rational(41, 21));
    }

    SUBCASE("difference") {
        Rational a(2, 7);
        Rational b(5, 3);
        CHECK(a - b == Rational(-29, 21));
        CHECK((a -= b) == Rational(-29, 21));
        CHECK(a == Rational(-29, 21));
    }
}

TEST_CASE("comparisons") {
    SUBCASE("equality") {
        Rational a(2, 7);
        Rational b(-2, -7);
        CHECK(a == b);
        CHECK(a <= b);
        CHECK(a >= b);
    }

    SUBCASE("smaller") {
        Rational a(2, 7);
        Rational b(20, 6);
        CHECK(a <= b);
        CHECK(!(a >= b));
        CHECK(!(a == b));
        CHECK(a != b);
    }

    SUBCASE("bigger") {
        Rational a(20, 6);
        Rational b(2, 7);
        CHECK(a >= b);
        CHECK(!(a <= b));
        CHECK(!(a == b));
        CHECK(a != b);
    }
}

TEST_CASE("increment/decrement") {
    Rational a (12, 16); //3 4
    CHECK(++a == Rational(7, 4));
    CHECK(a == Rational(7, 4));
    CHECK(a++ == Rational(7, 4));
    CHECK(a == Rational(11, 4));

    CHECK(--a == Rational(7, 4));
    CHECK(a == Rational(7, 4));
    CHECK(a-- == Rational(7, 4));
    CHECK(a == Rational(3, 4));
    CHECK(-a == Rational(-3, 4));
    CHECK(a == Rational(-3, 4));
}