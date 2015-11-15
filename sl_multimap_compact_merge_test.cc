#include "skiplist_multimap.h"
#include "skiplist_multimap_ro.h"

int main() {
    typedef cmu::skiplist_multimap<uint64_t, uint64_t> SkiplistType;
    typedef cmu::skiplist_multimap_ro<uint64_t, uint64_t> SkiplistReadOnlyType;
    SkiplistReadOnlyType::iterator slmapro_iter;

    SkiplistType slmap;
    SkiplistReadOnlyType slmapro;

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 2; j++) {
            slmap.insert(i+1, j+1);
        }
    }

    slmap.print(std::cout);
    slmapro.merge(slmap);
    slmap.print(std::cout);
    slmapro.print(std::cout);

    slmapro.find(2).data() = 0;

    slmapro_iter = slmapro.find(2);
    assert(slmapro_iter != slmapro.end());
    assert(slmapro_iter.key() == 2 && slmapro_iter.data() == 1);

    slmapro_iter = slmapro.lower_bound(2);
    assert(slmapro_iter != slmapro.end());
    assert(slmapro_iter.key() == 2 && slmapro_iter.data() == 1);

    slmapro_iter = slmapro.upper_bound(1);
    assert(slmapro_iter != slmapro.end());
    assert(slmapro_iter.key() == 2 && slmapro_iter.data() == 1);

    std::pair<SkiplistReadOnlyType::iterator, SkiplistReadOnlyType::iterator> res = slmapro.equal_range(2);
    assert(res.first.key() == 2 && res.first.data() == 1);
    assert(res.second.key() == 3 && res.second.data() == 2);

    for (int i = 32; i < 64; i++) {
        for (int j = 0; j < 2; j++) {
            slmap.insert(i+1, j+1);
        }
    }

    slmap.print(std::cout);
    slmapro.merge(slmap);
    slmap.print(std::cout);
    slmapro.print(std::cout);
}
