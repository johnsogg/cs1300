Cellular Automata
===========

Cellular Automata are a fun way to make code seem _alive_. You can use
this approach to generate graphics or model natural phenomena. The
word _Cellular_ refers to how the data are stored: in discrete
cells. We'll model this using arrays (like Java's `String[]` we
learned about recently, or Python's built in lists). The word
_Automata_ refers to the apparently self-running nature of these
things. Given a set of rules, a well-defined cellular automaton will
run forever. (At least, until you hit Control C).

We'll look at cellular automata that are based on _discrete values_,
and on _discrete time steps_. There are other kinds based on continues
values and time, but those are trickier (though they would form the
basis for a rad 1300 project after spring break).

Some cellular automata are one-dimensional, meaning we can reference
any cell with a single variable (and since we're using discrete cells,
we'll use an integer to index them.) Here's a cellular automaton state
represented with a Java character array:

	// indices -->           0    1    2    3    4    5    6    7    8    9    10   11   12   13
	char[] initialState = { '*', '.', '*', '*', '.', '.', '*', '*', '.', '*', '.', '.', '.', '*' };

The cool thing about automata is that they evolve, based on a series
of _rules_, and on previous state. A rule tells us what the next state
should be, depending on what previous state was. For example, we could
have the rule that says if the previous state was `*`, the next state
should be `.`, and vice-versa. Here's that rule in Java syntax:

	// states may be '*' or '.' only
	if (previousState[i] == '*') {
	  nextState[i] = '.';
	} else {
	  nextState[i] = '*';
	}

That rule used an index `i` to look at the previous state at that
index and to set the next state's value for that index. This means
that if our previous state's cell 6 was `*`, that means our next cell
6 state will be `.`. The values we examine to determine our next state
is called the _neighborhood_. In this first case, it is a small
neighborhood of one. But we could have bigger neighborhoods by looking
at more nearby cells.

A larger neighborhood may look at cells `i-1`, `i`, and `i+1`. A
complete rule set for this neighborhood of 3 members might look
something like this, using pseudocode:

	input   output
	--------------
	...   ->   *
	..*   ->   .
	.*.   ->   *
	.**   ->   .
	*..   ->   *
	*.*   ->   .
	**.   ->   .
	***   ->   *

I don't actually know what kind of visual output this ruleset might
produce (I just made it up). You can play around with different
rulesets to get different results. Some of them are pretty
amazing. Read the [http://en.wikipedia.org/wiki/Rule_90](Wikipedia
Page on _Rule 90_) for a pattern that generates pretty sweet geometry.

Here's the Java syntax for checking the first couple rules. You can
see the pattern and go from there.

	if (previousState[i-1] == '.' && previousState[i] == '.' && previousState[i+1] == '.') {
		nextState[i] = '*';
	} else if (previousState[i-1] == '.' && previousState[i] == '.' && previousState[i+1] == '*') {
		nextState[i] = '.';
	} else ... // and so on.

In general, the algorithm for running a cellular automaton involves
(1) making an initial state; (2) setting up the rules, either in a map
or using if-statements like the above, (3) running a loop, (4), inside
the loop, looking at prior (or initial) state to determine the next
state, and (5) remembering prior state for the next round of the loop.

Here's pseudo-code of that algorithm:

	rules = (some mapping of rules like "... --> *")
	initial = ".***.*...*...."
	prev = initial
	loop 1000 times:
	  next_state = empty array that is the same size as prev
	  for each cell i in prev:
		  current_pattern = neighborhood in prev surrounding i
		  next_state[i] = rules[current_pattern]
	   print next_state to screen
	   prior = next_state

Some Common Problems
--------

What should you do if you are at index `i=0`? Your neighborhood is now
`-1, 0, 1`, and you can't index negative numbers in an array (at
least, not in Java). There are at least three solutions.

1. Don't even check the pattern for indices at the edges. Just repeat
whatever the previous value was.

2. Check the patterns at the edges but use some other value for the
values that are out of bounds. E.g. you might use `prev[0], prev[0],
prev[1]`. Or you might assume that all out of bounds values are the
same, either `*` or `.`.

3. You could _wrap around_ so that instead trying to look at
`prev[-1]` (which doesn't exist and would give you an error), you
could instead use `prev[prev.length-1]`. This means to index the last
item in the array.

I gave examples for what to do on the left boundary, where `i=0`, and
there is a corresponding solution for the other side, where `i=N`,
assuming `N` is the largest addressable index in the array.

Sierpinsky Triangle Output (Rule 90)
---------

You can make the following graphic output using a 3-neighbor rule set
with a one-dimensional cellular automata. Cells have two states, '*'
and ' ' (space character).


										*                                   
									   * *                                  
									  *   *                                 
									 * * * *                                
									*       *                               
								   * *     * *                              
								  *   *   *   *                             
								 * * * * * * * *                            
								*               *                           
							   * *             * *                          
							  *   *           *   *                         
							 * * * *         * * * *                        
							*       *       *       *                       
						   * *     * *     * *     * *                      
						  *   *   *   *   *   *   *   *                     
						 * * * * * * * * * * * * * * * *                    
						*                               *                   
					   * *                             * *                  
					  *   *                           *   *                 
					 * * * *                         * * * *                
					*       *                       *       *               
				   * *     * *                     * *     * *              
				  *   *   *   *                   *   *   *   *             
				 * * * * * * * *                 * * * * * * * *            
				*               *               *               *           
			   * *             * *             * *             * *          
			  *   *           *   *           *   *           *   *         
			 * * * *         * * * *         * * * *         * * * *        
			*       *       *       *       *       *       *       *       
		   * *     * *     * *     * *     * *     * *     * *     * *      
		  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *     
		 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *    
		*                                                               *   
	   * *                                                             * *  
	  *   *                                                           *   * 
	 * * * *                                                         * * *  
			*                                                       *     * 
		   * *                                                     * *   *  
		  *   *                                                   *   * * * 
		 * * * *                                                 * * *      
		*       *                                               *     *     
	   * *     * *                                             * *   * *    
	  *   *   *   *                                           *   * *   *   
	 * * * * * * * *                                         * * *   * * *  
					*                                       *     * *     * 
				   * *                                     * *   *   *   *  
				  *   *                                   *   * * * * * * * 
				 * * * *                                 * * *              
				*       *                               *     *             
			   * *     * *                             * *   * *            
			  *   *   *   *                           *   * *   *           
			 * * * * * * * *                         * * *   * * *          
			*               *                       *     * *     *         
		   * *             * *                     * *   *   *   * *        
		  *   *           *   *                   *   * * * * * *   *       
		 * * * *         * * * *                 * * *           * * *      
		*       *       *       *               *     *         *     *     
	   * *     * *     * *     * *             * *   * *       * *   * *    
	  *   *   *   *   *   *   *   *           *   * *   *     *   * *   *   
	 * * * * * * * * * * * * * * * *         * * *   * * *   * * *   * * *  
									*       *     * *     * *     * *     * 
								   * *     * *   *   *   *   *   *   *   *  
								  *   *   *   * * * * * * * * * * * * * * * 
								 * * * * * * *                              

