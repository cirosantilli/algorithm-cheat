#ifndef MAP_H
#define MAP_H

#include <utility>          // pair

/**
Map abstract class.

@tparam KEY the key type of the map
@tparam VAL the value type value of the map.
@todo Add a key value iterator interface and implement str() in terms of it.
*/
template<class KEY,class VAL>
class Map {
    public:
        /**
        Initialize map with key value pairs.

        Cannot be done from a constructor because relies on virtual method `add`

        <http://stackoverflow.com/questions/496440/c-virtual-function-from-constructor>
        */
        void init_pair(const KEY& key, const VAL& val) { this->add(key, val); }
        void init_initializer(std::initializer_list<std::pair<KEY,VAL>> pairs) {
            for (auto& pair : pairs) {
                this->add(pair);
            }
        }

        virtual bool add(const KEY& key, const VAL& val) = 0;
        virtual bool del(const KEY& key) = 0;
        // TODO Should be const, waiting for Bst find to become const.
        virtual bool find(const KEY& key, VAL& val) = 0;
        // TODO how to add those to the interface? Does not override because
        // derived class signature is different (Hash instead of Map).
        //virtual bool operator==(const Map<KEY,VAL>& other) const = 0;
        //virtual bool operator!=(const Map<KEY,VAL>& other) const = 0;
        virtual std::string str() const = 0;

        /**
        std::pair add based on add(key,val).
        */
        bool add(const std::pair<KEY,VAL>& pair) { return add(pair.first, pair.second); }

        /**
        ostream << operator. Based on str.
        */
        friend std::ostream& operator<<(std::ostream& os, const Map<KEY,VAL>& rhs) { return os << rhs.str(); }
};

#endif
