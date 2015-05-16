Feature: Solve problem
  @python
  Scenario Outline: Solve <program> by python
    Given a input file for <program>
    When I execute python using the input file
    Then I see the output file
    And check with the expected file
    
    Examples: tests
    | program          |
    | sample           |
    | A-small-practice |
    | A-large-practice |
