this workflow is valid for any [vcm](http://en.wikipedia.org/wiki/Revision_control)
with a web interface

here i'm showing [git](http://git-scm.com/) + [github](https://github.com/)

# version control

    git commit -am 'all working'

make more changes. type:

    git commit -am 'an error'

to create another version

    git log

to see existing versions. sample output:

    commit eebb226391c75c9caf661e4ea1a7199ea55a1a63
    Author: Ciro Duran Santillli <ciro.santilli@gmail.com>
    Date:   Wed Nov 28 19:31:46 2012 -0200

        an error

    commit 06637b73e9fe4ed27f65c11f8d33552b253ff50c
    Author: Ciro Duran Santillli <ciro.santilli@gmail.com>
    Date:   Fri Nov 16 12:07:29 2012 -0200

        all working

explanation: Ciro Duran Santilli made two versions:

- one named 06637b73e9fe4ed27f65c11f8d33552b253ff50c 
- other named eebb226391c75c9caf661e4ea1a7199ea55a1a63

at the given dates.

enter:

    git checkout 06637b

to go back before the error (start of the name only is enough)

and you local files will become exactly equal
to those in the version that starts with eebb22

enter:

    git checkout eebb22

and your local files are back to the version with the error

## why this is useful

1) you *will* make mistakes, and you can come back to 
before you made them

2) if you write a text, and someone links to a section id
in the most recent version always, the section may be moved
to a new file, and the link is broken!

solution: always link to a specific version
        
# upload to a external server easily

write

    git push origin master

and you work is uploaded to the server.

## why this is useful

1) backup you work

    your disk may burn someday

2) publish your work

    other can see the latest version immediatelly

# view differences between versions

    git diff eebb22 06637b

to see differences between current version and last one

sample output:

    @@ 3,2 3,3 @@
        before
    +error
        after

meaning:

    - before, line 3 was "before", line for "after".

        there were 2 lines total in what we see

    - after, "error" was added after "before", becoming line 4

        there will be 3 lines total in what we see

# why this is useful

1) if someone wants to improve your work

    - he makes the modifications
    - tells you
    - you see exactly what he changed
    - you accept/reject his changes

    if he makes good modificaitons, your work improves while you do nothing

    people *will* make mofications to:

    - help others
    - become more famous

2) if you make mistakes on a new version
    you can compare it to older working version to see where things went wrong
