/*
TODO factor out test data with C++.

TODO create a top level object so that we can have an
empty method. currently NULL is used.
*/

#include "common.h"

typedef struct Bst Bst;
struct Bst {
    Bst *right;
    Bst *left;
    int key;
    int value;
};

int bst_add(Bst **bst, int key, int value) {
    int cur_key;
    int done = 0;
    int present = 0;
    Bst *cur = *bst;
    if (cur == NULL) {
        *bst = malloc(sizeof(Bst));
        cur = *bst;
    } else {
        while (!done) {
            cur_key = cur->key;
            if (cur_key == key) {
                done = 1;
                present = 1;
            } else if (cur_key < key) {
                if (cur->left == NULL) {
                    cur->left = malloc(sizeof(Bst));
                    done = 1;
                }
                cur = cur->left;
            } else {
                if (cur->right == NULL) {
                    cur->right = malloc(sizeof(Bst));
                    done = 1;
                }
                cur = cur->right;
            }
        }
    }
    cur->key = key;
    cur->value = value;
    return present;
}

int bst_find(const Bst *bst, int key, int *value) {
    while (bst != NULL) {
        if (bst->key == key) {
            *value = bst->value;
            return 1;
        } else if (bst->key < key) {
            bst = bst->left;
        } else {
            bst = bst->right;
        }
    }
    return 0;
}

void bst_free(Bst **bst) {
    Bst *cur = *bst;
    if (cur != NULL) {
        bst_free(&(cur->left));
        bst_free(&(cur->right));
        free(cur);
        *bst = NULL;
    }
}

int bst_remove(Bst **bst, int key) {
    int cur_key;
    int has_left, has_right;
    int is_left_child;
    int value;
    Bst *cur, *parent, *left, *right, *next;
    cur = *bst;
    parent = NULL;
    while (cur != NULL) {
        cur_key = cur->key;
        if (cur_key == key) {
            left = cur->left;
            right = cur->right;
            has_left = left != NULL;
            has_right = right != NULL;
            if (has_left && has_right) {
                parent = cur;
                next = right;
                while (next->left != NULL) {
                    parent = next;
                    next = next->left;
                }
                value = next->value;
                bst_remove(&parent, value);
                cur->value = value;
            } else if (has_left) {
                if (parent == NULL) {
                    *bst = parent->left;
                } else {
                    if (is_left_child)
                        parent->left = left;
                    else
                        parent->right = left;
                }
                free(cur);
            } else if (has_right) {
                if (parent == NULL) {
                    *bst = parent->right;
                } else {
                    if (is_left_child)
                        parent->left = right;
                    else
                        parent->right = right;
                }
                free(cur);
            } else {
                if (parent == NULL) {
                    *bst = NULL;
                } else {
                    if (is_left_child)
                        parent->left = NULL;
                    else
                        parent->right = NULL;
                }
                free(cur);
            }
            return 1;
        } else if (cur_key < key) {
            parent = cur;
            is_left_child = 1;
            cur = cur->left;
        } else {
            parent = cur;
            is_left_child = 0;
            cur = cur->right;
        }
    }
    return 0;
}

int main(void) {
    Bst *bst = NULL;
    int value, i;

    /* find on empty bst. */
    assert(!bst_find(bst, 0, &value));

    /* Add to empty bst. */
    assert(!bst_add(&bst, 0, 1));

    /* Find on BST that contains a single element. */
    assert(bst_find(bst, 0, &value));
    assert(value == 1);

    /* Update existing value. */
    assert(bst_add(&bst, 0, 2));
    assert(bst_find(bst, 0, &value));
    assert(value == 2);

    /*
    Operations on a more complex tree:

                    0
            -2              2
        -3      -1      1       3
    */
    bst_free(&bst);
    bst = NULL;
    assert(!bst_add(&bst,  0,  1));
    assert(!bst_add(&bst, -2, -1));
    assert(!bst_add(&bst,  2,  3));
    assert(!bst_add(&bst, -3, -2));
    assert(!bst_add(&bst, -1,  0));
    assert(!bst_add(&bst,  1,  2));
    assert(!bst_add(&bst,  3,  4));
    for (i = -3; i < 4; ++i) {
        assert(bst_find(bst, i, &value));
        assert(value == i + 1);
    }
    assert(!bst_find(bst, -4, &value));
    assert(!bst_find(bst,  4, &value));

    /* remove. TODO. This is too hard for interviews. */
    /*bst_remove(&bst, 0);*/
    /*assert(!bst_find(bst, 0, &value));*/
    /*assert(bst_find(bst, -1, &value));*/
    /*assert(value == 0);*/
    /*assert(bst_find(bst, 1, &value));*/
    /*assert(value == 2);*/

    return EXIT_SUCCESS;
}
