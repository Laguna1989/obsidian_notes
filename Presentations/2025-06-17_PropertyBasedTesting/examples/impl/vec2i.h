#pragma once

class Vec2i {
public:
    constexpr Vec2i() = default;

    constexpr Vec2i(int const x, int const y) : x{x}, y{y} {
    }

    int x{0};
    int y{0};
};

[[nodiscard]] constexpr bool operator==(Vec2i const &lhs, Vec2i const &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

[[nodiscard]] constexpr double lengthSq(Vec2i const &vec) {
    return vec.x * vec.x + vec.y * vec.y;
}
