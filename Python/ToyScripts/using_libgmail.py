import libgmail

password=raw_input("add your password (Be carful! its not hidden)")
ga = libgmail.GmailAccount("assem.ch@gmail.com", password)
ga.login()
folder = ga.getMessagesByFolder('inbox')

for thread in folder:
  print thread.id, len(thread), thread.subject
  for msg in thread:
    print "  ", msg.id, msg.number, msg.subject
    print msg.source
    
    
input()
    


