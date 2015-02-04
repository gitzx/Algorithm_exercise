Priority queues are a type of container adaptors, specifically designed such that its first element is always the greatest of the elements it contains, according to some strict weak ordering criterion.

This context is similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved (the one at the top in the priority queue).

The underlying container may be any of the standard container class templates or some other specifically designed container class. The container shall be accessible through random access iterators and support the following operations:

(1)empty()

(2)size()

(3)front()

(4)push_back()

(5)pop_back()

The standard container classes `vector and deque` fulfill these requirements.

Support of random access iterators is required to keep a heap structure internally at all times. This is done automatically by the container adaptor by automatically calling the algorithm functions make_heap, push_heap and pop_heap when needed.

###Member functions###

(1)constructor

(2)empty

(3)size

(4)top

(5)push

(6)pop

(8)emplace(C++11): construct and insert element

(9)swap(C++11) : swap contents