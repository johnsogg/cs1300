import processing.core.*;
import java.util.List;
import java.util.ArrayList;

public class Lecture_25 extends PApplet {
    public static void main(String[] args) {
	PApplet.main(new String[] { "Lecture_25" });
    }

    int bg_count = 0;
    int bg_dir = 1;
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

	for (Ball b : ballList) {
	    b.draw();
	}
	// some draw methods associated with PApplet:
	// background(int)
	// stroke(int, int, int)
	// fill(int)
	// ellipse(x, y, radius_1, radius_2)
	// noFill()

	// text(str, x, y)
    }

}

class Ball {
    int ballX, ballY;
    Lecture_25 main;

    Ball(Lecture_25 main, int x, int y) {
	ballX = x;
	ballY = y;
	this.main = main;
    }

    void draw() {
	main.ellipse(this.ballX, ballY, 40, 40);
    }
}
