#
#  automata.py
#
# See the README.md in the homework directory.

# Your Name:

# Your Collaborators:

# There are several methods for you to implement below. They are
# indicated with IMPLEMENT THIS METHOD. Instructions are embedded
# within. Happy hacking!

import sys

class Automata:

    def __init__(self):
	# create a new Map that relates String keys to char
	# values. then assign it to the object's "rules" member
	# variable.
	self.rules = { } # string to char

        # The 'prev' member in the Python version is a string. This is
        # different from the Java version. In Python you can address
        # individual characters just like you do with lists. If foo =
        # 'hello', then foo[2] is 'l', and len(foo) is 5.
        self.prev = None
        
    def addRule(self, pattern, output):
        # Associate this pattern with an output char. 
        self.rules[pattern] = output

    def applyRule(self, pat):
	# this is done for you.
	ret = '?'
	if not self.rules.has_key(pat):
	    print "Warning: the rule map does not have a key '" + pat + "'"
        else:
	    ret = self.rules[pat]
	return ret

    def printPrev(self):
	# This is done for you. It prints the previous state.
	if self.prev is None:
	    print "No data. Get to work!"
	else:
	    for c in self.prev:
		sys.stdout.write(c)
	    print

    def setInitialPattern(self, input_pattern):
	# IMPLEMENT THIS METHOD.

	# Instructions: You are given a String, and you need to
	# initialize 'prev', which is a string. In Python this is easy
	# (one line!)
        pass


    def run(self, iterations):
	# IMPLEMENT THIS METHOD.

	# Write a loop that runs the specified number of times, and
	# each time through the loop it does two things: (1) calls
	# the 'cycle' method, and (2) calls the 'printPrev()' method.
        pass


    def cycle(self):
	# IMPLEMENT THIS METHOD.

	# This method advances the automaton's life cycle by one
	# stage. The previous state of the automaton is described by
	# the 'prev' string. The goal here is to create a different
	# string that represents the next cycle of the automaton's
	# evolution. Iterate through each character in 'prev' using:
        #
        # for i in range(len(prev)):
        #      <code>
        #
	# and calculate the next state, and store it in some character
	# array that you initialize here.
	#
	# To do this correctly, you should implement and use the
	# 'getPattern(int)' and use the 'applyRule' method that is
	# already defined for you to get the output. If the pattern
	# isn't known it will output a warning message. 
        pass

    def getPattern(self, idx):
	# IMPLEMENT THIS METHOD.

	# Using the index provided, look in the 'prev' string and
	# create a new String based on what you find there in the
	# 3-member neighborhood of idx. Then return that String.
	#
	# If idx is 0, the return string should use prev[prev.length -
	# 1], prev[0], and prev[1] combined.
	#
	# if idx is prev.length-1 (the last indexable cell): prev[idx
	# - 1], prev[idx], prev[0]
	#
	# otherwise the return value should use idx-1, idx, and idx+1.
        pass

if __name__ == "__main__":
    '''
    This is a main function that runs if we happen to run the Automata
    class. This is *not* what RetroGrade uses. It is here for you to
    test things out on your own.
    '''
    
    # pattern #1 is small and can be used for testing.
    PATTERN_1 = "  *    *  *      *  *      *";
    # if you use PATTERN_2, you'll think there's a bug. There isn't :)
    PATTERN_2 = " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
    # this is a good starting point for a 'pure' Sierpinksi triangle
    PATTERN_3 = "                                 *                                                            ";

    grover = Automata()

    # Add simple rules. Note that "x" is a string, but 'x' is a
    # char. The type of quote matters. Feel free to change these. The
    # default values I'm giving you are the ones for the Sierinski
    # triangle (read the wikipedia page for 'Rule 90') if you want to
    # see why this works.
    grover.addRule("***", ' ')
    grover.addRule("** ", '*')
    grover.addRule("* *", ' ')
    grover.addRule("*  ", '*')
    grover.addRule(" **", '*')
    grover.addRule(" * ", ' ')
    grover.addRule("  *", '*')
    grover.addRule("   ", ' ')

    # Give grover a starting pattern.
    pat = PATTERN_1 # change to 1, 2, 3, or your own.
    grover.setInitialPattern(pat)
    
    # Now that we have a rule set and an initial pattern, we can
    # tell grover to print out the initial state and then iterate
    # through some number of cycles.
    grover.printPrev()
    grover.run(len(pat)) # square pattern
    
    
