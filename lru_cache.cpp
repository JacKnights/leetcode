#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
    unordered_map<int, list<pair<int, int>>::iterator> m_idx;
    list<pair<int, int>> m_data;
    int m_cap;

   public:
    LRUCache(int capacity) { m_cap = capacity; }

    int get(int key) {
        if (m_idx.find(key) == m_idx.end()) {
            return -1;
        }
        int val = m_idx[key]->second;
        m_data.erase(m_idx[key]);
        m_data.push_front(make_pair(key, val));
        m_idx[key] = m_data.begin();
        return val;
    }

    void put(int key, int value) {
        if (m_idx.find(key) != m_idx.end()) {
            m_data.erase(m_idx[key]);
        } else if (m_data.size() >= this->m_cap) {
            auto back = m_data.back();
            m_idx.erase(back.first);
            m_data.pop_back();
        }
        m_data.push_front(make_pair(key, value));
        m_idx[key] = m_data.begin();
    }
};