import processing.core.*;

public class Lecture23_2 extends PApplet {
    public static void main(String[] args) {
	PApplet.main(new String[] { "Lecture23_2" });
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
	background(255, 0, 0); // set background to black
	fill(0, 0, 255);
	rect(400, 300, 200, 100);
	fill(0, 255, 255);
	ellipse(400, 300, 50, 100);
	// some draw methods associated with PApplet:
	// background(int)
	// stroke(int, int, int)
	// fill(int)
	// ellipse(x, y, radius_1, radius_2)
	// noFill()
	// strokeWeight(float)
	// text(str, x, y)
    }

}
