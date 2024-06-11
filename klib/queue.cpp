#include "../catch.hpp"
#include <klib/queue.hpp>

TEST_CASE("Queue stores data", "[klib::queue]") {
    struct x {
        int a;

        x() : a(0) {}
        x(int a) : a(a) {}

        virtual void foo() {};
    };

    klib::queue<x, 16> q;

    q.push(x(3));
    q.push(x(5));

    REQUIRE(q.copy_and_pop().a == 3);
    REQUIRE(q.copy_and_pop().a == 5);
}

TEST_CASE("Queue front and back work", "[klib::queue]") {
    klib::queue<int, 16> q;

    q.push(12);
    q.push(24);

    REQUIRE(q.front() == 12);
    REQUIRE(q.back() == 24);
}


TEST_CASE("Queue empty works", "[klib::queue]") {
    klib::queue<int, 2> q;

    q.push(12);
    q.push(24);

    q.pop();
    q.pop();

    REQUIRE(q.empty());
}

TEST_CASE("Queue full works", "[klib::queue]") {
    klib::queue<int, 2> q;

    q.push(12);
    q.push(24);

    REQUIRE(q.full());
}

TEST_CASE("Queue max_size is correct", "[klib::queue]") {
    klib::queue<int, 2> q;

    REQUIRE(q.max_size() == 2);

    klib::queue<int, 100> a;

    REQUIRE(a.max_size() == 100);
}

TEST_CASE("Queue size works", "[klib::queue]") {
    klib::queue<int, 2> q;

    q.push(12);
    REQUIRE(q.size() == 1);

    q.push(24);
    REQUIRE(q.size() == 2);

    q.pop();
    REQUIRE(q.size() == 1);

    q.pop();
    REQUIRE(q.size() == 0);
}

TEST_CASE("Read-optimized queue front and back work", "[klib::queue]") {
    klib::queue<int, 16, klib::queue_optimization::read> q;

    q.push(12);
    q.push(24);

    REQUIRE(q.front() == 12);
    REQUIRE(q.back() == 24);
}

TEST_CASE("Read-optimized queue empty, full, max_size and size work", "[klib::queue]") {
    klib::queue<int, 2, klib::queue_optimization::read> q;

    q.push(12);
    q.push(24);

    REQUIRE(q.size() == 2);
    REQUIRE(q.max_size() == 2);
    REQUIRE(q.full());

    q.pop();
    q.pop();

    REQUIRE(q.empty());
}

TEST_CASE("optimized_for given back the correct result", "[klib::queue]") {
    klib::queue<int, 2, klib::queue_optimization::write> a;
    klib::queue<int, 2, klib::queue_optimization::read> b;

    REQUIRE(a.optimized_for() == klib::queue_optimization::write);
    REQUIRE(b.optimized_for() == klib::queue_optimization::read);
}

TEST_CASE("queue is empty after clear()", "[klib::queue]"){
    klib::queue<int, 5> a;
    a.push(10);
    a.clear();

    REQUIRE(a.empty() == true);
}