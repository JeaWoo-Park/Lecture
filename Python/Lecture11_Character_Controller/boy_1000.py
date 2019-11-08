from pico2d import *
import random


class Boy:
    image = load_image('run_animation.png')

    def __init__(self):
        self.x, self.y = random.randint(100, 700), 90
        self.frame = random.randint(0, 7)

    def draw(self):
        self.image.draw(self.x, self.y)

    def update(self):
        self.x += 1


def handle_events():
    global running
    events = get_events()
    for event in events:
        if event.type == SDL_QUIT:
            running = False
        elif event.type == SDL_KEYDOWN and event.key == SDLK_ESCAPE:
            running = False


running = True
open_canvas()
boy = [Boy() for i in range(1000)]
while running:
    clear_canvas()
    for b in boy:
        b.update()
    for b in boy:
        b.draw()
    handle_events()
    update_canvas()

close_canvas()
