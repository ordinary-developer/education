Git Branching
=============


Base material
-------------

When you make a commit, Git stores a commit object that contains 
a pointer to the snapshot of the content you staged. A branch in Git
is simply a lightweight movable pointer to one of these commits.

As you start making commits, you're given a master branch that points
to the last commit you made. Every time you commit, it moves forward
automatically.


Creating branches
-----------------

The next command  
```
$ git branch branch-name
```  
will create a new branch (a new pointer at the same commit
you're currently on) based on the current branch.
 
HEAD is a pointer to the local branch you're currently on.

To switch to the branch-name:  
```
$ git checkout branch-name
```

To create and switch to the new branch:  
```
$ git checkout -b branch-name
```

It's best to have a clean working state when you switch branches.
 

Merging branches
----------------

To merges your current branch (contents of your current branch) with
the branch-name branch:  
```
$ git merge branch-name
```  

To delete the branch with the name "branch-name":  
```
$ git branch --delete branch-name
```


Resolving conflicts during merging
----------------------------------

If you changed the same part of the same file differently in the two
branches you're merging together, Git won't be able to merge
them cleanly.

After  
- typing:  
  ```
  $ git checkout master
  $ git checkout -b iss53
  ```  
- editing the file "filename":  
- typing:  
  ```
  $ git checkout master
  $ git checkout -b hotfix
  ```  
- editing the same file "filename":  
- typing:  
  ```
  $ git checkout master
  $ git merge hotfix
  $ git checkout iss53
  ```  
- editing the same file "filename":  
  ```
  $ git checkout master
  $ git merge iss53
  ```

you will see info about a merge conflict.

You can see conflict files by  
```
$ git status
```

You can have one or more conflict files.
These files have the next structure:  
```
 -----------------------------------------------
 | text ... text (may be and may be not)       |
 | <<<<<<< HEAD                                |
 | text ... text                               |
 | =======                                     |
 | text ... text                               |
 | >>>>>>> [merge-branch-name]                 |
 | text ... text (my be and may be not)        |
 -----------------------------------------------
```  
This means the version in HEAD (your master branch,
because that was what you had checked out when you ran
your merge command) is the top part of the block 
(everything between "<<<<<<< HEAD" and " ======= "),
while the version in your "merge-branch-name" branch
looks like everything in the bottom part 
(everything between "=======" and ">>>>>>> [merge-branch-name]").

In order to resolve the conflict, you have to  
- either choose one side or the other or merge (edit) the contents
  yourself (after that the "<<<<<<<", "=======", ">>>>>>>" must be
  completely removed);
- type for each conflicted file:  
  ```
  $ git add file
  ```  
- type (if the last operation was successful) to finalize 
  the merge commit:  
  ```
  $ git commit
  ```  
  you will see an editor with a commit message.


Showing branches
----------------

To show all branches:  
```
$ git branch --color
```  
(a * means the branch you are currently on).

To show the branches that you have merged into the branch
you're currently on:  
```
$ git branch --merged
```

To show the brances that you have not merged into the branch
you're currently on:  
```
$ git branch --no-merged
```


Remote branches
---------------

Push the branch (in our case "serverfix") to the server:  
```
$ git push origin serverfix
// or
$ git push push origin serverfix:serverfix
```

To copy pointers to server branches that you can't modify:  
```
$ git fetch origin
```

To merge this work into your current working branch you can run:  
```
$ git merge origin/serverfix
```

and for the master branch:  
```
$ git merge origin/master
```

If you want your own serverfix branch that you can work on,
you can base it off your remote branch:  
```
$ git checkout -b serverfix origin/serverfix
```  
that will create what is called a "tracking branch" 
(an "upstream branch").

Tracking branches are local branches that have a direct relationship 
to a remote branch. 

If you're on a tracking branch and type "git pull",
Git automatically knows which server to fetch from 
and branch to merge into. Also it is a synonym for this command  
```
$ git checkout --track origin/serverfix
```

If you already have a local branch and want to set it
to a remote branch you just pulled down, or want to change 
the upstream branch you're tracking, type  
```
$ git branch --set-upstream origin/serverfix
// or
$ git branch -u origin/serverfix
```

When you have a tracking branche set up, you can reference it with 
the @{upstream} or @{u} shorthand. So if you're on the master branch
and it's tracking origin/master, you can say something like  
```
$ git merge @{upstream}
```  
instead of  
```
$ git merge origin/master
```
    
To show full information about branches:  
```
$ git branch -vv
// or
$ git branch --verbose --verbose
```

To show remote branches:  
```
$ git branch --remote
```

To show all branches:  
```
$ git branch --all
```

To take all from all remote servers:  
```
$ git fetch --all
```

To delete your serverfix branch from the server:  
```
$ git push origin --delete serverfix
```


Rebasing
--------

Instead of merging you can use rebasing:
- create a new brach from the master branch  
  ```
  $ git checkout -b experiment" 
  ```  
- edit some file  
- commit changes  
  ```
  $ git commit --all --message 'Add some functionality'
  ```  
- go to the master branch  
  ```
  $ git checkout master
  ```  
- edit some file  
- commit the changes  
  ```
  $ git commit --all --message 'Add some other functionality'
  ```  
- rebase  
  ```
  $ git checkout experiment 
  $ git rebase master
  $ git checkout master         
  $ git merge experiment
  ```


Rebase merge conflict
---------------------

You can resolve merge conflict during rebasing:  
- create a new brach from the master branch  
  ```
  $ git checkout -b experiment" 
  ```  
- edit a file  
- commit changes  
  ```
  $ git commit --all --message 'Add some functionality'
  ```  
- go to the master branch  
  ```
  $ git checkout master
  ```  
- edit the same file  
- commit the changes  
  ```
  $ git commit --all --message 'Add some other functionality'
  ```  
- rebase  
  ```
  $ git checkout experiment 
  $ git rebase master
  // edit a conflict file
  $ git add conflict_file_name
  $ git rebase --continue
  $ git checkout master
  $ git merge experiment
  ```

If during rebase conflict after adding already resolved file
by `git add ...` you have the next message:
> No changes - did you forget to use "git add"?
> If there is nothing left to stage, chances are that something else
> already introduced the same changes;
> you might want to skip this patch.
>
> When you have resolved this problem, run "git rebase --continue".
> If you prefer to skip this patch, run "git rebase --skip" instead.
> To check out the original branch and stop rebasing,
> run "git rebase --abort".
run the next command:
```
$ git rebase --skip
```


For pulling from the server:   
```
$ git pull --rebase
// or
$ git fetch && git rebase teamone/master
```

if you work with a remote branch that then must be rebased 
sometimes it is useful to run the next command:
```
git push --force-with-lease
```

**DO NOT REBASE COMMITS THAT EXISTS OUTSIDE YOUR REPOSITORY!!!**

It is better to rebase local changes you've made 
but haven't shared yet before you push them in order to clean up
your history, but never rebase anything you've pushed somewhere.


Getting rebased from server
---------------------------

To rebase on the server branch:  
```
$ git pull --rebase
// or
$ git fetch && 
$ git rebase teamone/master
```
