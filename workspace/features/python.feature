Feature: Solve problem
  Scenario: Solve sample by python
    Given a file sample.in and sample.expected
    When I execute python with sample
    Then check the sample.out with sample.expected

  Scenario: Solve all by python
    Given input files
    When I execute python using the input files
    Then I see the output files
    And check with the expected files
    
  # Scenario: Solve large by python
  #   Given a input file for B-large-practice
  #   When I execute python using the input file
  #   Then I see the output file
  #   And check with the expected file
