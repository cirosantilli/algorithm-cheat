This talks about object oriented design patterns.

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

        relations (member that is a list of other objects):

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

