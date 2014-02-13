#open addressing

Good sources on open adressing:

- <http://webdocs.cs.ualberta.ca/~holte/T26/open-addr.html>
- <http://www.algolist.net/Data_structures/Hash_table/Open_addressing>

Tradeoffs with chaining:

Open addressing vs. chaining

- Collision resolution

    Using external data structure

    Using hash table itself

- Memory waste

    - Pointer size overhead per entry (storing list heads in the table)

    - No overhead 1

- Performance dependence on table's load factor

    - Directly proportional

    - Proportional to (loadFactor) / (1 - loadFactor)

- Allow to store more items, than hash table size

    - Yes
    - No. Moreover, it's recommended to keep table's load factor below 0.7

- Hash function requirements

    - Uniform distribution

    - Uniform distribution, should avoid clustering

- Handle removals

    - Removals are ok

    - Removals clog the hash table with "DELETED" entries

- Implementation

    - Simple

    - Correct implementation of open addressing based hash table is quite tricky
