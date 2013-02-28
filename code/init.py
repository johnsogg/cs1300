name = ""

class Widget:
    all_widgets = { }
    spokes=0
    teeth=0
    def __init__(self, realname, spokes, teeth):
        self.spokes=spokes
        self.teeth=teeth
        self.realname = realname
        Widget.all_widgets[realname]= self
        name = Widget.all_widgets[realname]

#    def __str__(self):
#        return "This is widget number " + str(self.name)

w = Widget(1, 10, 15)
print Widget.all_widgets[1]
print "The type of w is", type(w)
print "The type of Widget is", type(Widget)
#print Widget.name

        
print "What's the name? " + name
