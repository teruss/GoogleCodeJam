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
    Given a input file for C-small-practice
    When I execute the input file
    Then I see the output file
    And check with the expected file
    
  Scenario: Solve large
    Given a input file for C-large-practice
    When I execute the input file
    Then I see the output file
    And check with the expected file

  # Scenario: Solve sample by ruby
  #   Given a file sample.in and sample.expected
  #   When I execute ruby with sample
  #   Then check the sample.out with sample.expected

  # Scenario: Solve small by ruby
  #   Given a file A-small-practice.in
  #   When I execute ruby with A-small-practice
  #   Then check the A-small-practice.out with A-small-practice.expected
    
  # Scenario: Solve large by ruby
  #   Given a file A-large-practice.in
  #   When I execute ruby with A-large-practice
  #   Then the output file A-large-practice.out is there
  #   And check the A-large-practice.out with A-large-practice.expected

  # Scenario: Solve sample by python
  #   Given a file sample.in and sample.expected
  #   When I execute python with sample
  #   Then check the sample.out with sample.expected

  # Scenario: Solve large by python
  #   Given a file A-large-practice.in
  #   When I execute python with A-large-practice
  #   Then the output file A-large-practice.out is there
  #   And check the A-large-practice.out with A-large-practice.expected
