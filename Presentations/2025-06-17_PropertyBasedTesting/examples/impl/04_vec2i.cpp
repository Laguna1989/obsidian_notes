#include <catch2/catch_all.hpp>
#include <rapidcheck.h>
#include <rapidcheck/catch.h>
#include <ostream>
#include "vec2i.h"

TEST_CASE("Vec2iTest fundamentals") {
    rc::prop("initial values", []() {
        auto const x = *rc::gen::arbitrary<int>().as("x");
        auto const y = *rc::gen::arbitrary<int>().as("y");

        Vec2i const v{x, y};

        RC_ASSERT(v.x == x);
        RC_ASSERT(v.y == y);
    });
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
//
//
//

namespace rc {
    template<>
    struct Arbitrary<Vec2i> {
        static Gen<Vec2i> arbitrary() {
            return gen::build<Vec2i>(
                // clang-format off
                gen::set(&Vec2i::x),
                gen::set(&Vec2i::y)
                // clang-format on
            );
        }
    };
} // namespace rc

TEST_CASE("Vec2iTest Generator") {
    rc::prop("Symmetric comparison", []() {
        auto const a = *rc::gen::arbitrary<Vec2i>();
        auto const b = *rc::gen::arbitrary<Vec2i>();

        RC_ASSERT((a == b) == (b == a));
    });
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
//
//
//

// TEST_CASE("Vec2iTest") {
//     rc::prop("length >= 0", []() {
//         auto const v = *rc::gen::arbitrary<Vec2i>();
//
//         RC_ASSERT(lengthSq(v) >= 0.0);
//     });
// }

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
//
//
//

//
// void showValue(Vec2i const &v, std::ostream &os) {
//     os << "x: " << v.x << std::endl;
//     os << "y: " << v.y << std::endl;
// }
//
