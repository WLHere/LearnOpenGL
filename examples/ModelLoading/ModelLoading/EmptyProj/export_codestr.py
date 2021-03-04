#!/usr/bin/env python
#coding:utf-8

import os
import os.path
import io


print("------------------------------------------------------------------------------------------------")
print("------------------------------------------------------------------------------------------------")

currentPath = os.getcwd()
print "path", currentPath

fileList = os.listdir(currentPath)
for i in range(0, len(fileList)):
	subFileName = fileList[i]
	if (subFileName.endswith(".h")):
		with io.open(currentPath + os.path.sep + subFileName, "r", encoding="utf-8") as file:
			content = file.read()
			print("------------------------------------------------------------------------------------------------")
			print "\n" + subFileName + "\n"
			if (content.startswith("#version 330 core")):
				for line in content.split("\n"):
					if len(line.strip()) > 0:
						print "\"" + line + "\\n\""
			print ""

print("------------------------------------------------------------------------------------------------")
print("------------------------------------------------------------------------------------------------")