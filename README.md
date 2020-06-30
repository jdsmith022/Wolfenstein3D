# Wolfenstein3D

## Codam Coding College project Wolf3D

![Demo of 42.fdf](https://github.com/jdsmith022/fdf_/blob/master/pictures/fdf.gif)

### Description
This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research, data mining etc. As a graphic design project, Wolf3D will enable you to solidify your skills in this area: windows, colors, events, fill shapes etc.

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
![ls-la display](https://github.com/jdsmith022/fdf_/blob/master/pictures/ls-la.png)

However, a relief map from the local computer can be used as long as the path to the file is given as parameter.
```
$ ./wolf3d [path-to-map]
```

#### Example:
```
$ ./wolf3d maps/map24
```

As a bonus feature, the program can take color as parameter from the map file. The largest maps, julia.fdf and fractol.fdf, have this feature and, as a result, takes longer to process. If color is given with map, colors cannot be changed via the user interface.

If incorrect parameters are given or the map is invalid, a usage error will be given. The user interface provides information for the use and exit of the program. 


To delete all object files from directory, run:
```
$ make clean
```
To delete executable and all object files from directory, run:
```
$ make fclean
```


### Collaborator
This project was a group effort with:
[Malou](https://github.com/mminkjan)
