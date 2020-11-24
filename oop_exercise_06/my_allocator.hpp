#pragma once

#include <queue>

template<typename T, size_t size>
class my_allocator
{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = T const*;
    using size_type = size_t;
    my_allocator();
    void* allocate();
    void deallocate(void *ptr) { free_blocks.push(ptr); }
    bool empty() { return free_blocks.empty(); }
    size_t size() { return free_blocks.size(); }
    ~my_allocator();

private:
    void* used_blocks;
    std::queue<void*> free_blocks;
};

template<typename T, size_t size>
my_allocator<T,size>::my_allocator()
{
    used_blocks = malloc(size*sizeof(T));
    for(size_t i = 0; i < size; ++i)
    {
        void* ptr = malloc(sizeof(void*));
        ptr = used_blocks + i*sizeof(T);
        free_blocks.push(ptr);
    }
}


template<typename T, size_t size>
void* my_allocator<T,size>::allocate()
{
    if(!free_blocks.empty())
    {
        void* res =  free_blocks.front();
        free_blocks.pop();
        return res;
    } else { throw std::bad_alloc(); }
}

template<typename T, size_t size>
my_allocator<T,size>::~my_allocator()
{
    while(!free_blocks.empty()) { free_blocks.pop(); }
    free(used_blocks);
}
