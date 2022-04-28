#include <m3i.h>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("creation") {
    SUBCASE("size") {
        M3i tensor(2, 3, 4, 5);
        CHECK(tensor.Size(0) == 2);
        CHECK(tensor.Size(1) == 3);
        CHECK(tensor.Size(2) == 4);
        for (int i = 0; i < tensor.Size(0); ++i) {
            for (int j = 0; j < tensor.Size(1); ++j) {
                for (int k = 0; k < tensor.Size(2); ++k) {
                    CHECK(tensor.At(i, j, k) == 5);
                }
            }
        }
    }

    SUBCASE("copy") {
        M3i tensor(2, 3, 4, 0);
        tensor.At(0, 0, 0) = 4;
        M3i tensor_copy(tensor);
        CHECK(tensor_copy.Size(0) == 2);
        CHECK(tensor_copy.Size(1) == 3);
        CHECK(tensor_copy.Size(2) == 4);
        tensor.At(1, 1, 1) = 5;
        for (int i = 0; i < tensor.Size(0); ++i) {
            for (int j = 0; j < tensor.Size(1); ++j) {
                for (int k = 0; k < tensor.Size(2); ++k) {
                    CHECK(tensor.At(i, j, k) == tensor_copy.At(i, j, k));
                }
            }
        }
    }

    SUBCASE("move") {
        M3i tensor(2, 3, 4, 0);
        tensor.At(0, 0, 0) = 4;
        M3i tensor_move(std::move(tensor));
        std::vector<int> values(2 * 3 * 4, 0);
        values[0] = 4;
        for (int i = 0; i < tensor_move.Size(0); ++i) {
            for (int j = 0; j < tensor_move.Size(1); ++j) {
                for (int k = 0; k < tensor_move.Size(2); ++k) {
                    CHECK(tensor_move.At(i, j, k) == values[i * 3 * 4 + j * 4 + k]);
                }
            }
        }
        //проверка, что удален tensor
    }

    SUBCASE("initializer_list") {
        M3i tensor = {{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};
        CHECK(tensor.Size(0) == 2);
        CHECK(tensor.Size(1) == 2);
        CHECK(tensor.Size(2) == 3);
        int value = 1;
        for (int i = 0; i < tensor.Size(0); ++i) {
            for (int j = 0; j < tensor.Size(1); ++j) {
                for (int k = 0; k < tensor.Size(2); ++k) {
                    CHECK(tensor.At(i, j, k) == value);
                    ++value;
                }
            }
        }
    }
}

TEST_CASE("= and clone") {
    SUBCASE("copy") {
        M3i tensor(2, 3, 4, 0);
        tensor.At(0, 0, 0) = 4;
        M3i tensor_copy = tensor;
        CHECK(tensor_copy.Size(0) == 2);
        CHECK(tensor_copy.Size(1) == 3);
        CHECK(tensor_copy.Size(2) == 4);
        tensor.At(1, 1, 1) = 5;
        for (int i = 0; i < tensor.Size(0); ++i) {
            for (int j = 0; j < tensor.Size(1); ++j) {
                for (int k = 0; k < tensor.Size(2); ++k) {
                    CHECK(tensor.At(i, j, k) == tensor_copy.At(i, j, k));
                }
            }
        }
    }

    SUBCASE("move") {
        M3i tensor(2, 3, 4, 0);
        tensor.At(0, 0, 0) = 4;
        M3i tensor_move = std::move(tensor);
        std::vector<int> values(2 * 3 * 4, 0);
        values[0] = 4;
        for (int i = 0; i < tensor_move.Size(0); ++i) {
            for (int j = 0; j < tensor_move.Size(1); ++j) {
                for (int k = 0; k < tensor_move.Size(2); ++k) {
                    CHECK(tensor_move.At(i, j, k) == values[i * 3 * 4 + j * 4 + k]);
                }
            }
        }
        //проверка, что удален tensor
    }

    SUBCASE("clone") {
        M3i tensor(2, 3, 4, 0);
        tensor.At(0, 0, 0) = 4;
        M3i tensor_clone = tensor.Clone();
        tensor_clone.At(1, 1, 1) = 5;
        std::vector<int> values(2 * 3 * 4, 0);
        values[0] = 4;
        values[1 * 3 * 4 + 1 * 4 + 1] = 5;
        for (int i = 0; i < tensor_clone.Size(0); ++i) {
            for (int j = 0; j < tensor_clone.Size(1); ++j) {
                for (int k = 0; k < tensor_clone.Size(2); ++k) {
                    CHECK(tensor_clone.At(i, j, k) == values[i * 3 * 4 + j * 4 + k]);
                }
            }
        }
        CHECK(tensor_clone.At(1, 1, 1) != tensor.At(1, 1, 1));
    }
}

