from decisions import Decisions

class BaseSlug:

    hunger = 5.0 # Ranges from 0.0 (starved) to 10.0 (full)
    energy = 5.0 # Ranges from 0.0 (exhausted) to 10.0 (peppy)

    name = "Slug"
    position = 0 # Ranges from 0 (start) to 100 (finish line)
    naptime = False  # Is True if we're sleeping
    naptime_over = 0 # Set to iteration number that we wake up

    def __init__(self, name):
        self.name = name

    def __str__(self):
        return self.name

    def next_round(self):
        return Decisions.MOVE


