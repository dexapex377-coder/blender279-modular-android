#ifndef __BLI_STRING_REF_HH__
#define __BLI_STRING_REF_HH__

#include <cstring>
#include <string>
#include <string_view>

namespace BLI {

class StringRef {
public:
    StringRef() : m_data(""), m_size(0) {}
    StringRef(const char *str) : m_data(str), m_size(std::strlen(str)) {}
    StringRef(const char *data, size_t size) : m_data(data), m_size(size) {}
    StringRef(const std::string &str) : m_data(str.data()), m_size(str.size()) {}

    const char *data() const { return m_data; }
    size_t size() const { return m_size; }
    bool empty() const { return m_size == 0; }
    char operator[](size_t i) const { return m_data[i]; }
    const char *begin() const { return m_data; }
    const char *end() const { return m_data + m_size; }
    StringRef substr(size_t start, size_t len) const { return StringRef(m_data + start, len); }
    std::string to_string() const { return std::string(m_data, m_size); }

    int compare(const StringRef &other) const {
        if (m_size != other.m_size) return m_size < other.m_size ? -1 : 1;
        return std::memcmp(m_data, other.m_data, m_size);
    }
    bool operator==(const StringRef &other) const {
        return m_size == other.m_size && std::memcmp(m_data, other.m_data, m_size) == 0;
    }
    bool operator!=(const StringRef &other) const { return !(*this == other); }
    bool operator<(const StringRef &other) const { return compare(other) < 0; }

    operator std::string() const { return to_string(); }
    operator std::string_view() const { return std::string_view(m_data, m_size); }

    static StringRef from_ptr(const char *data, size_t size) { return StringRef(data, size); }

private:
    const char *m_data;
    size_t m_size;
};

}  // namespace BLI

#endif
