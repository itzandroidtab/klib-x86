#include "../../catch.hpp"
#include <klib/io/rtc.hpp>

TEST_CASE("datetime to epoch conversion is correct", "[klib::io::rtc]") {
    REQUIRE(klib::io::rtc::datetime_to_epoch(2024, 1, 7, 23, 40, 6).value == 1704670806);
    REQUIRE(klib::io::rtc::datetime_to_epoch(1970, 1, 1, 0, 0, 0).value == 0);
    REQUIRE(klib::io::rtc::datetime_to_epoch(2000, 1, 1, 0, 0, 0).value == 946684800);
    REQUIRE(klib::io::rtc::datetime_to_epoch(2050, 1, 1, 0, 0, 0).value == 2524608000);
    REQUIRE(klib::io::rtc::datetime_to_epoch(2099, 1, 1, 0, 0, 0).value == 4070908800);
    REQUIRE(klib::io::rtc::datetime_to_epoch(2098, 12, 31, 23, 59, 59).value == 4070908799);
    REQUIRE(klib::io::rtc::datetime_to_epoch(2097, 12, 31, 23, 59, 59).value == 4039372799);
    REQUIRE(klib::io::rtc::datetime_to_epoch(2050, 12, 31, 23, 59, 59).value == 2556143999);
    REQUIRE(klib::io::rtc::datetime_to_epoch(2024, 2, 6, 3, 20, 2).value == 1707189602);   
    REQUIRE(klib::io::rtc::datetime_to_epoch(2024, 3, 6, 3, 20, 2).value == 1709695202);   
}

TEST_CASE("epoch to datetime conversion is correct", "[klib::io::rtc]") {
    const auto x = klib::io::rtc::epoch_to_datetime(4070908799);
    const auto y = klib::io::rtc::datetime{2098, 12, 31, 23, 59, 59};
    CHECK(x.year == y.year);
    CHECK(x.month == y.month);
    CHECK(x.day == y.day);
    CHECK(x.hours == y.hours);
    CHECK(x.minutes == y.minutes);
    CHECK(x.seconds == y.seconds);

    REQUIRE(klib::io::rtc::epoch_to_datetime(1704670806) == klib::io::rtc::datetime{2024, 1, 7, 23, 40, 6});
    REQUIRE(klib::io::rtc::epoch_to_datetime(0) == klib::io::rtc::datetime{1970, 1, 1, 0, 0, 0});
    REQUIRE(klib::io::rtc::epoch_to_datetime(946684800) == klib::io::rtc::datetime{2000, 1, 1, 0, 0, 0});
    REQUIRE(klib::io::rtc::epoch_to_datetime(2524608000) == klib::io::rtc::datetime{2050, 1, 1, 0, 0, 0});
    REQUIRE(klib::io::rtc::epoch_to_datetime(4070908800) == klib::io::rtc::datetime{2099, 1, 1, 0, 0, 0});
    REQUIRE(klib::io::rtc::epoch_to_datetime(4070908799) == klib::io::rtc::datetime{2098, 12, 31, 23, 59, 59});
    REQUIRE(klib::io::rtc::epoch_to_datetime(4039372799) == klib::io::rtc::datetime{2097, 12, 31, 23, 59, 59});
    REQUIRE(klib::io::rtc::epoch_to_datetime(2556143999) == klib::io::rtc::datetime{2050, 12, 31, 23, 59, 59});
}

