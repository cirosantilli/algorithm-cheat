# motivation

# operational system choice (linux propaganda)

- how to install
- distros

# programming language

- most popular? hard to say
- niches php, javascript == web, fortran == numerical
- all languages the same (theorethical)
- categories:

    - compiled vs interpreted (virtual machine) non compiled languages

        speed vs multiplataform, quick test, prototyping

        there is no hard distiction: any compiled language could also be interpreted and vice versa

        it is mainly a question of design: some langs are designed to be interpreted

        hakell for example can be compiled but also comes with a standard [REPL] interface

    - objects oriented vs non object oriented

    - statically vs dinamically typed: <http://pythonconquerstheuniverse.wordpress.com/2009/10/03/static-vs-dynamic-typing-of-programming-languages/>

    - weakly vs strongly typed: <http://pythonconquerstheuniverse.wordpress.com/2009/10/03/static-vs-dynamic-typing-of-programming-languages/>

- lang easy, lib hard

    - learn *several* important libraries of a language

my choices:

- c
- c++
- python
- java

## data languages

- json
- xml

## web development

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

# what makes a good programmer

- know the best way to do tasks in language
- algorithms
- computer inner workings: (how language becomes assembler, how drives are accessed, etc.)
- design patterns

    <https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns>
    <http://calumgrant.net/patterns/index.html>
    <http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms>
        huge list, c++
    <http://sourcemaking.com/:
        site on both uml and design patterns

    - creation

        - abstract factory : select from an entire family of abstract classes (one per OS for example)

        - factory

            <http://sourcemaking.com/design_patterns/factory_method/cpp/1>

            make specific derived classes based on runtime information

            ``static Base make_object(enum type)`` method that returns an instance of a given type

            application : factor out the selection from enum into lib

        - prototype

            abstract ``virtual Class* clone(){ return new Class(*this); }`` method

            TODO why use this?

        - singleton : self evident. Application: hold configuration.

        - object pool

            <http://sourcemaking.com/design_patterns/object_pool>

            insted of dynamically destroying/creating objects, ``acquire`` and ``release`` them for later use

            performance only

    - structural

        - adapter

            <http://sourcemaking.com/design_patterns/adapter>

            convert one class interface into another.

            new class contains old.

        - bridge TODO ?

        - composite

            <http://en.wikipedia.org/wiki/Composite_pattern>

            treat leaves and inner nodes uniformly

            call on inner node propagates call down to all leaves

        - decorator

            lots of classes have a given ``do_it`` method

            pattern makes a linked list of those classes, calling do it on all of them
            when the first is called

            the linked list can receive any combination of nodes, and a call to
            the first calls all the elements

        - facade

            <http://sourcemaking.com/design_patterns/facade>

            simple single interface for lots of classes

        - flyweight

            <http://sourcemaking.com/design_patterns/flyweight/cpp/1>

            separated shared state from individual state

            memory performance only

        - private class data

            <http://sourcemaking.com/design_patterns/private_class_data>

            prevent attribute modification from ``class Main``
            by putting them into ``class Data`` with getters

        - proxy

            <http://sourcemaking.com/design_patterns/proxy/cpp/1>

            a proxy interface is used instead of the real interface

            the proxy interface bahaves differently from the real interface
            by doing additional actions

    - behaviour

        - strategy : abstract method to vary algorithm
        - template : same as strategy, but change only part of an algorithm

- uml

    - class diagram

        - name
        - members
            - relations (member that is a list of other objects)
                - bi
                - uni
                - association class
                - basic aggregation (car wheel)
                - compositio (company department)
                - reflexive
        - methods
        - inheritance
        - interfaces
        - visibility
        - packages

    - object diagram

        - same as class, but with instances instead

    http://www.ibm.com/developerworks/rational/library/content/RationalEdge/sep04/bell/
        uml intro

# stragegy

artistic level

- coworkers
- clients
- market

- <http://www.joelonsoftware.com/>

    quite a few strategy articles

    ex microsoft employee, lots of exp

# filesystem

- home dir
- case
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

# important programs for life

- vim

    best editor ever

- markup

    you need to communicate with:

    - others
    - yourself

    learn:

    - latex
    - html
    - markdown
    - reStructuredText

- krusader

    you need to manage your files

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

## terminal

- language:
    - linux: bash
    - windows: cmd

- terminal:
    - pro: reproduce commands easily
    - con: cannot do graphs

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

