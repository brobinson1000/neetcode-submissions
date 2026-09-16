class LRUCache {
private:
    std::list<std::pair<int, int>> cacheList; 
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // If value does not exist
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }

        // Move value to the begininning of the list
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key] -> second;

        
    }
    
    void put(int key, int value) {
        // If we already have a value for key update value and put back at beginning
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return;
        }

        // If capacity is full for LRU cache we need to delete the least frequently acessed
        if (cacheMap.size() == cap) {
            int delkey = cacheList.back().first;
            cacheList.pop_back();
            cacheMap.erase(delkey);
        }

        //append new value and key
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};
