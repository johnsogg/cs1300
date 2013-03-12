Cellular Automata (Java)
==========

To compile and your Automata class, simply use:

	javac Automata.java
	java Automata
	
If you'd like to run the unit tests (and I highly recommend this), you
must also have `junit.jar` and the `RetroPrinter.java` and
`TestAutomata.java` files. Then compile like this on Linux and OSX:

	javac -classpath junit.jar:. *.java
	java -classpath junit.jar:. TestAutomata

__On Windows__ (and this is the case generally) you have to use the
semicolon character `;` rather than the colon character `:` in the
path separator. So on Windows, the above becomes:

	javac -classpath junit.jar;. *.java
	java -classpath junit.jar;. TestAutomata
