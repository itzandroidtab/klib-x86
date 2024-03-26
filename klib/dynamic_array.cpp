#include "../catch.hpp"
#include <klib/dynamic_array.hpp>

TEST_CASE("dynamic array stores data", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 1> array;
    array.push_back(0xdeadbeef);

    REQUIRE(array[0] == 0xdeadbeef);
}

TEST_CASE("dynamic array stores multiple items", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 10> array;
    array.push_back(0xdeadbeef);
    REQUIRE(array[0] == 0xdeadbeef);

    array.push_back(0x12345678);
    REQUIRE(array[1] == 0x12345678);
}

TEST_CASE("dynamic array size is correct", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 10> array;
    REQUIRE(array.size() == 0);

    array.push_back(0xdeadbeef);
    REQUIRE(array.size() == 1);
}

TEST_CASE("dynamic array begin", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 10> array;
    array.push_back(0xdeadbeef);
    REQUIRE(array.size() == 1);

    REQUIRE(array.begin() == &array[0]);
    REQUIRE(array.cbegin() == &array[0]);
}

TEST_CASE("dynamic array erase (const iterator)", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 10> array;
    array.push_back(0xdeadbeef);
    array.push_back(0x12345678);
    REQUIRE(array.size() == 2);

    array.erase(array.cbegin());
    REQUIRE(array.size() == 1);
    REQUIRE(array[0] == 0x12345678);
}

TEST_CASE("dynamic array erase (iterator)", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 10> array;
    array.push_back(0xdeadbeef);
    array.push_back(0x12345678);
    REQUIRE(array.size() == 2);

    const klib::dynamic_array<uint32_t, 10>::iterator it = array.begin();
    array.erase(it);
    REQUIRE(array.size() == 1);
    REQUIRE(array[0] == 0x12345678);
}

TEST_CASE("dynamic array pop_back", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 10> array;
    array.push_back(0xdeadbeef);
    array.push_back(0x12345678);
    REQUIRE(array.size() == 2);

    array.pop_back();
    REQUIRE(array.size() == 1);
    REQUIRE(array[0] == 0xdeadbeef);
}

TEST_CASE("dynamic array pop_front", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 10> array;
    array.push_back(0xdeadbeef);
    array.push_back(0x12345678);
    REQUIRE(array.size() == 2);

    array.pop_front();
    REQUIRE(array.size() == 1);
    REQUIRE(array[0] == 0x12345678);
}

TEST_CASE("dynamic array emplace_back", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 10> array;
    array.emplace_back(0xdeadbeef);

    REQUIRE(array.size() == 1);
    REQUIRE(array[0] == 0xdeadbeef);
}

TEST_CASE("dynamic array emplace", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 10> array;
    array.push_back(0x12345678);
    REQUIRE(array.size() == 1);

    array.emplace(static_cast<uint32_t>(0), 0xdeadbeef);
    REQUIRE(array.size() == 2);
    REQUIRE(array[0] == 0xdeadbeef);
}

TEST_CASE("dynamic array emplace (const iterator)", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 10> array;
    array.emplace(array.cbegin(), 0xdeadbeef);

    REQUIRE(array.size() == 1);
    REQUIRE(array[0] == 0xdeadbeef);
}

TEST_CASE("dynamic array emplace (iterator)", "[klib::dynamic_array]") {
    klib::dynamic_array<uint32_t, 10> array;

    const klib::dynamic_array<uint32_t, 10>::iterator it = array.begin();
    array.emplace(it, 0xdeadbeef);

    REQUIRE(array.size() == 1);
    REQUIRE(array[0] == 0xdeadbeef);
}