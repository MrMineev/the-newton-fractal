import pygame
from assets import assets

def set_text(string, coordx, coordy, fontSize, color=(255, 255, 255)): #Function to set text

    font = pygame.font.Font('freesansbold.ttf', fontSize) 
    #(0, 0, 0) is black, to make black text
    text = font.render(string, True, color) 
    textRect = text.get_rect()
    textRect.center = (coordx, coordy) 
    return (text, textRect)

tools = assets()

width = 700
height = 700

pygame.init()
back = (192,192,192)
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption('A bit Racey')
screen.fill(back)
clock = pygame.time.Clock()
running = True
# imports and Pygame initialization here

a = 0
size_of_gas_cloud = 30

while True:

    if pygame.mouse.get_pressed()[0] != 0:
        # collision detection also needed here
        a = pygame.mouse.get_pos()[0] - 5
        if a < 0:
            a = 0

    size_of_gas_cloud += a

    pygame.draw.rect(screen, (0, 0, 0), pygame.Rect(0, 0, width, height))
    pygame.draw.rect(screen, (255, 0, 0), pygame.Rect(a, 5, 10, 90))
    pygame.display.update()
    clock.tick(60)

    # Pygame event loop here
pygame.quit()

quit()
