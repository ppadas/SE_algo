#include <rational.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("creation") {
    Rational a(10, 7);
    CHECK(a.num() == 10);
    CHECK(a.denum() == 7);

    a  = Rational(-10, 7);
    CHECK(a.num() == -10);
    CHECK(a.denum() == 7);

    a = Rational(10, -7);
    CHECK(a.num() == -10);
    CHECK(a.denum() == 7);

    a = Rational(-10, -7);
    CHECK(a.num() == 10);
    CHECK(a.denum() == 7);

    a = Rational(10);
    CHECK(a.num() == 10);
    CHECK(a.denum() == 1);

    a = Rational(-10);
    CHECK(a.num() == -10);
    CHECK(a.denum() == 1);
    
    a = Rational(12, -16);
    CHECK(a.num() == -3);
    CHECK(a.denum() == 4);
    
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

TEST_CASE("streams") {
    SUBCASE("istream works") {
        std::vector<std::string> input;
        std::vector<std::pair<int, int>> answers;

        input.push_back(" 10/15 ");
        answers.push_back(std::make_pair(2, 3));

        input.push_back(" -10/15 ");
        answers.push_back(std::make_pair(-2, 3));

        input.push_back(" 0/15 ");
        answers.push_back(std::make_pair(0, 1));

        for (size_t i = 0; i < input.size(); ++i) {
            std::istringstream instr(input[i]);
            Rational value;
            instr >> value;
            CHECK(value.num() == answers[i].first);
            CHECK(value.denum() == answers[i].second);
        }
    }

    SUBCASE("ostream works") {
        std::vector<std::string> answers;
        std::vector<Rational> rationals;

        rationals.push_back(Rational(10, 15));
        answers.push_back("2/3");

        rationals.push_back(Rational(-10, 15));
        answers.push_back("-2/3");

        rationals.push_back(Rational(0, 15));
        answers.push_back("0/1");

        for (size_t i = 0; i < rationals.size(); ++i) {
            std::ostringstream outstr;
            outstr << rationals[i];
            CHECK(answers[i] == outstr.str());
        }
    }

    SUBCASE("from istream to ostream") {
        std::vector<std::string> input;
        std::vector<std::string> output;

        input.push_back("10/15");
        output.push_back("2/3");

        input.push_back("-10/15");
        output.push_back("-2/3");

        input.push_back("0/15");
        output.push_back("0/1");

        input.push_back("-0/15");
        output.push_back("0/1");

        for (size_t i = 0; i < input.size(); ++i) {
            std::ostringstream outstr;
            std::istringstream instr(input[i]);
            Rational value;
            instr >> value;
            outstr << value;
            CHECK(outstr.str() == output[i]);
        }
    }

    SUBCASE("incorrect input") {
        std::vector<std::string> input;
        input.push_back("1/0");
        input.push_back("2/");
        input.push_back("/3");
        input.push_back("5");
        input.push_back("2/-3");

        for(size_t i = 0; i < input.size(); ++i) {
            std::istringstream instr(input[i]);
            Rational value;
            instr >> value;
            CHECK(instr.fail());
        }
    }
}