// INSERTION SORT IMPLEMENTATION

// PSEUDOCODE: 
// two iterators, pointing at first and second elements
// compare, swap if first < second
// decrement both iterators and compare and swap again, 
// decrement again until no swap OR first == begin
// advance both iterators back to the end of the sorted subarray 
// (first on end of subarray, second on one past that one)
// need iterator to point to the end of the sorted subarray and stay there to mark how far we've sorted
// end if sorted points to the end of vector

#include <cstddef>
#include <iostream>
#include <vector> 

using namespace std;

typedef vector<int>::iterator iter;

void PrintVector(const vector<int>& vec){
    size_t size = vec.size();
    for(size_t i = 0; i!= size; ++i){
        cout << vec[i] << " ";
    }
    cout << endl;
}

void InsertionSort(vector<int>& nums){
    if (nums.empty() || nums.size() == 1)
        return;

    iter sorted = nums.begin();

    // keep incrementing and sorting until sorted iterator points to the last element, then we are done
    while (sorted != nums.end() - 1){
        iter left = sorted;
        iter right = sorted + 1;
        while (*left > *right){
            // swap elements
            int temp = *left;
            *left = *right;
            *right = temp;
            
            // decrement and swap until the element at right is at the correct place
            if (left != nums.begin()){
                --left;
                --right;
            }
        }
        ++sorted;
    }
}

int main() {
    vector<int> nums = {-10, 10, 5, 0, 0, 5, 10, -10};
    InsertionSort(nums);
    PrintVector(nums);

    return 0;
}