class MedianFinder {
    std::vector<int> vals;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        vals.push_back(num);
        std::sort(vals.begin(), vals.end());
    }
    
    double findMedian() {
        int vs = vals.size();

        if (vs % 2 == 0) {
            int m1 = vs / 2; // find 2 most middle values
            int m2 = (vs / 2) - 1;
            
            return (vals[m1] + vals[m2]) / 2.0; // compute mean
        } else {
            return vals[vs / 2]; // if odd find size / 2 = middle val
        }

        
    }
};
