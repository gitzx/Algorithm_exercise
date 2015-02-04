Vectors are sequence containers representing arrays that can change in size.

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

(3)resize

(4)capacity 

(5)empty

(6)reserve:Request a change in capacity

(7)shrink_to_fit(C++11):Shrink to fit

#####四.Element access:#####

(1)operator[]

(2)at

(3)front

(4)back

(5)data(C++11):Access data

#####五.Modifiers:#####

(1)assign

(2)push_back

(3)pop_back

(4)insert

(5)erase

(6)swap

(7)clear

(8)emplace(C++11):Construct and insert element

(9)emplace_back(C++11):Construct and insert element at the end

#####六.Allocator:#####

(1)get_allocator

#####七.Template specializations:######

(1)vector<bool>