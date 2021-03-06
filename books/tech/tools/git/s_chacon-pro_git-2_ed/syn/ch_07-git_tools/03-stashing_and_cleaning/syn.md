Stashing and cleaning
=====================
 
Stashing
--------

### Base material
Stashing takes the dirty state of your working directory - that is,
your modified tracked files and staged changes - and saves it on a stack
of unfinished changes that you can reapply at any time

Let's assume that you work, and you see your dirty state,
to push a new stash onto your stack, run:
```
$ git stash
```
or
```
$ git stash save
```

By default "git stash" will only store files that are alredy in the index
(i.e. they are trackable and staged or unstaged).

to see which stashes you've stored:
```
$ git stash list
```
Where stash@{0} - is the last stashed work .

To apply a stash, specify it by name:
```
$ git stash apply stash@{2}
```

To apply the most recent stash:
```
$ git stash apply
```

Having a clean working directory and stash applying on the same branch
aren't necessary you can save a stash on one branch, switch to another branch later,
and try to reapply the changes you can also have modified and uncommited
files in your working directory when you apply a stash
Git gives you merge conflicts if anything no longer applies cleanly.

To try to reapply the staged changes
(will try to reapply all: staged and unstaged changes):
```
$ git stash apply --index
```

To remove the stashed work (without unstashing):
```
$ git stash drop stash@{0}
```

To apply the stash (the last stashed work in the stash list)
and then immediately drop it from your stack:
```
$ git stash pop
```

 
### Auxiliary material
To stash anything that you've alredy staged with the "git add" command:
```
$ git stash --keep-index
```  
it is "git stash" + saving staged in your working directory

To stash untracked files as well as the tracked ones:
```
$ git stash --incldue-untracked
```
or
```
$ git stash -u
```

For interactively select changes to stash:
```
$ git stash --patch
```

The next command:
```
$ git stash branch branch-name
```
creates a new branch for you, checks out the commit you were on when
you stashed your work, reapplies your work there, and then drops the stash
if it applies successfully.

 
### Cleaning

To clean working directory (to delete untracked files and directories):
```
$ git clean -d -f
```
or  for "dry" running
```
$ git clean -d -n
```

These commands will only remove untracked files that are not ignored.
Any file that matches a pattern in your ".gitignore" or other 
ignore files will not be removed.

To remove these files too:
```
$ git clean -d -x -f
```
or for "dry" running
```
$ git clean -d -x -n
```

To clean in interactive mode:
```
$ git clean -x -i
```


### Summary
**git stash save**
Save staged, and not staged modificated file to stash
doesn't save untrackabe files
delete all changed in working directory,
doesn't delete untrackable files (they will remain in the working dir).


**git stash apply**
After reapplying:
staged in stash -> modificated trackable, not staged in working dir
modificated trackable in stash -> modificated trackable in working dir.

**git stash apply --index**
After reapplying:
staged in stash -> staged in working directory
modificated trackable in stash -> modificated trackable in working dir.
 
**git stash save --include-untracked**
Save staged, and not staged modificated file to stash
save untracked files to stash
delete all changed in working directory,
delete all untracked files from working dir (and pyshically deletes them).

**git stash apply**
After reapplying:
untracked in stash -> untracked in working dir
staged in stash -> modificated trackable, not staged in working dir
modificated trackable in stash -> modificated trackable in working dir.

**git stash apply --index**
After reapplying:
untracked in stash -> untracked in working dir
staged in stash -> staged in working directory
modificated trackable in stash -> modificated trackable in working dir.
