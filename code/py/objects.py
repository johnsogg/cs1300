class Phone:
    vendor = "Unknown"
    model = "Unknown"

    def ring(self):
        print "The phone " + self.vendor + " is ringing"

gabes_phone = Phone()

print "Gabe's phone: ", gabes_phone
print "Gabe's phone vendor:", gabes_phone.vendor

jillian_phone = Phone()
jillian_phone.vendor = "Samsung"
jillian_phone.model = "Galaxy"

print "Jillian's phone type:", jillian_phone.vendor, jillian_phone.model

print "GAbe's model is:", gabes_phone.model

jillian_phone.ring()
gabes_phone.ring()

