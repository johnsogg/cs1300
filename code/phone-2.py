# class called Phone
class Phone:
    model = "Default Unknown Model"
    
    def print_model(self):
        print Phone.model
        print self.model

gabe_phone = Phone()
# prints default twice, since we havent updated it yet.
gabe_phone.print_model()
# update gabe's particular model
gabe_phone.model = "Apple"
# print Default and then Apple since we changed it.
gabe_phone.print_model()
