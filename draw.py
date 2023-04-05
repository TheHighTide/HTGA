from tkinter import *


def draw_square(color):
    if color == "red":
        window = Tk()
        window.title("")
        window.configure(width=100, height=100)
        window.configure(bg='white')
        window.resizable(False, False)
        window.attributes('-toolwindow', True)
        colorRender = Canvas(window, width=100, height=100)
        colorRender.pack()
        colorRender.create_rectangle(0, 0, 100, 100, fill="red")
        window.mainloop()
    elif color == "blue":
        window = Tk()
        window.title("")
        window.configure(width=100, height=100)
        window.configure(bg='white')
        window.resizable(False, False)
        window.attributes('-toolwindow', True)
        colorRender = Canvas(window, width=100, height=100)
        colorRender.pack()
        colorRender.create_rectangle(0, 0, 100, 100, fill="blue")
        window.mainloop()
    elif color == "green":
        window = Tk()
        window.title("")
        window.configure(width=100, height=100)
        window.configure(bg='white')
        window.resizable(False, False)
        window.attributes('-toolwindow', True)
        colorRender = Canvas(window, width=100, height=100)
        colorRender.pack()
        colorRender.create_rectangle(0, 0, 100, 100, fill="green")
        window.mainloop()
    elif color == "pink":
        window = Tk()
        window.title("")
        window.configure(width=100, height=100)
        window.configure(bg='white')
        window.resizable(False, False)
        window.attributes('-toolwindow', True)
        colorRender = Canvas(window, width=100, height=100)
        colorRender.pack()
        colorRender.create_rectangle(0, 0, 100, 100, fill="pink")
        window.mainloop()
    else:
        print("Wrong Color!")

