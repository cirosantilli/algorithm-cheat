/*
Trie set.

Unlike single struct BSTs, we can represent empty tries without the NULL pointer:

TODO:

- free
- is_empty
- find with prefix
- typo correction
*/

#include <assert.h>
#include <stdlib.h>

#define ALPHABET_SIZE 8

typedef unsigned int t;
typedef t ts[];

typedef struct Trie Trie;
struct Trie {
    Trie *children[ALPHABET_SIZE];
    int is_word;
};

void Trie_init(Trie **trie) {
    size_t i;
    *trie = malloc(sizeof(Trie));
    (*trie)->is_word = 0;
    for (i = 0; i < ALPHABET_SIZE; ++i)
        (*trie)->children[i] = NULL;
}

int Trie_add(Trie *trie, t *word, size_t size) {
    size_t i;
    int present;
    Trie **next;
    for (i = 0; i < size; ++i) {
        next = &trie->children[word[i]];
        if (*next == NULL)
            Trie_init(next);
        trie = *next;
    }
    present = trie->is_word;
    trie->is_word = 1;
    return present;
}

int Trie_find(Trie *trie, t *word, size_t size) {
    size_t i;
    for (i = 0; i < size; ++i) {
        trie = trie->children[word[i]];
        if (trie == NULL)
            return 0;
    }
    if (trie->is_word)
        return 1;
    return 0;
}

int main(void) {
    Trie *trie = NULL;
    Trie_init(&trie);

    /* find on empty trie. */
    assert(!Trie_find(trie, (ts){0}, 1));

    /* Add and find length 1. */
    assert(!Trie_add(trie, (ts){0}, 1));
    assert(Trie_find(trie, (ts){0}, 1));
    assert(!Trie_find(trie, (ts){1}, 1));

    /* Add previously added. */
    assert(Trie_add(trie, (ts){0}, 1));

    /* Add and find length 3 */
    {
        assert(Trie_find(trie, (ts){0}, 1));
        assert(!Trie_find(trie, (ts){0, 1}, 2));
        assert(!Trie_find(trie, (ts){0, 1, 2}, 3));

        assert(!Trie_add(trie, (ts){0, 1, 2}, 3));

        assert(Trie_find(trie, (ts){0}, 1));
        assert(!Trie_find(trie, (ts){0, 1}, 2));
        assert(Trie_find(trie, (ts){0, 1, 2}, 3));
    }

    return EXIT_SUCCESS;
}
