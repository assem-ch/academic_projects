def xor(a,b):
   if int(a)==int(b): return 0
   else: return 1
def rev_xor(a,b):
   if int(a)==int(b): return 1
   else: return 0

n, k = map(int, raw_input().split())
code = raw_input()
res = int(code[0])
msg = [res]
rev = res
i=1
while i<k and i<n:
   new_res = xor(res, code[i])
   msg.append(new_res)
   res = xor(res, msg[i])
   i+=1
i=0
if n>k:
   while i+k<n:
      res = xor(res, msg[i])
      new_res2=xor(res, code[i+k]);
      msg.append(new_res2)
      i+=1
      res = xor(res, msg[-1])
print "".join(str(x) for x in msg)