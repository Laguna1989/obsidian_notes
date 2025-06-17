#include <catch2/catch_all.hpp>
#include <rapidcheck.h>
#include <rapidcheck/catch.h>

TEST_CASE("Advanced features") {
    // SECTION("RC_TAG") {
    //     rc::check([](int a) {
    //         int const result = a + 5;
    //
    //         RC_TAG(a);
    //         RC_CLASSIFY(a > 0, "positive values");
    //
    //         RC_ASSERT(result > a);
    //     });
    // }

    // SECTION("RC_CLASSIFY") {
    //     rc::check([](int a) {
    //         int const result = a + 5;
    //
    //         RC_CLASSIFY(a > 0, "positive values");
    //
    //         RC_ASSERT(result > a);
    //     });
    // }

    // SECTION("RC_PRE") {
    //     rc::check([](int a) {
    //         int const result = a + 5;
    //         RC_PRE(a < -5);
    //
    //         RC_ASSERT(result > 0);
    //     });
    // }
}
