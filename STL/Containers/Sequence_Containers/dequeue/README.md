deque (usually pronounced like "deck") is an irregular acronym of double-ended queue. Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back).

###Container properties###

(1)Sequence

(2)Dynamic array

(3)Allocator-aware

###Member ###

#####一.Member functions:#####

(1)constructor

(2)destructor

(3)operator=

#####二.Iterators:#####

(1)begin 

(2)end

(3)rbegin

(4)rend

(5)cbegin(C++11)

(6)cend(C++11)

(7)crbegin(C++11)

(8)crend(C++11)

#####三.Capacity:#####

(1)size

(2)max_size

(3)empty

(4)resize

(5)shrink_to_fit

#####四.Element access:#####

(1)front

(2)back

(3)at 

(4)operator[]

#####五.Modifiers:#####

(1)assign

(2)push_back

(3)pop_back

(4)push_front

(5)pop_front

(6)insert

(7)erase

(8)swap

(9)clear

(10)emplace(C++11): Construct and insert element

(11)emplace_back(C++11):Construct and insert element at the end

(12)emplace_front(C++11):Construct and insert element at beginning 


#####六.Observers:######

(1)get_allocator