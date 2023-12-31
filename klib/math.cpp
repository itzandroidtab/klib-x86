#include "../catch.hpp"

#include <math.h>
#include <cmath>
#include <klib/math.hpp>

TEST_CASE("math isnan", "[klib::math]") {
    REQUIRE(klib::isnan(NAN));
    REQUIRE(!klib::isnan(0.f));
}

TEST_CASE("math isinf", "[klib::math]") {
    REQUIRE(klib::isinf(std::numeric_limits<float>::infinity()));
    REQUIRE(!klib::isinf<float>(0.f));
}

TEST_CASE("math 16 bit byte swap", "[klib::math]") {
    REQUIRE(klib::bswap16(0xaabb) == 0xbbaa);
    REQUIRE(klib::bswap16(0xdeadbeef) == 0xefbe);
}

TEST_CASE("math 32 bit byte swap", "[klib::math]") {
    REQUIRE(klib::bswap32(0xaabb) == 0xbbaa0000);
    REQUIRE(klib::bswap32(0xdeadbeef) == 0xefbeadde);
}

TEST_CASE("math 64 bit byte swap", "[klib::math]") {
    REQUIRE(klib::bswap64(0xaabb) == 0xbbaa000000000000);
    REQUIRE(klib::bswap64(0xdeadbeef00000000) == 0xefbeadde);
}