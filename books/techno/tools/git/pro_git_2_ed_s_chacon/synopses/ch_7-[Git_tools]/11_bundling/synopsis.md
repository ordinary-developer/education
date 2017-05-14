Bundling
========

Common
------

The "bundle" command will package up everything that would normally
be pushed over the wire with a "git push" command into a binary file
that you can email to someone or put on a flash drive, then unbundle
into another repository.

To bundle you repository: 
```sh
$ git bundle create repo.bundle HEAD master
```

To clone from the binary file into a directory: 
```sh
$ git clone repo.bundle repo
```

You can create a bundle from a rage of commits:
```sh
$ git bundle create commits.bundle 8bcf3a7 ^9a466c5
```
where *9a466c5* designate "from"(*may be(?)* including) 
and *8bcf3a7* designate "to" (including)

or 
```sh
$ git bundle create commits.bundle 9a466c5..8bcf3a7
```
where *9a466c5* designate "from"(including) 
and *8bcf3a7* designate "to" (including)

To verify a bundle (verify the file is actually a valid Git bundle
and that you have all necessary ancestor to reconstitute it properly:
```sh
$ bit bundle verify bundle-file
```

To see what branches are in the bundle that can be imported:
```sh
$ git bundle list-heads bundle-file
```

To fetch the "master" branch of the bundle 
to a branch named "other-master" in your repository:
```sh
$ git fetch bundle-file master:other-master
```
