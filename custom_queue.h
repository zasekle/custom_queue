//
// Created by jeremiah on 5/9/23.
//

#pragma once

#include <memory>

template<typename T>
struct CustomQueue {

    size_t size() const {
        return q_size;
    }

    bool empty() {
        return q_size == 0;
    }

    std::unique_ptr<T> front() {
        return !start ?
               std::unique_ptr<T>(nullptr) :
               std::make_unique<T>(*start->value);
    }

    std::unique_ptr<T> back() {
        return !end ?
               std::unique_ptr<T>(nullptr) :
               std::make_unique<T>(*end->value);
    }

    void push(const T& val) {
        std::unique_ptr<T> new_value = std::make_unique<T>(val);
        Node* new_node = new Node{
                std::move(new_value)
        };

        if (!start) {
            start = new_node;
            end = new_node;
        } else {
            new_node->prev = end;
            end->next = new_node;
            end = new_node;
        }

        q_size++;
    }

    std::unique_ptr<T> pop() {
        if (!start) {
            return std::unique_ptr<T>(nullptr);
        }

        std::unique_ptr<T> front_val = std::move(start->value);

        Node* current_start = start;

        if (!start->next) {
            start = nullptr;
            end = nullptr;
        } else {
            start = start->next;
            start->prev = nullptr;
        }

        delete current_start;
        q_size--;

        return front_val;
    }

private:

    struct Node {
        std::unique_ptr<T> value = nullptr;
        Node* prev = nullptr;
        Node* next = nullptr;

        Node() = delete;

        explicit Node(std::unique_ptr<T>&& _value) : value(std::move(_value)) {}
    };

    Node* start = nullptr;
    Node* end = nullptr;

    size_t q_size = 0;
};
