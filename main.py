from draw import draw_square

import random

userInput = 'await'
isInApp = True

print("Welcome to HighTide's app! This is how you can check up on me!")
print("What do you want to do?\nType 'help' for a list of options...")
while isInApp == True:
    userInput = input()
    if userInput == "help":
        print("exit = Shuts down the app")
        print("random = Do some random things")
    elif userInput == "exit":
        isInApp = False
        print("Exiting app...")
    elif userInput == "random":
        print("What thing to you want to do random things with?\n1. color\n2. word")
        userInput = input()
        if userInput == "color":
            with open("Resources/colors.txt", "r") as file:
                allText = file.read()
                words = list(map(str, allText.split()))
                draw_square(random.choice(words))
        elif userInput == "word":
            with open("Resources/word.txt", "r") as file:
                allText = file.read()
                words = list(map(str, allText.split()))
                print(random.choice(words))
        else:
            print("Invalid option! Please try the command again!")
    else:
        print("Invalid command!\nPlease type 'help' for a list of commands!")