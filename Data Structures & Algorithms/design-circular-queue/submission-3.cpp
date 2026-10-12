#include <atomic>
class MyCircularQueue {
private:
size_t capacity{};
std::vector<int> buffer;
alignas(64) std::atomic<int> head{0};
alignas(64) std::atomic<int> tail{0};
public:
    MyCircularQueue(int k) : capacity(k + 1) {
        buffer.resize(capacity);
    }
    
    bool enQueue(int value) {
        size_t current_head = head.load(std::memory_order_relaxed);
        size_t current_tail = tail.load(std::memory_order_acquire);

        if ((current_head + 1) % capacity == current_tail) {
            return false;
        }

        buffer[current_head] = value;
        head.store((current_head + 1) % capacity, std::memory_order_release);
        return true;
    }
    
    bool deQueue() {
        size_t current_head = head.load(std::memory_order_acquire);
        size_t current_tail = tail.load(std::memory_order_relaxed);

        if (current_head == current_tail) {
            return false;
        }

        tail.store((current_tail + 1) % capacity, std::memory_order_release);
        return true;
        
    }
    
    int Front() {
        size_t current_tail = tail.load(std::memory_order_relaxed);
        size_t current_head = head.load(std::memory_order_acquire);

        if (current_head == current_tail){
            return -1;
        }
        

        return buffer[current_tail];
    }
    
    int Rear() {
                size_t current_tail = tail.load(std::memory_order_acquire);
        size_t current_head = head.load(std::memory_order_relaxed);

        if (current_head == current_tail) {
            return -1;
        }
        size_t rear = (current_head + capacity -1 ) % capacity;
        return buffer[rear];
        
    }
    
    bool isEmpty() {
                size_t current_tail = tail.load(std::memory_order_relaxed);
        size_t current_head = head.load(std::memory_order_relaxed);
        
        return (current_head == current_tail);

    }
    
    bool isFull() {
                size_t current_tail = tail.load(std::memory_order_relaxed);
        size_t current_head = head.load(std::memory_order_acquire);
        
        return((current_head + 1) % capacity == current_tail);
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */