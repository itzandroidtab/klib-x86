#include "../catch.hpp"
#include <klib/string.hpp>
#include <string>

TEST_CASE("klib is_binary", "[klib::string]") {
    REQUIRE(klib::string::is_binary('0'));
    REQUIRE(klib::string::is_binary('1'));
    REQUIRE(!klib::string::is_binary(';'));
    REQUIRE(!klib::string::is_binary('A'));
    REQUIRE(!klib::string::is_binary('2'));
    REQUIRE(!klib::string::is_binary('z'));
}

TEST_CASE("klib is_octal", "[klib::string]") {
    for (uint32_t i = 0; i < 7; i++) {
        REQUIRE(klib::string::is_octal('0' + i));
    }

    REQUIRE(!klib::string::is_octal(';'));
    REQUIRE(!klib::string::is_octal('8'));
    REQUIRE(!klib::string::is_octal('A'));
    REQUIRE(!klib::string::is_octal('z'));
}

TEST_CASE("klib is_digit", "[klib::string]") {
    for (uint32_t i = 0; i < 9; i++) {
        REQUIRE(klib::string::is_digit('0' + i));
    }

    REQUIRE(!klib::string::is_digit(';'));
    REQUIRE(!klib::string::is_digit('A'));
    REQUIRE(!klib::string::is_digit('z'));
}

TEST_CASE("klib is_upper", "[klib::string]") {
    REQUIRE(!klib::string::is_upper(';'));
    REQUIRE(klib::string::is_upper('A'));
    REQUIRE(!klib::string::is_upper('z'));
}

TEST_CASE("klib is_lower", "[klib::string]") {
    REQUIRE(!klib::string::is_lower(';'));
    REQUIRE(!klib::string::is_lower('A'));
    REQUIRE(klib::string::is_lower('z'));
}

TEST_CASE("klib is_character", "[klib::string]") {
    REQUIRE(!klib::string::is_character('8'));
    REQUIRE(!klib::string::is_character(';'));
    REQUIRE(klib::string::is_character('A'));
    REQUIRE(klib::string::is_character('z'));
}

TEST_CASE("klib to_upper", "[klib::string]") {
    REQUIRE(klib::string::to_upper('8') == '8');
    REQUIRE(klib::string::to_upper(';') == ';');
    REQUIRE(klib::string::to_upper('A') == 'A');
    REQUIRE(klib::string::to_upper('z') == 'Z');
}

TEST_CASE("klib to_lower", "[klib::string]") {
    REQUIRE(klib::string::to_lower('8') == '8');
    REQUIRE(klib::string::to_lower(';') == ';');
    REQUIRE(klib::string::to_lower('A') == 'a');
    REQUIRE(klib::string::to_lower('z') == 'z');
}

TEST_CASE("klib strlen", "[klib::string]") {
    REQUIRE(klib::string::strlen("hello world") == 11);
    REQUIRE(klib::string::strlen("") == 0);
}

TEST_CASE("klib strcpy", "[klib::string]") {
    char buffer[32];
    klib::string::strcpy(buffer, "");
    REQUIRE(std::string(buffer) == "");

    klib::string::strcpy(buffer, "hello world");
    REQUIRE(std::string(buffer) == "hello world");
}

TEST_CASE("klib strcat", "[klib::string]") {
    char buffer[32] = "hello";
    klib::string::strcat(buffer, "");
    REQUIRE(std::string(buffer) == "hello");

    klib::string::strcat(buffer, " world");
    REQUIRE(std::string(buffer) == "hello world");
}

TEST_CASE("klib left_pad", "[klib::string]") {
    char buffer[32] = "hello";
    klib::string::left_pad(buffer, 0, ' ');
    REQUIRE(std::string(buffer) == "hello");

    klib::string::left_pad(buffer, 3, ' ');
    REQUIRE(std::string(buffer) == "   hello");
}

TEST_CASE("klib right_pad", "[klib::string]") {
    char buffer[32] = "hello";
    klib::string::right_pad(buffer, 0, ' ');
    REQUIRE(std::string(buffer) == "hello");

    klib::string::right_pad(buffer, 3, ' ');
    REQUIRE(std::string(buffer) == "hello   ");
}

TEST_CASE("klib set_width", "[klib::string]") {
    char buffer[32] = "1.000";
    klib::string::set_width(buffer, 0, ' ');
    REQUIRE(std::string(buffer) == "1.000");

    klib::string::set_width(buffer, 4, ' ');
    REQUIRE(std::string(buffer) == "1.000");

    klib::string::set_width<false>(buffer, 7, '0');
    REQUIRE(std::string(buffer) == "1.00000");
}

TEST_CASE("klib stoi", "[klib::string]") {
    REQUIRE(klib::string::stoi<klib::base::HEX>("dead") == 0xdead);
    REQUIRE(klib::string::stoi<klib::base::DEC>("1000") == 1000);
    REQUIRE(klib::string::stoi<klib::base::OCT>("3333") == 03333);
    REQUIRE(klib::string::stoi<klib::base::BIN>("1010") == 0b1010);
}

TEST_CASE("klib itoa", "[klib::string]") {
    char buffer[32] = {};
    klib::string::itoa<klib::base::HEX>(0xdead, buffer);
    REQUIRE(std::string(buffer) == "0xdead");
    klib::string::itoa<klib::base::DEC>(1000, buffer);
    REQUIRE(std::string(buffer) == "1000");
    klib::string::itoa<klib::base::BIN>(0b1010, buffer);
    REQUIRE(std::string(buffer) == "0b1010");
    klib::string::itoa<klib::base::BIN, true>(true, buffer);
    REQUIRE(std::string(buffer) == "true");
    klib::string::itoa<klib::base::BIN, true>(false, buffer);
    REQUIRE(std::string(buffer) == "false");
}

// TODO: stoa