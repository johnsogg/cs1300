import processing.core.*;
import java.util.List;
import java.util.ArrayList;

// The goal in this lecture is to give the balls the ability to move
// around the screen based on context: where is the edge of the world?
// Where are other balls?
//
// How should a ball behave when it gets near another ball?
//
// Move away? Stand still to avoid a collision? Move towards it? Take
// no action?

public class Lecture_26 extends PApplet {
    public static void main(String[] args) {
	PApplet.main(new String[] { "Lecture_26" });
    }

    int bg_count = 0;
    int bg_dir = 1;
    // At the end of class last time, I created list list of balls to
    // contain an arbitrary number (including 0) of balls.
    List<Ball> ballList = new ArrayList<Ball>();
    
    /**
     * This is run ONE TIME ONLY.
     */
    public void setup() {
	size(800, 600);
	// other stuff.
    }

    public void mouseClicked() {
	System.out.println("You clicked at: " + mouseX + ", " + mouseY);
	Ball myNewBud = new Ball(this, mouseX, mouseY);
	ballList.add(myNewBud);
    }
    
    /**
     * The  draw()  function  runs  once  every  time  the  screen  is
     * drawn. Processing usually does this  on a repeating basis of 60
     * Hertz. That means it is called every 16 milliseconds.
     */
    public void draw() {
	background(bg_count); // set background to something
	bg_count = bg_count + bg_dir;
	if (bg_count >= 255) {
	    bg_dir = -1;
	} else if (bg_count <= 0) {
	    bg_count = 0;
	    bg_dir = 1;
	}

	fill(0, 64, 0);
	//    x     y   w     h
	rect(400, 300, 200, 100);

	fill(212, 111, 249);
	
	strokeWeight(4.0f);

	// for x in my_list:
	//    do_stuff(x)

	for (Ball b : ballList) {
	    for (Ball a : ballList) { // starbucks!
		if (b != a) {
		    float dist = b.dist(a);
		    if (dist < 300) {
			a.turnAround();
		    }
		}
	    }
	}

	for (Ball b : ballList) {
	    b.move();
	}

	for (Ball b : ballList) {
	    b.draw();
	}

	// some draw methods associated with PApplet:
	// background(int)
	// stroke(int, int, int)
	// fill(int)
	// ellipse(x, y, diam_1, diam_2)
	// noFill()

	// text(str, x, y)
    }

}

class Ball {
    float ballX, ballY;
    Lecture_26 main;
    float dx, dy;

    Ball(Lecture_26 main, int x, int y) {
	ballX = (float) x;
	ballY = (float) y;
	dy = 3f; // moves 3px per draw
	dx = 0.5f; // moves 0.5px per draw
	this.main = main;
    }

    //    a.turnAround();
    void turnAround() {
	System.out.println("Turning around! ew get away from me.");
	dx = -dx;
	dy = -dy;
    }

    // float dist = b.dist(a);
    float dist(Ball other) {
	// the current ball is 'this'
	// the other is sneakily named 'other'
	float delta_x = other.ballX - this.ballX;
	float delta_y = other.ballY - this.ballY;
	// pythagoras sez: x*x + y*y = dist*dist
	float xx = delta_x * delta_x;
	float yy = delta_y * delta_y;
	float sumsum = xx + yy; // dist squared
	float sum = (float) Math.sqrt(sumsum); // take square root of dist squared
	//	System.out.println("Distance: " + sum);
	return sum;
    }

    void move() {
	ballY = ballY + dy;
	ballX = ballX + dx;
	if (ballY > main.height && dy > 0) {
	    dy = -dy; // dy = -1f * dy
	}
	if (ballY < 0 && dy < 0) {
	    dy = -dy; // dy = -1f * dy
	}
	if (ballX > main.width && dx > 0) {
	    dx = -dx;
	}
	if (ballX < 0 && dx < 0) {
	    dx = -dx;
	}
    }

    void draw() {
	// ellipse: the last two params are the diam in x and y
	// dimensions
	main.ellipse(this.ballX, ballY, 40, 40);
	main.noFill();
	main.ellipse(this.ballX, ballY, 300, 300);
    }

}
