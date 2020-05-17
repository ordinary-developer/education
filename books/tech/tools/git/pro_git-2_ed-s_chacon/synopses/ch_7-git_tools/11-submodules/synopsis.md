# submodules - base
after changes (or fetching changes) (changes are commits) in (from) the sub repo
it is necessary to make commits with these changes (commits) in the main repo


## adding a submodule to the repo
1. to add a submodule to the current repo: `$ git submodule add <URL>`
2. to see changes (after submodule fetching): `$ git diff --cached --submodule`
3. to save and push 'submodule fetching': `$ git commit -am 'add a submodule'`


## cloning a project with submodules
```sh
$ git clone <URL>
$ git submodule init
$ git submodule update
```


## pulling data from the submodule repo
- 1. enter the main repo
- 2. enter the necessary submodule within the main repo
- 3. fetch changes
     ```sh
     $ git fetch
     $ git rebase origin/master
     ```
- 4. enter the main repo
- 5. commit the changes and push to the server


## pulling data from the main repo
in the main repo in the master branch:
```sh
$ git fetch origin
$ cd sub_prj
$ git rebase origin/master
$ cd ..
$ git rebase origin/master
```
   

## working on a submodule
1. update the repo (main prj and sub prj)
2. enter the sub_prj
3. make here a new branch (from the detached state):
   ```sh
   $ git checkout master
   $ git rebase origin/master
   ```
4. make changes and commit, and then rebase with the sub_prj/origin, resolve conflicts if necessary
5. make final steps in the main repo 
   ```sh
   $ cd ..
   $ git commit // changes in the main repo
   $ git push --recurse-submodules=on-demand origin
   ```



# submodules - aux

## cloning a project with submodules
```sh
$ git clone --recurse-submodules <URL>
```


## pulling data from the submodule repo
- 1. enter the main repo
- 2. fetch submodule changes
     for the necessary submodule:
     ```sh
     $ git submodule update --remote <submodule>
     ```
     for all submodules (with --init - for new added repos):
     ```sh
     $ git submodule update --init --recursive --remote
     ``` 
- 3. commit the changes


## pulling data from the main repo 
on the master branch (in main prj)
```sh
$ git pull
$ git submodule update --init --recursive
```

## working on a submodule
1. enter the sub_prj
2. make here a new branch (from the detached state):
   ```sh
   $ git checkout master
   $ git rebase origin/master
   ```
3. enter to the main prj and update the submodule
   ```sh
   $ cd ..
   $ git submodule update --remote --rebase
   ```
- conflict resovling
  1. in main repo:
     ```sh
     $ cd sub_prj
     $ // edit and commit changes
     ```
  2. in the "sub_prj" repo make changes, commit and push
  3. in main repo:
     ```sh
     $ cd ..
     $ git submodule update --remote --rebase
     ```
     here the conflict will be
   4. enter the sub_prj:
      ```sh
      $ cd sub_prj
      $ // edit the conflict file //
      $ git add <conflict file>
      $ git rebase --continue
      ```

## pushing submodule changes
in the main repo:
```sh
$ git push --recursive-submodules=check
```




                                                                              
## high level thoughts
  