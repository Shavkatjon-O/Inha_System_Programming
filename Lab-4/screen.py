import os
import json
import pyautogui
import random
import subprocess
import time


CURRENT_DIR = os.getcwd()
SCREENS_DIR = f"{CURRENT_DIR}/screenshots"


def getScreensCount(screens_path):
    screens = []
    for file_name in os.listdir(screens_path):
        if file_name.startswith("screen"):
            screens.append(file_name)
    count = len(screens)
    if count == 0:
        return 1
    return count


def scrollUp():
    prev_screen = None
    while True:
        pyautogui.hotkey("shift", "pageup")
        curr_screen = pyautogui.screenshot()
        if prev_screen == curr_screen:
            break
        prev_screen = curr_screen


def takeScreenshots(screens_path):
    scrollUp()

    screens_count = getScreensCount(screens_path) + 1
    prev_screen = None

    while True:
        curr_screen = pyautogui.screenshot()
        if prev_screen == curr_screen:
            break

        curr_screen.save(f"{screens_path}/screen-{screens_count}.png")
        prev_screen = curr_screen

        pyautogui.hotkey("shift", "pagedown")
        screens_count += 1


def takeScreenshotsReverse(screens_path):
    screens_count = getScreensCount(screens_path) + 1
    prev_screen = None

    for i in range(3):
        curr_screen = pyautogui.screenshot()
        if prev_screen == curr_screen:
            break

        curr_screen.save(f"{screens_path}/screen-{screens_count}.png")
        prev_screen = curr_screen

        pyautogui.hotkey("shift", "pageup")
        screens_count += 1


def executeCommandsQuestion1(file_name):
    pyautogui.write(f"./{file_name}\n")

    vector_size = random.randint(20, 50)
    scalar_num = random.randint(-10000, 10000)
    sort_option = random.choices([1, 2])[0]

    for value in (vector_size, scalar_num, sort_option):
        pyautogui.write(f"{value}\n")

    for i in range(vector_size):
        pyautogui.write(f"{random.randint(-10000, 10000)}\n")

    for i in range(vector_size):
        pyautogui.write(f"{random.randint(-10000, 10000)}\n")

    vector_size = random.randint(20, 50)
    scalar_num = random.uniform(-10000.0, 10000.0)
    sort_option = random.choices([1, 2])[0]

    for value in (vector_size, scalar_num, sort_option):
        pyautogui.write(f"{value}\n")

    for i in range(vector_size):
        pyautogui.write(f"{random.uniform(-10000.0, 10000.0)}\n")

    for i in range(vector_size):
        pyautogui.write(f"{random.uniform(-10000.0, 10000.0)}\n")

    takeScreenshots(f"{SCREENS_DIR}/question1")
    pyautogui.write("clear\n")


def question1():
    pyautogui.write(f"cd {CURRENT_DIR}/question1/code/\n")
    pyautogui.write("clear\n")

    commands = (
        "ar rcs lib/static/libvector.a bin/static/*.o",
        "gcc -shared -o lib/shared/libvector.so bin/shared/*.o",
        "gcc -static -o compile src/static.c ./lib/static/libvector.a",
        "gcc -o load src/static.c ./lib/shared/libvector.so",
        "gcc -rdynamic -o runtime src/dynamic.c -ldl",
        "ls -la",
    )

    for command in commands:
        pyautogui.write(f"{command}\n")

    screens_count = getScreensCount(f"{SCREENS_DIR}/question1/")
    pyautogui.screenshot(f"{SCREENS_DIR}/question1/screen-{screens_count}.png")

    pyautogui.write("clear\n")

    files = ("compile", "load", "runtime")

    for file_name in files:
        for i in range(2):
            executeCommandsQuestion1(file_name)


