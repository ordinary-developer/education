First steps
===========

To run a new container:
```sh
$ docker run --hostname <hostname> --name <name>
             --interactive --tty <distr> <command>
```
or
```sh
$ docker run -h <hostname> --name <name> 
             -i -t <distr> <command>
```

where
- hosttname <hostname> - the hostname for the container
- <name> - the name of the container
- <distr> - the ditributif for the container
- <command> - a command to be launched inside a container  
(all parameters must be specified without angle brackets),
"-- interactive" means running an interactive session,
"--tty" means running a session with a tty atached.

A concrete example is below:
```sh
$ docker run --hostname CONTAINER --name my_name 
             --interactive --tty debian /bin/bash
```

Other usefull commands:
- to see currently running containers:  
  `docker ps`
- to see all containers (include "exited"):   
  `docker ps -a`
- to inspect a container:  
  `docker inspect <container-name>`
- to see what files has been changed:  
  `docker diff <container-name>`
- to see all actions:  
  `docker logs <container-name>`
- to remove a container:  
  `docker rm <container-name>`
- to start an 'exited' container:  
  `docker start <container-name>`         
- to stop a container:  
  `docker stop <container-name>`

To remove automatically a container after its execution
use the "run" command with the "--rm" flag.

To commit an image:
```sh
$ docker commit <container-name> <repository-name>/<image-name>
```
For example:
```sh
$ docker commit cowsay test/cowsayimage
```

