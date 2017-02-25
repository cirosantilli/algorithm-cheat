# Licenses

Comparison of popular software licenses.

For all licenses, you cannot go back: once a given software version is published with a license, that license is valid for good.

You can however allow multiple licences so that users may chose which one they will use.

## Dual

Some licenses are called dual X/Y (e.g.: dual BSD/GPL), meaning that users can chose between them.

## Permissive

### MIT

- you can use, study, share (copy), and modify the software

- you are not obliged to open source your modifications

- every substantial reproduction of the software must maintain the copyright note

Basically like GPL except you *can* use in commercial projects, so you can basically do anything you want, except remove the license from sub products

### BSD

TODO vs MIT

### ISC

<https://en.wikipedia.org/wiki/ISC_license>

## GPL

If someone else makes a derivative work of your code and distributes it, he must make the source open.

What counts as a "derivative" is gray. Some well known cases that count as derivative:

- modify the source
- use the source in your project, even if you don't modify it
- use compiled output like `.so` in your project. The LGPL exists to allow that.

Things which do not count as derivatives:

-   Linux kernel specifics, Kernels are atypical softwares, and the following rules apply to Linux:

    - systems calls do not count as derivatives: <https://github.com/torvalds/linux/blob/v4.4/COPYING#L2>
    - loadable modules do not count as derivatives: <http://unix.stackexchange.com/questions/13284/proprietary-or-closed-parts-of-the-kernel> <http://stackoverflow.com/questions/2721290/propietary-modules-within-gpl-and-bsd-kernels>

Apple Store and GPL:

- <https://www.fsf.org/news/2010-05-app-store-compliance>
- <http://www.fsf.org/blogs/licensing/more-about-the-app-store-gpl-enforcement>

### GPL ownership

The holder of the copyright is not force to do so. For example, before being bought by Oracle, MySQL makers got some money from selling licences that allows companies to distribute closed source forks of MySQL.

By default, everyone owns whichever modifications they make. So if someone makes something and then merges back, you cannot not sell a relicensed version without asking for their permission.

I think it is because of this that you don't write your name on the GPL, e.g. unlike MIT. Otherwise, every derived work would say it is owned by you. TODO but then, how do you get attribution? <http://programmers.stackexchange.com/questions/170188/is-requiring-attribution-gpl-compatible>

---

If you don't distribute the code, you can fork it without opening the source: <http://stackoverflow.com/questions/1492687/using-gpl-3rd-party-code-for-internal-closed-source-project> Of course, what "distributing" mans may be blurry: <http://programmers.stackexchange.com/questions/162870/gpl-what-is-distribution>

You are not forced to merge back: only open source the contributions. But in the end it is much more profitable to try to merge back, as the community will then maintain the code for you.

You are obliged to give away the method used to generate the derivative work, e.g. the `Makefile`. TODO: what if it requires a closed source compiler? This site says no: <https://softwarefreedom.org/resources/2008/compliance-guide.html>, you only need to say what version of it you used, and how.

The following website is of a leading group of lawyers that enforces GPL: <http://gpl-violations.org/about.html> It is in general up to the copyright owner to enforce GPL.

Notable cases include:

-   Iliad: major Telecom player in France, sued in 2008, released it's source code modification in 2011 at <http://floss.freebox.fr> to avoid further pursuits.

It is also helpful to see what they have to say about other projects: <http://www.gnu.org/licenses/license-list.en.html>

### Linking and the GPL

It is not very clear in the GPL text is dynamic and static linking are allowed or not from proprietary libraries.

It is therefore better to play it safe and assume that it is not possible.

