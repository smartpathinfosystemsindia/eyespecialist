


# Add more folders to ship with the application, here
bin.source = qml/shadereffects
bin.target = qml
DEPLOYMENTFOLDERS = bin

# Additional import path used to resolve QML modules in Creator's code model

symbian:TARGET.UID3 = 0xE1CB8EBB
# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the followingTE        = app
TARGET          = eyespecialist


HEADERS         = include/eyespecialistmw.h include/imgfiledialog.h include/eyerecognition.h

FORMS           = src/eyespecialistwindow.ui



 INCLUDEPATH += /usr/include /usr/include/opencv2 include
 CFLAGS  += -I/usr/include -I/usr/include/opencv2   -Iinclude

LIBS += -L/usr/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann  
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
# CONFIG += qdeclarative-boostable

# Add dependency to Symbian components
# CONFIG += qt-components

QT += 

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += src/main.cpp  src/eyespecialist.cpp src/imgfiledialog.cpp src/eyerecognition.cpp

symbian {
    DEFINES += SHADEREFFECTS_USE_OPENGL_GRAPHICSSYSTEM
}

