# Revision selection

Single revisions
================
 
Short SHA
---------

To see one commit:
```
$ git show 1c002d
```
(where "1c002d" is a short SHA)

To see commits a short form:
```
$ git log --abbrev-commit --pretty=oneline
```

To see the last commit in the branch:
```
$ git show branch-name
```

 
Reflog shortnames
-----------------

To see a log, where your HEAD and branch references have been for the
last few months:
```
$ git reflog
```
 
To see the concrete commit by reflog:
```
$ git show HEAD@{5}
```

To see a commit history with a head logging:
```
$ git log -g master
```

It's important to note that the reflog information is strictly local
 - it is a log of what you've done in your repository.


Ancestry references
-------------------

to see the first parent of HEAD:
```
git show HEAD^
```
 
for a usual commit:
```
git show d912970^
```
(where d912970 is a show SHA)

To see the second parent (it is only useful for merge commits):
```
$ git show HEAD^
```
 
To see the first parent of the first parent of the first parent:
```
$ git show HEAD~3
// it is equivalent to
$ git show HEAD^^^
```


Commit ranges
=============

Double dot
----------

To see what commits are in the "branch2" and not in "branch1"
(all commits reachable by "branch2" that aren't reachable by "branch1")
this allow preview what you're about to merge in:
```
$ git log branch1..branch2
```
 
To see what you're about to push to a remote:
```
$ git log origin/master..HEAD
// or its equivalent
$ git log origin/master..
```

Multiple points
---------------

The next 3 strings are equivalent:
```
$ git log refA..refB
$ git log ^refA refB
$ git log refB --not refA
```

To see all commits that are reachable from refA or refB 
but not from refC:
```
$ git log refA refB ^refC
// or 
$ git log refA refB --not refC
```
 
Triple dot
----------
 
To see the commits, that are reachable (contained) 
by either of two refs but not by both of them:
```
$ git log branch1...branch2
```

To do the same but with "<" and ">" signs:
```
$ git log --left-right branch1...branch2
```