#include <catch2/catch_all.hpp>
#include <rapidcheck.h>
#include <rapidcheck/catch.h>


/**
 * set env variable
 * RC_PARAMS=verbose_shrinking=1
 */

// TEST_CASE("shrinking") {
//     rc::prop("bla", [](int const a, int const b) {
//         std::cout << a << " _____ " << b << std::endl;
//         RC_ASSERT(a + b > -20);
//     });
// }
