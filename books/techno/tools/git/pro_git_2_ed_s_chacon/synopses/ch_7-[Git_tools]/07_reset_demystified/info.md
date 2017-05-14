reset demystified
=================


the three trees
---------------

Git as a system manages and manipulates three trees 
(three collections of files) in its normal operation:
- *HEAD* - last commit snapshot, next parent
- *Index* - proposed next commit snapshot
- *Working Directory* - sandbox


#### HEAD

*HEAD* is the pointer to the current branch reference, which is in 
turn a pointer to the last commit made on that branch;

*HEAD* will be the parent of the next commit that is created

it is simplest to think of HEAD as the snapshot 
of your last commit


#### the index

the index is your *proposed next commit*
(you can also refer to this concept as Git's "Staging Area"
as this is what Git looks at when you run "git commit")


#### the working directory

think of the Working Directory as a *sandbox*, where you can try
changes out before committing them to your staging area (index)
and then to history



the workflow
------------

you got into a new directory with a single file in it; we call this
v1 of the file;  
we run "git init", which will create a Git repository with a HEAD
reference which points to an unborn branch 
("master" doesn't exist yet); at this point only 
the Working Directory tree has any content



the "reset" command
-------------------

#### step 1: move head

the first thing "reset" will do is move what HEAD points to

this isn't the same as chaning HEAD itself (which is what "checkout"
does) "reset" moves the branch that HEAD is pointing to; 

this means if HEAD is set to the master branch (i.e. you're currently
on the master branch) running "git reset 9e5e64a" will start by 
making "master" point to "9e5e64a";  
with "reset --soft" it will simply stop there

after the next command:  
```git
$ git reset --soft HEAD~
```

it essentially undid the last "git commit" command;  
when you run "git commit", Git creates a new commit and moves the 
branch that HEAD points to up to it; when you reset back to HEAD~
(the parent of HEAD), you are moving the branch back to where it was,
without changing the Index or Working Directory;  
you could now update the "Index" and run "git commit" again to 
accomplish what "git commit --amend" would have done


#### step 2: updating the index (with --mixed)

the next thing "reset" will do is to update the index with the
contents of whatever snapshot HEAD now points to
 
if you specify the "--mixed" option, "reset" will stop at this point,
this is also the default, so if you specify no options at all,
this is where the command will stop

after the next command:
```git
$ git reset --mixed HEAD~ 
```
it still undid your last commit, but also unstaged everything, you 
rolled back to before you ran all you "git add" and "git commit"
commands


#### step 3: updating the working directory (with --hard)

the third thing that "reset" will do is to make the Working Directory
look like the Index

if you use the "--hard" option, it will continue to this stage

after the next command:
```git
git reset --hard HEAD~
```

you undid your last commit, the "git add" and "git commit" commands,
and all the work you did in your working directory

it's important to note that this flag (--hard) is the only way to
make the "reset" command dangerous, and one of the very few cases
where Git will actually destroy data


#### recap

the "reset" command overwrites these three trees in a specific order,
stopping when you tell it to:
1. move the branch HEAD points to (stop here if --soft)
2. make the index look like HEAD (stop here unless --hard)
3. make the working directory look like the Index



"reset" with a path
-------------------

if you specify a path, "reset" will skip step 1, and limit the remainder
of its actions to a specific file or set of files

so the next command
```git
$ git reset file.txt
```

is a shorthand for:
```git
$ git reset --mixed file.txt
```

or 
```git
$ git reset -- file.txt
```

which will:
1. move the branch HEAD points to (skipped)
2. make the index look like HEAD (stop here)

so it essentially just copies "file.txt" from HEAD to the index;  
this has the practical effect of unstaging the file

to copy a file from other commit:
```git
$ git reset eb43bf -- file.txt
```

where "eb43bf" is a short SHA for the needed commit



squashing
---------

let's say you have a project where the first commit has on file, 
the second commit added a new file and changed the first,
the third commit changed the first file again

the second commit was a work in progress 
and you want to squash it down

you can run:
```git
$ git reset --soft HEAD~2
```

to move the HEAD branch back to an older commit (the first commit
you want to keep)

and then simply run:
```git
$ git commit 
```



check it out
------------

like "reset", "checkout" manipulates the three trees, and it is a bit
different depending on whether you give the command a file path
or not

#### without paths

running "git checkout [branch]" is pretty similar to running 
"git reset -- hard [branch]" in that it updates all three trees for
you to look like "[branch]", but there are two important differences
- unlike "reset --hard", "checkout" is working-directory safe  
  (it tries to do a trivial merge in the Working Directory, so all
   of the files you haven't changed in will be updates)  
  "reset --hard", on the other hand, will simply replace everything
  across the board without checking
- where "reset" will move the branch that HEAD points to, "checkout"
  will move HEAD itself to point to another branch  
  ("reset" will move the branch HEAD points to, "checkout" moves
   HEAD itself)


#### with paths

running the "checkout" command with a file path, does not move HEAD;  
it update the index with that file at that commit, but is also
overwrites the file in the working directory;  

