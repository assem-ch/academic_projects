#!/bin/python


##
def won(board):
    empty=False
    WX=WO=False
    #check diagonals
    diag1= set( [board[k][k] for k in xrange(4)])
    diag2= set( [board[k][3-k] for k in xrange(4)])
    if "." not in diag1:
            X_exist= "X" in diag1;
            O_exist= "O" in diag1;
            WX= X_exist and not O_exist
            WO= not X_exist and O_exist
        
        
    if not (WX or WO) and "." not in diag2:
            X_exist= "X" in diag2;
            O_exist= "O" in diag2;
            WX= X_exist and not O_exist
            WO= not X_exist and O_exist

    if not (WX or WO):
        for i in xrange(4):
            line=set(board[i])
            column=set( [board[j][i] for j in xrange(4)]) 
            #check lines
            if "." not in line:
                X_exist = "X" in line;
                O_exist= "O" in line;
                WX= X_exist and not O_exist
                WO= not X_exist and O_exist
                if WX or WO:
                    break
            else:
                empty= empty or True
            #check columns
            if "." not in column:
                X_exist= "X" in column;
                O_exist= "O" in column;
                WX= X_exist and not O_exist
                WO= not X_exist and O_exist
                if WX or WO:
                    break

    result = "X won" if WX \
        else "O won" if WO \
        else "Draw" if not empty \
        else "Game has not completed"
    return result
		            
		            

    
        
    


		
	



    


# read the input
f=open("in")
T=int(f.readline())


output=""
for i in xrange(T):
    board = []
    for j in xrange(4):
	    board.append(list(f.readline()[:-1]))

   
    output+="Case #%d: %s\n" % (i+1,won(board))
    f.readline()
    
    
    
    
OUTPUT=open("out","w")
OUTPUT.write(output)
print output
print "done"
    
    
    
