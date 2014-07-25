# Computer Science

Practical and theoretical topics.

## Tips

### Operating system choice

Use Linux because it is free and open source and better than windows for programming.

### Make cheatsheets

Everything you learn, write it down! You will forget it later.

If there is a good link or book, save the link or the book page.

If possible make assertions like C, Java or Python `assert` statements,
so you can be sure that what you think is right is right.

Publish your cheats so that others can use them too.

Always use correct grammar, and make things as understandable as possible.

### Build your CV

Keep a list of:

- open source contributions with importance of each contribution. Example: <http://www.cirosantilli.com/contrib>
- a self evaluation of what you know about programming. Example: <http://www.cirosantilli.com/self-evaluation>

### How to type

- user four fingers
- use closes finger
- look at the screen
- use keyboard shortcuts and good programs that have them (ex: vim)

Saves time and preserves your arm.

### Standards matter

The first thing you should ask yourself when learning a new language
or other interfaces is: what are the standards?

Is there a dominating standard?

What is the state of implementations? Are they consistent with one another?
Are they updated. Example:

- standard: W3C HTML or CSS
- semi compatible implementations: browsers: Firefox, Chrome, IE

What are the most important extensions to the standard? How portable are they? Example:

- standard: ANSI C vs POSIX vs GNU Extensions

### Download and read the docs

First start with tutorials which are easier to understand
and find the most interesting things in.

As soon as you can handle the docs, download and read the official docs,
since those are more precise and up to date than tutorials.

## Language

### Programming

-   Most popular? Hard to say

-   Niches matter. Some languages dominate certain application spaces.

    - PHP, Ruby, Javascript == web
    - Fortran == numerical

-   All programming languages the same (theoretical)

-   Categories:

    -   Compiled vs interpreted (virtual machine) non compiled languages.

        Speed vs multiplataform, quick test, prototyping.

        There is no hard distiction: any compiled language could also be interpreted and vice versa.

        It is mainly a question of design: some langs are designed to be interpreted.

        Haskell for example can be compiled but also comes with a standard [REPL] interface.

    -   Objects oriented vs non object oriented.

    -   Type systems:

        - statically vs dynamically typed
        - weakly vs strongly typed

-   Languages are easy, libraries are hard.

    Languages are easy to learn because they are all very similar.

    Library interfaces however are not, because they involve completely different concepts between one another.

    Therefore: if a project does what you want in a language you don't know

    - learn that language!
    - **don't** recode the project!

My languages of choice:

- C
- C++
- Java
- Python

### Data languages

- XML
- JSON

### Markup languages

- HTML
- LaTeX
- Markdown

### Web development

-   HTML

-   HTTP

-   CGI

-   Apache configuration

-   CSS

-   JS

-   MySQL

-   PHP

-   the other interpreted CGI languages:

    - Python
    - Ruby
    - Perl

- real deployment

    - ftp
    - deal with permissions you lack on server
    - ssh

### Multiple browsers

Have at least two browsers, one main where you are logged in all your websites,
and one secondary, which you will use to see how other users see your profiles.

Same goes for web development: have multiple browsers to quickly switch users.
Also good practice as it lets you see often how the website renders under different browsers.

For websites that allow you limited unsigned entry, have a third browser to test as unsigned.

E.g. on Ubuntu 12.04 I run Firefox (primary), Chromium (secondary) and Chrome (unsigned).

## Filesystem

One of the first things you should understand better as a programmer is your filesystem.

-   home dir

-   upper vs lower case

-   naming conventions

    - bin

    - `~` and `.bak`

    - doc

    - dot hidden

    - lib

    - src

    - include

    - share

    - local

    - and the rest of the Linux Filesystem Hierarchy Standard
        <http://www.tuxfiles.org/linuxhelp/linuxdir.html>

-   do not start with hyphen

-   symlinks/hardlinks

-   magic folders ala Windows library/documents

-   inner workings: how is data actually stored/retreived on disk?

## Database

- MySQL
- SQLite

## Important programs for life

-   dropdown terminal emulator: Guake.

-   Vim

    Text editor.

-   Krusader

    File manager.

-   Source version control.

    You need to contribute with others.

    Most commonly used:

    - Git. Entirely dominates web development.
    - SVN

-   make (Makefile)

    Automate compilations.

    <http://www.jfranken.de/homepages/johannes/vortraege/make_inhalt.en.html>

-   Bug trackers, like GitHub built-in one. **Always** use one for your project!

-   Virtual machines. VirtualBox + Vagrant are game changing.

-   Ack (find/grep replacement)

    Find in files.

### shell

-   Language:

    - Linux: bash
    - windows: cmd

-   Terminal:

    - pro: reproduce commands easily
    - con: cannot do graphs

    The terminal allows you to interact with the shell interpreter.

