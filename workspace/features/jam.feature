Feature: Solve problem
  Scenario: Create Makefile using CMake
    Given a file CMakeLists.txt
    When I create build directory
    And I move to the build directory
    And I execute command "cmake .."
    Then I see a Makefile

  Scenario: Execute Makefile to create execute file
    Given a file Makefile
    When I execute command "make"
    Then I see a exec

  Scenario: Solve
    Given a file exec
    When I move to the .. directory
    And I execute command "build/exec < sample.in > sample.out"
    Then check the sample.out with sample.expected
    
  Scenario: Solve
    Given a input file for C-small-practice-1
    When I execute the input file
    Then I see the output file
    And check with the expected file
    
  Scenario: Solve
    Given a input file for C-small-practice-2
    When I execute the input file
    Then I see the output file
    And check with the expected file
    
  Scenario: Solve large
    Given a input file for C-large-practice
    When I execute the input file
    Then I see the output file
    And check with the expected file
