Feature: Solve problem
  Scenario: Solve sample by python
    Given a file sample.in and sample.expected
    When I execute python with sample
    Then check the sample.out with sample.expected

  Scenario: Solve small by python
    Given a input file for A-small-practice
    When I execute python using the input file
    Then I see the output file
    And check with the expected file
    
  # Scenario: Solve large by python
  #   Given a input file for C-small-practice-2
  #   When I execute python using the input file
  #   Then I see the output file
  #   And check with the expected file
