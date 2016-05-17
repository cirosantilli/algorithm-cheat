# B-tree TODO

*Not* binary tree: <http://en.wikipedia.org/wiki/B-tree>.

Like a binary tree with many values per node:

![btree](bree.png)

Notable sub-cases:

- 2-3 <https://en.wikipedia.org/wiki/2%E2%80%933_tree>. Equivalent to AA-trees, which are somewhat like RB-trees (TODO understand exactly how)
- 2-3-4 <https://en.wikipedia.org/wiki/2%E2%80%933%E2%80%934_tree>. Equivalent to RB-trees! TODO how.

Same complexity as RB-tree, but with slower in theory by a constant factor.

Default data structure for MySQL InnoDB `INDEX`.

In practice: way faster for accessing trees saved in slow storage like hard disks.

- to go down each level, you must traverse all values of a node
- less memory efficient

Advantage:

- less nodes need to be retrieved. Huge practical gains here to read data from slow media.
