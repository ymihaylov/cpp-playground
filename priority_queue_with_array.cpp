// C++ program to implement Priority Queue
// using Arrays
using namespace std;

// Structure for the elements in the
// priority queue
struct item {
    int value;
    int priority;
};

// Store the element of a priority queue
item priorityQueue[100000];

// Pointer to the last index
int size = -1;

// Function to insert a new element
// into priority queue
void enqueue(int value, int priority)
{
    // Increase the size
    size++;

    // Insert the element
    priorityQueue[size].value = value;
    priorityQueue[size].priority = priority;
}

// Function to check the top element
int peek()
{
    int highestPriority = INT_MIN;
    int index = -1;

    // Check for the element with
    // the highest priority
    for (int i = 0; i <= size; i++) {
        // If priority is same choose the element with the highest value
        if (highestPriority == priorityQueue[i].priority && index > -1
            && priorityQueue[index].value < priorityQueue[i].value) {
            highestPriority = priorityQueue[i].priority;
            index = i;
        } else if (highestPriority < priorityQueue[i].priority) {
            highestPriority = priorityQueue[i].priority;
            index = i;
        }
    }

    // Return position of the element
    return index;
}

// Function to remove the element with
// the highest priority
void dequeue()
{
    // Find the position of the element
    // with highest priority
    int index = peek();

    // Shift the element one index before
    // from the position of the element
    // with highest priority is found
    for (int i = index; i < size; i++) {
        priorityQueue[i] = priorityQueue[i + 1];
    }

    // Decrease the size of the
    // priority queue by one
    size--;
}

// Driver Code
int main()
{
    // Function Call to insert elements
    // as per the priority
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);

    // Stores the top element
    // at the moment
    int index = peek();

    cout << priorityQueue[index].value << endl;

    // Dequeue the top element
    dequeue();

    // Check the top element
    index = peek();
    cout << priorityQueue[index].value << endl;

    // Dequeue the top element
    dequeue();

    // Check the top element
    index = peek();
    cout << priorityQueue[index].value << endl;

    return 0;
}
