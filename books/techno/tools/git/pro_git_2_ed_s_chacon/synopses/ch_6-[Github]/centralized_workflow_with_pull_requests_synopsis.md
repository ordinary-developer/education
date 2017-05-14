Centralized workflow with pull requests
=======================================

Base
----

To create a pull request:


- make a topic branch from the master (or develop) branch
  ```
  $ git checkout master 
  // or
  $ git checkout develop
  $ git checkout -b topic_branch
  ```
- make a commit in the topic branch
  ```
  // edit files
  $ git add file
  $ git commit
  ```
- push the topic branch to the server (may make it trackable)
  ```
  $ git push origin topic_branch
  // or
  $ git push --set-upstream origin topic_branch
  ```
   
After that you will see a button "Compare && pull request", click it.
Then you must select the base branch (develop)
and the current branch (your current topic branch).
Create the message and click the "Create pull request" button.

After that maintainer can close your pull request.

If you want to edit the file :  
- fetch the data from the server 
  ```
  $ git fecth origin
  ```
- merge it or rebase with your topic branch
  ```
  $ git checkout topic_branch
  $ git merge origin/master 
  // or 
  $ git rebase origin/master
  ```
  Resolve conflicts if neccessary (?!)
- edit files and commit again
  ```
  // edit files
  $ git add file
  $ git commit
  ```
- push your branch to the server
  ```
  $ git push origin topic_branch
  ```
  After that a maintainer can merge your pull request.
  If there is a conflict, the conflict cab be resolved 
  also by the maintainer
- pull the branch to the maintainer's repository and merge to it
  ```
  $ git fetch origin
  $ git checkout develop
  $ git merge origin/topic_branch
  ```
- resolve the conlifct
  ```
  // edit the conflict file
  $ git add file
  $ git commit
  ```
- push the changes to the server
  ```
  $ git push origin develop
  ```
  And the pull request will be closed.


If you want to create a pull request after creating the topic branch 
manually, nn the top page you must click ("New pull request") 
and select necessary branches
  