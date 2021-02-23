//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef SAFEQUEUE_HPP
#define SAFEQUEUE_HPP

#include <mutex>
#include <queue>

template<class T>
class SafeQueue
{
private:
    std::queue<T> q;
    std::mutex m;

public:
    SafeQueue() {}

    void push(T elem)
    {
        std::lock_guard<std::mutex> lock(m);
        q.push(elem);
    }

    bool pop(T& elem)
    {
        std::lock_guard<std::mutex> lock(m);
        if (q.empty())
        {
            return false;
        }
        elem = q.front();
        q.pop();
        return true;
    }
};

#endif