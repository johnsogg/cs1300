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

