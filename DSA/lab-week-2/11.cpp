void push(T item) {
    list.add(item);
}

// Remove an element in the head of the queue
T pop() {
    if (!empty()) {
        T front = list.get(0);
        list.removeAt(0);
        return front;
    } else {
        throw std::out_of_range("Queue is empty");
    }
}
// Get value of the element in the head of the queue
T top() {
    if (!empty()) {
        return list.get(0);
    } else {
        throw std::out_of_range("Queue is empty");
    }
}
// Determine if the queue is empty
bool empty() {
    return list.empty();
}

// Get the size of the queue
int size() {
    return list.size();
}

// Clear all elements of the queue
void clear() {
    list.clear();
}
