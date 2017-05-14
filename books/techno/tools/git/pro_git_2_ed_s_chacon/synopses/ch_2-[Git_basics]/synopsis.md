Git basics
==========


Base material
-------------

Each file in your working directory can be in one of two states: 
tracked or untracked  
- tracked files are files that were in the last snapshot;
  they can be unmodified, modified, or staged;
- untracked files are everything else - any files in your working 
  directory that were not in your last snapshot and are not in 
  your staging area.

```
 unracked                unmodified          modified        staged
   |                        |                   |               |
   |                    add the file                            |
   |----------------------------------------------------------->|
   |                        | edit the file     |               |
   |                        | ----------------->|               |
   |                        |                   | stage the file|
   |                        |                   | ------------->|
   | remove the file        |                                   |       
   |<---------------------- |                commit             |
   |                        | <-------------------------------- |
```


#### git add

"git add" - is a multipurpose command - you use it to begin tracking
new files, to stage files, and to do other things like marking 
merge-conflicted files as resolved.


#### git diff

To see what you've changed but not yet staged type:
```
$ git diff --color
```
This command compares what is in your working directory with what is 
in your staging area.

To see what you've staged that will go into your next commit type:
```
$ git diff --staged --color
```
This command compares your staged changes to your last commit.


#### git commit

To commit your changed use the command:
```
$ git commit
$ git commit --message "Commit messages"
$ git commit --all --message "Commit message"
```


#### git rm

To remove file it is not neccessary to use standard unix "rm" 
command, instead you can type:

if you have not changed the file
```
$ git rm file-to-remove
```

or if you have changed and then staged the file
```
$ git rm --force file-to-remove
```
and then commit your changes.


By the next command you can keep the file in your working tree,
but it will be untracked:
```
$ git rm --cached file-name
```
after that you must commit your changes.
 

#### git mv

If you want to rename a file in Git, you can run something like:
```
$ git mv file_from file_to
```
and then you must commit your changes.

This is equivalent to running something like that:
```
$ mv file_from file_to
$ git rm file_from
$ git add file_to
```


#### git log

To see your history:
```
$ git log --color
```

To see the difference introduced in each commit:
```
$ git log --patch -2 --color
```
you can use -2, which limits the output to only the last two entries.

To see some abbreviated stats for each commit:
```
$ git log --stat --color
```

The option "--pretty" changes the log output to formats other 
than the default.

The next option prints each commit in a single line:
```
$ git log --pretty=oneline
```

The "format" option allows you to specify your own log output format,
for example:
```
$ git log --pretty=format:"%h - %an, %ar : %s"
```

To see your commit history as a graph:
```
$ git log --graph
```

Useful option - "--abbrev-commit":
shows only the first few characters of the SHA-1 checksum 
instead of all 40.

Another useful command:
```
$ git log --oneline --decorate --graph --color
```


#### git commit --amend

This command is useful when you commit too early and possibly forget
to add some files, or you mess up your commit message.
This command takes your staging area and uses it for the commit  
but the second commit replaces the results of the first.
```
$ git commit --message 'Initial commit'
$ git add forgotten_file
$ git commit --amend
```


#### git reset HEAD filename

This command is used to unstage the 'filename' 
but to keep it modified.


#### git checkout -- filename

This commnad unmodifies a modifiled file.
 

#### git fetch [remote-name]

"git fetch" command pulls the data to your local repository,
it doesn't automatically merge it with any of your work or
modify what you're currently working on.
You have to merge it manually into your work when you're ready;  
instead you can use "git pull" command.


#### git push [remote-name] [branch-name]

This command pushes the data to the server.


#### tags

Git uses two main types of tags: lightweight and annotated.
Difference:
- a lightweight tag is very much like a branch that doesn't change -
  it's just a pointer to a specific commit;  
- annotated tags are store as full objects in the Git database.

Is is generally recommended to create annotated tags.

The next command will show all tags:
```
$ git tag
```

The next command will show the tag v1.5:
```
$ git show v1.5
```

The next command will create an annoated tag:
```
$ git tag --annotate v1.5 --message 'Message for a tag'
```

The next command will create a lightweight tag:
```
$ git tag v1.5-lw
```

The next command will create an annotated tag v1.2 for the commit "9fceb02":
```
$ git tag --annotate v1.2 9fceb02
```


The next command will push the v1.5 tag to the server (origin in this case):
```
$ git push origin v1.5
```

The next command will push all tags to the server (origin in this case):
```
git push origin --tags
```
