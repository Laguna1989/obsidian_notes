#include <catch2/catch_all.hpp>
#include <rapidcheck.h>
#include <rapidcheck/catch.h>
#include <algorithm>

template<typename... Args>
void cool_sort(Args &&... args) {
    std::ranges::sort(std::forward<Args>(args)...);
}


TEST_CASE("cool sort unit tests") {
    std::vector data{2, 7, 1, 5, 1, 8};

    REQUIRE(!std::ranges::is_sorted(data));

    auto const input_copy = data;
    cool_sort(data);

    SECTION("is sorted") {
        REQUIRE(std::ranges::is_sorted(data));
    }

    SECTION("is permutation") {
        REQUIRE(std::ranges::is_permutation(data, input_copy));
    }
}


//
//
//
//
//
//
//
//
//
//

TEST_CASE("cool sort property based tests") {
    SECTION("prop A") {
        rc::check([](std::vector<int> const &data) {
        });
    }
}
