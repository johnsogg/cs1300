# class called Phone
class Phone:
    model = "Default Unknown Model"
    phone_num = 5555555
    
    def print_model(self):
        print self.model

    def send_text(self, phone_num, text_body):
        print "Sending message..."
        print "  To:  " + str(phone_num)
        print "  Msg: " + str(text_body)
        print "... message sent. Charge: $15.00."

    def call_myself(self):
        print "Calling " + str(self.phone_num)

gabe_phone = Phone()
gabe_phone.model = "Apple"
gabe_phone.print_model()
gabe_phone.send_text(8675309, "Hey Jenny!")
gabe_phone.send_text(8675309, 5555555)
gabe_phone.call_myself()
gabe_phone.phone_num = 720998348
gabe_phone.call_myself()
