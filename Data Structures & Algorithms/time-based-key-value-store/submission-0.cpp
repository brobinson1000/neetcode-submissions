class TimeMap {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> db;
public:
    TimeMap() = default;
    
    void set(string key, string value, int timestamp) {
        db[key].emplace_back(std::move(value), timestamp);
    }
    
    string get(string key, int timestamp) {
        auto it = db.find(key);
        if (it == db.end()) {
            return "";
        }

        const auto& entries = it->second;

        auto upper = std::upper_bound(entries.begin(), entries.end(), timestamp, [](int target_ts, const std::pair<std::string, int>& entry) {
            return target_ts < entry.second;
        });

        if (upper == entries.begin()) {
            return "";
        }

        return std::prev(upper)->first;



    }
};
