import java.util.ArrayList;

import processing.core.PApplet;
import processing.core.PVector;

public class BlueBall extends Ball {

  public BlueBall(Main parent, float x, float y, float d) {
    super(parent, x, y, d);
  }

  int getColor() {
    if (angry()) {
      return p.color(255, 165, 0);
    } else {
      return p.color(0, 0, 255);
    }
  }

  public void resolveCollision(Ball other, ArrayList<Ball> addUs, ArrayList<Ball> removeUs) {
    // the default behavior is just to bounce off
    PVector faultLine = bounce(other);
    if (p.random(1.0f) < 0.5f) {
      hp--;
    }
    if (other instanceof BlueBall) {
      absorb(other, removeUs);
    } else if (other instanceof RedBall && d < other.d) {
      collideInAnger(other, addUs, removeUs);
    }
    if (hp < 0) {
      split(addUs, other, faultLine, (d > p.initialBallRadius));
      removeUs.add(this);
    }
  }

  int getArmorColor() {
    return 128;
  }

  public void updateHeading(ArrayList<Ball> others) {
    float bestDist = Float.MAX_VALUE;
    Ball bestBall = null;
    for (Ball b : others) {
      if (b != this && b instanceof RedBall) {
        PVector toOther = new PVector(b.loc.x - loc.x, b.loc.y - loc.y);
        float toOtherDist = toOther.mag();
        if (toOtherDist < bestDist) {
          bestDist = toOtherDist;
          bestBall = b;
        }
      }
    }
    if (bestBall != null && bestDist < (p.initialBallRadius * 3)) {
      PVector toOther = new PVector(bestBall.loc.x - loc.x, bestBall.loc.y - loc.y);
      // blue balls avoid
      PVector avoid = new PVector(-toOther.x, -toOther.y);
      avoid.normalize();
      avoid.mult(0.3f);
      float speed = vec.mag();
      vec.add(avoid);
      vec.normalize();
      vec.mult(speed);
    }
  }
}
