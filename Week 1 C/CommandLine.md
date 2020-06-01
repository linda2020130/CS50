## Using the Linux Command Line

These commands can be used on any UNIX-based operating system including Linux and Mac OS.

### ls

To **list** everything that exists in my current directory.

![ls](https://github.com/linda2020130/Notes_CS50/blob/master/Pictures/ls.PNG)

* Green -> executable file
* blue -> directory

<br />

### cd *directory*

Short for **change directory**, this command change your current directory to *directory*
* shorthand name for the current directory is `.`
* shorthand name for the parent directory of the current directory is `..`
* `pwd` short for present working directory; this tells you where you are.
* bring you back to the original place by just type in cd.

![cd](https://github.com/linda2020130/Notes_CS50/blob/master/Pictures/cd.PNG)

<br />

### mkdir *directory*

Short for **make directory**, this command will create a new directory called *directory* 
located in the current directory

![mkdir](https://github.com/linda2020130/Notes_CS50/blob/master/Pictures/mkdir.PNG)

<br />

### cp *source* *destination*

Short for **copy**, this command will allow you to create a dulplicate of the file you
specify as *source*, which it will save in *destination*.

* Use `cp -r <source directory> <destination directory>` to copy entire directories.
* `-r` means *recursive*, and tells `cp` to dive down into the directory and copy everything inside of it.

![cp](https://github.com/linda2020130/Notes_CS50/blob/master/Pictures/cp.PNG)

<br />

### rm *file*

Short for **remove**, this command will delete *file* after it asks you to confirm (y/n) you want to deleteit.

* You can skip the confirmation by typing `rm -f <file>`
* `-f` means *force*, and tells `rm` to remove without confirming again.
* To delete the entire directories you need to use `rm -r <directory>` (with confirmation) or `rm -rf <directory` (without confirmation).

~[rm](https://github.com/linda2020130/Notes_CS50/blob/master/Pictures/rm.PNG)

<br />

### mv *source* *destination*

Short for **move**, this command will allow you to effectively rename a file, moving it from *source* to *destination*.

![mv](https://github.com/linda2020130/Notes_CS50/blob/master/Pictures/mv.PNG)

