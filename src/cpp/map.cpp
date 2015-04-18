//#define DEBUG_OUTPUT

#include <algorithm>
#include <cassert>
#include <cmath>
#include <limits>
#include <functional>
#include <iostream>
#include <list>
#include <sstream>

#include "map.hpp"
//#include "bst.hpp"
#include "hash_map.hpp"

int main() {

    // Choose the map type.
    typedef HashMap<int,int> map_t;

    // TODO broken.
    //typedef Bst<int,int> map_t;

    map_t mapOrig{
        { 0, 1},
        { 1, 2},
        { 2, 3},
        { 3, 4},
        { 4, 5},
        {-1, 0},
    };
    map_t map;
    map_t mapExpect;
    int val;

    for (int i = 0; i < 1; i++) {

        //add

            // BST test

            // create a bst with all possible deletion cases:
            //
            // - two children
            // - one child
            // - 0   children

                mapOrig.add( 2, 3);
                mapOrig.add( 1, 2);
                mapOrig.add( 3, 4);
                mapOrig.add( 4, 5);
                mapOrig.add(-1, 0);

        //<<

            // TODO test with stringstream

            //std::cout << mapOrig << std::endl;

        //find

            map = mapOrig;
            assert(!map.find(-2, val));
            assert(map.find(-1, val));
            assert(val == 0);
            assert(map.find(0, val));
            assert(val == 1);
            assert(map.find(1, val));
            assert(val == 2);
            assert(map.find(2, val));
            assert(val == 3);
            assert(map.find(3, val));
            assert(val == 4);
            assert(map.find(4, val));
            assert(val == 5);

            //==

                map = mapOrig;
                assert(map == mapOrig);
                map.add(5, 6);
                assert(map != mapOrig);


            //del

                //two children
                map.del(0);
                assert(!map.find(0, val));

                //leaf
                map = mapOrig;
                map.del(1);
                assert(!map.find(1, val));

                //one child
                map = mapOrig;
                map.del(3);
                assert(!map.find(3, val));

        // Hash map tests.

            // Add at powers of 2 the 0 hash so they clutter at hash 0
            map = map_t(0, 1);
            map.add( 1,  2);
            map.add( 2,  3);
            map.add( 4,  5);
            map.add( 8,  9);
            map.add(16, 17);

            //find
            assert(map.find(8, val));
            assert(val == 9);

            //del
            map.del(0);
            assert(!map.find(0, val));
    }
}
