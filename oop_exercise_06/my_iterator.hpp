#pragma once

//Структура итератор для последовательного контейнера
template <typename T>
struct iterator
{
    //Для iterator_traits
    using difference_type = int;
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using iterator_category = std::forward_iterator_tag;

    T* ptr;
    iterator (T* ptr_ = nullptr) : ptr(ptr_) {}
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    T* operator++() { return ++ptr; }
    T* operator--() { return --ptr; }
    bool operator==(iterator const& other) const { return ptr == other.ptr; }
    bool operator!=(iterator const& other) const { return !(*this == other); }
};

template <typename T>
bool operator<(iterator<T> const& lhs, iterator<T> const& rhs) { return lhs.ptr < rhs.ptr; }
template <typename T>
bool operator>(iterator<T> const& lhs, iterator<T> const& rhs) { return rhs.ptr < lhs.ptr; }
template <typename T>
bool operator<=(iterator<T> const& lhs, iterator<T> const& rhs) { return !(rhs.ptr < lhs.ptr); }
template <typename T>
bool operator>=(iterator<T> const& lhs, iterator<T> const& rhs) { return !(lhs.ptr < rhs.ptr); }
