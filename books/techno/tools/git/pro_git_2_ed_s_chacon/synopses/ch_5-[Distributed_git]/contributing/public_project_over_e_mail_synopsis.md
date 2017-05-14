Distributed git
===============


Base
----

This example describes contributing via e-mail
(without Git hosting platforms).
  
Idea:
You create topic branches for each patch series you work on.
Instead of forking the project and pushing to your own writable
version, you generate e-mail versions of each commit series and
e-mail them to the developer mailing list:


Public project over e-mail
--------------------------
 
Let's assume that you begin your work:
```
$ git checkout -b topicA
//   (work)
$ git commit
//  (work)
$ git commit
``` 

Now you have two commits that you want to send to the mailing list:
```
$ git format-patch -M origin/master 
```

The "format-patch" command prints out the names of the patch files
it creates. The -M switch tells Git to look for renames.
 
After that you can send these patches by email to the maintainer.
(by pasting the file into you e-mail program or by sending
 it via a command-line program).
But "smart" e-mail clients like browser and others often
may generate formatting errors

You can send e-mails by git tools.
Here we shall demostrate how to send a patch via Gmail
 
First, set up the "imap" section in your "~/.gitconfig"
You can set each value separately with a series of "git config"
commands, or you can add it manually, but your config file shoold look
```
[imap]
    folder = "[Gmail]/Drafts"
    host = imaps://imap.gmai.com
    user = your_user@gmail.com
    pass = your_password
    port = 993
    sslverify = false
```

Where "your_user" is you user name
and "your_passwd" is your password
 
Then you can use "git send-email" to place the patch series
in the Drafts folder of the specified IMAP server:
```
$ git send-email *.patch
```

At this point, you should be able to go to your "Drafts" folder, 
change the "To" field to the mailing list youre sending the patch to, 
possibly CC the maintainer or person responsible for that section, 
and send it off.
