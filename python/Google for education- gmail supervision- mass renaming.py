'''
Created on Nov 1, 2011

https://www.google.com/accounts/b/0/SmsAuthConfig
'''



import gdata.apps.service


gservice= gdata.apps.service.AppsService(email="a_chelli@esi.dz", password="xxxxxxxxxxxxxxxxxxx", domain="esi.dz")
gservice.ProgrammaticLogin()

print "before users"
users=gservice.RetrieveAllUsers()
print "before len & after users"
print len(users.entry)
print "hello3"


#gn_set=set()
for user in users.entry:
        print 
        first=user.name.given_name.split(" ")[0].upper()
        #if first[0].isdigit():
        #gn_set.add(first )  #user.name.family_name
        if first in  ['2CPI', '3SIQ', '2TC','5SIQ', '4SI', '1CPI', '5SI', '5I', '1', '3', '5', '4', '2']:
                print user.login.user_name,":",user.name.given_name,user.name.family_name,
                user.name.given_name=" ".join(user.name.given_name.split(" ")[1:])
                print "changed to: ",  user.name.given_name
                """
                confirm=raw_input(", ok? ")
                if confirm=="y":
                    
                print 
                """
                gservice.UpdateUser(user.login.user_name, user)

