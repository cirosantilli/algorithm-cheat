#about

this workflow is basically valid for any [vcm]
with a web interface

#motivation

in short, git allows you to do the following *easily*:

- [make *versions* of your work](#versions)
    - others can refer to a specific version: in a new version, what they refer to may be gone
    - backup: if you make a serious mistake you can come back to an old correct version
- [*upload* your work to a server](#upload)
    - backup your work
    - publish it
- [view *differences* between versions](#differences)
    - to find out where things went wrong if they were correct before
    - view what modifications have been made by others to your work
- work with *real* software projects
    - learn by doing a real project
    - make a difference to the world

in what follows, I will try to convince you that this is all easy and useful
by showing you how to do it.

#setup

here i'm showing linux (ubuntu) + [git](http://git-scm.com/) + [github]

install and configure git on ubuntu:

    sudo aptitude insatll git
    git config --global user.name "Ciro Duran Santilli"
    git config --global user.email "ciro.santilli@gmail.com"

create a test folder and file:

    mkdir test
    cd test
    echo -n "before\nafter" > test.md

create a new repository with:

    git init

this creates a ``.git`` dir to contain all git information.

# versions

before making a new version, you must tell git which files it will consider

see which files git considers currently with:

    git status

``test.md`` should be under the ``Untracked files:`` section

``untracked`` means git is not seeing ``file.md``

this means git won't do anything with it at all.

track ``test.md`` with git with:

    git add test.md

now git will take it into consideration

check this out with:

    git status

now ``added: test.md`` should be under the ``Changes to be committed:`` section

``Changes to be committed:`` tells you what will happen next time you try to create a version

create a version with:

    git commit -m 'all working'

make more changes

    echo -n "before\nerror\nafter" > test.md

see what will happen on next commit:

    git status

now ``modified: files.md`` should be under the ``Changes not staged for commit:`` section

this means that git already considers ``files.md`` since we already added it before,
but that next time we try to make a new version this file won't be considered.

if you want the new version to consider this, you have two choices:

1) add it again with ``git add`` and then commit
2) commit with the ``-a`` option:

        git commit -am 'an error'

    this will consider changes for all files that have already been added before

    this is often what we want

see existing versions with:

    git log

samle output:

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

at the given dates

back before the error with:

    git checkout 06637b

start of the version name only is enough

now your local files will become exactly equal
to those in the version that starts with eebb22

    cat test.md

output:

    before
    after

go back to latest version:

    git checkout eebb22

your file is back to latest version:

    cat test.md

output:

    before
    error
    after

## motivation

1) you *will* make mistakes, and you can come back to 
before you made them

2) if you write a text, and someone links to a section id
in the most recent version always, the section may be moved
to a new file, and the link is broken!

solution: always link to a specific version
        
# upload

go to [github]

create an account. your userid is: ``userid``

create a repository. call it ``test``

add this remote location with:

    git remote add origin git@github.com:userid/test.git

it is called ``origin``

see all the remote locations with:

    git remote -v

output:

    origin  git@github.com:cirosantilli/programming.git (fetch)
    origin  git@github.com:cirosantilli/programming.git (push)

upload to the server with:

    git push origin master

enter your github userid and password

go back to github and browse your uploaded files

## motivation

1) backup you work

    your disk may burn someday

2) publish your work

    so other can see the latest version immediatelly

# differences

see differences between two versions with:

    git diff eebb22 06637b

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

    '+' indicates that a line was added.

    not surprisingly, if we remove something, a '-' will show instead

## motivation

### see *where* others want to modify your work

others will want to suggest modifications to your work to contribute with you

this way, you can see modifications line by line and decide to accept or
reject his modifications

#### why others want to collaborate

- to become more famous:

    if they make lots of good contributions, others will thing they work well
    and may hire them

- to collaborate via snowball effect:

    - if he uses your work, he wants your work to get better quick
    
    - for your work to get better quick, lots of people need to use your work
    
    - if he improves your work, more people will will use your work too

this way, your work improves while you sleep!

#### how other will suggest modifications

git + web interface makes that easy

modifying works like this:

1) he goes to your page on the web interface and clicks on *fork*
    
    this makes a copy of your work on the server to his workspace on the server

2) he copies files on his workspace copied files are copyied to his disk with:

        git clone git@github.com:his_userid/test.git 

3) he makes the modifications on his disk

4) he uploads to his workspace with:

        git push origin master

    ``origin`` was already added after ``clone``

5) he goes to the web interface, and clicks make *pull request*
    
6) you see exactly what he changed, line by line

7) you accept/reject his changes

    if you reject, say why, and what he could to for you to accept it

    this way, you will have more collaborators

## undo mistakes

if you make mistakes on a new version
you can compare it to older working version to see where things went wrong

# follow-up

this was the minimal knowledge to see why git is useful

there are many features left:

- HEAD, HEAD^, HEAD~3
- tags
- branches
- merge


[github]: https://github.com/
[vcm]: http://en.wikipedia.org/wiki/Revision_control
