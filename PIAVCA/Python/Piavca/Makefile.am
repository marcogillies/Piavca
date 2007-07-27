

# set the include path found by configure
INCLUDES= $(all_includes)

# the library search path.
SUBDIRS = Piavca_base PiavcaGlut 


post_build:
	cd Piavca_base && make post_build
	cd PiavcaGlut && make post_build