#!/usr/bin/python3
from shutil import copyfile
import os
import re

category = { 1: "Classical", 2: "Tutorial" }
file_type = { 1: ".cc", 2: ".c", 3: ".bf" }
language = { 1: "C++", 2: "C", 3: "Brainfuck" }
github_link = 'https://github.com/RayZ-O/SPOJ/blob/master/src/'
problem_link = 'http://www.spoj.com/problems/'
draft_path = 'draft/'
src_path = 'src/'
md =  'README.md'

name = input("Problem name\n")
cate = int(input("Category: (1) Classical (2) Tutorial\n"))
ftype = int(input("File type: (1) C++ (2) C (3) Brainfuck\n"))
tag = input("Problem tag\n")


file_name = name.lower() + file_type[ftype]
copyfile(os.path.join(draft_path, 'solution.txt'), os.path.join(src_path+category[cate], file_name))

github_link += category[cate] + '/' + file_name

descr = '|['+name+']('+problem_link+name+'/)|['+language[ftype]+']('+github_link+')| '+tag+' |\n'

f = open(md, "r")
contents = f.readlines()
f.close()

i = 0
while contents[i] != '|------|------|------|\n':
    i += 1

i += 1
classical = []
while contents[i] != '\n':
    classical.append(contents[i])
    i += 1

while contents[i] != '|------|------|------|\n':
    i += 1

i += 1
tutorial = []
while contents[i] != '\n':
    tutorial.append(contents[i])
    i += 1

if cate == 1:
    classical.append(descr)
    classical.sort(key=lambda x: x.split(']')[0])
else:
    tutorial.append(descr)
    tutorial.sort(key=lambda x: x.split(']')[0])

updated = ['# SPOJ problems\n', '\n', '## Classical\n', '|Title | Code | Tag  |\n', '|------|------|------|\n']
for item in classical:
    updated.append(item)
updated.extend(['\n', '## Tutorial\n', '|Title | Code | Tag  |\n', '|------|------|------|\n'])
for item in tutorial:
    updated.append(item)
updated.append('\n')

f = open(md, "w")
contents = "".join(updated)
f.write(contents)
f.close()





