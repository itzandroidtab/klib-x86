#include "../catch.hpp"
#include <klib/vector3.hpp>

TEST_CASE("vector3 constructor", "[klib::vector3]") {
    klib::vector3<uint8_t> vector1(10, 20, 30);

    REQUIRE(vector1.x == 10);
    REQUIRE(vector1.y == 20);
    REQUIRE(vector1.z == 30);

    klib::vector3<uint8_t> vector2(10);

    REQUIRE(vector2.x == 10);
    REQUIRE(vector2.y == 10);
    REQUIRE(vector2.z == 10);
}

TEST_CASE("vector3 operator+", "[klib::vector3]") {
    const auto vector = klib::vector3<uint8_t>(10) + 10;

    REQUIRE(vector.x == 20);
    REQUIRE(vector.y == 20);
    REQUIRE(vector.z == 20);

    klib::vector3<uint8_t> vector1(10);
    klib::vector3<uint8_t> vector2(10);
    const auto vector3 = vector1 + vector2;

    REQUIRE(vector3.x == 20);
    REQUIRE(vector3.y == 20);
    REQUIRE(vector3.z == 20);
}

TEST_CASE("vector3 operator+=", "[klib::vector3]") {
    klib::vector3<uint8_t> vector(10);
    vector += 10;

    REQUIRE(vector.x == 20);
    REQUIRE(vector.y == 20);
    REQUIRE(vector.z == 20);

    klib::vector3<uint8_t> vector1(10);
    klib::vector3<uint8_t> vector2(10);
    vector1 += vector2;

    REQUIRE(vector1.x == 20);
    REQUIRE(vector1.y == 20);
    REQUIRE(vector1.z == 20);
}

TEST_CASE("vector3 operator-", "[klib::vector3]") {
    const auto vector = klib::vector3<uint8_t>(20) - 10;

    REQUIRE(vector.x == 10);
    REQUIRE(vector.y == 10);
    REQUIRE(vector.z == 10);

    klib::vector3<uint8_t> vector1(10);
    klib::vector3<uint8_t> vector2(10);
    const auto vector3 = vector1 - vector2;

    REQUIRE(vector3.x == 0);
    REQUIRE(vector3.y == 0);
    REQUIRE(vector3.z == 0);
}

TEST_CASE("vector3 operator-=", "[klib::vector3]") {
    klib::vector3<uint8_t> vector(20);
    vector -= 10;

    REQUIRE(vector.x == 10);
    REQUIRE(vector.y == 10);
    REQUIRE(vector.z == 10);

    klib::vector3<uint8_t> vector1(10);
    klib::vector3<uint8_t> vector2(10);
    vector1 -= vector2;

    REQUIRE(vector1.x == 20);
    REQUIRE(vector1.y == 20);
    REQUIRE(vector1.z == 20);
}