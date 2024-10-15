#include <cstddef>
#include <vector>
#include <stdexcept>

template <typename T>
class Deque {
private:
    std::vector<T> head, tail;

public:
    bool Empty() const
    {
        return head.empty() && tail.empty();
    }

    size_t Size() const
    {
        return head.size() + tail.size();
    }

    void Clear()
    {
        head.clear();
        tail.clear();
    }

    const T& operator [] (size_t i) const
    {
        if (i < head.size())
            return head[head.size() - i - 1];

        return tail[i - head.size()];
    }

    T& operator [] (size_t i)
    {
        if (i < head.size())
            return head[head.size() - i - 1];

        return tail[i - head.size()];
    }

    // throws std::out_of_range on incorrect index
    const T& At(size_t i) const
    {
        if (i >= this->Size())
            throw std::out_of_range("Index is out of range");

        return (*this)[i];
    }

    T& At(size_t i)
    {
        if (i >= this->Size())
            throw std::out_of_range("Index is out of range");

        return (*this)[i];
    }

    const T& Front() const
    {
        if (head.empty())
            return tail.front();

        return head.back();
    }

    T& Front()
    {
        if (head.empty())
            return tail.front();

        return head.back();
    }

    const T& Back() const
    {
        if (tail.empty())
            return head.front();

        return tail.back();
    }

    T& Back()
    {
        if (tail.empty())
            return head.front();

        return tail.back();
    }

    void PushFront(const T& elem)
    {
        head.push_back(elem);
    }

    void PushBack(const T& elem)
    {
        tail.push_back(elem);
    }
};

#include <iostream>

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
