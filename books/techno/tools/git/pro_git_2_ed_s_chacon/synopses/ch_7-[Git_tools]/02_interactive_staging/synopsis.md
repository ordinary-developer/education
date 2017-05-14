INTERACTIVE STAGING
===================
 
Common
------

If you modify a bunch of files and then dedice 
that you want those changes to be in several focused commits
rather than one big commit.

For such interactive staging your can use
```
$ git add --interactive"
// or 
git add -i
```


Staging and unstaging files
---------------------------

To stage files (after modifying) you can type 
```
: "2" // (or "u")
```
(for add untracked files use "a" or "4")
, press "Enter",

And then select files by their numbers
```
: "1" // (or "1,2" etc.)
```
(the numbers are provided by git),
and press "Enter"

The * next to each file means the file is selected to be staged.

To unstage files (both from modifying or adding from an untrackable state)
```
: "3" // (or "r")
```

To see what you've staged use
```
: "6" // (or "d")
```
it shows the list of files with numbers, 
you can see the file's changes by pressing its number

 

Staging patches
---------------
 
To partially stage something, use
```
 : "5" // (or "p")
```

Git will ask you which files would you like to partially stage;
then, for each selection of the selected files, it will display
hunks of the file diff and ask if you would like to stage them,
one by one.

Type "?" to show what you can do.