[libgit2](https://github.com/libgit2/libgit2) is a notable example of GPLv2 with a linking exception, explicitly allowing linking, since GitHub is behind the library.

### GPL and NDA

A company A cannot modify a GPL source, and license it to another company B, with a license that requires the other company B to not release the source it received.

### LGPL

<http://en.wikipedia.org/wiki/GNU_Lesser_General_Public_License>

Lesser GPL: closed source projects can use it without opening their source, but they must allow end users to modify the LGPL component.

Quintessential example: glibc. Every C program links to it. So if it were GPL, there could be no closed source C programs on Linux, which would be too restrictive.

For this reason, this license is used in practice mostly for linked libraries where the separation between library and proprietary code is clear.

LGPL 2.1 was standalone, with not relation to GPL. LGPL 3 refer to the GPL: <https://en.wikipedia.org/wiki/GPL_linking_exception>

### GNU Free Documentation License

### GFDL

<http://www.gnu.org/licenses/fdl-1.3.en.html>

<https://en.wikipedia.org/wiki/GNU_Free_Documentation_License>

See also: Creative Commons.

Used by Wikipedia, dual with CC BY SA.

### AGPL

### Affero GPL

GPL allows you to modify software used Server Side without distributing the source code.

Affero GPL blocks it:

- <http://programmers.stackexchange.com/questions/131264/what-constitutes-distributing-for-lgpl-v3>
- <http://www.gnu.org/licenses/why-affero-gpl.en.html>

Apparently you can use AGPL as a service in the backend of a closed source site: what you can't do is make source level usage / modifications to it.

MongoDB uses it: <http://programmers.stackexchange.com/questions/226111/can-i-use-mongodb-for-a-commercial-web-based-service> But it explicitly notes that you can use it as a backend for closed source projects.

MySQL Google closed source fork is a notable case where the server-side loophole was used.

Banned by Google: <http://www.theregister.co.uk/2011/03/31/google_on_open_source_licenses/>

## CC

## Creative commons

Family of licenses.

<https://creativecommons.org/licenses/>

<https://wiki.creativecommons.org/Frequently_Asked_Questions>

Not specialized for software, and more used for human readable text, music, etc.

Likely the best choice for non-software. One main reason is that it is very popular, so using it makes it much easier to interface with other projects.

One major downside for text is that it does not require source code to be released: <http://programmers.stackexchange.com/questions/297894/does-the-creative-commons-sharealike-license-require-that-source-code-of-derivat>

Used by: Stack Overflow and Wikipedia (BY_SA) content.

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

What CC can you combine: <https://wiki.creativecommons.org/wiki/Frequently_Asked_Questions#Can_I_combine_material_under_different_Creative_Commons_licenses_in_my_work.3F>

### CC0

Creative commons public domain version. GPL compatible.

## Public domain

Term that can be used to describe several licenses, and I think it has legal meaning in different countries. Those licenses include CC0.

You relinquish your copyright. You are not the copyright owner anymore.

Once released on the public domain, you relinquish any rights you have over the work: in particular you cannot change it to another license later on.

Anyone can do anything with the work without even mentioning you, except copyright it.

There have been cases of removal from the public domain because of earlier international blunders: <http://www.themarysue.com/take-works-out-of-public-domain/>

There are some practical downsides of public domain licences: <http://linuxmafia.com/faq/Licensing_and_Law/public-domain.html>

## WTFPL

<http://programmers.stackexchange.com/questions/182137/whats-the-difference-between-wtfpl-cc0-and-public-domain>

TODO.

## Copyright ownership

## Contributor License Agreement

## CLA

It seems that by default in all licenses, the person who makes a significant change owns it.

So if you want to sell a relicensed version, you'd have to contact everyone.

This is why the FSF requires software assignments for merging back. This is a great idea.

TODO: is there a license that requires assignment automatically on commit? <http://programmers.stackexchange.com/questions/191535/could-submitting-a-pull-request-ever-constitute-accepting-a-contributor-licence>

Examples:

- <http://apache.org/licenses/icla.txt>
- <https://cla.developers.google.com/about/google-individual>
- <http://doc.gitlab.com/ce/legal/individual_contributor_license_agreement.html>

GitHub: <https://github.com/clahub/clahub> But I think I'd just keep it inside the repo in a `CLI.md` file, and make first time committers write a line there saying I agree.

TODO: can you make a CLA that allows you to resell the work under a different license? E.g.: you work is GPL, someone contributes, and then you want to sell a license that allows buyers to modify the source, without asking every single contributor if you can do that with their code. Discourse's makes that very clear with: the terms "relicense". 

### Copyright assignment

Stronger than CLA: gives copyright to someone else.

<http://producingoss.com/en/copyright-assignment.html> vs CLA Contributor License Agreement

Used by the FSF.

## Non-software

### Freedom of panorama

<https://en.wikipedia.org/wiki/Freedom_of_panorama>

<https://commons.wikimedia.org/wiki/Commons:Freedom_of_panorama>

## MPL

Mozilla Public License.

<https://en.wikipedia.org/wiki/Mozilla_Public_License>

Per-file GPL.

Version 2 GPL compatible.

## CDDL

Common Development and Distribution License.

<https://en.wikipedia.org/wiki/Common_Development_and_Distribution_License>

Similar to Mozilla, but not GPL compatible: <http://vschart.com/compare/mozilla-public-license/vs/common-development-and-distribution-license>

## Proprietary

- freeware: currently free to use
- shareware: https://en.wikipedia.org/wiki/Shareware

## Open font license

<https://en.wikipedia.org/wiki/SIL_Open_Font_License>

Most popular license at `fontlibrary.org`: <https://fontlibrary.org/en/search?license=OFL%20%28SIL%20Open%20Font%20License%29>

## Fair usage

This is what as decided on the Oracle v. Google case:

- <http://law.stackexchange.com/questions/10945/would-the-oracle-v-google-lawsuit-imply-that-any-api-can-be-re-implemented-inc/10950#10950>
- <http://law.stackexchange.com/questions/7683/in-the-us-when-is-fair-use-a-defense-to-copyright-infringement/7684#7684>
- <http://law.stackexchange.com/questions/9510/in-oracle-america-v-google-what-was-the-district-court-jurys-rationale-behind>

It basically give very little insight into future similar cases.

## EULA

Can enforce anything that is not illegal. Some cool examples:

-   you cannot disclose benchmarks of this product. So how can you compare between two vendors? You have to buy both!
    - <http://law.stackexchange.com/questions/7272/is-the-benchmarking-clause-in-vmwares-eula-actually-valid>
    - Cadence goes a step further and forbids internal benchmarks as well: <https://web.archive.org/web/20161008212948/https://www.sec.gov/Archives/edgar/data/1160958/000119312511056594/dex1014.htm>
-   You cannot use this as legal evidence against us:
    > Your access to the information in this ARM Architecture Reference Manual is conditional upon your acceptance that you will not use or permit others to use the information for the purposes of determining whether implementations of the ARM architecture infringe any third party patents.
    Very practical. Just put that note on everything you make, and you can never be sued! How can this be enforceable.

Enforceability:

- <http://superuser.com/questions/30940/is-an-eula-enforceable>
- <https://en.wikipedia.org/wiki/End-user_license_agreement#Enforceability_of_EULAs_in_the_United_States>
- <https://www.eff.org/wp/dangerous-terms-users-guide-eulas> Mentions the non-benchmark EULA.

## FAL

## Free Art License

<https://en.wikipedia.org/wiki/Free_Art_License>

A copyleft for art.
