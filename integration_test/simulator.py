from subprocess import Popen, PIPE, STDOUT
import sys

RED = "\033[1;31m"
GREEN = "\033[0;32m"
RESET = "\033[0;0m"

test_file = "test_input.txt"

def run_test(test_name, test_input):
    command_list = []
    success_flag = False
    result_strings = ""
    expect_strings = ""

    test_run = Popen(['./../build/iress'], stdout=PIPE, stdin=PIPE, stderr=STDOUT)

    # start to read line from test_input
    string_line = test_input.readline().strip()
    while ('Expect' != string_line[0:6]):
        print("Sending command: " + string_line)
        command_list.append(string_line)
        string_line = test_input.readline().strip()  # continously read line from file

    expect_line = string_line  # the last line should be the expected output

    # send command list and receive the result string from the server
    result = test_run.communicate(('\n'.join(command_list)).encode())

    # handle the result
    strings = result[0].strip().decode().replace("<fail>\n", "").split('\n')
    if len(strings) > 7:  # The first 7 lines are greetings
        result_strings = strings[7:]
        expect_strings = expect_line[7:].strip().split(';')
        for index , str in enumerate(result_strings):
            if expect_strings[index] != result_strings[index]:
                break
            success_flag = True
    else:
        if "" == expect_line[7:].strip():
            success_flag = True

    # print result on screen
    if success_flag:
        print("\nReceived: ", result_strings)
        sys.stdout.write(GREEN)
        print(test_name + 'PASS\n')
        sys.stdout.write(RESET)
    else:
        sys.stdout.write(RED)
        print(test_name + 'FAIL')
        print('Expected ', expect_strings)
        print('But Got ',result_strings)
        sys.stdout.write(RESET)


if __name__ == '__main__':

    print('Starting Iress Robot Test')
    test_input = open(test_file)  # load the whole file

    for line in test_input:
        if line.strip():
            test_name = line
            print("Start Test: " + test_name)
            run_test(test_name, test_input)

    test_input.close()
