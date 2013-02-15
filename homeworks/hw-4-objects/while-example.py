response = "4"
while response == "4":
    response = raw_input("How many lights do you see? ")
    print "You responded: " + response
    if response == "4":
        print "No, you seem to be mistaken. Let's continue..."
print "Done with loop."