-   Bash:

    - pro: super easy file/pipe/process handling
    - con: insane, slow

    Use for one liners only. replacements:

    - Perl is dead, but golfs really well.
    - Python! Also useful for other things, so worth learning

-   --help (how to read, [], ..., ), man, version

-   directory structure, homedir, fake vs real dirs

-   options, ls, cd, mkdir, cp, rm, rmdir, control z, bg, find, grep

-   stdin/stderr/stdout

    - three holes
    - pipes > to file, | grep, 1>&2

-   exit status

-   pipe (help grep example)

-   interactive vs. non-interactive

## algorithm

See [this](algorithm.md).

## assembler

Understand exactly what operations a processor can do.

<http://www.bottomupcs.com/>

## data representation

### character representation

- ascii
- unicode
- utf8

### integer representation

- binary, hexa
- signed

    - one's complement
    - 2-complement

### float representation

TODO

## operating systems

You must learn how your operating system works.

The only operating system you can really understand is Linux since it is open source,
so understand Linux.

Topics which you should look into:

### program memory space

address, operational system division

-   <www.dirac.org/linux/gdb/02a-Memory_Layout_And_The_Stack.php>

    Tutorial to gdb

### driver programming

- <http://www.linuxjournal.com/article/7353> Control a lamp. Contains C code.

- <http://www.freesoftwaremagazine.com/articles/drivers_linux>

### executable files

ELF files, including libraries

## hardware

-   Memory: registers vs caches vs RAM vs ROM (BIOS) vs VRAM vs HD.

    <http://arstechnica.com/gadgets/2002/07/caching/2/>

    Deep explanation.

-   Busses: <http://computer.howstuffworks.com/pci1.htm>

## Multithreading concurrency IPC

    - thread vs process

        a process can contain many threads

        threads share a memory space, process don't

    - ipc

        - pipes : same machine
        - sockets : different machines
            - internet
            - pci
            - usb

## Formal languages

Important if you ever want to create a computer language.

- Backus-Naur form: <http://en.wikipedia.org/wiki/Backus%E2%80%93Naur_Form>

## Optimizing code

More important than those are to first:

- use best algorithm

- compile instead of interpret

A few important ones are:

- cache: <http://en.wikipedia.org/wiki/CPU_cache>

- speculative execution <http://en.wikipedia.org/wiki/Speculative_execution>

- loop unwinding: <http://en.wikipedia.org/wiki/Loop_unwinding>

- out of order execution: <http://en.wikipedia.org/wiki/Out-of-order_execution>

- register renaming: <http://en.wikipedia.org/wiki/Register_renaming>

## Automatic optimization

-   branch prediction

    <http://en.wikipedia.org/wiki/Branch_predictor>

    An example of perceptible branch prediction:

    <http://stackoverflow.com/questions/11227809/why-is-processing-a-sorted-array-faster-than-an-unsorted-array>

## Design patterns

See [this](design-patterns).

## GPU programming

TODO

## Strategy

Artistic level:

-   coworkers

-   clients

-   market

-   <http://www.joelonsoftware.com/>

    Quite a few strategy articles.

    E.g.: Microsoft employee, lots of exp.

## Philosophy

### What computers do

Manipulate information:

- copy and move information around
- reaching new information from old

In a way that is *very*:

- fast
- cheap
- without errors

### Programming and ideas

    ideas (that can be programmed)
    +
    programming
    ------------------------------
    *power*

- without ideas, programming is useless!
- without programming, some ideas are useless!

### Imperfection

It is the work of a programmer to search perfection,
while accepting that imperfection is inevitable.

When in doubt, look, decide, and follow your decision all the time,
knowing that all other choices are also imperfect.

## SemVer

## Semantic versioning

Popular standard for program versioning <http://semver.org/> by Tom Preston-Werner.

## Sources

### Free

-   [Stack Overflow](http://stackoverflow.com/)

    Great QA site with gamification. Huge programming community.

    Also check related sites maintained by the same enterprise: [stack exchange](http://stackexchange.com/).

    Reasonable way to show your knowledge to enterprises.

-   [TopCoder algorithm contests](http://community.topcoder.com/tc?module=ProblemArchive&sr=1&er=50&sc=&sd=&class=&cat=&div1l=&div2l=&mind1s=&mind2s=&maxd1s=&maxd2s=&wr=)

    Hosts timed programming contests online.

    Lost of programming problems available with solutions proposed by contestants.

    Good way to show your knowledge to enterprises.
    Very popular as of 2013, lots of employers looking there.

    Also worth checking their tutorials: <http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=alg_index>

    Must use a annoying Java program to run in the contests,
    and hard to find the problems in the site in the first place.

-   [SPOJ contests](http://www.spoj.com/problems/classical/)

    Much like top coder.

    Problems can be solved any time.

    Solutions can be submitted any time for online tests.

    Does time and memory tests, and ranks algorithms accordingly.

    It is not possible to view submitted solutions.
