#ifndef __BLI_SPAN_HH__
#define __BLI_SPAN_HH__

#include <cstddef>
#include <type_traits>

namespace BLI {

template<typename T>
class Span {
public:
    Span() : m_data(nullptr), m_size(0) {}
    Span(const T *data, size_t size) : m_data(data), m_size(size) {}
    template<size_t N>
    Span(const T (&arr)[N]) : m_data(arr), m_size(N) {}

    const T &operator[](size_t index) const { return m_data[index]; }
    size_t size() const { return m_size; }
    bool empty() const { return m_size == 0; }
    const T *data() const { return m_data; }
    const T *begin() const { return m_data; }
    const T *end() const { return m_data + m_size; }
    const T &first() const { return m_data[0]; }
    const T &last() const { return m_data[m_size - 1]; }
    Span slice(size_t start, size_t len) const { return Span(m_data + start, len); }

private:
    const T *m_data;
    size_t m_size;
};

template<typename T>
class MutableSpan {
public:
    MutableSpan() : m_data(nullptr), m_size(0) {}
    MutableSpan(T *data, size_t size) : m_data(data), m_size(size) {}
    template<size_t N>
    MutableSpan(T (&arr)[N]) : m_data(arr), m_size(N) {}

    T &operator[](size_t index) const { return m_data[index]; }
    size_t size() const { return m_size; }
    bool empty() const { return m_size == 0; }
    T *data() const { return m_data; }
    T *begin() const { return m_data; }
    T *end() const { return m_data + m_size; }
    T &first() const { return m_data[0]; }
    T &last() const { return m_data[m_size - 1]; }
    MutableSpan slice(size_t start, size_t len) const { return MutableSpan(m_data + start, len); }

private:
    T *m_data;
    size_t m_size;
};

}  // namespace BLI

#endif