def executeCommandsQuestion2(file_name):
    pyautogui.write(f"./{file_name}\n")

    vector_size = random.randint(15, 20)
    pyautogui.write(f"{vector_size}\n")

    for i in range(vector_size):
        row_elements = " ".join(
            str(random.randint(-10000, 10000)) for _ in range(vector_size)
        )
        pyautogui.write(f"{row_elements}\n")

    for i in range(vector_size):
        row_elements = " ".join(
            str(random.randint(-10000, 10000)) for _ in range(vector_size)
        )
        pyautogui.write(f"{row_elements}\n")

    vector_size = random.randint(15, 20)
    pyautogui.write(f"{vector_size}\n")

    for i in range(vector_size):
        row_elements = " ".join(
            "{:.2f}".format(random.uniform(-10000.0, 10000.0))
            for _ in range(vector_size)
        )
        pyautogui.write(f"{row_elements}\n")

    for i in range(vector_size):
        row_elements = " ".join(
            "{:.2f}".format(random.uniform(-10000.0, 10000.0))
            for _ in range(vector_size)
        )
        pyautogui.write(f"{row_elements}\n")

    takeScreenshots(f"{SCREENS_DIR}/question2")
    pyautogui.write("clear\n")


def question2():
    pyautogui.write(f"cd {CURRENT_DIR}/question2/code/\n")
    pyautogui.write("clear\n")

    commands = (
        "ar rcs lib/static/libmatrix.a bin/static/*.o",
        "gcc -shared -o lib/shared/libmatrix.so bin/shared/*.o",
        "gcc -static -o compile src/static.c ./lib/static/libmatrix.a",
        "gcc -o load src/static.c ./lib/shared/libmatrix.so",
        "gcc -rdynamic -o runtime src/dynamic.c -ldl",
        "ls -la",
    )

    for command in commands:
        pyautogui.write(f"{command}\n")

    screens_count = getScreensCount(f"{SCREENS_DIR}/question2/")
    pyautogui.screenshot(f"{SCREENS_DIR}/question2/screen-{screens_count}.png")

    pyautogui.write("clear\n")

    files = ("compile", "load", "runtime")

    for file_name in files:
        for i in range(2):
            executeCommandsQuestion2(file_name)


def executeCommandsQuestion3(file_name, list_size):
    pyautogui.write(f"./{file_name}\n")

    free_num = random.randint(0, list_size)

    pyautogui.write(f"{list_size}\n")
    pyautogui.write(f"{free_num}\n")

    with open(f"{CURRENT_DIR}/students_info_full.json", "r") as file:
        students_info = json.load(file)

    for i in range(list_size):
        entry = students_info[i]

        pyautogui.write(f"{entry['name']}\n")
        pyautogui.write(f"{entry['program']}\n")
        pyautogui.write(f"{entry['level']}\n")
        pyautogui.write(f"{entry['email']}\n")
        pyautogui.write(f"{entry['phone']}\n")
        pyautogui.write(f"{entry['id']}\n")
        pyautogui.write(f"{entry['section']}\n")

    takeScreenshots(f"{SCREENS_DIR}/question3")
    pyautogui.write("clear\n")


def question3():
    pyautogui.write(f"cd {CURRENT_DIR}/question3/code/\n")
    pyautogui.write("clear\n")

    commands = (
        "gcc -Wall -DCOMPILETIME -c src/wrappers/malloc_compile.c -o bin/wrappers/malloc_compile.o",
        "gcc -Wall -I./include -o main_compile src/main.c bin/wrappers/malloc_compile.o",
        "gcc -Wall -DLINKTIME -c src/wrappers/malloc_link.c -o bin/wrappers/malloc_link.o",
        "gcc -Wall -Wl,--wrap,malloc -Wl,--wrap,free -o main_link src/main.c bin/wrappers/malloc_link.o",
    )

    for command in commands:
        pyautogui.write(f"{command}\n")

    screens_count = getScreensCount(f"{SCREENS_DIR}/question3/")
    pyautogui.screenshot(f"{SCREENS_DIR}/question3/screen-{screens_count}.png")

    pyautogui.write("clear\n")

    files = ("main_compile", "main_link")

    for i in range(10, 40, 10):
        executeCommandsQuestion3(files[0], i)
    for i in range(30, 70, 10):
        executeCommandsQuestion3(files[1], i)


