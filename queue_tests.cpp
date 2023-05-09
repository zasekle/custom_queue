//
// Created by jeremiah on 5/9/23.
//

#include <cassert>
#include "queue_tests.h"
#include "custom_queue.h"

void TestSuite::empty_queue() {
    CustomQueue<int> q;

    assert(q.empty());
}

void TestSuite::non_empty_queue() {
    CustomQueue<int> q;
    q.push(12);

    assert(!q.empty());
}

void TestSuite::front_when_empty() {
    CustomQueue<int> q;
    auto ret_val = q.front();

    assert(!ret_val.get());
}

void TestSuite::front_with_elements() {
    CustomQueue<int> q;
    q.push(1);
    q.push(2);

    auto ret_val = q.front();
    assert(ret_val.get());
    assert(*ret_val == 1);
}

void TestSuite::back_when_empty() {
    CustomQueue<int> q;
    auto ret_val = q.back();

    assert(!ret_val.get());
}

void TestSuite::back_with_elements() {
    CustomQueue<int> q;
    q.push(1);
    q.push(2);

    auto ret_val = q.back();
    assert(ret_val.get());
    assert(*ret_val == 2);
}

void TestSuite::push_to_empty_list() {
    CustomQueue<int> q;
    q.push(1);

    auto back_val = q.back();
    auto front_val = q.front();
    assert(back_val.get());
    assert(front_val.get());
    assert(q.size() == 1);

    assert(*back_val == 1);
    assert(*front_val == 1);
}

void TestSuite::push_to_list() {
    CustomQueue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    auto back_val = q.back();
    auto front_val = q.front();
    assert(back_val.get());
    assert(front_val.get());
    assert(q.size() == 3);

    assert(*back_val == 3);
    assert(*front_val == 1);
}

void TestSuite::pop_from_empty_list() {
    CustomQueue<int> q;
    auto ret_val = q.pop();

    assert(!ret_val);
    assert(q.size() == 0);
}

void TestSuite::pop_from_single_element() {
    CustomQueue<int> q;
    q.push(5);

    assert(q.size() == 1);

    auto ret_val = q.pop();

    assert(ret_val.get());
    assert(q.size() == 0);

    assert(*ret_val == 5);
}

void TestSuite::pop_from_list() {
    CustomQueue<int> q;
    q.push(5);
    q.push(6);
    q.push(7);

    auto ret_val = q.pop();

    assert(ret_val.get());
    assert(q.size() == 2);

    assert(*ret_val == 5);
}

