import random
from random import randint
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
        print("hello = Talk to the program")
        print("ping = test to see if the program responds")
        print("schedule = View HighTide's schedule")
        print("notes = Take and view notes")
    elif userInput == "exit":
        have_fun("exit")
    elif userInput == "ping":
        print("Pong")
    elif userInput == "notes":
        print("What note do you want to interact with?\n1\n2\n3")
        userInput = input()
        if userInput == "1":
            print("Would you like to view or edit the note?")
            userInput = input()
            if userInput == "edit":
                with open("User/note1.txt", "w") as note:
                    print("Please enter the new content of the note...")
                    note.truncate(0)
                    userInput = input()
                    note.write(userInput)
                    print("Saved the note!")
            if userInput == "view":
                with open("User/note1.txt", "r") as note:
                    contents = note.read()
                    print(contents)
            else:
                print("I can't", userInput, "a note...")
        elif userInput == "2":
            print("Would you like to view or edit the note?")
            userInput = input()
            if userInput == "edit":
                with open("User/note2.txt", "w") as note:
                    print("Please enter the new content of the note...")
                    note.truncate(0)
                    userInput = input()
                    note.write(userInput)
                    print("Saved the note!")
            elif userInput == "view":
                with open("User/note2.txt", "r") as note:
                    contents = note.read()
                    print(contents)
            else:
                print("I can't", userInput, "a note...")
        elif userInput == "3":
            print("Would you like to view or edit the note?")
            userInput = input()
            if userInput == "edit":
                with open("User/note3.txt", "w") as note:
                    print("Please enter the new content of the note...")
                    note.truncate(0)
                    userInput = input()
                    note.write(userInput)
                    print("Saved the note!")
            if userInput == "view":
                with open("User/note3.txt", "r") as note:
                    contents = note.read()
                    print(contents)
            else:
                print("I can't", userInput, "a note...")
        else:
            print("That is not a note you can interact with...")
    elif userInput == "schedule":
        print("Displaying HighTide's Schedule!")
        display_schedule(0)
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
