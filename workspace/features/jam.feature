Feature: Solve problem
  Scenario: Solve
    Given a file sample.in and sample.expected
    When I execute program with sample
    Then check the sample.out with sample.expected
    
  # Scenario: Solve
  #   Given a file A-small-practice.in
  #   When I execute program with A-small-practice
  #   Then check the A-small-practice.out with A-small-practice.expected
    
  # Scenario: Solve large
  #   Given a file A-large-practice.in
  #   When I execute program with A-large-practice
  #   Then the output file A-large-practice.out is there
  #   And check the A-large-practice.out with A-large-practice.expected

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
