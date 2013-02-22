'''
Define a new class that represents a Candle. The candle's member
variables should be lit (a boolean that is false by default), and
remaining_wax (a floating point value that is 4.0 by default). It
should have a method called glimmer that prints out one of the
following: "Oooh shiny" if it is currently lit, or "Boring!" if it is
not lit. Every time 'glimmer' is called when the candle is lit, it
should reduce the amount of remaining wax by 0.1. When the wax hits or
dips below 0, we should extinguish the candle.
'''
class Candle:
    lit = False
    remaining_wax = 4.0

    def glimmer(self):
        if self.lit:
            print "Oooh, shiny"
            self.remaining_wax = self.remaining_wax - 0.1
        else:
            print "Boring!"

        if self.remaining_wax <= 0:
            self.lit = False


candle = Candle()
candle.lit = True
iteration = 1
while candle.lit:
    print "Iteration", iteration, "remaining wax:", candle.remaining_wax
    iteration = iteration + 1
    candle.glimmer()
candle.glimmer()

print ""
print 80 * "-"
print ""

class House:
    num_bedrooms = 2
    num_baths = 3

    def __init__(self, br, bath):
        self.num_bedrooms = br
        self.num_baths = bath
    
    def throw_raging_party(self):
        print "Yay! Partay!"

    def clean_rooms(self):
        num_cleaned = self.num_bedrooms + self.num_baths
        return num_cleaned

my_house = House(3, 4)
your_house = House(6, 8)
your_house.clean_rooms()
my_house.throw_raging_party()

print type(House)
print type(my_house)
print type(my_house.throw_raging_party())
print my_house.throw_raging_party()
print type(your_house.clean_rooms())
print your_house.clean_rooms()



