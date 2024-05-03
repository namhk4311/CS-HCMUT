//using namespace std;

int findMax(int* arr, int length)
{
    /*  
     * STUDENT ANSWER
     */
    if (length == 0) {
        return -1;
    }
    int max_val = arr[length - 1];
    return max(max_val, findMax(arr,length - 1));
}