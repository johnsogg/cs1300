public abstract class BaseSlug {
    private double hunger = 5.0;
    private double energy = 5.0;
    private String name = "Slug";
    private double position = 0d;
    private boolean naptime = false;
    private int naptime_over = 0;

    public BaseSlug(String name) {
	this.name = name;
    }

    public String toString() {
	return name;
    }

    public abstract Decision next_round();

    public final double getHunger() {
	return hunger;
    }

    public final double getEnergy() {
	return energy;
    }

    public final boolean isNapping() {
	return naptime;
    }

    public final void setNapping(boolean v) {
	naptime = v;
    }

    public final int whenIsNapOver() {
	return naptime_over;
    }

    public final void eat() {
	hunger = hunger + Race.uniform(1.5, 3.0);
	energy = energy + Race.uniform(0.0, 0.5);
    }

    public final void rest(int currentIteration) {
	naptime = true;
	naptime_over = currentIteration + Race.randint(2,4);
	energy = 10.0;
    }

    public final void move(double movement, double slowdown) {
	position = position + movement;
	hunger = hunger - Race.uniform(0.25, 0.35);
	energy = energy - slowdown;
    }

    public final double getPosition() {
	return position;
    }

}

