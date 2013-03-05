import java.util.ArrayList;

import processing.core.*;
import static processing.core.PApplet.sq;
import static processing.core.PApplet.sqrt;
import static processing.core.PApplet.PI;

public class Ball {

  Main p;
  float d;
  PVector loc;
  PVector vec;
  int hp;
  int redCollisions, blueCollisions;
  int anger = 0;
  int angerLimit = 50;
  boolean raging = false;
  int id;
  public static int ID_COUNTER = 0;

  public Ball(Main parent, float x, float y, float d) {
    this.hp = Math.min((int) d, 10);
    this.p = parent;
    this.loc = new PVector(x, y);
    this.d = d;
    this.vec = new PVector(p.random(-1.0f, 1.0f), p.random(-1.0f, 1.0f));
    vec.normalize();
    vec.mult(3f);
    id = ID_COUNTER++;
  }

  boolean angry() {
    return raging;
  }

  void collideInAnger(Ball other, ArrayList<Ball> addUs, ArrayList<Ball> removeUs) {
    anger += angerLimit;
    if (!angry() && anger > 2 * angerLimit) {
      raging = true;
    }
    if (angry() && anger < angerLimit) {
      raging = false;
    }
    if (angry()) {
      if (d < other.d) {
        absorb(other, removeUs);
      } else {
        PVector faultLine = new PVector(other.loc.x - loc.x, other.loc.y - loc.y);
        split(addUs, other, faultLine, false);
      }
      if (d > 60) {
        anger = 0;
      }
    }
  }

  /**
   * Move the ball according to the change vector. If it runs into the 'walls' then change the
   * direction vector accordingly. If it did bounce off a wall, return true.
   */
  boolean move() {
    boolean ret = false;
    vec.limit(10f);
    if (angry()) {
      vec.mult(1.01f);
    }
    loc.add(vec);
    float r = d / 2;
    float bot = p.height - r;
    float right = p.width - r;
    if (loc.y < r || loc.x < r || loc.y > bot || loc.x > right) {
      ret = true;
      if (loc.y < r && vec.y < 0) {
        vec.y = -vec.y;
      }
      if (loc.y > bot && vec.y > 0) {
        vec.y = -vec.y;
      }
      if (loc.x < r && vec.x < 0) {
        vec.x = -vec.x;
      }
      if (loc.x > right && vec.x > 0) {
        vec.x = -vec.x;
      }
    }
    if (anger > 0 && p.random(1.0f) > 0.05) {
      anger--;
      if (anger == 0) {
        raging = false;
      }
    }
    return ret;
  }

  float mass() {
    float r = d / 2;
    return PI * r * r;
  }

  int getArmorColor() {
    int ret = (int) ((((float) hp) / 20f) / 255f);
    if (ret < 0) {
      ret = 0;
    }
    return ret;
  }

  void draw() {
    p.fill(getColor());
    p.noStroke();
    p.ellipse(loc.x, loc.y, d, d);
    p.noFill();
    p.stroke(255, 255, 255);
    float w = p.min(hp, 5f) + 1f;
    p.strokeWeight(w);
    p.ellipse(loc.x, loc.y, d-(w/2f), d-(w/2f));
  }

  int getColor() {
    if (angry()) {
      return p.color(255, 165, 0);
    } else {
      int red = PApplet.min(redCollisions, 255);
      int blue = PApplet.min(blueCollisions, 255);
      int green = PApplet.min(128 + (hp * 10), 255);
      return p.color(red, green, blue);
    }
  }

  public float radius() {
    return d / 2;
  }

  boolean collide(Ball other) {
    float dist = other.loc.dist(loc);
    float thresh = other.radius() + radius();
    if (dist < thresh) {
      return true;
    } else {
      return false;
    }
  }

  public void collide(ArrayList<Ball> balls, ArrayList<Ball> collisions) {
    for (Ball other : balls) {
      if (other != this) {
        if (this.collide(other)) {
          collisions.add(other);
        }
      }
    }
  }

  public PVector bounce(Ball other) {
    PVector toOther = new PVector(other.loc.x - loc.x, other.loc.y - loc.y);
    PVector faultLine = toOther.get();
    toOther.normalize();
    other.vec.add(toOther);
    PVector fromOther = new PVector(-toOther.x, -toOther.y);
    vec.add(fromOther);
    return faultLine;
  }

  public void takeDamage() {
    if (p.random(1.0f) < 0.5f) {
      hp--;
    }
  }

