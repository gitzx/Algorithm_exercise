Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.

###Container properties###

(1)Associative

(2)Ordered

(3)Map

(4)Unique Keys

(5)Allocator-aware

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

(1)operator[]

(2)at(C++11)

#####五.Modifiers:#####

(1)insert

(2)erase

(3)swap

(4)clear

(5)emplace(C++11):Construct and insert element

(6)emplace_hint(C++11):Construct and insert element with hint

#####六.Operations:#####

(1)find :get iterator to element

(2)count :count elements with a specific value

(3)lower_boundz :return iterator to lower bound

(4)upper_bound :return iterator to upper bound

(5)equal_range :get range of equal elements

#####七.Observers:#####

(1)key_comp :Return comparison object

(2)value_comp :Return comparison object

#####八.Allocator:#####

(1)get_allocator
