userInput = 'await'
isInApp = true
while isInApp == true:
    print("Welcome to HighTide's app! This is how you can check up on me!")
    print("What do you want to do?\nType 'help' for a list of options...")
    userInput = input()
    if userInput == "help":
        print("exit = Shuts down the app")
    elif userInput == "exit":
        isInApp = false
        print("Exiting app...")
