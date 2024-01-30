##
## EPITECH PROJECT, 2023
## 2D_pong.py
## File description:
## 2D pong game
##

import pygame, sys, random

pygame.init()

WIDTH, HEIGHT = 1280, 720

# import sound
HIT_SOUND = pygame.mixer.Sound("bonus/data/hit.wav")
SCORE_SOUND = pygame.mixer.Sound("bonus/data/score.wav")
WIN_SOUND = pygame.mixer.Sound("bonus/data/win.wav")
LOSE_SOUND = pygame.mixer.Sound("bonus/data/lose.wav")

# define font
FONT = pygame.font.SysFont("Consoloas", int(WIDTH / 20))
FONT2 = pygame.font.SysFont("Consoloas", int(WIDTH / 10))

# screen function
SCREEN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("101pong")
CLOCK = pygame.time.Clock()
BACKGROUND = pygame.image.load("bonus/data/menu.jpg")

# paddles function
player = pygame.Rect(WIDTH - 110, HEIGHT / 2 - 50, 10, 100)
opponent = pygame.Rect(110, HEIGHT / 2 - 50, 10, 100)
player_score, opponent_score = 0, 0

# ball function
ball = pygame.Rect(WIDTH / 2 - 10, HEIGHT / 2 - 10, 20, 20)
x_speed, y_speed = 1, 1

# menu func
def show_menu():
    # display menu choices
    menu_font = pygame.font.SysFont("Consoloas", int(WIDTH / 15))
    title_txt = menu_font.render("Pong Menu", True, "red")
    start_txt = menu_font.render("1. Start game", True, "red")
    quit_text = menu_font.render("2. Exit", True, "red")

    menu_running = True
    while menu_running:
        for event in pygame.event.get():
            # if the player chooses exit the game quits
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                # launch game and leave menu if the player chooses to
                if event.key == pygame.K_1:
                    menu_running = False
                elif event.key == pygame.K_2:
                    pygame.quit()
                    sys.exit()
                    
        # display everything we said
        SCREEN.blit(BACKGROUND, (0, 0))
        SCREEN.blit(title_txt, (WIDTH / 2 - title_txt.get_width() / 2, HEIGHT / 4))
        SCREEN.blit(start_txt, (WIDTH / 2 - start_txt.get_width() / 2, HEIGHT / 2))
        SCREEN.blit(quit_text, (WIDTH / 2 - quit_text.get_width() / 2, HEIGHT / 1.5))

        pygame.display.update()

# show menu at first
show_menu()

# victory animation function
def victory_animation():

    pygame.mixer.Sound.play(WIN_SOUND)

    # 11000 to let the song finish
    flash_duration = 11000
    flash_interval = 500
    start_time = pygame.time.get_ticks()
    
    # if player wins, screen is black and green
    while pygame.time.get_ticks() - start_time < flash_duration:
        if (pygame.time.get_ticks() - start_time) % (2 * flash_interval) < flash_interval:
            SCREEN.fill("black")
        else:
            SCREEN.fill("green")

        winner_txt = FONT2.render("WINNER", True, "white")
        winner_rect = winner_txt.get_rect(center=(WIDTH / 2, HEIGHT / 2))
        SCREEN.blit(winner_txt, winner_rect)

        pygame.display.update()

# defeat animation function
def defeat_animation():

    pygame.mixer.Sound.play(LOSE_SOUND)

    # 3000 to let the song finish
    flash_duration1 = 3000
    flash_interval1 = 500
    start_time1 = pygame.time.get_ticks()
    
    # if player lose, screen is black and red
    while pygame.time.get_ticks() - start_time1 < flash_duration1:
        if (pygame.time.get_ticks() - start_time1) % (2 * flash_interval1) < flash_interval1:
            SCREEN.fill("black")
        else:
            SCREEN.fill("red")

        loser_txt = FONT2.render("LOSER", True, "white")
        loser_rect = loser_txt.get_rect(center=(WIDTH / 2, HEIGHT / 2))
        SCREEN.blit(loser_txt, loser_rect)

        pygame.display.update()

# game loop
while True:
    keys_pressed = pygame.key.get_pressed()

    # player movement
    if keys_pressed[pygame.K_UP]:
        if player.top > 0:
            player.top -= 3
    if keys_pressed[pygame.K_DOWN]:
        if player.bottom < HEIGHT:
            player.bottom += 3
    
    # to let us quit the game
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # ball movement
    if ball.y >= HEIGHT:
        y_speed = -1
    if ball.y <= 0:
        y_speed = 1

    # calculate player score
    if ball.x <= 0:
        pygame.mixer.Sound.play(SCORE_SOUND)
        player_score += 1
        ball.center = (WIDTH / 2, HEIGHT / 2)
        x_speed, y_speed = random.choice([1, -1]), random.choice([1, -1])

    # calculate opponent score
    if ball.x >= WIDTH:
        pygame.mixer.Sound.play(SCORE_SOUND)
        opponent_score += 1
        ball.center = (WIDTH / 2, HEIGHT / 2)
        x_speed, y_speed = random.choice([1, -1]), random.choice([1, -1])

    # ball collision
    if player.x - ball.width <= ball.x <= player.x and ball.y in range(player.top - ball.width, player.bottom):
        pygame.mixer.Sound.play(HIT_SOUND)
        x_speed = -1
    if opponent.x - ball.width <= ball.x <= opponent.x and ball.y in range(opponent.top - ball.width, opponent.bottom):
        pygame.mixer.Sound.play(HIT_SOUND)
        x_speed = 1

    # ball speed *2 because normal speed is slow af higher value may bug
    ball.x += x_speed * 2
    ball.y += y_speed * 2

    # opponent bot movement
    if opponent.y < ball.y:
        opponent.top += 3
    if opponent.bottom > ball.y:
        opponent.bottom -= 3

    # score font and color
    player_score_txt = FONT.render(str(player_score), True, "pink")
    opponent_score_txt = FONT.render(str(opponent_score), True, "pink")

    # fill screen with black when there's movement
    SCREEN.fill("black")

    # display rectangles and circle
    pygame.draw.rect(SCREEN, "white", player)
    pygame.draw.rect(SCREEN, "white", opponent)
    pygame.draw.circle(SCREEN, "red", ball.center, 10)

    # print score
    SCREEN.blit(player_score_txt, (WIDTH / 2 + 50, 50))
    SCREEN.blit(opponent_score_txt, (WIDTH / 2 - 50, 50))

    # check win or lose
    if player_score == 6 or opponent_score == 6:
        if player_score == 6:
            victory_animation()
        else:
            defeat_animation()

        # After animation, return to the menu
        player_score = 0
        opponent_score = 0
        show_menu()

    pygame.display.update()
    CLOCK.tick(300)
