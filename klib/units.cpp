#include "../catch.hpp"
#include <klib/units.hpp>

TEST_CASE("klib time s", "[klib::units]") {
    REQUIRE(static_cast<klib::time::ms>(klib::time::s(1)) == klib::time::ms(1'000));
    REQUIRE(static_cast<klib::time::us>(klib::time::s(1)) == klib::time::us(1'000'000));
    REQUIRE(static_cast<klib::time::ns>(klib::time::s(1)) == klib::time::ns(1'000'000'000));

    using namespace klib::time;
    REQUIRE(klib::time::s(1) == 1_s);
}

TEST_CASE("klib time ms", "[klib::units]") {
    REQUIRE(static_cast<klib::time::s>(klib::time::ms(1'000)) == klib::time::s(1));
    REQUIRE(static_cast<klib::time::us>(klib::time::ms(1'000)) == klib::time::us(1'000'000));
    REQUIRE(static_cast<klib::time::ns>(klib::time::ms(1'000)) == klib::time::ns(1'000'000'000));

    using namespace klib::time;
    REQUIRE(klib::time::ms(1) == 1_ms);
}

TEST_CASE("klib time us", "[klib::units]") {
    REQUIRE(static_cast<klib::time::s>(klib::time::us(1'000'000)) == klib::time::s(1));
    REQUIRE(static_cast<klib::time::ms>(klib::time::us(1'000'000)) == klib::time::ms(1'000));
    REQUIRE(static_cast<klib::time::ns>(klib::time::us(1'000'000)) == klib::time::ns(1'000'000'000));

    using namespace klib::time;
    REQUIRE(klib::time::us(1) == 1_us);
}

TEST_CASE("klib time ns", "[klib::units]") {
    REQUIRE(static_cast<klib::time::s>(klib::time::ns(1'000'000'000)) == klib::time::s(1));
    REQUIRE(static_cast<klib::time::ms>(klib::time::ns(1'000'000'000)) == klib::time::ms(1'000));
    REQUIRE(static_cast<klib::time::us>(klib::time::ns(1'000'000'000)) == klib::time::us(1'000'000));

    using namespace klib::time;
    REQUIRE(klib::time::ns(1) == 1_ns);
}

TEST_CASE("klib time operator+=", "[klib::units]") {
    using namespace klib::time;

    auto time = klib::time::ns(1);
    REQUIRE(time == 1_ns);

    // increment the time
    time += klib::time::ns(1);
    REQUIRE(time == 2_ns);
}

TEST_CASE("klib time operator-=", "[klib::units]") {
    using namespace klib::time;

    auto time = klib::time::ns(10);
    REQUIRE(time == 10_ns);

    // increment the time
    time -= klib::time::ns(1);
    REQUIRE(time == 9_ns);
}

// TODO: add tests for operators