Rerere (reuse recorded resolution)
==================================

Common
------

The "rerere" feature allows you to ask Git to remember how you've
resolved a hunk conflict so that the next time it sees the same
conflict, Git can automatically resolve it for you.

To enable the "rerere" functionality:
```sh
$ git config --global rerere.enabled true 
```

The next command:
```sh
$ git rerere status
```
tell you what it has recorded the pre-merge state for.

The next command:
```sh
$ git rerere diff 
```
will show the current state of the resolution - what you started 
with to resolve and what you've resolved it to.t

To see the conflicted files and the before, left and right versions:
```sh
$ git ls-files -u
```


rerere workflow
---------------

- turn on the "rerere" functionality
  ```sh
  $ git config --global rerere.enabled true 
  ```
- resolve a conflict ("rerere" will remember your choice)
- try to rebase or merge
  (you will have a conflict, but the file will contain correct
   contents according to your "rerere" strategy, so you don't
   need to edit your file)
- run
  ```sh
  $ git rerere
  $ git add your_conflict_file
  $ git rebase --continue
  ```
