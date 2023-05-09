//
// Created by jeremiah on 5/9/23.
//

#pragma once


#include <iostream>

class TestSuite {
public:
    void runAllTests() {
        std::cout << "starting runAllTests()\n";

        empty_queue();
        non_empty_queue();
        front_when_empty();
        front_with_elements();
        back_when_empty();
        back_with_elements();
        push_to_empty_list();
        push_to_list();
        pop_from_empty_list();
        pop_from_single_element();
        pop_from_list();

        std::cout << "Tests Passed\n";
    }

private:
    static void empty_queue();

    static void non_empty_queue();

    static void front_when_empty();

    static void front_with_elements();

    static void back_when_empty();

    static void back_with_elements();

    static void push_to_empty_list();

    static void push_to_list();

    static void pop_from_empty_list();

    static void pop_from_single_element();

    static void pop_from_list();
};
