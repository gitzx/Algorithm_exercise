Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.

The underlying container may be any of the standard container class templates or some other specifically designed container class. The container shall support the following operations:

(1)empty

(2)size

(3)back

(4)push_back

(5)pop_back

The standard container classes `vector, deque and list` fulfill these requirements.

###Member functions###

(1)constructor

(2)empty

(3)size

(4)top

(5)push

(6)pop

(7)emplace(C++11): construct and insert element

(8)swap(C++11) : swap contents