import java.util.ArrayList;

import processing.core.PVector;

public class RedBall extends Ball {

  public RedBall(Main parent, float x, float y, float d) {
    super(parent, x, y, d);
  }

  int getColor() {
    if (angry()) {
      return p.color(255, 165, 0);
    } else {
      return p.color(255, 0, 0);
    }
  }

  public void resolveCollision(Ball other, ArrayList<Ball> addUs, ArrayList<Ball> removeUs) {
    PVector faultLine = bounce(other);
    if (p.random(1.0f) < 0.5f) {
      hp--;
    }
    if (other instanceof RedBall) {
      absorb(other, removeUs);
    } else if (other instanceof RedBall && d < other.d) {
      collideInAnger(other, addUs, removeUs);
    }
    if (hp < 0) {
      split(addUs, other, faultLine, (d > p.initialBallRadius));
      removeUs.add(this);
    }
  }

  @Override
  public void updateHeading(ArrayList<Ball> others) {
    float bestDist = Float.MAX_VALUE;
    Ball bestBall = null;
    for (Ball b : others) {
      if (b != this && b instanceof BlueBall) {
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
      // red balls hunt
      toOther.normalize();
      toOther.mult(0.1f);
      float speed = vec.mag();
      vec.add(toOther);
      vec.normalize();
      vec.mult(speed);
    }
  }
}
