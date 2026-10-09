class LRUCache {
private:
int cap{};
std::list<std::pair<int, int>> cache_list;
std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_map;
public:
    LRUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        auto it = cache_map.find(key);
        if (it == cache_map.end()) {
            return -1;
        }

        cache_list.splice(cache_list.begin(), cache_list, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = cache_map.find(key);

        if (it != cache_map.end()) {
            it->second->second = value;
            cache_list.splice(cache_list.begin(), cache_list, it->second);
            return;
        }

        if (cache_list.size() == cap) {
            int lru_key = cache_list.back().first;
            cache_map.erase(lru_key);
            cache_list.pop_back();
        }

        cache_list.emplace_front(key, value);
        cache_map[key] = cache_list.begin();
    }
};
