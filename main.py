import random
from draw import *
from fun import have_fun

userInput = 'await'
isInApp = True

print("Welcome to HighTide's app! This is how you can check up on me!")
print("What do you want to do?\nType 'help' for a list of options...")
while isInApp:
    userInput = input()
    if userInput == "help":
        print("exit = Shuts down the app")
        print("random = Do some random things")
    elif userInput == "exit":
        have_fun("exit")
    elif userInput == "random":
        print("What thing to you want to do random things with?\n1. color\n2. word")
        userInput = input()
        if userInput == "color":
            with open("Resources/colors.txt", "r") as file:
                allText = file.read()
                words = list(map(str, allText.split()))
                randomWord = random.choice(words)
                draw_square(randomWord)
        elif userInput == "word":
            with open("Resources/word.txt", "r") as file:
                allText = file.read()
                words = list(map(str, allText.split()))
                randomWord = random.choice(words)
                print(randomWord)
        else:
            print("Invalid option! Please try the command again!")
    else:
        print("Invalid command!\nPlease type 'help' for a list of commands!")
