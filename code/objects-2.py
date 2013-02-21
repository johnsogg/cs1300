class Dog:
    age = 0
    name = "Default"
    fr1 = None
    fr2 = None
    def get_older(self):
        if self.fr1.age > self.fr2.age:
            return self.fr1
        else:
            return self.fr2
    def bark(self):
        print self.name, "barks! Woof."
        print self.name + " awwwooooooooo"

sputnik = Dog()
sparky = Dog()
sparky.name = "Sparky" # one way to access
sputnik.fr1 = sparky # another
fido = Dog()
fido.name = "Fido"
sputnik.fr2 = fido

sputnik.fr1.age = 5 # and another
sputnik.fr2.age = 8

old = sputnik.get_older()
# old is now fr2
old.bark()
