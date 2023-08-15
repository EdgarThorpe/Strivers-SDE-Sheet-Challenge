class MedianFinder {
    // MedianFinder() {
        priority_queue<int> maxH;
        priority_queue<int, vector<int>, greater<int>> minH;
    // }
    
public:
    void addNum(int num) {
        // maxH.push(num);
        // minH.push(maxH.top());
        // maxH.pop();
        // if(maxH.size()<minH.size()){
        //     maxH.push(minH.top());
        //     minH.pop();
        // }
        maxH.push(num);
        minH.push(maxH.top());
        maxH.pop();
        if(maxH.size() != minH.size()){
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        return maxH.size() != minH.size() ? maxH.top() : (double)(minH.top() + maxH.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */