Linked Lists (as a C++ class)
==========

In the last assignment, we implemented linked lists as a series of
functions, where the list itself was passed in with a pointer. In this
assignment we will implement linked lists again, but this time as a
C++ class.

A `class` in C++ is similar to a `struct`. They both have a bunch of
members, including data and functions. These two things are so similar
that for the moment you can treat them as the same thing.

_Classes give you additional abilities that structs do not, but we
will not use those abilities here. If you take a software engineering
course you will learn those concepts._

A C++ class is a lot like classes in Python and Java: they provide a
blueprint for making things. We've seen the `burrito` struct:

	struct burrito {
		float cheese;
		float veggies;
		float steak;
		// and so on
	};
	
We can make different burritos that contain different amounts of these
ingredients. The struct just provides a way to make compound things
with named sub-parts. A class works the same way.

Unlike Java and Python, a C++ class is broken into two parts: the
class definition and the implementation. The definition is typically
found in a header file, but it could be in an implementation file. The
important thing is that the compiler knows about the definition before
it encounters implementations. So: put your class definition before
the implmentation. Really, just use a header file :)

A _class definition_ for a rectangle with width, height, and
coordinates for the top left corner might look like this:

	class Rectangle {
	private:
		float x;
		float y;
		float width;
		float height;
	public:
		Rectangle(float initial_x, float initial_y);
		void setSize(float width, float height);
		float getWidth();
		float getHeight();
		float getX();
		float getY();
	}; // semicolon is needed

This specifies a bunch of fields (the four floating point variables at
the top) and several functions, like the constructor `Rectangle(float,
float)` and `setSize(float, float)`.

This is telling the compiler:

	Dear Compiler,

	There is a class called `Rectangle` that has four floating point
	numbers called x, y, width, and height. But those are my private
	property and you should not let anybody else read or write
	them. I'm serious.

	There are six functions whose implementations can access my
	private data, though. These are the constructor, setSize, getWidth
	and Height, and getX and Y. Somebody else will tell you what these
	things specifically do.

	Love, 

	The Programmer.

To give those functions definitions, you have to write code that obeys
the function signatures, in that class's _namespace_. The namespace
has the same name as the class (in this case, `Rectangle`). Here is a
definition of the `setSize(float, float)` function:

	void Rectangle::setSize(float monkey, float peanut) {
		width = monkey;
		height = peanut;
	} // note: no semicolon needed here.
	
Those silly variable names `monkey` and `peanut` were chosen to for
two reasons. First: we can name those parameters anything we
want. They don't have to match what the class definition said they
were called. Second: if we named them `width` and `height` like the
class definition suggests, we would have a problem because our input
parameters are the same as the object's width and height fields.

We can overcome this with the cunning use of `this`. `this` is a
special variable available in all object's functions. It is a pointer
to the particular object that the function was called on. In this case
it is a `Rectangle*` that refers to the specific rectangle:

	void Rectangle::setSize(float width, float height) {
		this->width = width; // 'this->width' means the class's member
		                     // 'width' by itself means the input param
		this->height = height;
	}

The implementation for the LinkedList functions like `size` and
`insert` will be almost identical to the versions you just made. The
only difference is that these functions do not receive an explicit
`node*` or `node**` as a parameter. Instead, you should use the
LinkedLists's `head` variable, which is of type `Node*`.
