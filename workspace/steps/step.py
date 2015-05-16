import os
import os.path
from behave import *
import shlex, subprocess
import glob
import re

@when(u'I create build directory')
def step_impl(context):
    if not os.path.exists("build"):
        os.mkdir("build")

@when(u'I move to the {name} directory')
def step_impl(context, name):
    os.chdir(name)

@when(u'I execute command "{command}"')
def step_impl(context, command):
    subprocess.call(command, shell=True)

@then(u'I see a {filename}')
def step_impl(context, filename):
    assert os.path.isfile(filename)

@given(u'a file sample.in and sample.expected')
def step_impl(context):
    assert os.path.isfile("sample.in")
    assert os.path.isfile("sample.expected")

@given(u'a file {filename}')
def step_impl(context, filename):
    assert os.path.isfile(filename) is True

@given(u'a input file for {program}')
def step_impl(context, program):
    assert os.path.isfile(program + ".in")
    context.program = program

@when(u'I execute the input file')
def step_impl(context):
    program = context.program
    p = subprocess.call("build/exec < " + program + ".in > " + program + ".out", shell=True)
    assert p is 0

@then(u'I see the output file')
def step_impl(context):
    assert os.path.isfile(context.program + ".out")

@when(u'I execute program with {program}')
def step_impl(context, program):
    p = subprocess.call("build/exec < " + program + ".in > " + program + ".out", shell=True)
    assert p is 0

@then(u'the output file {filename} is there')
def step_impl(context, filename):
    assert os.path.isfile(filename) is True

@when(u'I execute ruby with {filename}')
def step_impl(context, filename):
    command = "ruby main.rb < " + filename + ".in > "+filename+".out"
    p = subprocess.call(command, shell=True)
    print(p)
    assert p is 0

def is_almost_same(line1, line2):
    if line1 == line2:
        return True
    print(line1)
    
def compare_files(filename1, filename2):
    print (filename1, filename2)
    f1 = open(filename1)
    f2 = open(filename2)

    file1lines = f1.readlines()
    file2lines = f2.readlines()

    assert len(file1lines) == len(file2lines)

    prog = re.compile('(Case #\d+: )(\d+\.?\d*)')
    for i in range(0, len(file1lines)):
        line1 = file1lines[i]
        line2 = file2lines[i]
        print (line1 + line2)
        l1 = prog.match(line1)
        l2 = prog.match(line2)
        assert l1.group(1) == l2.group(1)
        assert round(float(l1.group(2)) - float(l2.group(2)), 7) == 0
    
@then(u'check the {filename1} with {filename2}')
def step_impl(context, filename1, filename2):
    compare_files(filename1, filename2)

@then(u'check with the expected file')
def step_impl(context):
    p = context.program
    expected = p + ".expected"
    if not os.path.isfile(expected):
        context.scenario.skip()
        return

    compare_files(p + ".out", expected)

def exec_python(program):
    command = "python main.py < {0}.in > {0}.out".format(program)
    p = subprocess.call(command, shell=True)
    print(command)
    assert p is 0
    
@when(u'I execute python with {filename}')
def step_impl(context, filename):
    exec_python(filename)

@when(u'I execute python using the input file')
def step_impl(context):
    exec_python(context.program)

@given(u'input files')
def step_impl(context):
    context.inputs = glob.glob("*.in")
    assert context.inputs

@when(u'I execute python using the input files')
def step_impl(context):
    context.programs = []
    for filename in context.inputs:
        program = filename[:-3]
        context.programs.append(program)
        exec_python(program)

@then(u'I see the output files')
def step_impl(context):
    for program in context.programs:
        assert os.path.isfile(program + ".out")

@then(u'check with the expected files')
def step_impl(context):
    for program in context.programs:
        if os.path.isfile(program + ".expected"):
            compare_files(program + ".out", program + ".expected")
