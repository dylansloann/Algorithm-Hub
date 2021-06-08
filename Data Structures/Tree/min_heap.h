#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdexcept>
#include <vector>
#include <math.h>

template <typename T>
class MinHeap {
    private:
        std::vector<T> queue;
        int size = 0;

    protected:
        int right_child(int i) {return 2*i + 2;}

        int left_child(int i) {return 2*i + 1;}
        
        int parent(int i) {return floor((i-1)/2);}
        
        void down_heap(int i) {
            T data = queue[i];
            int parent_index;
            for (; i > 0; i = parent_index) {
                parent_index = parent(i);
                if (data < queue[parent_index])
                    queue[i] = queue[parent_index];
                else
                    break;
            }

            queue[i] = data;
        }

        void up_heap(int i) {
            T start = queue[i];
            int right_index;
            int left_index;
            int smaller_child;
            for (; left_child(i) < size; i = smaller_child) {
                left_index = left_child(i);
                right_index = right_child(i);
                
                if (!(right_index < size))
                    smaller_child = left_index;
                else {
                    if (queue[left_index] < queue[right_index])
                        smaller_child = left_index;
                    else
                        smaller_child = right_index;
                }

                if (queue[smaller_child] < start)
                    queue[i] = queue[smaller_child];
                else
                    break;
            }

            queue[i] = start;            
        }
    
    public:
        void insert(const T& data) {
            if (size == queue.capacity()) {
                if (size == 0)
                    queue.resize(2);
                else
                    queue.resize(2 * size);
            }
            
            queue[size] = data;
            up_heap(size);
            size++;
        }

        bool is_empty() { return size == 0; }


        T min() { 
            if (is_empty())
                throw std::exception();
            return queue[0]; 
        }

        T remove_min() {
            if (is_empty())
                throw std::exception();
            
            T min = queue[0];
            queue[0] = queue[--size];
            down_heap(0);
            return min;
        }
};

#endif