import os.path
from behave import *
import shlex, subprocess

@given(u'a file sample.in and sample.expected')
def step_impl(context):
    assert os.path.isfile("sample.in") is True
    assert os.path.isfile("sample.expected") is True

@given(u'a file {filename}')
def step_impl(context, filename):
    assert os.path.isfile(filename) is True

@when(u'I execute program with {program}')
def step_impl(context, program):
    p = subprocess.call("build/bin/exec < " + program + ".in > " + program + ".out", shell=True)
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

@then(u'check the {filename1} with {filename2}')
def step_impl(context, filename1, filename2):
    f1 = open(filename1)
    f2 = open(filename2)

    file1lines = f1.readlines()
    file2lines = f2.readlines()

    print (len(file1lines), ":", len(file2lines))
    assert len(file1lines) == len(file2lines)

    for i in range(0, len(file1lines)):
        print (file1lines[i] + "," + file2lines[i])
        print (file1lines[i] == file2lines[i])
        assert file1lines[i] == file2lines[i]

@when(u'I execute python with {filename}')
def step_impl(context, filename):
    command = "python main.py < " + filename + ".in > "+filename+".out"
    p = subprocess.call(command, shell=True)
    assert p is 0
