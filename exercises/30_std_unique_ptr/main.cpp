﻿#include "../exercise.h"
#include <memory>
#include <string>

// READ: `std::unique_ptr` <https://cppreference.cn/w/cpp/memory/unique_ptr>
// READ: `std::make_unique` <https://cppreference.cn/w/cpp/memory/unique_ptr/make_unique>

struct Resource {
    std::string data;
    Resource(std::string d) : data(std::move(d)) {}
    ~Resource() { std::cout << "Resource destroyed: " << data << std::endl; }
};

template<typename T>
struct MyUniquePtr {
    // TODO: 实现 unique_ptr 的基本功能
    // NOTICE: 面试时经常会问到 unique_ptr 的实现原理，建议自己独立实现一个简单的 unique_ptr。
    // 这有助于加深对 unique_ptr 的理解，并且可以在面试中展示自己的能力。
    // 例如，构造函数、析构函数、移动构造函数、移动赋值运算符等。
};

int main(int argc, char **argv) {
    // Part 1: Basic usage and ownership
    {
        auto ptr1 = std::make_unique<Resource>("Part 1 Resource");
        ASSERT(ptr1 != nullptr, "ptr1 should own a resource");
        ASSERT(ptr1->data == ?, "Check resource data");

        // TODO: 打开注释并解释为什么这会导致编译错误。
        // auto ptr2 = ptr1;

        // 使用 std::move 转移所有权
        auto ptr3 = std::move(ptr1);
        ASSERT(ptr3 != nullptr, "ptr3 should own the resource now");
        ASSERT(ptr3->data == ?, "Check resource data in ptr3");

        // Resource 在 ptr3 超出作用域时自动销毁
    }

    // Part 2: Using reset()
    {
        auto ptr = std::make_unique<Resource>("Part 2 Initial");
        ASSERT(ptr->data == ?, "Check initial data");

        // Reset to manage a new resource
        ptr.reset(new Resource("Part 2 New"));
        ASSERT(ptr != nullptr, "ptr should own the new resource");
        ASSERT(ptr->data == ?, "Check data of the new resource");

        // Reset to release ownership (becomes nullptr)
        ptr.reset();
        ASSERT(ptr == ?, "ptr should be null after reset()");
    }

    // Part 3: Using release()
    {
        auto ptr = std::make_unique<Resource>("Part 3 Resource");
        ASSERT(ptr != nullptr, "ptr should own the resource initially");

        // Release ownership
        Resource* raw_ptr = ptr.release();
        ASSERT(ptr == ?, "ptr should be null after release()");
        ASSERT(raw_ptr != nullptr, "raw_ptr should point to the resource");
        ASSERT(raw_ptr->data == ?, "Check data via raw_ptr");

        // TODO: 请在下方补充代码，确保不会发生内存泄漏。
        // delete ?;
    }

    // Part 4: unique_ptr with arrays
    {
        // 使用 make_unique 创建一个 unique_ptr 指向一个包含 5 个整数的数组
        auto arr_ptr = std::make_unique<int[]>(5);

        for (int i = 0; i < 5; ++i) {
            arr_ptr[i] = i * 10;
        }

        ASSERT(arr_ptr[0] == ?, "Check array element 0");
        ASSERT(arr_ptr[4] == ?, "Check array element 4");

        // THINK：作用域结束时，数组都会被销毁吗？
    }

    return 0;
}
