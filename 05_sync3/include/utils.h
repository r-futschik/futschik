#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <mutex>
#include <iostream>



class Utils {
    private:
        static std::recursive_mutex out_mtx;

    public:
        static void println();

        template<typename T, typename... Rest>
        static void println(const T& word, const Rest&... rest) {
            std::lock_guard<std::recursive_mutex> lg{Utils::out_mtx};
            std::cout << word << ' ';
            Utils::println(rest...);
        }
};

#endif