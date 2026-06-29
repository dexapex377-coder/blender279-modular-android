#ifndef __BLI_VECTOR_HH__
#define __BLI_VECTOR_HH__

#include <cstddef>
#include <utility>
#include <algorithm>
#include <initializer_list>

namespace BLI {

template<typename T, int N = 0>
class Vector {
public:
    Vector() : m_data(nullptr), m_size(0), m_capacity(0) {}
    explicit Vector(size_t size) : m_size(size), m_capacity(size) {
        m_data = new T[size]();
    }
    Vector(size_t size, const T &value) : m_size(size), m_capacity(size) {
        m_data = new T[size];
        std::fill(m_data, m_data + size, value);
    }
    Vector(std::initializer_list<T> list) : m_size(list.size()), m_capacity(list.size()) {
        m_data = new T[m_size];
        std::copy(list.begin(), list.end(), m_data);
    }
    ~Vector() { delete[] m_data; }

    Vector(const Vector &other) : m_size(other.m_size), m_capacity(other.m_size) {
        m_data = new T[m_size];
        std::copy(other.m_data, other.m_data + m_size, m_data);
    }
    Vector(Vector &&other) noexcept : m_data(other.m_data), m_size(other.m_size), m_capacity(other.m_capacity) {
        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }
    Vector &operator=(const Vector &other) {
        if (this != &other) {
            delete[] m_data;
            m_size = other.m_size;
            m_capacity = other.m_size;
            m_data = new T[m_size];
            std::copy(other.m_data, other.m_data + m_size, m_data);
        }
        return *this;
    }
    Vector &operator=(Vector &&other) noexcept {
        std::swap(m_data, other.m_data);
        std::swap(m_size, other.m_size);
        std::swap(m_capacity, other.m_capacity);
        return *this;
    }

    T &operator[](size_t index) { return m_data[index]; }
    const T &operator[](size_t index) const { return m_data[index]; }
    T *data() { return m_data; }
    const T *data() const { return m_data; }
    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
    bool empty() const { return m_size == 0; }

    T *begin() { return m_data; }
    T *end() { return m_data + m_size; }
    const T *begin() const { return m_data; }
    const T *end() const { return m_data + m_size; }

    T &first() { return m_data[0]; }
    const T &first() const { return m_data[0]; }
    T &last() { return m_data[m_size - 1]; }
    const T &last() const { return m_data[m_size - 1]; }

    void append(const T &value) {
        if (m_size >= m_capacity) grow();
        m_data[m_size++] = value;
    }
    void append(T &&value) {
        if (m_size >= m_capacity) grow();
        m_data[m_size++] = std::move(value);
    }
    void append_n(const T *values, size_t n) {
        reserve(m_size + n);
        std::copy(values, values + n, m_data + m_size);
        m_size += n;
    }
    void pop_last() { if (m_size > 0) m_size--; }
    T pop_last_get() { return m_data[--m_size]; }

    void reserve(size_t capacity) {
        if (capacity > m_capacity) {
            T *new_data = new T[capacity];
            std::copy(m_data, m_data + m_size, new_data);
            delete[] m_data;
            m_data = new_data;
            m_capacity = capacity;
        }
    }
    void resize(size_t size) {
        if (size > m_capacity) reserve(size);
        if (size > m_size) std::fill(m_data + m_size, m_data + size, T());
        m_size = size;
    }
    void clear() { m_size = 0; }
    void fill(const T &value) { std::fill(m_data, m_data + m_size, value); }

    Vector copy() const { return Vector(*this); }
    Vector &extend(const Vector &other) {
        append_n(other.data(), other.size());
        return *this;
    }

private:
    void grow() {
        size_t new_cap = m_capacity ? m_capacity * 2 : 4;
        T *new_data = new T[new_cap];
        std::copy(m_data, m_data + m_size, new_data);
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_cap;
    }

    T *m_data;
    size_t m_size;
    size_t m_capacity;
};

}  // namespace BLI

#endif
