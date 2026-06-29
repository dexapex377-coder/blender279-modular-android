#ifndef __BLI_SET_HH__
#define __BLI_SET_HH__

#include <unordered_set>
#include <cstddef>

namespace BLI {

template<typename T>
class Set {
public:
    Set() = default;
    Set(std::initializer_list<T> list) : m_set(list) {}

    void add(const T &value) { m_set.insert(value); }
    void add_multiple(std::initializer_list<T> list) { m_set.insert(list.begin(), list.end()); }
    bool contains(const T &value) const { return m_set.find(value) != m_set.end(); }
    void remove(const T &value) { m_set.erase(value); }
    size_t size() const { return m_set.size(); }
    bool empty() const { return m_set.empty(); }
    void clear() { m_set.clear(); }

    auto begin() const { return m_set.begin(); }
    auto end() const { return m_set.end(); }

private:
    std::unordered_set<T> m_set;
};

}  // namespace BLI

#endif
