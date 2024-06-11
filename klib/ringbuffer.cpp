#include "../catch.hpp"
#include <klib/ringbuffer.hpp>

TEST_CASE("Ringbuffer stores data", "[klib::ringbuffer]") {
    struct x {
        int a;

        x() : a(0) {}
        x(int a) : a(a) {}

        virtual void foo() {};
    };

    klib::ringbuffer<x, 16> q;

    q.push(x(3));
    q.push(x(5));

    REQUIRE(q.copy_and_pop().a == 3);
    REQUIRE(q.copy_and_pop().a == 5);
}

TEST_CASE("Ringbuffer emplace works", "[klib::ringbuffer]") {
    struct x {
        int a;
        int b;

        x() : a(0), b(0) {}
        x(int a, int b) : a(a), b(b) {}

        virtual void foo() {};
    };

    klib::ringbuffer<x, 16> q;

    q.emplace();
    q.emplace(100, 20);

    {
        const auto t = q.copy_and_pop();
        REQUIRE(t.a == 0);
        REQUIRE(t.b == 0);
    }
    
    {
        const auto t = q.copy_and_pop();
        REQUIRE(t.a == 100);
        REQUIRE(t.b == 20);
    }
}

TEST_CASE("Ringbuffer removing a item works", "[klib::ringbuffer]"){
    klib::ringbuffer<int, 5> a;
    a.push(10);
    a.push(20);
    a.push(30);

    REQUIRE(a.size() == 3);

    a.copy_and_pop();
    REQUIRE(a.size() == 2);

    a.copy_and_pop();
    REQUIRE(a.size() == 1);

    a.copy_and_pop();
    REQUIRE(a.size() == 0);
}

TEST_CASE("Ringbuffer empty works", "[klib::ringbuffer]") {
    klib::ringbuffer<int, 2> q;

    q.push(12);
    q.push(24);

    q.copy_and_pop();
    q.copy_and_pop();

    REQUIRE(q.empty());
}

TEST_CASE("Ringbuffer full works", "[klib::ringbuffer]") {
    klib::ringbuffer<int, 2> q;

    q.push(12);
    q.push(24);

    REQUIRE(q.full());
}

TEST_CASE("Ringbuffer max_size is correct", "[klib::ringbuffer]") {
    klib::ringbuffer<int, 2> q;

    REQUIRE(q.max_size() == 2);

    klib::ringbuffer<int, 100> a;

    REQUIRE(a.max_size() == 100);
}

TEST_CASE("Ringbuffer size works", "[klib::ringbuffer]") {
    klib::ringbuffer<int, 2> q;

    q.push(12);
    REQUIRE(q.size() == 1);

    q.push(24);
    REQUIRE(q.size() == 2);

    q.push(33);
    REQUIRE(q.size() == 2);

    q.copy_and_pop();
    REQUIRE(q.size() == 1);

    q.copy_and_pop();
    REQUIRE(q.size() == 0);
}

TEST_CASE("Ringbuffer is empty at initialisation", "[klib::ringbuffer]"){
    klib::ringbuffer<int, 5> a;

    REQUIRE(a.empty() == true);
}

TEST_CASE("Ringbuffer is empty after clear()", "[klib::ringbuffer]"){
    klib::ringbuffer<int, 5> a;
    a.push(10);
    a.clear();

    REQUIRE(a.empty() == true);
}

TEST_CASE("Ringbuffer overflow works", "[klib::ringbuffer]"){
    klib::ringbuffer<int, 2> a;
    a.push(10);
    a.push(20);
    a.push(30);

    REQUIRE(a.copy_and_pop() == 20);
    REQUIRE(a.copy_and_pop() == 30);
}

TEST_CASE("Ringbuffer operator[] works", "[klib::ringbuffer]"){
    klib::ringbuffer<int, 5> a;
    a.push(10);
    a.push(20);

    REQUIRE(a[0] == 10);
    REQUIRE(a[1] == 20);
}

TEST_CASE("Ringbuffer operator[] with overflow works", "[klib::ringbuffer]"){
    klib::ringbuffer<int, 2> a;
    a.push(10);
    a.push(20);
    a.push(30);

    REQUIRE(a[0] == 20);
    REQUIRE(a[1] == 30);
}