TEST_CASE("fill") {
    M3i tensor(2, 3, 4);
    tensor.Fill(1);
    for (int i = 0; i < tensor.Size(0); ++i) {
        for (int j = 0; j < tensor.Size(1); ++j) {
            for (int k = 0; k < tensor.Size(2); ++k) {
                CHECK(tensor.At(i, j, k) == 1);
            }
        }
    }
}

TEST_CASE("size") {
    SUBCASE("it works") {
        M3i tensor(2, 3, 4);
        CHECK(tensor.Size(0) == 2);
        CHECK(tensor.Size(1) == 3);
        CHECK(tensor.Size(2) == 4);
    }

    SUBCASE("errors") {
        M3i tensor(2, 3, 4);
        CHECK_THROWS(tensor.Size(-1));
        CHECK_THROWS(tensor.Size(3));
    }
}

TEST_CASE("at") {
    SUBCASE("it works") {
        M3i tensor(2, 3, 4, 0);
        CHECK(tensor.At(1, 1, 1) == 0);
        tensor.Fill(1);
        CHECK(tensor.At(1, 1, 1) == 1);
        tensor.At(1, 1, 1) = 2;
        CHECK(tensor.At(1, 1, 1) == 2);
    }

    SUBCASE("errors") {
        M3i tensor(2, 3, 4, 0);
        CHECK_THROWS(tensor.At(-1, 0, 0));
        CHECK_THROWS(tensor.At(0, -1, 0));
        CHECK_THROWS(tensor.At(0, 0, -1));
        CHECK_THROWS(tensor.At(2, 0, 0));
        CHECK_THROWS(tensor.At(0, 3, 0));
        CHECK_THROWS(tensor.At(0, 0, 4));
    }
}

TEST_CASE("resize") {
    SUBCASE("it works") {
        M3i tensor(2, 3, 4, 0);
        for (int i = 0; i < tensor.Size(0); ++i) {
            for (int j = 0; j < tensor.Size(1); ++j) {
                for (int k = 0; k < tensor.Size(2); ++k) {
                    tensor.At(i, j, k) = i * tensor.Size(1) * tensor.Size(2) + j * tensor.Size(2) + k;
                }
            }
        }
        tensor.Resize(1, 1, 2);
        for (int i = 0; i < tensor.Size(0); ++i) {
            for (int j = 0; j < tensor.Size(1); ++j) {
                for (int k = 0; k < tensor.Size(2); ++k) {
                    tensor.At(i, j, k) = i * 3 * 4 + j * 4 + k;
                }
            }
        }
    }

    SUBCASE("errors") {
        M3i tensor(2, 3, 4);
        CHECK_THROWS(tensor.Resize(0, 1, 1));
        CHECK_THROWS(tensor.Resize(1, 0, 1));
        CHECK_THROWS(tensor.Resize(1, 1, 0));
        CHECK_THROWS(tensor.Resize(-1, 1, 1));
        CHECK_THROWS(tensor.Resize(1, -1, 1));
        CHECK_THROWS(tensor.Resize(1, 1, -1));
    }
}