

int defaultSize = 50;

template <typename E> class AStack: public Stack<E> {
    private:
        int maxSize;
        int top;
        E *listArray;
    public:
        AStack(int size = defaultSize) {
            maxSize = size;
            top = 0;
            listArray = new E[size];
        }
        ~AStack() {
            delete [] listArray;
        }
        void clear() {
            top = 0;
        }
        void push(const E& it) {
            if (top == maxSize) std::cout << "Stack Overflow\n";
            assert(top != maxSize);
            listArray[top++] = it;
        }
        E pop() {
            assert(top != 0);
            return listArray[--top]; 
        }
        const E& topValue() const {
            if (top == 0) std::cout << "stack is empty\n";
            assert(top != 0);
            return listArray[top - 1];

        }
        int length() const {return top;}
};
