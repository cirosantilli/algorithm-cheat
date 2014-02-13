This contains a list of things you should know to be a good programmer.

#tips

- operating system choice

    Use linux becaues it is free and open source.

- make cheatsheets! Everything you learn, write it down!

    If there is a good link or book, save the link or the book page!

    If possible make assertions like C, Java or python `assert` statements,
    so you can be sure that what you think is right is right.

    Publish your cheats so that others can use them too.

- how to type:

    - user four fingers
    - use closes finger
    - look at the screen
    - use keyboard shortcuts and good programs that have them (ex: vim)

    Saves time and preserves your arm.

- download and read the docs as soon as you can.

    First start with tutorials which are easier
    to understand and find the most interesting things in.

    As soon as you can handle the docs, download and read the official docs,
    since those are more precise and up to date than tutorials.

#language

##programming

- most popular? hard to say

- niches PHP, Javascript == web, Fortran == numerical

- all programming languages the same (theorethical)

- categories:

    - compiled vs interpreted (virtual machine) non compiled languages

        speed vs multiplataform, quick test, prototyping

        there is no hard distiction: any compiled language could also be interpreted and vice versa

        it is mainly a question of design: some langs are designed to be interpreted

        hakell for example can be compiled but also comes with a standard [REPL] interface

    - objects oriented vs non object oriented

    - type systems

        - statically vs dynamically typed
        - weakly vs strongly typed

- lang easy, lib hard

    - learn *several* important libraries of a language

my choices:

- c
- c++
- python
- java

##data languages

- xml
- json

##markup languages

- html
- latex
- markdown

##web development

- html
- http
- cgi
- apache configuration
- css
- js
- mysql
- framework
    - all the best addons of a framework
- source control

    even more fundamental for web apps

- php
- the other interpreted cgi languages:
    - python
    - ruby
    - perl

- real deployment

    - ftp
    - deal with permissions you lack on server
    - ssh

#filesystem

One of the first things you should understand better as a programmer is your filesystem.

- home dir

- upper vs lower case

- naming conventions

    - bin

    - ~ and .bak

    - doc

    - dot hidden

    - lib

    - src

    - include

    - share

    - local

    - and the rest of the Linux Filesystem Hierarchy Standard
        <http://www.tuxfiles.org/linuxhelp/linuxdir.html>

- do not start with hyphen

- symlinks/hardlinks

- magic folders ala Windows library/documents

- inner workings: how is data actually stored/retreived on disk?

#database

- MySQL
- SQLite

#important programs for life

- vim

    text editor

- krusader

    file manager

- source version control (svc)

    you need to contribute with others

    my picks:

    - git
        - <http://try.github.com/>
        - [git-motivation.html]()

    - svn

    related:

    - use a bugracker

- ack (find/grep replacement)

    find in files

- make (makefile)

    automate compilations

    <http://www.jfranken.de/homepages/johannes/vortraege/make_inhalt.en.html>

##shell

- language:

    - linux: bash
    - windows: cmd

- terminal:

    - pro: reproduce commands easily
    - con: cannot do graphs

    The terminal allows you to interact with the shell interpreter.

- bash:

    - pro: super easy file/pipe/process handling
    - con: INSANE, INNEFICIENT

    use for one liners only. replacements:

    - perl is dead
    - python! yes, also useful for other things, so worth learning

- --help (how to read, [], ..., ), man, version

- directory structure, homedir, fake vs real dirs

- options, ls, cd, mkdir, cp, rm, rmdir, control z, bg, find, grep

- stdin/stderr/stdout

    - three holes
    - pipes > to file, | grep, 1>&2

- exit status

- pipe (help grep example)

- interactive vs. non-interactive

#algorithm

See [this](algorithm.md).

#assembler

Understanc exactly what operations a processor can do.

<http://www.bottomupcs.com/>

#data representation

##character representation

- ascii
- unicode
- utf8

##integer representation

- binary, hexa
- signed

    - one's complement
    - 2-complement

##float representation

TODO

#operating systems

You must learn how your operating system works.

The only operating system you can really understand is Linux since it is open source,
so understand Linux.

Topics which you should look into:

##program memory space

address, operational system division

- <www.dirac.org/linux/gdb/02a-Memory_Layout_And_The_Stack.php>

    tutorial to gdb

##driver programming

- <http://www.linuxjournal.com/article/7353>
    #5/5
    #control a lamp. contains c code.

- <http://www.freesoftwaremagazine.com/articles/drivers_linux>

##executable files

ELF files, including libraries

#hardware

- memory: registers vs caches vs RAM vs ROM (BIOS) vs VRAM vs HD

    <http://arstechnica.com/gadgets/2002/07/caching/2/>

    deep explanaition

- busses
    <http://computer.howstuffworks.com/pci1.htm>

#multithreading concurrency ipc

    - thread vs process

        a process can contain many threads

        threads share a memory space, process don't

    - ipc

        - pipes : same machine
        - sockets : different machines
            - internet
            - pci
            - usb

#formal languages

Important if you ever want to create a computer language.

- backus naur form: http://en.wikipedia.org/wiki/Backus%E2%80%93Naur_Form

#optimizing code

more important than those are to first:

- use best algorithm

- compile instead of interpret

a few important ones are:

- cache: http://en.wikipedia.org/wiki/CPU_cache

- speculative execution http://en.wikipedia.org/wiki/Speculative_execution

- loop unwinding: http://en.wikipedia.org/wiki/Loop_unwinding

- out of order execution: http://en.wikipedia.org/wiki/Out-of-order_execution

-register renaming: http://en.wikipedia.org/wiki/Register_renaming

#automatic optimization

- branch prediction

    <http://en.wikipedia.org/wiki/Branch_predictor>

    An example of perceptible branch prediction:

    <http://stackoverflow.com/questions/11227809/why-is-processing-a-sorted-array-faster-than-an-unsorted-array>

#design patterns

See [this](design-patterns).

#GPU programming

TODO

#stragegy

artistic level

- coworkers
- clients
- market

- <http://www.joelonsoftware.com/>

    quite a few strategy articles

    ex microsoft employee, lots of exp

#phylosophy

##what computers do

Manipulate information:

- copy and move information around
- reaching new information from old

In a way that is *very*:

- fast
- cheap
- without errors

##programming and ideas

    ideas (that can be programmed)
    +
    programming
    ------------------------------
    *power*

- without ideas, programming is useless!
- without programming, some ideas are useless!

#sources

##free

- [stack overflow](http://stackoverflow.com/)

    Great QA site with gamification. Huge programming community.

    Also check related sites maintained by the same enterprise: [stack exchange](http://stackexchange.com/).

    Reasonable way to show your knowledge to enterpreises.

- [top coder algorithm contests](http://community.topcoder.com/tc?module=ProblemArchive&sr=1&er=50&sc=&sd=&class=&cat=&div1l=&div2l=&mind1s=&mind2s=&maxd1s=&maxd2s=&wr=)

    Hosts timed programming contests online.

    Lost of programming problems available with solutions proposed by contestants.

    Good way to show your knowledge to enterpreises.
    Very popular as of 2013, lots of employers looking there.

    Also worth checking their tutorials: <http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=alg_index>

    Must use a annoying Java program to run in the contests, and hard to find the problems in the site in the first place.

- [spoj contests](http://www.spoj.com/problems/classical/)

    Much like top coder.

    Problems can be solved any time.

    Solutions can be submitted any time for online tests.

    Does time and memory tests, and ranks algorithms accordingly.

    It is not possible to view submitted solutions.