  public void resolveCollision(Ball other, ArrayList<Ball> addUs, ArrayList<Ball> removeUs) {
    // the default behavior is just to bounce off
    PVector faultLine = bounce(other);
    takeDamage();
    if (other instanceof RedBall) {
      redCollisions++;
    } else if (other instanceof BlueBall) {
      blueCollisions++;
    }
    if (hp < 0) {
      split(addUs, other, faultLine, false);
      removeUs.add(this);
    }
  }

  void absorb(Ball other, ArrayList<Ball> removeUs) {
    if ((!other.angry() && d > other.d) || angry()) {
      float r1 = radius();
      float r2 = other.radius();
      float mass1 = PI * r1 * r1;
      float mass2 = PI * r2 * r2;
      PVector v1 = vec.get();
      v1.normalize();
      v1.mult(mass1);
      PVector v2 = other.vec.get();
      v2.normalize();
      v2.mult(mass2);
      float r3 = sqrt(sq(r1) + sq(r2));
      this.d = r3 * 2f;
      PVector v3 = v1.get();
      v3.add(v2);
      v3.normalize();
      this.vec = v3;
      removeUs.add(other);
      //      System.out.println(p.frameCount + " absorb");
    }
  }

  public void split(ArrayList<Ball> addUs, Ball other, PVector faultLine, boolean beGreen) {
    if (!other.angry()) {
      PVector toOther = new PVector(other.loc.x - loc.x, other.loc.y - loc.y);
      toOther.normalize();
      PVector fromOther = new PVector(-toOther.x, -toOther.y);
      fromOther.mult(vec.mag() * 0.5f);
      float r = radius();
      float newRad = sqrt(sq(r) / 2f);
      faultLine.normalize();
      faultLine.mult(newRad);
      PVector faultNorm1 = new PVector(-faultLine.y, faultLine.x);
      faultNorm1.mult(1.1f);
      PVector faultNorm2 = new PVector(faultLine.y, -faultLine.x);
      faultNorm2.mult(1.1f);
      Ball baby1 = null;
      Ball baby2 = null;
      if (beGreen) {
        //      System.out.println(p.frameCount + " split green.");
        baby1 = new Ball(p, loc.x + faultNorm1.x, loc.y + faultNorm1.y, newRad * 2f);
        baby2 = new Ball(p, loc.x + faultNorm2.x, loc.y + faultNorm2.y, newRad * 2f);
      } else if (redCollisions > blueCollisions) {
        //      System.out.println(p.frameCount + " split blue");
        baby1 = new BlueBall(p, loc.x + faultNorm1.x, loc.y + faultNorm1.y, newRad * 2f);
        baby2 = new BlueBall(p, loc.x + faultNorm2.x, loc.y + faultNorm2.y, newRad * 2f);
      } else if (blueCollisions > redCollisions) {
        //      System.out.println(p.frameCount + " split red");
        baby1 = new RedBall(p, loc.x + faultNorm1.x, loc.y + faultNorm1.y, newRad * 2f);
        baby2 = new RedBall(p, loc.x + faultNorm2.x, loc.y + faultNorm2.y, newRad * 2f);
      } else {
        //      System.out.println(p.frameCount + " split mixed");
        baby1 = new BlueBall(p, loc.x + faultNorm1.x, loc.y + faultNorm1.y, newRad * 2f);
        baby2 = new RedBall(p, loc.x + faultNorm2.x, loc.y + faultNorm2.y, newRad * 2f);
      }
      if (baby1 != null) {
        baby1.vec.add(fromOther);
        addUs.add(baby1);
      }
      if (baby2 != null) {
        baby2.vec.add(fromOther);
        addUs.add(baby2);
      }
    } else {
      System.out.println("can't split angry ball " + other.id);
    }

  }

  public String toString() {
    return "Ball[" + loc.x + ", " + loc.y + " heading " + vec.x + ", " + vec.y + "]";
  }

  public void damp() {
    if (vec.mag() > 20.0) {
      vec.mult(0.9999f);
    } else if (vec.mag() > 10.0) {
      vec.mult(0.999f);
    }
  }
  //
  //  public void increaseMass(float f) {
  //    float r = radius();
  //    float newRad = sqrt(r * r * f);
  //    System.out.println("Pumping up radius from " + r + " to " + newRad);
  //    d = newRad * 2f;
  //  }

  public void updateHeading(ArrayList<Ball> others) {
    // no effect for green balls.
  }

}
