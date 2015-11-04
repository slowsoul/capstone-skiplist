#include "skiplist_map_compact.h"

int main() {
    typedef cmu::skiplist_map_compact<uint64_t, uint64_t> SkiplistType;
    SkiplistType slmap;
    SkiplistType::const_iterator slmap_keyIter;

    // insert test
    std::pair<typename SkiplistType::iterator, bool> retval;

    for (int i = 0; i < 10; i++) {
        retval = slmap.insert(i, i);
        assert(retval.second == true);
    }

    slmap.print(std::cout);

    // update test
    slmap[2] = 4;
    slmap[5] = 10;
    assert(slmap.find(5).data() == 10);

    // find test
    slmap_keyIter = slmap.find(2);
    assert(slmap_keyIter != slmap.end());

    slmap_keyIter = slmap.find(200);
    assert(slmap_keyIter == slmap.end());

    // iterator test
    std::cout << "iterator: " << std::endl;
    for (slmap_keyIter = slmap.begin();slmap_keyIter != slmap.end();slmap_keyIter++) {
        std::cout << slmap_keyIter.key() << ": " << slmap_keyIter.data() << std::endl;
    }
    std::cout << std::endl;
    for (slmap_keyIter = --slmap.end();;slmap_keyIter--) {
        std::cout << slmap_keyIter.key() << ": " << slmap_keyIter.data() << std::endl;
        if (slmap_keyIter == slmap.begin()) {
            break;
        }
    }

    SkiplistType::const_reverse_iterator slmap_rev_keyIter;
    std::cout << "reverse iterator: " << std::endl;
    for (slmap_rev_keyIter = slmap.rbegin();slmap_rev_keyIter != slmap.rend();slmap_rev_keyIter++) {
        std::cout << slmap_rev_keyIter.key() << ": " << slmap_rev_keyIter.data() << std::endl;
    }
    std::cout << std::endl;
    for (slmap_rev_keyIter = --slmap.rend();;slmap_rev_keyIter--) {
        std::cout << slmap_rev_keyIter.key() << ": " << slmap_rev_keyIter.data() << std::endl;
        if (slmap_rev_keyIter == slmap.rbegin()) {
            break;
        }
    }

    // erase key test
    bool erased = slmap.erase(200);
    assert(erased == false);

    slmap.print(std::cout);

    erased = slmap.erase(1);
    assert(erased == true);

    slmap.print(std::cout);

    erased = slmap.erase(1);
    assert(erased == false);

    slmap.print(std::cout);

    // erase iterator test
    SkiplistType::iterator slmap_nonconst_keyIter;
    slmap_nonconst_keyIter = slmap.find(2);
    assert(slmap_nonconst_keyIter != slmap.end());
    slmap.erase(slmap_nonconst_keyIter);
    slmap.print(std::cout);

    slmap_nonconst_keyIter = slmap.find(3);
    assert(slmap_nonconst_keyIter != slmap.end());
    slmap.erase(slmap_nonconst_keyIter);
    slmap_nonconst_keyIter = slmap.find(2);
    assert(slmap_nonconst_keyIter == slmap.end());

    slmap.print(std::cout);
}
