#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "map.hpp"

template<class KEY>
size_t hash(KEY key, size_t container_size);

template<>
size_t hash<int>(int key, size_t container_size){
    return key % container_size;
}

/**
Hash map.

@tparam KEY the key type of the map
@tparam VAL the value value of the map
*/
template<class KEY,class VAL>
class HashMap : public Map<KEY,VAL> {
    typedef std::vector<std::list<std::pair<KEY,VAL>>> map_t;
    public:
        using Map<KEY,VAL>::init_initializer;
        using Map<KEY,VAL>::add;
        HashMap(size_t keyCountInitial = HashMap::keyCountInitialDefault,
             float loadFactor = 0.7
        ):
             keyCount(keyCountInitial),
             loadFactor(loadFactor),
             map(map_t(keyCount))
        {};

        HashMap(const KEY& key, const VAL& val,
             size_t keyCountInitial = HashMap::keyCountInitialDefault,
             float loadFactor = 0.7
        ) : HashMap(keyCountInitialDefault, loadFactor)
        { this->init_pair(key, val); }

        HashMap(std::initializer_list<std::pair<KEY,VAL>> pairs) : HashMap() { this->init_initializer(pairs); }

        virtual ~HashMap() {}

        bool add(const KEY& key, const VAL& val) {
            size_t h, newKeyCount, newSize;
            map_t oldMap;
            h = hash<KEY>(key, map.size());
            // If already present, return false.
            for (auto& pair : map[h])
                if (std::get<0>(pair) == key)
                    return false;
            newKeyCount = this->keyCount + 1;
            // Increase size if necessary and rehash everything
            if (newKeyCount >= this->map.size() * this->loadFactor) {
                oldMap = this->map; //TODO possible to avoid this costly copy?
                newSize = this->map.size() * this->increaseFactor;
                this->map = map_t(newSize);
                for (auto& list : oldMap) {
                    for (auto& pair : list) {
                        this->add(pair);
                    }
                }
                h = hash(key, newSize);
            }
            //if (std::find_if(
                //map[h].begin(),
                //map[h].end(),
                //[&key](std::pair<KEY,VAL> pair){ return std::get<0>(pair) == key; }
            //) != map[h].end()) {
                //return false;
            //}
            this->map[h].push_back(std::pair<KEY,VAL>(key, val));
            this->keyCount = newKeyCount;
            return true;
        }

        bool del(const KEY& key) {
            auto& list = map[ hash<KEY>(key, map.size()) ];
            //for (auto& pair : list) {
                //if (std::get<0>(pair) == key)
                    //break;
            //}
            auto it = std::find_if(
                list.begin(),
                list.end(),
                [&key](const std::pair<KEY,VAL>& pair){ return std::get<0>(pair) == key; });

            if (it != list.end()) {
                list.erase(it);
                return true;
            }
            return false;
        }

        bool find(const KEY& key, VAL& val) {
            size_t h;
            h = hash<KEY>(key, map.size());
            for (auto& pair : map[h]) {
                if (std::get<0>(pair) == key) {
                    val = std::get<1>(pair);
                    return true;
                }
            }
            return false;
        }

        /**
        Return a string representation of the map.
        */
        std::string str() const {
            std::stringstream ss;
            for (size_t i = 0; i < this->map.size(); i++) {
                auto& list = this->map[i];
                if (list.size() > (size_t)0) {
                    ss << i << ": ";
                    for (auto& pair : list) {
                        ss << std::get<0>(pair) << ":" << std::get<1>(pair) << ", ";
                    }
                    ss << std::endl;
                }
            }
            return ss.str();
        }

        bool operator==(const HashMap<KEY,VAL>& other) const { return this->map == other.map; }
        bool operator!=(const HashMap<KEY,VAL>& other) const { return ! (this->map == other.map); }

    private:
        const static size_t keyCountInitialDefault = 1;
        // By how much the map size will be multiplied if it needs to grow
        const static int increaseFactor = 2;
        size_t keyCount;
        float loadFactor;
        map_t map;
};

#endif
