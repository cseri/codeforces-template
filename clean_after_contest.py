# Removes folders for compiled files of a contest to save space.

import glob
import os
import shutil

def remove_if_exists(target):
  if os.path.exists(target):
    shutil.rmtree(target)

taskList = ["TaskA", "TaskB", "TaskC", "TaskD", "TaskE"]

for f in glob.glob("*.db"):
  os.remove(f)

# TODO: Should we remove the .vs folder? It is small so I decided to leave it
# for now.
#remove_if_exists(".vs")
remove_if_exists("x64")
for task in taskList:
  remove_if_exists(task+"/x64")

