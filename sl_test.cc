#include "skiplist_map.h"

int main() {
    typedef cmu::skiplist_map<uint64_t, uint64_t> SkiplistType;
    SkiplistType slmap;
    SkiplistType::const_iterator slmap_keyIter;

    // insert test
    std::pair<typename SkiplistType::iterator, bool> retval;
    /*
    retval = slmap.insert(1, 1);
    assert(retval.second == true);
    retval = slmap.insert(1, 3);
    assert(retval.second == false);
    retval = slmap.insert(2, 2);
    assert(retval.second == true);
    */

    slmap.print(std::cout);

    for (int i = 0; i < 40; i++) {
        retval = slmap.insert(i, i);
        assert(retval.second == true);
        slmap.print(std::cout);
    }

    /*
    // update test
    slmap[2] = 4;
    slmap[5] = 5;

    slmap.print(std::cout);

    // find test
    slmap_keyIter = slmap.find(2);
    assert(slmap_keyIter != slmap.end());

    slmap_keyIter = slmap.find(3);
    assert(slmap_keyIter == slmap.end());

    // erase key test
    bool erased = slmap.erase(3);
    assert(erased == false);
    erased = slmap.erase(1);
    assert(erased == true);

    slmap.print(std::cout);

    // erase iterator test
    SkiplistType::iterator slmap_nonconst_keyIter;
    slmap_nonconst_keyIter = slmap.find(2);
    assert(slmap_nonconst_keyIter != slmap.end());
    slmap.erase(slmap_nonconst_keyIter);

    slmap.print(std::cout);
    */
}
