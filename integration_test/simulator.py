from subprocess import Popen, PIPE, STDOUT
import sys

RED = "\033[1;31m"
GREEN = "\033[0;32m"
RESET = "\033[0;0m"

def run_test(test_name, test_input):
    command_list = []
    success_flag = False
    last_string = ""

    test_run = Popen(['./../build/iress'], stdout=PIPE, stdin=PIPE, stderr=STDOUT)

    # start to read line from test_input file
    string_line = test_input.readline().rstrip()
    while ('Expect' != string_line[0:6]):
        print("Sending command: " + string_line)
        command_list.append(string_line)
        string_line = test_input.readline().rstrip()  # continously read line from file

    expect_line = string_line  # the last line should be the expect output

    # send command list and receive the result string from the server
    result_string = test_run.communicate(('\n'.join(command_list)).encode())

    strings = result_string[0].rstrip().decode().split('\n')
    if len(strings) > 7:  # The first 7 lines are greetings
        last_string = strings[-1]  # # The real result info are in the last string
        if last_string == expect_line[8:].rstrip():  # if result info is as the same as expected
            success_flag = True
            print("\nReceived: ", last_string)
    else:
        if "" == expect_line[7:].rstrip():
            success_flag = True

    if success_flag:
        sys.stdout.write(GREEN)
        print(test_name + 'PASS\n')
        sys.stdout.write(RESET)
    else:
        sys.stdout.write(RED)
        print(test_name + 'FAIL')
        sys.stdout.write(RESET)
        print('Expected ' + string_line[7:] + ', got ' + last_string + '\n')


if __name__ == '__main__':

    print('Starting Iress Robot Test')
    test_input = open("test_input.txt")

    for line in test_input:
        if line.rstrip():
            test_name = line
            print("Start Test: " + test_name)
            run_test(test_name, test_input)

    test_input.close()
