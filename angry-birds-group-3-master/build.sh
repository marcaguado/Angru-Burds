
#Qt:

qt_inst_dir=$(cat config.txt | grep "Qt install directory")
qt_inst_dir=${qt_inst_dir#*:}
PATH_TO_qtpaths=$(find $qt_inst_dir -name "qtpaths" | grep /bin/qtpaths)
PATH_TO_qtpaths=${PATH_TO_qtpaths%qtpaths}

VAR=$(${PATH_TO_qtpaths}qtpaths --query | grep QT_INSTALL_HEADERS)
QT_INSTALL_HEADERS=${VAR#*:}

if [ "$QT_INSTALL_HEADERS" == "" ]
then
	echo "qtpaths was not found from '$qt_inst_dir'"
	echo "Searching path..."
	PATH_TO_qtpaths=""

	VAR=$(${PATH_TO_qtpaths}qtpaths --query | grep QT_INSTALL_HEADERS)
	QT_INSTALL_HEADERS=${VAR#*:}
		
	if [ "$QT_INSTALL_HEADERS" == "" ]
		then
			echo "Searching the whole system..."
			
			PATH_TO_qtpaths=$(find / -wholename "*/bin/qtpaths" | grep /bin/qtpaths)
			PATH_TO_qtpaths=${PATH_TO_qtpaths%qtpaths}
		fi
		
		if [ "$PATH_TO_qtpaths" == "" ]
		then
			echo "Problem: program qtpaths was not found."
			echo "Do you have Qt installed?"
		fi
fi

echo "qtpaths dir:"
echo $PATH_TO_qtpaths

VAR=$(${PATH_TO_qtpaths}qtpaths --query | grep QT_INSTALL_HEADERS)
export QT_INSTALL_HEADERS=${VAR#*:}

VAR=$(${PATH_TO_qtpaths}qtpaths --query | grep QT_INSTALL_LIBS)
export QT_INSTALL_LIBS=${VAR#*:}

VAR=$(${PATH_TO_qtpaths}qtpaths --query | grep QT_INSTALL_BINS)
export QT_INSTALL_BINS=${VAR#*:}

VAR=$(${PATH_TO_qtpaths}qtpaths --query | grep QT_INSTALL_LIBEXECS)
export QT_INSTALL_LIBEXECS=${VAR#*:}


# Box2D:

#VAR=$(cat config.txt | grep "Box2D install directory")
#export BOX2DDIR=${VAR#*:}

export BOX2DDIR="libs/box2d"

echo $BOX2DDIR


# Build:

make


# Make the execution script:

if [ -f "Angry Birds" ];
then
		rm "Angry Birds"
fi

VAR=$(${PATH_TO_qtpaths}qtpaths --query | grep QT_INSTALL_BINS)
QT_INSTALL_BINS=${VAR#*:}

VAR=$(${PATH_TO_qtpaths}qtpaths --query | grep QT_INSTALL_PLUGINS )
QT_INSTALL_PLUGINS=${VAR#*:}

echo "export PATH=$QT_INSTALL_BINS:\$PATH">>"Angry Birds"
echo "export LD_LIBRARY_PATH=$QT_INSTALL_LIBS:\$LD_LIBRARY_PATH">>"Angry Birds"
echo "export QT_PLUGIN_PATH=$QT_INSTALL_PLUGINS">>"Angry Birds"
echo "">>"Angry Birds"
echo "bin/main">>"Angry Birds"
chmod +x Angry\ Birds
