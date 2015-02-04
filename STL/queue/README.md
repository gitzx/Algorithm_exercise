queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out), where elements are inserted into one end of the container and extracted from the other.

The underlying container may be one of the standard container class template or some other specifically designed container class. This underlying container shall support at least the following operations:

(1)empty

(2)size

(3)front

(4)back

(5)front

(6)push_back

(7)pop_front

The standard container classes `deque and list` fulfill these requirements.

###Member functions###

(1)constructor

(2)empty

(3)size

(4)front

(5)back

(6)push

(7)pop

(8)emplace(C++11): construct and insert element

(9)swap(C++11) : swap contents