class Person:
    first_name = "??"
    last_name = "??"

    def __init__(self, first, last):
        self.first_name = first
        self.last_name = last

    def __str__(self):
        return self.first_name + " " + self.last_name

class Phone:
    model = "Unknown Phone"
    ring_tone = "Brrrrrrrring..."
    weight = 8
    # dictionary of names and phone numbers
    contacts = { }
    # owner is initially None.
    owner = None

    def ring(self):
        print ring_tone

    # name is a person's name (string)
    # phone_number is an integer
    def add_contact(self, name, phone_number):
        if self.contacts.has_key(name):
            print "Overwriting phone number for '" + name + "'"
        self.contacts[name] = phone_number
        print "Set phone number: " + name + " = " + str(phone_number)
    
    def has_owner(self):
        return owner is not None


bob = Person("Bob", "Johnson")
print bob
