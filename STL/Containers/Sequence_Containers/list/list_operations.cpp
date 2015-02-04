#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> first;
    list<int> second(4,100);
    list<int> third(second.begin(),second.end());
    list<int> fourth(third);
    int myints[]={1,2,3,4};
    list<int> fifth(myints,myints+sizeof(myints)/sizeof(int));
    list<int>::iterator it;
    for(it=fifth.begin();it!=fifth.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    list<int>::reverse_iterator rit;
    for(rit=fifth.rbegin();rit!=fifth.rend();++rit){
        cout<<*rit<<" ";
    }
    cout<<endl;
/*
    for(auto cit=fifth.cbegin();cit!=fifth.cend();++cit){
        cout<<*cit<<" ";
    }
    cout<<endl;
    for(auto crit=fifth.crbegin();crit!=fifth.crend();crit++){
        cout<<*crit<<" ";
    }
    cout<<endl;
*/
    cout<<"fifth is empty? "<<fifth.empty()<<endl;
    cout<<"size of fifth: "<<fifth.size()<<endl;
    cout<<"max_size of fifth: "<<fifth.max_size()<<endl;
    cout<<"front of fifth: "<<fifth.front()<<endl;
    cout<<"back of fifth: "<<fifth.back()<<endl;
    list<int> sixth;
    sixth.assign(fifth.begin(),fifth.end());
    sixth.push_front(0);
    sixth.push_front(1);
    sixth.pop_front();
    sixth.push_back(5);
    sixth.push_back(6);
    sixth.pop_back();
    sixth.insert(sixth.end(),6);
    sixth.remove(3);
    sixth.push_back(2);
    sixth.unique();
    sixth.sort();
    sixth.reverse();
    sixth.merge(fifth);
    list<int>::iterator it1;
    for(it1=sixth.begin();it1!=sixth.end();++it1){
        cout<<*it1<<" ";
    }
    cout<<endl;
    return 0;
}

/*
 1 2 3 4 
 4 3 2 1 
 fifth is empty? 0
 size of fifth: 4
 max_size of fifth: 768614336404564650
 front of fifth: 1
 back of fifth: 4
 1 2 3 4 6 5 4 2 2 1 0 
 */
