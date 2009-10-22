import glob
import shutil, os
import zipfile

os.mkdir("ofxPiavca")
os.mkdir("ofxPiavca/example")
os.mkdir("ofxPiavca/example/src")
for file in glob.glob("exampleOFApp/src/*"):
	shutil.copy(file, "ofxPiavca/example/src/")
os.mkdir("ofxPiavca/example/openFrameworks.xcodeproj")
for file in glob.glob("exampleOFApp/openFrameworks.xcodeproj/*"):
	shutil.copy(file, "ofxPiavca/example/openFrameworks.xcodeproj")
#shutil.copytree("exampleOFApp/src","ofxPiavca/example/src")
#shutil.copytree("exampleOFApp/openFrameworks.xcodeproj", "ofxPiavca/example/openFrameworks.xcodeproj")
shutil.copy("exampleOFApp/openFrameworks-Info.plist", "ofxPiavca/example/openFrameworks-Info.plist")


filestart = """
<install>

	<version>0.2.4</version>
	<author>marco gillies/author>
	<url></url>

	<add>

		<!-- 	=====================================================================	-->
		<!--	========================== add per project using this addon =========	-->
		<!-- 	=====================================================================	-->

		<src>
			

"""
fileend = """	
		
		</src>

		<include>
			<path>../../../addons/ofxPiavca/src</path>
		</include>
		
		
	</add>
	
	
</install>
"""

outfile = open("ofxPiavca/install.xml", "w")

print >> outfile, filestart

for folder in ["", "PiavcaAPI", "PiavcaCal3dImp", "StdMotionImp", "cal3d"]:
	os.mkdir("ofxPiavca/src/"+folder)
	print >> outfile, "\t\t\t<folder name=\"addons/ofxPiavca/src/" + folder + "\">"
	for file in glob.glob("src/"+folder+"/*.h")+glob.glob("src/"+folder+"/*.cpp"):
		print file
		shutil.copy(file, "ofxPiavca/"+file)
		print >> outfile, "\t\t\t\t<file>../../../addons/ofxPiavca/"+file+"</file>"
	print >> outfile, "\t\t\t</folder>"

print >> outfile, fileend
outfile.close()

archive = zipfile.ZipFile("ofxPiavca.zip", "w")
for folder in ["src/PiavcaAPI", "src/PiavcaCal3dImp", "src/StdMotionImp", "src/cal3d", "src", "example/src", "example/openFrameworks.xcodeproj", "example", ""]:
	for file in glob.glob("ofxPiavca/"+folder+"/*"):
		archive.write(file)
		os.remove(file)
	os.removedirs("ofxPiavca/"+folder)
archive.close()
