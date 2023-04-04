userInput = 'await'
isInApp = True
while isInApp == True:
    print("Welcome to HighTide's app! This is how you can check up on me!")
    print("What do you want to do?\nType 'help' for a list of options...")
    userInput = input()
    if userInput == "help":
        print("exit = Shuts down the app")
        print("random = Do some random things")
    elif userInput == "exit":
        isInApp = False
        print("Exiting app...")
    elif userInput == "random":
        print("What thing to you want to do random things with?\n1. art")
        userInput = input()
        if userInput == "art":
            print("This will soon be art!")
        else:
            print("Invalid option! Please try the command again!")
    else:
        print("Invalid command!\nPlease type 'help' for a list of commands!")
