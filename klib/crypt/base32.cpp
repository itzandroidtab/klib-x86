#include "../../catch.hpp"
#include <klib/crypt/base32.hpp>

#include <cstring>

TEST_CASE("Base32 invalid input string size works", "[klib::base32]") {
    uint8_t buf[32];

    // check if a invalid input length exits without success
    REQUIRE(!klib::crypt::base32::decode("123", buf, sizeof(buf)));
}

TEST_CASE("Base32 invalid output size works", "[klib::base32]") {
    // note, every character in the input needs 5 bits. 
    // ((8 * 5) / 8 = 5 bytes are required for 8 input characters)
    uint8_t buf[5];

    // check if we return failure when the buffer is too small
    REQUIRE(!klib::crypt::base32::decode("ABCDEFGH", buf, 1));
    REQUIRE(!klib::crypt::base32::decode("ABCDEFGH", buf, 2));
    REQUIRE(!klib::crypt::base32::decode("ABCDEFGH", buf, 3));
    REQUIRE(!klib::crypt::base32::decode("ABCDEFGH", buf, 4));
}

TEST_CASE("Base32 valid output size works", "[klib::base32]") {
    // note, every character in the input needs 5 bits. 
    // ((8 * 5) / 8 = 5 bytes are required for 8 input characters)
    uint8_t buf[6];

    // this should pass as we need 5 bytes
    REQUIRE(klib::crypt::base32::decode("ABCDEFGH", buf, sizeof(buf)));
}

TEST_CASE("Base32 invalid padding returns failure", "[klib::base32]") {
    uint8_t buf[32];

    // check if a invalid padding gives a failure
    REQUIRE(!klib::crypt::base32::decode("ABCDEF=H", buf, sizeof(buf)));
}

TEST_CASE("Base32 invalid characters (numbers) returns failure", "[klib::base32]") {
    uint8_t buf[32];

    // check if invalid numbers give a error
    REQUIRE(!klib::crypt::base32::decode("189ABCDE", buf, sizeof(buf)));
}

TEST_CASE("Base32 valid input does not fail", "[klib::base32]") {
    uint8_t buf[32];

    REQUIRE(klib::crypt::base32::decode("ABCDEFGH", buf, sizeof(buf)));
    REQUIRE(klib::crypt::base32::decode("23456723", buf, sizeof(buf)));
}

TEST_CASE("Base32 output is valid", "[klib::crypt::base32]") {
    uint8_t buf[32];

    // make sure we do not have a failure
    REQUIRE(klib::crypt::base32::decode("MFRGGZDFMYYTEMZUGU3DOOBZGA======", buf, sizeof(buf)));

    // check if the output matches
    REQUIRE(std::strcmp(reinterpret_cast<const char*>(buf), "abcdef1234567890") == 0);
}
