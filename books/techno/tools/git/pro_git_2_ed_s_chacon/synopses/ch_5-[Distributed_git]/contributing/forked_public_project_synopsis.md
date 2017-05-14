Distributed git
===============

Idea
----


You fork the main repository and make all work in the theme branches
of this forked repository. You comminacate with the maintainer 
by pull-requests.

This example describes contributing via forking on Git hosts
that that support easy forking (pull requests).
  

Forked Public Project
---------------------

First:
```
$ git clone (url)
$ cd project
$ git checkout -b featureA
 (work)
$ git commit
 (work)
$ git commit
```

When your branch is finished, go to the original project page
and click the "Fork" button, creating your own writable fork 
of the project. Then you need ot add in this new repository URL
as a second remote (myfork)
```
$ git remote add myfork (url)       
```

Then you need to push your work up to it.
It is easier to push the topic branch you're working on up 
to your repository (if your work isn't accepted, 
you don't have to rewind your master branch)
```
$ git push --set-upstream featureA
```

When your work is finished you need to notify the maintainer
(to make a pull-request).  
The request-pull command takes the next argumests:
 - the base branch into wich you want your topica branch pulled
 - the Git repository URL you want them to pull from  and ouputs
   a summary of all the changes you're asking to be pulled in.

If Jessica wants to send John a pull request, and she's done two
commits on the topica branch she just pushed up, she can run this
```
$ git request-pull origin/master myfork
 ...(output)
```

The output can be send to the maintainer - it tells him
where the work

On a project for which you're not the maintainer it is easier
to have a branch like mater always track origin/master
and to do your work in topic branches 
```
$ git checkout -b featureB origin/master
  (work)
$ git commit
$ git push myfork featureB
  (emial maintainer with a pull-request) 
$ git fetch origin
```

After that you can rebase from origin/master
(Now you are on the featureB branch)
```
$ git rebase origin/master
```

If it is neccessarily to resolve the conflicts
```
$ git checkout featureA
$ git rebase origin/master
$ git push -f myfork featureA
```

You can rebase the featureA branch history
beacause it is only your branch.


#### Scenario

The maintainer has looked at work in your branch
and wants you to make some changes
```
git checkout -b featureBv2 origin/master
$ git merge --no-commit --squash featureB
 (work)
$ git commit
$ git push myfork featureBv2
```

The "--squash" option takes all the work on the merged branch
and squashes it into one non-merge commit on the top of 
the branch you're on. The "--no-commit" option tells Git not
to automatically record a commit.
 
After that you can use the "pull-request" command
and send its output to the maintainer
 
After the maintainer has accepted your work
you can delete your branch by the next command
```
$ git push myfork --delete featureBv2
``` 