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
        CHECK_NOTHROW(BitSet bs(10));
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
        //CHECK_THROWS(BitSet bs(-5));
    }
}

TEST_CASE("BitHolder") {
    SUBCASE("one difference") {
        BitSet bs(10, false);
        bs[0] = true;
        CHECK(bs[0]);
        for (int i = 1; i < bs.Size(); ++i) {
            CHECK(!bs[i]);
            if (bs[i]) {
                std::cout << i << "\n";
            }
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