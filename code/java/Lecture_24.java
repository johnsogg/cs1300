import processing.core.*;

public class Lecture_24 extends PApplet {
    public static void main(String[] args) {
	PApplet.main(new String[] { "Lecture_24" });
    }

    /**
     * This is run ONE TIME ONLY.
     */
    public void setup() {
	size(800, 600);
	// other stuff.
    }

    /**
     * The  draw()  function  runs  once  every  time  the  screen  is
     * drawn. Processing usually does this  on a repeating basis of 60
     * Hertz. That means it is called every 16 milliseconds.
     */
    public void draw() {
	background(70, 70, 70); // set background to something
	fill(0, 64, 0);
	//    x     y   w     h
	rect(400, 300, 200, 100);

	fill(212, 111, 249);
	
	strokeWeight(4.0f);

	//       x    y   r1   r2
	ellipse(400, 300, 100, 100);

	// some draw methods associated with PApplet:
	// background(int)
	// stroke(int, int, int)
	// fill(int)
	// ellipse(x, y, radius_1, radius_2)
	// noFill()

	// text(str, x, y)
    }

}
