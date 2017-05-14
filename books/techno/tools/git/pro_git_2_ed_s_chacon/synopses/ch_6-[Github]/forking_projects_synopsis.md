Forking projects via GitHub
=========================== 

Fork projects
-------------
 
To contribute to a project you must
 - create a fork of the project by clicking on the fork button   
 - create a topic branch from master
 - make some commits to improve the project
 - push this branch to your GitHub project
 - open a pull request on GitHub
 - discuss, and optionally continue committing
 - the project owner merges or closes the Pull requests  
   (he can create a topic branch based on the master branch,
    merge all data from your topic branch to his topic branch, 
    test his topic branch and merge it to the master branch)

```
$ git clone https://github.com/projectowner/project
$ cd project_folder
$ git checkout -b slow-blink
$ git diff --word-diff
$ git commit -a -m 'A message for a commit'
$ git push origin slow-blink
```

After that GitHub will present us with a big green button 
"Compare and pull request" to check out our changes 
and open a Pull Request to the original project.
 
Or you can alternatively go to the "Branches" page at "https://github.com/<user>/<project>/branches" 
to locate your branch and open a new Pull Request from there.

If we click that green button, we'll see a screen 
that allows us to create a title and description for the change 
we would like to request.

When you hit the "Create pull request" button, 
the owner of the project will get a notification
that someone is suggesting a change.

After that a contributor makes a change he cand commit these changes 
to the topic branch and push this branch again 
(instead of re-rolling his series and resubmiting it 
to the mailing list without GitHub)

After that the maintainer can click the "Merge pull request" button
(This button will apear if we can perform a merging) or he can
simply pull the branch down and merge it locally. 
If you merge this branch into the master branch and push it to GitHub,
the Pull Request will automatically be closed.

You can alson open a Pull Request between two branches 
in the same repository.

If you want to merge in the target branch 
to make your Pull Request mergeable,
you would
- add the original repository as a new remote
- fetch from it
- merge the main branch of that repository into your topic branch 
- fix any issues 
- and finally push it back up to the same branch 
  you opened the Pull Request on.

```
$ git remote add upstream https://github.com/projectowner/project
$ git fetch upstream
//  you must be in the topic branch
$ git merge upstream/master
//  assume that a conflict is here)
//  edit the conflict file
$ git add conflict.file
$ git commit
$ git push origin topic_branch
```