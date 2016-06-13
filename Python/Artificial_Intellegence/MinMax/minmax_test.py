'''
Created on Apr 17, 2011
'''

INFINI=100

def winner(player,square):
    won = False
    L = len(square)
    # verify lines
    for i in range(L):
        same_as_player = True
        for x in square[i]:
            if x != player:
                same_as_player = False
        if same_as_player :
            won = True
            break
    
        
    # verify lines 
    for j in range(L):
        same_as_player = True
        for i in range(L):
            if square[i][j] != player:
                same_as_player = False
        if same_as_player :
            won = True
            break
    
    
    # verify rayon 1
    same_as_player = True
    for i in range(L):
        if square[i][i] != player:
            same_as_player = False
    if same_as_player:
        won = True
        
    # verify rayon 2
    same_as_player = True
    for i in range(L):
        if square[L-i-1][i] != player:
            same_as_player = False
    if same_as_player:
        won = True
        
    return won
        
        
        
    
    


def coups_possibles(square,palyer=0):
    """
    """
    L= len(square)
    for i in range(L):
        for j in range (L):
            if square(i, j) is None:
                yield (i,j)

 

def simuler(coup):
    pass

def appliquer(square,best):
    pass


def jouer(square_state=[[None,None,None],[None,None,None],[None,None,None]]):
    max_val = - INFINI
    for coup in coups_possibles(square_state,player=0):
        val = simuler(coup)
        if val > max_val:
            max_val=val
            meilleur_coup = coup
    appliquer(square_state,meilleur_coup)
    jouer(square_state)
    


if __name__ == '__main__':
    pass