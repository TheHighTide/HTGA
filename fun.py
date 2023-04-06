import tkinter
import random
from tkinter import Tk
import tkinter.font as font
from playsound import playsound


def play_click():
    playsound('Resources/click.mp3')
    exit()


def have_fun(activity):
    if activity == "exit":
        with open("Resources/numbers.txt", "r") as file:
            allText = file.read()
            words = list(map(str, allText.split()))
            randomNumber1 = random.choice(words)
            randomNumber2 = random.choice(words)
            randomNumber3 = random.randint(0,0)

        window = Tk()
        henryfont = font.Font(size=randomNumber3)
        window.title("Exit Application?")
        window.protocol("WM_DELETE_WINDOW", exit)
        window.geometry("300x300")
        window.resizable(False, False)
        btn_quit = tkinter.Button(window, text="Quit Application", command=lambda: [play_click(), window.destroy], font=henryfont)
        btn_quit.place(x=randomNumber1, y=randomNumber2)
        window.mainloop()
    else:
        print("NO")
