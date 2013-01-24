Hello World
======

"Hello World" is the name we traditionally give to the first program
we write when learning a new programming language. It is the simplest
program imaginable: all it does is displays "Hello World" to the
console.

We don't do this because it is interesting. We do this to demonstrate
that the programming environment is set up correctly, and to convince
ourselves that we can write a program. (Even if that program is very
simple.)

Python
--------

Here is the entire program:

	# this is the Hello World program in Python
	print("Hello, World!")
	
That's it.

Typing that program is not the tricky part. The tricky part is getting
the Python interpreter to run it. 

Lets say that you've saved the above Python program in a file named
"hello.py". From you command line, go to the directory where hello.py
is, and type 'python hello.py'. Like this:

	$ python hello.py

If it prints "Hello World" to the console, everything is working fine.

_(By the way, the dollar sign up there is the conventional way to
indicate the command is typed into the command line interface. Don't
actually type the dollar sign.)_

But what if the program doesn't run?

You might get an error that looks like this:

	-bash: python: command not found
	
If that's the case, it means that Python is either not installed, or
the shell doesn't know where it is. If you are using the VirtualBox
environment, Python should work right away. If you _aren't_ using
VirtBox, unfortunately you are on your own because we can't do tech
support for 500 of you. If you come to the CSEL one of the LAs or TAs
might be around and have a quick fix, though.

Another way of running a python script is to make it executable. There
are two parts to this. First, you have to add the following code _to
the very top of your Python program_ so the whole file looks like
this:

	#!/usr/bin/env python
	print("Hello, World!")

Second, you have to use the command line to change the _mode_ of the
file so that it is executable. This is the command:

	$ chmod +x hello.py

Then you can run the program like this:

	$ ./hello.py

It should print "Hello World!" to the console.

Notice the funny "./" syntax up there. It is needed because the shell
(by default) won't execute programs that are in the current
directory. This is a security precaution. When you type "./" it forces
the shell to look in the directory called ".", which is a special name
for the directory you are in right now.

Go ahead and play around with the print command. You can have your
computer print out pleasant greetings to you by name. Or you can make
your computer print out an expletive-laden rant about your 1300
teacher. 

Java
-------

For Java, there are three requirements:

1. You create a plain text file written in java. For the assignment,
you save this as `hello.java`, and the file must contain the
definition for a single public class called 'hello'. The main()
function simply uses System.out.println("Hello World") to print text
to the console.

1. You give this java source file to the Java compiler. To run the
compiler with your source file, you cd into the directory where your
file is, and type `javac hello.java`.

1. If successful, the compiler creates an output file called a 'class
file', and it will be named `hello.class`. To run this, you give the
Java interpreter the name of a class (note: this is the name of the
class, not the name of the class _file_). Run this from the same
directory as above by typing `java hello`. You will see "Hello World"
appear on the screen.

Turn in the homework by uploading hello.java.

I am intentionally leaving these instructions vague because I expect
you to learn how to learn how to program. Yes, I just said "learn how
to learn how to". That is not a typo :)

C++
------

The requirements for C++ are similar. Make a plain text file written
in C++ and name it 'hello.cpp'. Like Java, you must first _compile_
your C++ program using a compiler. Using the VM (or any Linux
distribution, or on a Mac with the developer utils installed (please
read about these in Learn C The Hard Way)) you compile your source
program like this:

	g++ -o hello hello.cpp
	
This may translate into Victorian English as the following:

"Dear C++ compiler whose name is `g++`, please kindly compile the source
file named `hello.cpp` and output an executable whose name is
`hello`."

The output file is directly executable by the operating system. This
_differs_ from Java. Java uses a virtual machine to translate Java
bytecode into machine instructions. With C++, the binary sitting in
`hello` already contains machine code that can be executed right away.

You may run your executable file by typing __exactly__ the following:

	./hello

The dot-slash characters are vitally important. The dot means 'the
current directory', the slash is a path separator, and the rest is the
name of the file you want to run. This is necessary because `hello` is
not in your shell's search path. (And _search path_ is a topic beyond
this assignment, but it would serve you well to learn about what $PATH
is.)

Submit your source file, `hello.cpp`. _Pro tip: You will never need to submit
anything other that source files, in any language._

Again, I am leaving it vague about how to do this, because a primary
skill in computer programming is being able to quickly learn new tools
and technologies---including programming languages.

Turning In Your Homework
=========

__For your homework, the only requirement is that it outputs text to
the console.__

To turn in your assignment, you will use the RetroGrade
system. You may log in to RetroGrade at the following URL:

[http://retrograde.cs.colorado.edu/](http://retrograde.cs.colorado.edu/)

In order for the grading system to work, you will need to make sure
your file is named correctly. You can turn your homework in using
whichever programming language you want. The file names that we accept
are:

- For __Python__: hello.py
- For __C++__: hello.cpp
- For __Java__: hello.java

We've provided simple files with these names. These files contain only
comments. Your job is to write the code that prints stuff to the
console.

Note: only turn in one programming language file at a time. 
