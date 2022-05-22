#include <bitset.h>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("simple creation") {
    SUBCASE("without arguments") {
        CHECK_NOTHROW(BitSet bs);
        BitSet bs;
        CHECK(bs.Size() == 0);
    }

    SUBCASE("with length") {
        CHECK_NOTHROW(BitSet bs(10));
        const BitSet bs(10);
        CHECK(bs.Size() == 10);
        for (int i = 0; i < bs.Size(); ++i) {
            CHECK(!bs[i]);
        }
    }

    SUBCASE("with length and default value") {
        CHECK_NOTHROW(BitSet bs(10, true));
        const BitSet bs(10, true);
        CHECK(bs.Size() == 10);
        for (int i = 0; i < bs.Size(); ++i) {
            CHECK(bs[i]);
        }
    }

    SUBCASE("copy") {
        BitSet bs(10, true);
        bs[0] = false;
        BitSet copy = bs;
        bs[0] = true;
        CHECK(bs.Size() == copy.Size());
        CHECK(copy[0] == false);
        CHECK(bs[0] == true);
        for (int i = 1; i < bs.Size(); ++i) {
            CHECK(copy[i] == bs[i]);
        }
    }

    SUBCASE("move") {
        BitSet bs(10, true);
        bs[0] = false;
        BitSet move(std::move(bs));
        CHECK(move.Size() == 10);
        CHECK(move[0] == false);
        for (int i = 1; i < bs.Size(); ++i) {
            CHECK(move[i]);
        }
    }

    SUBCASE("errors") {
        //To do
    }
}

TEST_CASE("BitHolder") {
    SUBCASE("one difference") {
        BitSet bs(10, false);
        bs[0] = true;
        CHECK(bs[0]);
        for (int i = 1; i < bs.Size(); ++i) {
            CHECK(!bs[i]);
        }
    }

    SUBCASE("many differences") {
        BitSet bs(10, false);
        for (int i = 0; i < bs.Size(); ++i) {
            if (i % 2 == 0) {
                bs[i] = true;
            }
        }
        for (int i = 0; i < bs.Size(); ++i) {
            if (i % 2 == 0) {
                CHECK(bs[i]);
            } else {
                CHECK(!bs[i]);
            }
        }
    }
}

TEST_CASE("bit operations") {
    SUBCASE("~") {
        BitSet bs(10, false);
        for (int i = 0; i < bs.Size(); ++i) {
            if (i % 2 == 0) {
                bs[i] = true;
            }
        }
        bs = ~bs;
        for (int i = 0; i < bs.Size(); ++i) {
            if (i % 2 == 0) {
                CHECK(!bs[i]);
            } else {
                CHECK(bs[i]);
            }
        }
    }
    SUBCASE("&") {
        BitSet bs2(20, false);
        for (int i = 0; i < bs2.Size(); ++i) {
            if (i % 2 == 0) {
                bs2[i] = true;
            }
        }
        BitSet bs3(20, false);
        for (int i = 0; i < bs3.Size(); ++i) {
            if (i % 3 == 0) {
                bs3[i] = true;
            }
        }
        BitSet result = bs2 & bs3;
        for (int i = 0; i < result.Size(); ++i) {
            if (i % 6 == 0) {
                CHECK(result[i]);
            } else {
                CHECK(!result[i]);
            }
        }
    }

    SUBCASE("|") {
        BitSet bs2(20, false);
        for (int i = 0; i < bs2.Size(); ++i) {
            if (i % 2 == 0) {
                bs2[i] = true;
            }
        }
        BitSet bs3(20, false);
        for (int i = 0; i < bs3.Size(); ++i) {
            if (i % 3 == 0) {
                bs3[i] = true;
            }
        }
        BitSet result = bs2 | bs3;
        for (int i = 0; i < result.Size(); ++i) {
            if (i % 2 == 0 || i % 3 == 0) {
                CHECK(result[i]);
            } else {
                CHECK(!result[i]);
            }
        }
    }

    SUBCASE("^") {
        BitSet bs2(20, false);
        for (int i = 0; i < bs2.Size(); ++i) {
            if (i % 2 == 0) {
                bs2[i] = true;
            }
        }
        BitSet bs3(20, false);
        for (int i = 0; i < bs3.Size(); ++i) {
            if (i % 3 == 0) {
                bs3[i] = true;
            }
        }
        BitSet result = bs2 ^ bs3;

        for (int i = 0; i < result.Size(); ++i) {
            if ((i % 2 == 0 || i % 3 == 0) && (i % 6 != 0)) {
                CHECK(result[i]);
            } else {
                CHECK(!result[i]);
            }
        }
    }

    SUBCASE("Errors") {
        BitSet bs1(20, false);
        BitSet bs2(10, false);
        CHECK_THROWS(bs1 & bs2);
        CHECK_THROWS(bs1 | bs2);
        CHECK_THROWS(bs1 ^ bs2);
    }
}

TEST_CASE("Size") {
    int size = 20;
    BitSet bs(size, false);
    bs[0] = true;
    bs[size - 1] = true;
    CHECK(bs.Size() == size);
    bs.Resize(size / 2);
    CHECK(bs.Size() == size / 2);
    CHECK(bs[0]);
    for (int i = 1; i < size / 2; ++i) {
        CHECK(!bs[i]);
    }

    bs.Resize(20);
    CHECK(bs.Size() == size);
    CHECK(bs[0]);
    for (int i = 1; i < size / 2; ++i) {
        CHECK(!bs[i]);
    }
}

TEST_CASE("Fill") {
    int size = 20;
    BitSet bs(size, false);
    bs.Fill(true);
    for (int i = 0; i < size; ++i) {
        CHECK(bs[i]);
    }
    bs.Fill(false);
    for (int i = 0; i < size; ++i) {
        CHECK(!bs[i]);
    }
}

TEST_CASE("Out") {
    int size = 10;
    std::vector<std::string> answer;
    std::vector<BitSet> bs;
    BitSet bs1(size, false);
    for (int i = 0; i < size; ++i) {
        if(i % 2 == 0) {
            bs1[i] = true;
        }
    }
    answer.push_back("1010101010");
    bs.push_back(bs1);
    std::ostringstream outstr;
    outstr << bs[0];
    CHECK(outstr.str() == answer[0]);
}

TEST_CASE("In") {
    SUBCASE("In and out") {
        std::vector<std::string> in_data;
        in_data.push_back("10101001");
        in_data.push_back("10000101001");
        in_data.push_back("1111111111");
        in_data.push_back("0");
        in_data.push_back("110");
        for (size_t i = 0; i < in_data.size(); ++i) {
            BitSet bs(1, true);
            std::istringstream in(in_data[i]);
            std::ostringstream out;
            in >> bs;
            out << bs;
            CHECK(out.str() == in_data[i]);

        }
    }

    SUBCASE("Errors") {
        std::vector<std::string> in_data;
        in_data.push_back("19101001");
        in_data.push_back("10o01001");
        in_data.push_back("1/0o01001");
        in_data.push_back("true");
        for (size_t i = 0; i < in_data.size(); ++i) {
            BitSet bs(1, true);
            std::istringstream in(in_data[i]);
            in >> bs;
            CHECK(in.fail());
        }
    }
}
