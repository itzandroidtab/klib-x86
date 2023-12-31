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

TEST_CASE("math count leading zeros", "[klib::math]") {
    REQUIRE(klib::clz(0x00) == 32);
    REQUIRE(klib::clz(0x01) == 31);
    REQUIRE(klib::clz(0x80000000) == 0);
    REQUIRE(klib::clz(0x8000) == 16);
}

TEST_CASE("math count trailing zeros", "[klib::math]") {
    REQUIRE(klib::ctz(0x00) == 32);
    REQUIRE(klib::ctz(0x01) == 0);
    REQUIRE(klib::ctz(0x80000000) == 31);
    REQUIRE(klib::ctz(0x8000) == 15);
}

TEST_CASE("math popcount", "[klib::math]") {
    REQUIRE(klib::popcount(0x00) == 0);
    REQUIRE(klib::popcount(0x01) == 1);
    REQUIRE(klib::popcount(0x80000000) == 1);
    REQUIRE(klib::popcount(0xffff) == 16);
    REQUIRE(klib::popcount(0xffffffff) == 32);
}

TEST_CASE("math exp2", "[klib::math]") {
    REQUIRE(klib::exp2(1) == (0x1 << 1));
    REQUIRE(klib::exp2(32) == 0);
    REQUIRE(klib::exp2(31) == (0x1 << 31));
    REQUIRE(klib::exp2(15) == (0x1 << 15));
    REQUIRE(klib::exp2<uint64_t>(63) == (static_cast<uint64_t>(0x1) << 63));
}

TEST_CASE("math pow", "[klib::math]") {
    REQUIRE(klib::pow(2, 10) == klib::exp2(10));
    REQUIRE(klib::pow(2, 0) == 1);
    REQUIRE(klib::pow(2, 1) == 2);
    REQUIRE(klib::pow(10, 5) == (10 * 10 * 10 * 10 * 10));
}

TEST_CASE("math ceil", "[klib::math]") {
    REQUIRE(klib::ceil(9.5f) == 10.f);
}