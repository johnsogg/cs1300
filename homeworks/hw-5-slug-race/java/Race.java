import java.util.Random;
import java.util.List;
import java.util.ArrayList;

public class Race {

    static Random rand = new Random(System.currentTimeMillis());
    List<Slug> slugs = new ArrayList<Slug>();
    int iteration = 0;

    /**
     * This 'uniform' function isn't available in Java, so I wrote my
     * own. Study it to see how it works.
     **/
    public static double uniform(double low, double high) {
	double range = high - low; 
	double r = rand.nextDouble();
	r = r * range;
	r = r + low;
	return r;
    }

    public static int randint(int low, int high) {
	int range = high - low;
	int r = rand.nextInt(range);
	r = r + low;
	return r;
    }

    public static String getSpaces(int howMany) {
	StringBuilder buf = new StringBuilder();
	for (int i=0; i < howMany; i++) {
	    buf.append(" ");
	}
	return buf.toString();
    }

    private double get_movement(double energy) {
	double third = energy / 3.0;
	double mv = Race.uniform(third - 0.5, third + 0.5);
	mv = Math.max(0, mv);
	mv = Math.min(10, mv);
	return mv;
    }

    private double get_slowdown(double energy) {
	double fifth = energy / 5.0;
	double sl = Race.uniform(fifth - 0.3, fifth + 0.3);
        sl = Math.max(0, sl);
        sl = Math.min(10, sl);
        return sl;
    }

    public void do_race() {
	Slug winner = null;
	List<Slug> removeUs = new ArrayList<Slug>();
	while (iteration < 200 && winner == null && slugs.size() > 0) {
	    iteration = iteration + 1; // could use iteration++ as well
	    for (Slug slug : slugs) {
		String icon = "*";
		boolean stop = false;
		if (slug.getHunger() <= 0) {
		    System.out.println("Slug starved to death :(");
		    removeUs.add(slug);
		    stop = true;
		}
		if (slug.getEnergy() <= 0) {
		    icon = "X";
		    stop = true;
		}
		if (slug.isNapping()) {
		    if (slug.whenIsNapOver() >= iteration) {
			slug.setNapping(false);
		    } else {
			stop = true;
		    }
		}
		if (!stop) {
		    Decision dec = slug.next_round();
		    if (dec == Decision.EAT) {
			slug.eat();
			icon = "E";
		    } else if (dec == Decision.REST) {
			slug.rest(iteration);
			icon = "R";
		    } else if (dec == Decision.MOVE) {
			double movement = get_movement(slug.getEnergy());
			double slowdown = get_slowdown(slug.getEnergy());
			slug.move(movement, slowdown);
		    }
		    if (slug.getPosition() > 100) {
			winner = slug;
			break;
		    }
		}
		if (slug.isNapping()) {
		    icon = "z";
		}
		if (!removeUs.contains(slug)) {
		    String pos = Race.getSpaces((int) slug.getPosition()) + icon;
		    System.out.println(iteration + "   " + pos);
		}
	    }
		slugs.removeAll(removeUs);
		removeUs.clear();
	}
	if (winner != null) {
	    System.out.println("Winner: " + winner + " in " + iteration + " iterations");
	} else {
	    System.out.println("There was no winner.");
	    System.out.println("Iteration: " + iteration);
	    System.out.println("# Slugs left: " + slugs.size());
	    System.out.println("Winner: " + winner);
	}
    }

    public static void main(String[] args) {
	Slug slug = new Slug("Barney");
	Race race = new Race();
	race.slugs.add(slug);
	race.do_race();
    }
}

/*
from slug import Slug
from decisions import Decisions
from random import uniform, randint

class Race:
    slugs = []
    iteration = 0

    def get_movement(self, energy):
        third = energy / 3.0
        mv = uniform (third - 0.5, third + 0.5)
        mv = max(0, mv)
        mv = min(10, mv)
        return mv

    def get_slowdown(self, energy):
        fifth = energy / 5.0
        sl = uniform (fifth - 0.3, fifth + 0.3)
        sl = max(0, sl)
        sl = min(10, sl)
        return sl
    
    def do_race(self):
        winner = None
        while self.iteration < 200 and winner is None and len(self.slugs) > 0:
            self.iteration = self.iteration + 1
            for slug in self.slugs:
                icon = "*"
                stop = False
                if slug.hunger <= 0:
                    print "Slug starved to death :("
                    self.slugs.remove(slug)
                    stop = True
                if slug.energy <= 0:
                    # print "Slug is exhausted."
                    icon = "X"
                    stop = True
                if slug.naptime:
                    if slug.naptime_over >= self.iteration:
                        slug.naptime = False
                    else:
                        stop = True
                if not stop:
                    dec = slug.next_round()
                    if dec == Decisions.EAT:
                        slug.hunger = slug.hunger + uniform(1.5, 3.0)
                        slug.energy = slug.energy + uniform(0.0, 0.5)
                        icon = "E"
                    elif dec == Decisions.REST:
                        slug.naptime = True
                        slug.naptime_over = self.iteration + randint(2,4)
                        slug.energy = 10.0
                        icon = "R"
                    elif dec == Decisions.MOVE:
                        slug.position = slug.position + self.get_movement(slug.energy)
                        slug.hunger = slug.hunger - uniform(0.25, 0.35)
                        slug.energy = slug.energy - self.get_slowdown(slug.energy)
                    else:
                        print "Slug is confused!"
                        icon = "?"
                    if slug.position > 100:
                        winner = slug
                        break
                if slug.naptime:
                    icon = "z"
                if self.slugs.count(slug):
                    pos = " " * int(slug.position) + icon
                    line = "{:<6} |" + pos
                    print line.format(self.iteration)
        if winner:
            print "Winner:", slug, "in", self.iteration, "iterations"
        else:
            print "There was no winner."
            print "Iteration:", self.iteration
            print "# Slugs left:", len(self.slugs)
            print "Winner:", winner

if __name__ == '__main__':
    slug = Slug("Barney")
    race = Race()
    race.slugs.append(slug)
    race.do_race()

*/
