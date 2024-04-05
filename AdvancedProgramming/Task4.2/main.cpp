//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>
#include<catch2/catch_session.hpp>

#include <cstdint>

#include <iostream>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

    int GetElement() {
        return value;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    
    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    //проверяемая функция
    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    //проверяемая функция
    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }
    

    //проверяемая функция
    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    //проверяемая функция
    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

   
    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};


//юнит-тесты
TEST_CASE("PushBack") {
    List list;
    SECTION("is element added") {
        list.PushBack(2);
        REQUIRE(list.Empty() == false);
    }

    SECTION("is element added to the back") {
        list.PushBack(2);
        list.PushBack(14);
       
        REQUIRE(list.PopBack() == 14);
    }
    
}
 
TEST_CASE("PushFront") {
    List list;
    SECTION("is element added") {
        list.PushBack(2);
        REQUIRE(list.Empty() == false);
    }
    SECTION("is element added to the front") {
        list.PushBack(2);
        list.PushBack(14);

        REQUIRE(list.PopFront() == 2);
    }

}

TEST_CASE("PopBack") {
    List list;
    SECTION("removing from the end") {
        list.PushBack(2);
        list.PushBack(14);
        list.PopBack();
        REQUIRE(list.PopBack() != 14);
    }
    SECTION("removing from empty list") {
        REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    }

}

TEST_CASE("PopFront") {
    List list;
    SECTION("removing from the front") {
        list.PushBack(2);
        list.PushBack(14);
        list.PopFront();
        REQUIRE(list.PopBack() != 2);
    }
    SECTION("removing from empty list") {
        REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
    }
}