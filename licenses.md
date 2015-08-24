# Licenses

Comparison of popular software licenses.

For all licenses, you cannot go back: once a given software version is published with a license, that license is valid for good.

You can however allow multiple licences so that users may chose which one they will use.

## Dual

Some licenses are called dual X/Y (e.g.: dual BSD/GPL), meaning that users can chose between them.

## MIT

- you can use, study, share (copy), and modify the software

- you are not obliged to open source your modifications

- every substantial reproduction of the software must maintain the copyright note

Basically like GPL except you *can* use in commercial projects, so you can basically do anything you want, except remove the license from sub products

## GPL

If someone else modifies your code and distributes it, he must make the source open.

The holder of the copyright is not force to do so. For example, before being bought by Oracle, MySQL makers got some money from selling licences that allows companies to distribute closed source forks of MySQL.

If you don't distribute the code, you can fork it without opening the source: <http://stackoverflow.com/questions/1492687/using-gpl-3rd-party-code-for-internal-closed-source-project> Of course, what "distributing" mans may be blurry: <http://programmers.stackexchange.com/questions/162870/gpl-what-is-distribution>

You are not forced to merge back:only open source the contributions. But in the end it is much more profitable to try to merge back, as the community will then maintain the code for you.

The following website is of a leading group of lawyers that enforces GPL: <http://gpl-violations.org/about.html> It is in general up to the copyright owner to enforce GPL.

Everyone owns whichever modifications they make. So if someone makes something and then merges back, you cannot not give out that part of the source when you distribute the source.

Notable cases include:

-   Iliad: major Telecom player in France, sued in 2008, released it's source code modification in 2011 at <http://floss.freebox.fr> to avoid further pursuits.

It is also helpful to see what they have to say about other projects: <http://www.gnu.org/licenses/license-list.en.html>

### Linking and the GPL

It is not very clear in the GPL text is dynamic and static linking are allowed or not from proprietary libraries.

It is therefore better to play it safe and assume that it is not possible.

[libgit2](https://github.com/libgit2/libgit2) is a notable example of GPLv2 with a linking exception, explicitly allowing linking, since GitHub is behind the library.

### LGPL

<http://en.wikipedia.org/wiki/GNU_Lesser_General_Public_License>

Lesser GPL: closed source projects can use it without opening their source, but they must allow end users to modify the LGPL component.

For this reason, this license is used in practice mostly for linked libraries where the separation between library and proprietary code is clear.

TODO: vs GPL linking exception?

### GNU Free Documentation License

### GFDL

<http://www.gnu.org/licenses/fdl-1.3.en.html>

<https://en.wikipedia.org/wiki/GNU_Free_Documentation_License>

See also: Creative Commons.

### Affero GPL

GPL allows you to modify software used Server Side without distributing the source code.

Affero GPL blocks it:

- <http://programmers.stackexchange.com/questions/131264/what-constitutes-distributing-for-lgpl-v3>
- <http://www.gnu.org/licenses/why-affero-gpl.en.html>

## CC

## Creative commons

Family of licenses.

<https://creativecommons.org/licenses/>

<https://wiki.creativecommons.org/Frequently_Asked_Questions>

Not specialized for software, and more used for human readable text, music, etc. Used by Stack Overflow and Wikipedia content.

The main difference between software and text is that for text the source is easily derived from the human readable output. Software however can be useful in a form that is not human understandable through compiled code.

For media like music, there may not even be a source format.

You can combine the following options as you wish:

-   `BY`: attribution to creator. All combinations have this, otherwise you cannot know who holds the rights.

-   `SA`: shared material and adaptations must have the same license.

-   `ND`: no derive: can't modify and share, but can modify and use internally.

    This is even more restrictive than GPL, which allows sharing as long as the source is distributed.

-   `NC`: cannot use in commercial products.

    This has many gray zones.

    In particular, I cannot find if you can make internal usage in a enterprise.

    <https://creativecommons.org/weblog/entry/17127>

and many fixed combinations are possible.

This is indicated in their logo.

### CC0

Creative commons public domain version. GPL compatible.

## Public domain

You relinquish your copyright. You are not the copyright owner anymore.

Once released on the public domain, you relinquish any rights you have over the work: in particular you cannot change it to another license later on.

Anyone can do anything with the work without even mentioning you, except copyright it.

There have been cases of removal from the public domain because of earlier international blunders: <http://www.themarysue.com/take-works-out-of-public-domain/>
