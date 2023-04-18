import random
from random import randint
from colorama import Fore
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
    elif userInput == "hello":
        print("Hello how are you?\na = good\nb = bad\nc = so so")
        userInput = input()
        if userInput == 'a':
            print("Well that is good!")
        elif userInput == 'b':
            print("Aww well I hope you feel better soon :)")
        elif userInput == 'c':
            print("Fair enough. Sometimes humans can be in the middle...")
        else:
            print("I don't know that response yet :( You have to try again...")
    elif userInput == "random":
        print("What thing to you want to do random things with?\n1. color\n2. word\n3. number")
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
        elif userInput == "number":
            print("What type of number do you want to generate?\ntiny = 1 to 10\nsmall = 1 to 50\nmedium = 1 to 100\nlarge = 1 to 1000\nbig = 1 to 5000\nhuge = 1 to 10000")
            userInput = input()
            if userInput == "tiny":
                randomNumber = randint(1, 10)
                print("Your random number is: ", randomNumber)
            elif userInput == "small":
                randomNumber = randint(1, 50)
                print("Your random number is: ", randomNumber)
            elif userInput == "medium":
                randomNumber = randint(1, 100)
                print("Your random number is: ", randomNumber)
            elif userInput == "large":
                randomNumber = randint(1, 1000)
                print("Your random number is: ", randomNumber)
            elif userInput == "big":
                randomNumber = randint(1, 5000)
                print("Your random number is: ", randomNumber)
            elif userInput == "huge":
                randomNumber = randint(1, 10000)
                print("Your random number is: ", randomNumber)
            else:
                print(Fore.RED, "Invalid Option! Please use one from a list of available options...", Fore.WHITE)
        else:
            print(Fore.RED,"Invalid option! Please try the command again!", Fore.WHITE)
    else:
        print(Fore.RED,"Invalid command!\nPlease type 'help' for a list of commands!",Fore.WHITE)
