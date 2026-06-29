#ifndef __BLI_ARRAY_HH__
#define __BLI_ARRAY_HH__

#include <cstddef>
#include <utility>
#include <algorithm>

namespace BLI {

template<typename T, int N = 0>
class Array {
public:
    Array() : m_data(nullptr), m_size(0) {}
    explicit Array(size_t size) : m_size(size) {
        m_data = new T[size]();
    }
    Array(size_t size, const T &value) : m_size(size) {
        m_data = new T[size];
        std::fill(m_data, m_data + size, value);
    }
    Array(std::initializer_list<T> list) : m_size(list.size()) {
        m_data = new T[m_size];
        std::copy(list.begin(), list.end(), m_data);
    }
    ~Array() { delete[] m_data; }
    Array(const Array &other) : m_size(other.m_size) {
        m_data = new T[m_size];
        std::copy(other.m_data, other.m_data + m_size, m_data);
    }
    Array(Array &&other) noexcept : m_data(other.m_data), m_size(other.m_size) {
        other.m_data = nullptr;
        other.m_size = 0;
    }
    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] m_data;
            m_size = other.m_size;
            m_data = new T[m_size];
            std::copy(other.m_data, other.m_data + m_size, m_data);
        }
        return *this;
    }
    Array &operator=(Array &&other) noexcept {
        std::swap(m_data, other.m_data);
        std::swap(m_size, other.m_size);
        return *this;
    }

    T &operator[](size_t index) { return m_data[index]; }
    const T &operator[](size_t index) const { return m_data[index]; }
    T *data() { return m_data; }
    const T *data() const { return m_data; }
    size_t size() const { return m_size; }
    bool empty() const { return m_size == 0; }
    T *begin() { return m_data; }
    T *end() { return m_data + m_size; }
    const T *begin() const { return m_data; }
    const T *end() const { return m_data + m_size; }

private:
    T *m_data;
    size_t m_size;
};

}  // namespace BLI

#endif
