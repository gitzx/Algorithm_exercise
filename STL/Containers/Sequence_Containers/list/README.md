Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.

###Container properties###

(1)Sequence

(2)Doubly-linked list

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

#####四.Element access:#####

(1)front

(2)back

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

(10)resize

(11)emplace(C++11): Construct and insert element

(12)emplace_back(C++11):Construct and insert element at the end

(13)emplace_front(C++11):Construct and insert element at beginning 

#####六.Operations:#####

(1)splice:Transfer elements from list to list

(2)remove: Remove elements with specific value 

(3)remove_if: Remove elements fulfilling condition

(4)unique: Remove duplicate values

(5)merge: Merge sorted lists 

(6)sort: Sort elements in container

(7)reverse: Reverse the order of elements

#####七.Observers:######

(1)get_allocator