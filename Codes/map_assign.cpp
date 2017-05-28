#include <assert.h>
#include <map>
#include <limits>
#include <bits/stdc++.h>
using namespace std;
template<class K, class V>
class interval_map {
    friend void IntervalMapTest();

private:
    std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.begin(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Do not change values outside this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, const V& val )
    {
        // INSERT YOUR SOLUTION HERE
         if ( keyBegin >= keyEnd ) return;
         if(m_map.find(keyBegin)!= m_map.end())
         {
            typename std::map<K,V>::iterator iter;
            iter it = m_map.find(keyBegin);
            int no_of_keys = keyEnd - keyBegin;
            m_map.erase(m_map.begin()+it,m_map.begin()+it+no_of_keys);
            for(int i = 0; i < no_of_keys; i++)
            {
                m_map.insert(m_map.begin()+it+i,std::make_pair(keyBegin+i,val));
            }

         }
//        for(typename std::map<K,V>::iterator i=m_map.find(keyBegin); i != m_map.find(keyEnd);++i)
//                    {
//                        //std::cout<<i->first;
//                        i->second=val;
//                    }
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a function IntervalMapTest() here that tests the
// functionality of the interval_map, for example using a map of unsigned int
// intervals to char.

int main(int argc, char* argv[]) {
    //IntervalMapTest();
    interval_map<short, int> IMap(4);
    cout<<IMap[5]<<endl;

    return 0;
}
