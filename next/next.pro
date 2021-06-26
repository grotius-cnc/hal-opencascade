# QT -= gui
QT += core gui opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
DEFINES += NEXT_LIBRARY

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    next.cpp \
    opencascade.cpp

HEADERS += \
    mainwindow.h \
    next_global.h \
    next.h \
    opencascade.h

# lcnc
INCLUDEPATH +=  /usr/lib/ \
                /opt/lib/linuxcnc/modules/ \
                /opt/include/ \
                /usr/include/linuxcnc/

#Hal
INCLUDEPATH+=   /opt/linuxcnc/include/ \
                /opt/linuxcnc/src/hal/ \


LIBS+= -L/opt/linuxcnc/lib/
LIBS+= -llinuxcnchal

#Opencascade
LIBS+= -L/usr/local/lib/ \

INCLUDEPATH +=  /usr/local/include/kdl/ \
                /usr/local/include/opencascade/ \
                /usr/include/eigen3/ \
                /usr/include/ \
                /usr/local/lib/ \

LIBS +=  -llinuxcnchal -Iinclude -Isrc/emc/rs274ngc -Llib -lnml -llinuxcnc -llinuxcnchal -llinuxcncini -lposemath

# Opencascade
LIBS += -lTKPrim
LIBS += -lTKernel -lTKMath -lTKTopAlgo -lTKService
LIBS += -lTKG2d -lTKG3d -lTKV3d -lTKOpenGl
LIBS += -lTKBRep -lTKXSBase -lTKGeomBase
LIBS += -lTKMeshVS -lTKXSDRAW
LIBS += -lTKLCAF -lTKXCAF -lTKCAF
LIBS += -lTKCDF -lTKBin -lTKBinL -lTKBinXCAF -lTKXml -lTKXmlL -lTKXmlXCAF
# -- IGES support
LIBS += -lTKIGES
# -- STEP support
LIBS += -lTKSTEP -lTKXDESTEP -lTKXDEIGES
# -- STL support
LIBS += -lTKSTL
# -- OBJ/glTF support

LIBS += -lTKRWMesh

#src/base/io_occ_base_mesh.cpp \
#src/base/io_occ_gltf.cpp \
#src/base/io_occ_obj.cpp

# -- VRML support
LIBS += -lTKVRML

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    mainwindow.ui
