#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
 /**
  * @brief Construct a new Heap object
  *
  * @param m ary-ness of heap tree (default to 2)
  * @param c binary predicate function/functor that takes two items
  *          as an argument and returns a bool if the first argument has
  *          priority over the second.
  */
 Heap(int m=2, PComparator c = PComparator()) {
   this->m = m;
   comp = c;
 }


 /**
 * @brief Destroy the Heap object
 *
 */
 ~Heap() {}


 /**
  * @brief Push an item to the heap
  *
  * @param item item to heap
  */
 void push(const T& item) {
   data.push_back(item);
   sort_push(data.size());
 }


 /**
  * @brief Returns the top (priority) item
  *
  * @return T const& top priority item
  * @throw std::underflow_error if the heap is empty
  */
 T const & top() const;


 /**
  * @brief Remove the top priority item
  *
  * @throw std::underflow_error if the heap is empty
  */
 void pop();


 /// returns true if the heap is empty


 /**
  * @brief Returns true if the heap is empty
  *
  */
 bool empty() const {
   return data.empty();
 }


   /**
  * @brief Returns size of the heap
  *
  */
 size_t size() const {
   return data.size();
 }


private:
 /// Add whatever helper functions and data members you need below
 std::vector<T> data;
 PComparator comp;
 int m;


 // sort_pop
 void sort_pop(int size) {
   int parent = 0;


   while (true) {
     // int leftChild = (2*parent) + 1;
     // int rightChild = (2*parent) + 2;
     int bestChild = parent;


     // left child check
     for (int i = 1; i <= m; i++) {
       int child = m * parent + i;
       if (child < size && comp(data[child], data[bestChild])) {
         bestChild = child;
       }
     }
    
     if (bestChild != parent) {
       std::swap(data[parent], data[bestChild]);
       parent = bestChild;
     } else {
       break;
     }
   }
 }


 void sort_push(int size) {
   int currentChild = size - 1;
   while (currentChild > 0) {
     int parent = (currentChild - 1) / m;
     if (comp(data[currentChild], data[parent])) {
       std::swap(data[currentChild], data[parent]);
       currentChild = parent;
     } else {
       break;
     }
   }
 }
};




// Add implementation of member functions here
// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
 // Here we use exceptions to handle the case of trying
 // to access the top element of an empty heap
 if(empty()){
   // ================================
   // throw the appropriate exception
   // ================================
   throw std::underflow_error("Can't retrieve the top of an empty heap.");
 }


 // return "best" element
 return data[0];
}




// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
 if(empty()){
   // ================================
   // throw the appropriate exception
   // ================================
   throw std::underflow_error("Can't pop an empty heap.");
 }


 // swap first and last element, resort the heap
 std::swap(data[0], data.back());


 data.pop_back();
 sort_pop(data.size());
}




#endif
