class Slug:
    hunger = 4

s1 = Slug()
s2 = Slug()

print "Slug 1 has hunger:", s1.hunger
print "Slug 2 has hunger:", s2.hunger

s1.hunger = 9
s2.hunger = 3
print "We just fed slug #1 but not the other."

print "Slug 1 has hunger:", s1.hunger
print "Slug 2 has hunger:", s2.hunger

