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
                if (!result[i]) {
                    std::cout << i << "\n";
                }
                CHECK(result[i]);
            } else {
                if (result[i]) {
                    std::cout << i << "\n";
                }
                CHECK(!result[i]);
            }
        }
    }
}

TEST_CASE("Size") {
    BitSet bs(20, false);
    CHECK(bs.Size() == 20);
    bs.Resize(10);
    CHECK(bs.Size() == 10);
    bs.Resize(20);
    CHECK(bs.Size() == 10);
}