# Licenses

Comparison of popular software licenses.

## MIT

- you can use, study, share (copy), and modify the software

- you are not obliged to open source your modifications

- every substantial reproduction of the software must maintain the copyright note

Basically like GPL except you *can* use in commercial projects,
so you can basically do anything you want, except remove the license from sub products

## GPL

Like MIT, but you *cannot* use it in non GPL PROJECTS (copyleft),
meaning that you cannot make a closed source project that uses it.

This makes the project useless for closed source projects to build upon,
and forces users to merge back improvements.

While a beautiful concept, which has arguably worked for the Linux kernel,
it is a similar principle to communism, and we all know how that went.

The following website is of a leading group of lawyers that enforce GPL:
<http://gpl-violations.org/about.html>

Notable cases include:

-   Iliad: major Telecom player in France, sued in 2008,
    released it's source code modification in 2011 at
    <http://floss.freebox.fr> to avoid further pursuits.

### Linking and the GPL

It is not very clear in the GPL text is dynamic and static linking are allowed or not
from proprietary libraries.

It is therefore better to play it safe and assume that it is not possible.

[libgit2](https://github.com/libgit2/libgit2) is a notable example of GPLv2 with a linking exception,
explicitly allowing linking, since GitHub is behind the library.

## LGPL

Lesser GPL: like MIT, but you must also distribute modifications you make to the source.

## Dual

Some licenses are called dual X/Y (ex: dual BSD/GPL), meaning that you can
take either one of them.

## CC

Family of licenses.

<https://creativecommons.org/licenses/>

Symbols:

- `BY`: attribution to creator
- `SA`: copyleft
- `ND`: no derive: can't modify
- `NC`: cannot use in commercial products

Many combinations are possible.

This is indicated in their logo.

There is also a `CC0` license which puts things in the public domain.

## Public domain

You have no rights over the work.

Once released on the public domain, you relinquish any rights you have over the work:
in particular you cannot change it to another license later on.

Anyone can do anything with the work without even mentioning you, except copyright it.