# machine/low-level
{

    <http://www.bottomupcs.com/>

    #assembler
    {
        - what operations a processor can do, isa
    }

    #representing letters
    {
        #ascii
        #unicode
        #utf8
    }

    #representing integers
    {
        #binary, hexa
        #signed
            #one's complement
            #2-complement
    }

    - representing real numbers

    - memory: registers vs caches vs RAM vs ROM (BIOS) vs VRAM vs HD

        <http://arstechnica.com/gadgets/2002/07/caching/2/>

        deep explanaition

    - program memory layout/segments: address, operational system division

        - <www.dirac.org/linux/gdb/02a-Memory_Layout_And_The_Stack.php>

            tutorial to gdb

    - RAM memory organization

    - HD program organiztion: ELF files, including libraries
        - <http://www.thegeekstuff.com/2011/10/gcc-linking/>

    - driver programming
        <http://www.linuxjournal.com/article/7353>
        #5/5
        #control a lamp. contains c code.
        <http://www.freesoftwaremagazine.com/articles/drivers_linux>

    - multithreading concurrency ipc

        - thread vs process

            a process can contain many threads

            threads share a memory space, process don't

        - ipc

            - pipes : same machine
            - sockets : different machines
                - internet
                - pci
                - usb

    - GPU programming

    - busses
        <http://computer.howstuffworks.com/pci1.htm>

    # general sources

    - <http://stackoverflow.com/questions/836946/basic-yet-thorough-assembly-tutorial-linux>

    - <en.wikibooks.org/wiki/X86_Assembly>

    - <http://www.serverwatch.com/hreviews/article.php/3581551/Hardware-Today-x86-Alternatives-Few-but-Strong.htm>
    alternatives to x86

    - carter <http://www.drpaulcarter.com/pcasm/>
        - no os specific interrupts system calls, elf files, linking

    - <http://docs.cs.up.ac.za/programming/asm/derick_tut/>
        - 5/5
        - linux system calls
        - short and to the point
}

# computer science

- algorithmic complexity

    http://en.wikipedia.org/wiki/Analysis_of_algorithms

    you need to decide what algorithm is better than what

    topics:

    - time and space

        - assymptotic vs non assymptotic

            often one algo is assymptotically better,
            but for small numbers it is worse

            in this case, before applying one must decide which algorithm
            to use

    - recursive vs non-recursive

    - turing machine

    - p vs. np

- data structures
    - list
        - sorting
    - hashmap

- languages

    - backus naur form: http://en.wikipedia.org/wiki/Backus%E2%80%93Naur_Form

# optimizing code

more important than those are to first:

- use best algorithm

- compile instead of interpret

a few important ones are:

- cache: http://en.wikipedia.org/wiki/CPU_cache

- speculative execution http://en.wikipedia.org/wiki/Speculative_execution

- loop unwinding: http://en.wikipedia.org/wiki/Loop_unwinding

- out of order execution: http://en.wikipedia.org/wiki/Out-of-order_execution

-register renaming: http://en.wikipedia.org/wiki/Register_renaming

# applications

## about

come from

- maths

    - calculus
    - linear algebra
    - probability
    - discrete

- physics

    - mechanics
    - thermo
    - eletromag
    - quantum

and the rest:

- based on maths and physics

    - chemistry
    - biology

- not based maths and physics

    - economy

then:

- implement their applications yourself
- find an existing implementation and learn to use it

## multiplication

- unknown sup of lower bounds

- naive $n^2$

- karatsuba

    <http://en.wikipedia.org/wiki/Karatsuba_algorithm>

    multiplication in $O(n^{\log_{2}3})$

- tom-cook

    generalization of karatsuba

    <http://en.wikipedia.org/wiki/Toom%E2%80%93Cook_multiplication>

    algorithm family, hard to analyse, Toom-3 does $O(n^{\log_{3}5})$, about
    $O(n^{1.465})$

- schonhage–strassen

    $O(log n log log n)$

    FFT based!

## matrix multiplication

- unknown sup of lower bounds

- naive $n^3$

- strassen $n^{\log_2{7}}$

    <http://en.wikipedia.org/wiki/Strassen_algorithm>

- and going down...

    <http://en.wikipedia.org/wiki/Matrix_multiplication#Algorithms_for_efficient_matrix_multiplication>

## unranged

- exponential
- factorial

- fibonacci
- min/max
- mcd, mcm
- prime sieve
- sorting
- f(x) = 0
    - divide by two
    - newtons method
- split, newton
- eq difs: ordinary/partial
- integration
- taylor series
- matrices
- foundations, incompleteness, forcing
- FFT

## control theory

## finite elements

- fluids
- solids

## integer programming

# misc

- make cheatsheets!!!!

- how to type: resource arm
    - user four fingers
    - closest one first
    - look at the screen

- use keyboard shortcuts

## funny

"Do you pine for the nice days of Minix-1.1, when men were men and wrote their own device drivers?" Linus Torvalds

[spaguetti code](http://en.wikipedia.org/wiki/Spaghetti_code)

[esoteric language]()

[REPL]: http://en.wikipedia.org/wiki/Read%E2%80%93eval%E2%80%93print_loop
