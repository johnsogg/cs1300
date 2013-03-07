// This is the file that runs the bouncy ball app.
// Just run this with 'java -classpath core.jar:. Main'

import java.util.ArrayList;

import processing.core.*;

public class Main extends PApplet {

  ArrayList<Ball> balls;
  ArrayList<Ball> collisions;
  ArrayList<Ball> removeUs;
  ArrayList<Ball> addUs;
  float targetMass;
  float lastMass = 0;
  float initialBallRadius = 35f;
  
  public static void main(String args[]) {
    PApplet.main(new String[] { "Main" });
  }

  public void setup() {
    size(800, 600);
    smooth();
    float r = initialBallRadius;
    balls = new ArrayList<Ball>();
    collisions = new ArrayList<Ball>();
    removeUs = new ArrayList<Ball>();
    addUs = new ArrayList<Ball>();
    int numInitialBalls = 4;
    int gridSpaces = (int) sqrt(numInitialBalls);
    for (int i = 1; i <= gridSpaces; i++) {
      for (int j = 1; j <= gridSpaces; j++) {
        int xLoc = i * (width / (gridSpaces + 1));
        int yLoc = j * (height / (gridSpaces + 1));
        balls.add(new Ball(this, xLoc, yLoc, 2 * r));
      }
    }
    targetMass = 4 * r * r * PI;
  }

  public void draw() {
    background(0);
    removeUs.clear();
    addUs.clear();
    for (Ball b : balls) {
      if (!removeUs.contains(b)) {
        collisions.clear();
        b.move();
        b.draw();
        b.collide(balls, collisions);
        for (Ball other : collisions) {
          b.resolveCollision(other, addUs, removeUs);
        }
      }
    }
    balls.removeAll(removeUs);
    for (Ball addMe : addUs) {
      if (balls.size() < 100) {
        balls.add(addMe);
      }
    }
    for (int i=0; i < balls.size(); i++) {
      balls.get(i).updateHeading(balls);
    }
    if (random(1.0f) < 0.001f) {
      System.out.println("Somebody is going to rage!");
      Ball smallest = null;
      float smallestD = Float.MAX_VALUE;
      for (Ball b : balls) {
        if (b.d < smallestD) {
          smallest = b;
          smallestD = b.d;
        }
      }
      if (smallest != null) {
        System.out.println("Sending ball " + smallest.id + " into a rage");
        smallest.anger = 3 * smallest.angerLimit;
        smallest.raging = true;
      }
    }
  }
}
