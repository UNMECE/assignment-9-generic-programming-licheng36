#include <iostream>
#include <stdexcept>

template <typename T>
class GenericArray {
private:
    T* array;  // Pointer to the dynamically allocated array
    int length;  // Current size of the array

public:
// Constructor
	GenericArray() : array(NULL), length(0) {}
// Destructor
	~GenericArray() {
	delete[] array;
}

// Add an element to the end of the array
void addElement(T param) {
T* newArray = new T[length + 1];  // Allocate new memory
for (int i = 0; i < length; ++i) {
newArray[i] = array[i];  // Copy existing elements
}
newArray[length] = param;  // Add the new element
delete[] array;  // Free old memory
array = newArray;  // Point to the new array
++length;
}

// Return the element at a specific index
T at(int param) const {
if (param < 0 || param >= length) {
throw std::out_of_range("Index out of bounds");
}
return array[param];
}

// Return the size of the array
int size() const {
return length;
}

// Return the sum of the entire array
T sum() const {
T total = 0;
for (int i = 0; i < length; ++i) {
total += array[i];
}
return total;
}

// Return the maximum element in the array
T max() const {
if (length == 0) {
throw std::underflow_error("Array is empty");
}
T maxVal = array[0];
for (int i = 1; i < length; ++i) {
if (array[i] > maxVal) {
maxVal = array[i];
}
}
return maxVal;
}

// Return the minimum element in the array
T min() const {
if (length == 0) {
throw std::underflow_error("Array is empty");
}
T minVal = array[0];
for (int i = 1; i < length; ++i) {
if (array[i] < minVal) {
minVal = array[i];
}
}
return minVal;
}

// Return a slice of the array
T* slice(int begin, int end) const {
if (begin < 0 || end >= length || begin > end) {
throw std::out_of_range("Invalid slice range");
}
int sliceSize = end - begin + 1;
T* sliceArray = new T[sliceSize];
for (int i = 0; i < sliceSize; ++i) {
sliceArray[i] = array[begin + i];
}
return sliceArray;
}
};
// Main function for testing
int main() {
GenericArray<int> int_array;
int_array.addElement(10);
int_array.addElement(20);
int_array.addElement(30);
int_array.addElement(40);
int_array.addElement(50);

std::cout << "size of array is " << int_array.size() << std::endl;
std::cout << "sum of the array is " << int_array.sum() << std::endl;
std::cout << "maximum and minimum of array is " 
<< int_array.max() << "\t" << int_array.min() << std::endl;

int* sliced_array = int_array.slice(1, 3);
std::cout << "Sliced array: ";
for (int i = 0; i < 3; ++i) {  // Size of slice is (3 - 1 + 1) = 3

std::cout << sliced_array[i] << " ";
}
std::cout << std::endl;

delete[] sliced_array;  // Free memory for the sliced array

return 0;

}




