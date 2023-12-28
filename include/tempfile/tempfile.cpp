#include "include/tempfile/tempfile.hpp"

#include <cstdio>
#include <fstream>
#include <mutex>

static std::mutex mutex;

std::filesystem::path tempfile::mkdtemp(void) {
    mutex.lock();

    auto dirname = std::tmpnam(nullptr);
    std::filesystem::create_directories(dirname);

    mutex.unlock();
    return std::filesystem::path(dirname);
}

std::filesystem::path tempfile::mkstemp(void) {
    mutex.lock();

    auto filename = std::tmpnam(nullptr);
    std::ofstream{filename};

    mutex.unlock();
    return std::filesystem::path(filename);
}
