template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return !count;
    
}

template<class T>
T Heap<T>::peek(){
    if(count == 0) return -1;
    else return elements[0];
    
}

template<class T>
bool Heap<T>::contains(T item){
    for(int i = 0 ; i < count ; i++)
    {
        if(item == elements[i]) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if(count == 0) return false;
    swap(elements[0],elements[count-1]);
    count--;
    reheapDown(0);
    return true;
}

emplate<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if(count < capacity) return;
    capacity++;
    T * new_elements = new T[capacity];
    for(int i = 0 ; i < count;  i++)
    {
        new_elements[i] = elements[i];
        
    }
    delete[] elements;
    elements = new_elements;
    
}

template<class T>
void Heap<T>::reheapUp(int position){
    int n = (position-1)/2;
    if(position == 0 || elements[n] >= elements[position]) return;
    else
    {
        T temp = elements[position];
        elements[position] = elements[n];
        elements[n] = temp;
        reheapUp(n);
    }
}

template<class T>
void Heap<T>::push(T item){
    ensureCapacity(capacity);
    elements[count]=item;
    reheapUp(count);
    count++;
}


void reheapDown(int maxHeap[], int numberOfElements, int index)
{
       while(index < numberOfElements/2){
        int x  = index;
        int l = index * 2 + 1;
        int r = index * 2 + 2;
        if(maxHeap[l] > maxHeap[index]) 
        {
            index = l;
        }
        if(maxHeap[r] > maxHeap[index]) 
        {
            index = r;
        }
        if(index != l && index != r) return;
        else swap(maxHeap[x],maxHeap[index]);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    while(index > 0){
        int parent = (index - 1) / 2;
        if(maxHeap[index] < maxHeap[parent]) return;
        
        swap(maxHeap[index], maxHeap[parent]);
        index = parent;
    }   
}

template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for(int i = 0; i < count; i++){
        if (elements[i] == item){
            return i;
        }
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    
    if (index == -1){
        return;
    }
    
    swap(elements[index], elements[count - 1]);
    
    count--;
    
    if (index > 0 && elements[index] > elements[(index -1) / 2]){
        reheapUp(index);
    } else {
        reheapDown(index);
    }
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    delete[] elements;
    
    this->capacity = 10;
    this->count = 0;
    this->elements = new T[capacity];
}

//Helping functions go here
static void heapSort(T* start, T* end){

    priority_queue<T> q(start, end);
    T* temp = end - 1;
    while(!q.empty()){
        *temp = q.top();
        q.pop();
        temp --;
    }
    Sorting<T>::printArray(start,end);
}

class PrinterQueue
{
    // your attributes
public:
    string max_heap[200];
    int size = 0;
    
public:
    // your methods

    void addNewRequest(int priority, string fileName)
    {
        // your code here
        if(max_heap[priority] == "")
        {
            max_heap[priority] = fileName;
            
        }
        else
        {
            max_heap[priority] += " " + fileName;
        }
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline
        for( int i = 200 - 1 ; i >= 0 ; i--)
        {
            if(max_heap[i] != "")
            {
                int index = max_heap[i].find(" ");
                if(index == -1)
                {
                    cout << max_heap[i] <<endl;
                    max_heap[i] = "";
                }
                else
                {
                    cout<<max_heap[i].substr(0,index) <<endl;
                    max_heap[i] = max_heap[i].substr(index+1);
                }
                return;
            }
        }
        cout << "No file to print" << endl;
    }
    
};

int leastAfter(vector<int>& nums, int k) {
    // STUDENT ANSWER
    priority_queue<int, vector<int>, greater<int>> min_Heap(nums.begin(), nums.end());

    while (k--) {
        int smallest = min_Heap.top();
        min_Heap.pop();

        min_Heap.push(smallest * 2);
    }

    return min_Heap.top();
}