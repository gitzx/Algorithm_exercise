#include <iostream>
#include <vector>
using namespace std;

int main(){
   vector<int> first;
   vector<int> second(4,100);
   vector<int> third(second.begin(),second.end());
   vector<int> forth(third);
   int myints[]={1,2,3,4,5};
   vector<int> fifth(myints,myints+sizeof(myints)/sizeof(int));
   cout<<"size: "<<fifth.size()<<endl;
   cout<<"max_size: "<<fifth.max_size()<<endl;
   cout<<"capacity: "<<fifth.capacity()<<endl;
   fifth.reserve(100);
   cout<<"reserve: "<<fifth.capacity()<<endl;
   //fifth.shrink_to_fit();
   //cout<<"shrink_to_fit: "<<fifth.capacity()<<endl;
   vector<int>::iterator it;
   for(it=fifth.begin();it!=fifth.end();++it){
       cout<<*it<<" ";
   }
   cout<<endl;
   vector<int>::reverse_iterator rit;
   for(rit=fifth.rbegin();rit!=fifth.rend();++rit){
       cout<<*it<<" ";
   }
   cout<<endl;
   for(int i=0;i<fifth.size();++i){
       cout<<fifth[i]<<endl;
   }
   cout<<endl;
   vector<int> sixth(10);
   for(int i=0;i<sixth.size();++i){
       sixth.at(i)=i;
   }
   cout<<"sixth front: "<<sixth.front()<<endl;
   cout<<"sixth back: "<<sixth.back()<<endl;
   for(int i=0;i<sixth.size();++i){
       cout<<sixth[i]<<" ";
   }
   cout<<endl;
   vector<int> seventh;
   seventh.assign(3,1);
   seventh.push_back(4);
   seventh.push_back(5);
   seventh.pop_back();
   int myarray[]={6,7,8};
   seventh.insert(seventh.end(),myarray,myarray+3);
   seventh.erase(seventh.begin(),seventh.begin()+1);
   for(int i=0;i<seventh.size();++i){
       cout<<seventh[i]<<" ";
   }
   cout<<endl;
   /*
   for(auto cit=fifth.cbegin();cit!=fifth.end();++cit){
       cout<<*cit<<" ";
   }
   cout<<endl;
   for(auto crit=fifth.crbegin();crit!=fifth.crend();++crit){
       cout<<*crit<<" ";
   }
   cout<<endl;
   i*/
   return 0;
}

/*
size: 5
max_size: 4611686018427387903
capacity: 5
reserve: 100
1 2 3 4 5 
0 0 0 0 0 
1
2
3
4
5

sixth front: 0
sixth back: 9
0 1 2 3 4 5 6 7 8 9 
1 1 4 6 7 8 
*/
