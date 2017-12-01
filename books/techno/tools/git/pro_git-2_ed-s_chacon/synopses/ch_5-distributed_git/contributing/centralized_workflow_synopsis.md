Centralized workflow
====================
  
Idea
----

You have the central git repository and have two main branches 
(master and develop). All contributors may write 
to the develop branch.


Intialization
-------------

First it is necessary to create a bare repository on the server:
```
$ git init --bare /path/to/repo.git
```

Then locally you must create file .gitignore, 
create the structure of the project, 
and then push it to the master.

Then you can you an add-status-commit approach, 
but instead you may create the develop branch:
```
$ git add <some-file>
$ git commit -a  ($ git commit --all)
```

Sometimes it is necessary to push something (may be nothing)
to the branch 'master':
```
$ git push -u origin master 
// or
$ git push --set-upstream origin master
```

Then it is necessary to create an empty develop branch locally
and push it to the server and may be to go to that branch
(you must have "origin" record in your remotes url):
```
$ git remote add origin your_origin_url
```
 
Instead you can create repository in GitHub or BitBucket and simply
clone them to your machine.
So you will have a repository with already tracked master branch.

After that you can create the "develop" branch
```
$ git branch develop
$ git checkout develop)
$ git push -u origin develop
```

Other developers should now clone the central repository 
and create a tracking branch for develop:
```
$ git clone ssh://user@host/path/to/repo.git
$ git checkout -b develop origin/develop
```

 
Creating features
-----------------

To work with new features you must do locally:
```
$ git checkout -b some-feature develop
```
 
Developers add commits to the feature branch in the usual fashion:
edit, stage, commit
```
$ git status
$ git add <some-file>
$ git commit
```
 
After adding a few commits, you can merge it into your local develop
```
$ git pull origin develop
// or
$ git checkout develop
$ git fetch origin //($git fetch origin/develop)
$ git merge origin/develop //($git rebase origin/develop)
```

and push it to the central repository, like so:
```
$ git checkout develop
$ git merge some-feature // ($ git rebase some-feature)
$ git push
$ git branch -d some-feature
```

Note that features should never be merged directly into master.
Also note, that when you pull data from the server, 
it is recommended to use the next command
```
$ git pull --rebase
```


Preparing a release (maintaining issues)
----------------------------------------

To prepare a release we must create a new branch
```
$ git checkout -b release-0.1 develop
```
 
Once the release is ready to ship, it is necessary
to merge it into master and develop, then delete the release branch.
Its important to merge back into develop because critical updates
may have been added to the release branch 
and they need to be accessible to new features.
```
$ git checkout master
$ git merge release-0.1
$ git tag -a 0.1 -m "Initial public release" master
($ git tag --annotate 1.0 \->
     --message "Initial public release" master)
$ git push --tags
$ git checkout develop
$ git merge release-0.1
$ git push
$ git branch -d release-0.1
```

Release branches act as a buffer
between feature development (develop)and public releases (master). 

Whenever you merge something into master, you should tag the commit
for easy reference
```
$ git tag -a 0.1 -m "Initial public release" master
( git tag --annotate 1.0 \->
   --message "Initial public release" master)
$ git push --tags
```


Maintenance
-----------

To a fix a bug in production code:
```
$ git checkout -b issue-#001 master
```

Then fix the bug.

Then
```
$ git checkout master
$ git merge issue-#001
$ git push
```
 
Like release branches, maintenance branches contain important updates
that need to be included in develop.

So Mary needs to perform 
that merge as well. Then, shes free to delete the branch:
```
$ git checkout develop
$ git merge issue-#001
$ git push
$ git branch -d issue-#001
```