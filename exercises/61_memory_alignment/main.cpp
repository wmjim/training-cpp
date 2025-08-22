#include "../exercise.h"
#include <cstddef>
#include <iostream>

// READ: 内存对齐 <https://cppreference.cn/w/cpp/language/object#Alignment>
// READ: sizeof 运算符 <https://cppreference.cn/w/cpp/language/sizeof>
// READ: alignof 运算符 <https://cppreference.cn/w/cpp/language/alignof>

struct SimpleStruct {
    char a;// 1 字节
    int b; // 4 字节
    char c;// 1 字节
};

struct PackedStruct {
    char a;// 1 字节
    char c;// 1 字节
    int b; // 4 字节
};

struct AlignedStruct {
    char a;  // 1 字节
    double d;// 8 字节
    int i;   // 4 字节
};

// 使用 alignas 指定对齐要求
struct alignas(16) CustomAlignedStruct {
    int x; // 4 字节
    char y;// 1 字节
};

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    // ---- 基本类型的 sizeof 和 alignof ----
    ASSERT(sizeof(char) == ?, "char 的大小");
    ASSERT(alignof(char) == ?, "char 的对齐要求");

    ASSERT(sizeof(int) == ?, "int 的大小");
    ASSERT(alignof(int) == ?, "int 的对齐要求");

    ASSERT(sizeof(double) == ?, "double 的大小");
    ASSERT(alignof(double) == ?, "double 的对齐要求");

    // ---- 结构体的大小和对齐 ----
    // SimpleStruct: char(1) + padding(3) + int(4) + char(1) + padding(3)
    ASSERT(sizeof(SimpleStruct) == ?, "SimpleStruct 的大小");
    // 结构体的对齐要求等于其成员中最大的对齐要求
    ASSERT(alignof(SimpleStruct) == ?, "SimpleStruct 的对齐要求 (等于 alignof(int))");

    // PackedStruct: char(1) + char(1) + padding(2) + int(4)
    ASSERT(sizeof(PackedStruct) == ?, "PackedStruct 的大小 (成员顺序优化)");
    ASSERT(alignof(PackedStruct) == ?, "PackedStruct 的对齐要求 (等于 alignof(int))");

    // AlignedStruct: char(1) + padding(7) + double(8) + int(4) + padding(4)
    ASSERT(sizeof(AlignedStruct) == ?, "AlignedStruct 的大小");
    ASSERT(alignof(AlignedStruct) == ?, "AlignedStruct 的对齐要求 (等于 alignof(double))");

    // ---- alignas ----
    // CustomAlignedStruct: alignas(16) 强制对齐为 16
    // int(4) + char(1) + padding(11)
    ASSERT(sizeof(CustomAlignedStruct) == ?, "CustomAlignedStruct 的大小 (受 alignas 影响)");
    ASSERT(alignof(CustomAlignedStruct) == ?, "CustomAlignedStruct 的对齐要求 (由 alignas 指定)");

    // ---- 成员偏移量 offsetof ----
    // READ: offsetof <https://cppreference.cn/w/cpp/types/offsetof>
    ASSERT(offsetof(SimpleStruct, a) == ?, "SimpleStruct::a 的偏移量");
    ASSERT(offsetof(SimpleStruct, b) == ?, "SimpleStruct::b 的偏移量 (考虑 a 后面的填充)");
    ASSERT(offsetof(SimpleStruct, c) == ?, "SimpleStruct::c 的偏移量 (考虑 b 后面的填充)");

    ASSERT(offsetof(PackedStruct, a) == ?, "PackedStruct::a 的偏移量");
    ASSERT(offsetof(PackedStruct, c) == ?, "PackedStruct::c 的偏移量");
    ASSERT(offsetof(PackedStruct, b) == ?, "PackedStruct::b 的偏移量 (考虑 a 和 c 后面的填充)");

    // THINK: 为什么调整结构体成员的顺序会影响结构体的大小？
    // THINK: `alignof` 和 `alignas` 有什么区别和联系？
    // THINK: 内存对齐的主要目的是什么？它对性能有什么影响？

    return 0;
}