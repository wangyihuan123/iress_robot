#Iress Toy Robot
------------------------

## About the project
1. Source code file
    - The source code files can also be found at github repository:**https://github.com/wangyihuan123/iress_robot.git**.
    - There are  three subdirectories (integration_test, unit_test, src)

```
iress_robot
├── integration_test  
          ├── simulator.py  
          └── test_input.txt  
├── src  
         ├── Command.h  
         ├── Direction.cpp  
         ├── Direction.h  
         ├── Left_Command.cpp  
         ├── Left_Command.h  
         ├── Move_Command.cpp  
         ├── Move_Command.h  
         ├── Parser.cpp  
         ├── Parser.h  
         ├── Place_Command.cpp  
         ├── Place_Command.h  
         ├── Position.cpp  
         ├── Position.h  
         ├── Report_Command.cpp  
         ├── Report_Command.h  
         ├── Right_Command.cpp  
         ├── Right_Command.h  
         ├── Robot.cpp  
         ├── Robot.h  
         ├── Table.cpp  
         └── Table.h  
├── unit_test  
         ├── CMakeLists.txt  
         ├── Left_command_test.cpp  
         ├── Move_command_test.cpp  
         ├── Parser_test.cpp  
         ├── Place_command_test.cpp  
         ├── Report_command_test.cpp  
         ├── Right_command_test.cpp  
         ├── Robot_test.cpp  
         └── Table_test.cpp  
├── CMakeLists.txt  
├── main.cpp  
├── README.md  
├── test_input0.txt  
├── test_input_a.txt  
├── test_input_b.txt  
├── test_input_c.txt  
├── test_input_d.txt  
├── test_input_e.txt  
└── valgrind-out.txt  
```
###
2. Dependencies and Install
    - The application was developed and tested on Ubuntu 18.04, but  should work on Windows. 
    - Here are some core tools or 3rd-party libs which are used in the project
      - gcc 11.1
      - cmake 3.25
      - boost 1.65.1
      - gtest 1.8.0
      - python 3.6
   
    - Here are some useful commands which may help you install the dependencies. Please see the official 
       ```
         sudo apt-get install g++
         sudo apt-get install build-essential
         sudo apt-get install cmake
         sudo apt-get install libgtest-dev
         sudo apt-get install libboost-all-dev
         sudo apt-get install python3.6
       ```

3. Build
         ```
          git clone https://github.com/wangyihuan123/iress_robot.git
          cd iress_robot
          cmake -S. -Bbuild
          cmake --build build
         ```

4. Run
    - Start app with console test on ubuntu. User input  on stdin should be of newline terminated.
         ```
         ./build/iress
         ```
    - Start app with test file
   ```
       ./build/iress test_input0.txt
   ```
   
    - start python simulator for integration test
   ```
   cd integration_test
   python3 simulator.py
   ```


## About tests

1. unit test
```
unit_test  
├── CMakeLists.txt  
├── Left_command_test.cpp  
├── Move_command_test.cpp  
├── Parser_test.cpp  
├── Place_command_test.cpp  
├── Report_command_test.cpp  
├── Right_command_test.cpp  
├── Robot_test.cpp  
└── Table_test.cpp
```



2. integration test

#### input command from test files 
```
├── main.cpp
├── test_input0.txt
├── test_input_a.txt
├── test_input_b.txt
├── test_input_c.txt
├── test_input_d.txt
├── test_input_e.txt
```

```
./iress test_input_a.txt
```

#### input command from console input
```
./iress
```

#### input command from another process
```
├── integration_test
│   ├── simulator.py
│   ├── test_input2.txt
│   └── test_input.txt
```


```
cd ./integration_test
python3 simulator.py
```

3.  dynamic test

#### Valgrind

` sudo apt install valgrind`
 - Run example below and valgrind will generate the output in the file valgrind-out.txt
```

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./build/iress ../test_input_e.txt
   ```

