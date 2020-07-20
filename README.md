# Wolfenstein3D

## Codam Coding College project Wolf3D

![Demo of 42.fdf](https://github.com/jdsmith022/fdf_/blob/master/pictures/fdf.gif)

### Description

For Wolf3D, my partner and I used ray casting paired with line intersection technique. Unlike other methods that use an algorithm  based on DDA or "Digital Differential Analysis", we used this technique to challenge ourselves futher and implement extra features such as thin walls. Links for videos and tutorials for ray casting and line intersection, go to Wiki pages.

Using a miniblix library provided for the project, Wold3D's objectives include: Rigor, use of C, use of basic algorithms, information research, data mining etc. As a graphic design project, Wolf3D is an exercies that solidifies the skills I have gained in the following areas thus far: windows, colors, events, fill shapes etc.



For full pdf of project requirements click [here](https://github.com/jdsmith022/fdf/blob/master/wolf3d.en.pdf).

### Prerequsites
XQuartz
To download click [here](https://www.xquartz.org/).
This program was written on LinuxOS and complies with a Makefile.

### Installation

From terminal, the program can be install with git clone with the project repository, followed by the name of the directory you wish to download the repository to.

#### Example 
```
$ git clone git@github.com:jdsmith022/Wolfenstein3D.git [directory-name]
```

### Usage

In terminal, go into the project directory. This program uses a makefile to compile. To compile, run:
```
$ make
```

The executable name is fdf. A directory in the repository named maps has a list of landscape maps that can be used. To see names of maps available for use is maps directory of repository, from terminal and in git repository:
```
$ ls -la maps/
```
![ls-la display](https://github.com/jdsmith022/Wolfenstein3D/blob/master/images/ls.png)

However, a map from the local computer can be used as long as the path to the file is given as parameter.
```
$ ./wolf3d [path-to-map]
```

#### Example:
```
$ ./wolf3d maps/map24
```

A map cam be created by the user and used by following the same usage as above. In order ensure a valid map is created enter the following for usage:
```
$ ./wolf3d --help
```
![usage display](https://github.com/jdsmith022/Wolfenstein3D/blob/master/images/usage.png)


If incorrect parameters are given or the map is invalid, a usage error will be given. The user interface provides information for the use and exit of the program. 


To delete all object files from directory, run:
```
$ make clean
```
To delete executable and all object files from directory, run:
```
$ make fclean
```

### Gameplay:

Settings and options can be display by entering the following in command line:
```
$ ./wolf3d --settings
```
![settings display](https://github.com/jdsmith022/Wolfenstein3D/blob/master/images/settings.png)


### Collaborator
This project was a group effort with:
[Malou](https://github.com/mminkjan)
