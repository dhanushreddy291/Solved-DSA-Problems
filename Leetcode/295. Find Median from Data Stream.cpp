class MedianFinder {
    
private:
    priority_queue <int> maxHeap;
    priority_queue <int, vector <int>, greater <int>> minHeap;
    
public:
    
    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
        } else {
            if (maxHeap.top() > num) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
        }
        balancer();
    }

    void balancer() {
        if (maxHeap.size() > 1 + minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        return;
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
    
};