def executeCommandsQuestion4(matrix_size):
    command = (
        f"./matgen2file matricies/matrix{matrix_size}x{matrix_size}.txt {matrix_size}"
    )
    pyautogui.write(f"{command}\n")
    time.sleep(0.5)

    takeScreenshotsReverse(f"{SCREENS_DIR}/question4")
    pyautogui.write("clear\n")


def question4():
    pyautogui.write(f"cd {CURRENT_DIR}/question4/code/\n")
    pyautogui.write("clear\n")

    command = "gcc -o matgen2file src/matgen2file.c"
    pyautogui.write(f"{command}\n")

    screens_count = getScreensCount(f"{SCREENS_DIR}/question4/")
    pyautogui.screenshot(f"{SCREENS_DIR}/question4/screen-{screens_count}.png")

    pyautogui.write("clear\n")

    for i in range(10, 100, 10):
        executeCommandsQuestion4(i)
    for i in range(100, 1100, 100):
        executeCommandsQuestion4(i)


def executeCommandsQuestion5(matrix_size):
    command = (
        f"./main {matrix_size} "
        f"matricies/matrixA{matrix_size}x{matrix_size}.txt "
        f"matricies/matrixB{matrix_size}x{matrix_size}.txt "
        f"matricies/matrixC{matrix_size}x{matrix_size}.txt"
    )
    pyautogui.write(f"{command}\n")
    time.sleep(15)


def question5():
    pyautogui.write(f"cd {CURRENT_DIR}/question5/code/\n")
    pyautogui.write("clear\n")

    command = "gcc -o main src/main.c"
    pyautogui.write(f"{command}\n")

    screens_count = getScreensCount(f"{SCREENS_DIR}/question5/")
    pyautogui.screenshot(f"{SCREENS_DIR}/question5/screen-{screens_count}.png")

    pyautogui.write("clear\n")

    for i in range(100, 1100, 100):
        command = f"./matgen2file matricies/matrixA{i}x{i}.txt {i}"
        time.sleep(5)

        pyautogui.write(f"{command}\n")
        pyautogui.write("clear\n")

    for i in range(100, 1100, 100):
        command = f"./matgen2file matricies/matrixB{i}x{i}.txt {i}"
        time.sleep(5)

        pyautogui.write(f"{command}\n")
        pyautogui.write("clear\n")

    for i in range(100, 1100, 100):
        executeCommandsQuestion5(i)

    takeScreenshots(f"{SCREENS_DIR}/question5")


def executeCommandsQuestion6(matrix_size):
    command = (
        f"./main {matrix_size} "
        f"matricies/matrixA{matrix_size}x{matrix_size}.txt "
        f"matricies/matrixB{matrix_size}x{matrix_size}.txt "
        f"matricies/matrixC{matrix_size}x{matrix_size}.txt"
    )
    pyautogui.write(f"{command}\n")
    time.sleep(15)

    takeScreenshotsReverse(f"{SCREENS_DIR}/question6")

    pyautogui.write("clear\n")


def question6():
    pyautogui.write(f"cd {CURRENT_DIR}/question6/code/\n")
    pyautogui.write("clear\n")

    for i in range(100, 1100, 100):
        command = f"./matgen2file matricies/matrixA{i}x{i}.txt {i}"
        time.sleep(5)

        pyautogui.write(f"{command}\n")
        pyautogui.write("clear\n")

    for i in range(100, 1100, 100):
        command = f"./matgen2file matricies/matrixB{i}x{i}.txt {i}"
        time.sleep(5)

        pyautogui.write(f"{command}\n")
        pyautogui.write("clear\n")

    for i in range(100, 1100, 100):
        executeCommandsQuestion6(i)


def main():
    import subprocess

    time.sleep(5)
    subprocess.run(["xdotool", "key", "ctrl+alt+t"])
    time.sleep(5)
    subprocess.run(["xdotool", "key", "alt+F10"])
    time.sleep(5)

    # pyautogui.hotkey("ctrl", "alt", "t")
    # pyautogui.write("clear\n")

    question1()
    question2()
    question3()
    question4()
    question5()
    question6()

    pyautogui.write("exit\n")


if __name__ == "__main__":
    main()
