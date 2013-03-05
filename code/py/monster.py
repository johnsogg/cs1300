#
# monster.py
#
'''
This is an example of creating subclasses that specialize a base class
in a fairly simple way. The child classes only redefine the default
values for member variables like the number of hitpoints.

The base class contains the behaviors for attacking and taking damage.

There are four subclasses: a fluffy bunny, a slime, a dragon, and the
player. It may seem strange to make the player a subclass of Monster,
but this it actually makes a lot of sense. All of these things have
hitpoints, they all have names, and they can all engage in combat.

'''

class Monster():
    hitpoints = 10
    name = "Terrifying monster"
    attack_power = 4

    def attack(self, other):
        print self.name, "attacks", other.name
        other.take_damage(self.attack_power)

    def take_damage(self, dmg):
        self.hitpoints = self.hitpoints - dmg
        if self.hitpoints < 0:
            print "*****", self.name, "has been slain."
        else:
            print self.name, "takes", dmg, "damage"

class FluffyBunny(Monster):
    hitpoints = 5
    attack_power = 4
    name = "Cute and adorable fluffy bunny"

class Slime(Monster):
    hitpoints = 15
    attack_power = 7
    name = "Disgusting slime thing"

class Dragon(Monster):
    hitpoints = 1000
    attack_power = 15
    name = "Ancient and annoyed Dragon"

class Player(Monster):
    hitpoints = 60
    attack_power = 13
    name = "The hero"

# make a list of monsters for the player 
# to fight in mortal combat.
monsters = [Monster(), FluffyBunny(), 
            Slime(), Dragon()]

# make a special reference to our player
player = Player()

# now play until the player is eaten by a grue.
while True:

    # loop through monsters, let them attack player
    for m in monsters:
        m.attack(player)
        print player.name, "has", player.hitpoints, "hitpoints"
        # check after each attack if the player is still
        # alive and kicking. if not, quit the game.
        if player.hitpoints <= 0:
            exit(0)

    # give our hero a chance to attack all monsters
    for m in monsters:
        player.attack(m)
        # check if the monster is dead.
        # if it is remove it from the list.
        if m.hitpoints <= 0:
            monsters.remove(m)
