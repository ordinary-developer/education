Debugging with Git
==================

File Annotation
---------------

File annotations show you what commit was the last 
to modify each line of any file.

So, if you see that a method in your code is buggy, you can annotate
the file with *git blame* to see when each line of the method 
was last edited and by whom.
```
$ git blame -L 12,22 filename.ext
```
Where 12, 22 - is a range of strings to find (counting from 1)

You can ask Git to figure out all sorts of code movement as well.
With *-C* option, you can see where sections of the code originally
came from
```
$ git blame -C -L 141, 153 filename.ext
```


Binary Search
-------------

If you don't know what is breaking, you can use *git bisect*.
The *bisect* command does a binary search through you commit history
to help you identify which commit introduced an issue.

```
$ git bisect start
$ git bisect bad
$ git bisect good v1.0
```
First you run *git bisect start* to get things going,
and then you use *git bisect bad* to tell the system 
that the current commit you're on is broken.
Then, you must tell bisect when the last known good state was,
using *git bisect good [good_commi]*

Let's assume than the issue doesn't exist in this commit, then run:
```
$ git bisect good
```

Let's assume that this commit is broken, then run
```
$ git bisect bad
```

now run:
```
$ git bisect good
```
Now Git has all information it needs to determine where the 
issue was introduced.
Git tells you the SHA-1 of the first bad commit and show some of
the commit information and which files were modified in the commit
so you can figure out what happened that may have introduced this bug

When you're finished, you should run *git bisect reset* to reset your 
HEAD to where you where before you started, or you'll end up in a
weird state:
```
$ git bisect reset
```
