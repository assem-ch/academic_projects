'''
Created on 18 janv. 2010

@author: assem
'''

"""

pygame.draw.arc

      draw a partial section of an ellipse
      pygame.draw.arc(Surface, color, Rect, start_angle, stop_angle, width=1): return Rect

      Draws an elliptical arc on the Surface. The rect argument is the area that the ellipse will fill. The two angle arguments are the initial and final angle in radians, with the zero on the right. The width argument is the thickness to draw the outer edge.
          
            

pygame.draw.line

      draw a straight line segment
      pygame.draw.line(Surface, color, start_pos, end_pos, width=1): return Rect

      Draw a straight line segment on a Surface. There are no endcaps, the ends are squared off for thick lines. 

"""
#import and init pygame

import pygame, bz2, sys
import xml.dom.minidom as dom
import urllib2


angleERR = {"blue":0, "green":0, "red":0, "yellow":0, "white":0}
colors = {"blue":(0, 0, 255), "green":(0, 255, 150), "red":(255, 0, 0), "yellow":(50, 250, 0), "white":(255, 255, 255)}
radian = lambda x: (x * 3.14) / 180.0


def rad(x):
    return x * 3.14 / 180.0

pygame.init() 
WX = WY = 800                   
window = pygame.display.set_mode((WX, WY)) 
#bzfile = urllib2.urlopen("./plotMe.xml.bz2")

choix=input("donnez moi votre choix?")
print int(choix)
if choix:
    if choix < 6:
        print x

pass 

uncompressedData = bz2.BZ2File("plotMe.xml.bz2")

lines = uncompressedData.readlines()

print len(lines) / 5
parsed = dom.parseString("\n".join(lines))
print lines

for root in  parsed.childNodes:
    if root.localName == "ppcPlot":
        for node in root.childNodes:
            if node.localName == "Line":
                Color = "white"
                for nody in node.childNodes:
                    if nody.localName == "Color":
                        Color = nody.firstChild.data
                    elif nody.localName == "XEnd":
                        XEnd = float(nody.firstChild.data)
                    elif nody.localName == "XStart":
                        XStart = float(nody.firstChild.data)
                    elif nody.localName == "YStart":
                        YStart = float(nody.firstChild.data)
                    elif nody.localName == "YEnd":
                        YEnd = float(nody.firstChild.data)
                    else:
                        pass
                print Color
                pygame.draw.line(window, colors[Color], (XStart, WY - YStart), (XEnd, WY - YEnd))     
                pygame.display.flip()
                pygame.event.get() 
            elif node.localName == "Arc":
                Color = "white"
                for nody in node.childNodes:
                    if nody.localName == "Color":
                        Color = nody.firstChild.data
                    elif nody.localName == "XCenter":
                        XCenter = float(nody.firstChild.data)
                    elif nody.localName == "Radius":
                        Radius = float(nody.firstChild.data)
                    elif nody.localName == "ArcStart":
                        ArcStart = float(nody.firstChild.data)
                    elif nody.localName == "YCenter":
                        YCenter = float(nody.firstChild.data)
                    elif nody.localName == "ArcExtend":
                        ArcExtend = float(nody.firstChild.data)
                    else:
                        pass
                
                start = radian(ArcStart)
                end = radian(ArcStart + ArcExtend)

                pygame.draw.arc(window, colors[Color], (XCenter - Radius, WY - YCenter - Radius, 2 * Radius, 2 * Radius), start , end)
                pygame.display.flip()
                pygame.event.get() 
            else:
                pass
                

#create the screen


#pygame.draw.line(window, (200,255,200),(500,0), (500,1000))
#pygame.draw.line(window, (200,255,200),(0,500), (1000,500))
pygame.draw.arc(window, (200, 255, 200), (0, 0, 2 * 500, 2 * 500), radian(370), radian(20))
#draw it to the screen
pygame.display.flip() 


#input handling (somewhat boilerplate code):
while True: 
   for event in pygame.event.get(): 
      if event.type == pygame.QUIT: 
         pass
         sys.exit(0) 
      else: 
         print event

     
