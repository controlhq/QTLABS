include("C:/Users/Arek/Desktop/QTLABS/lab1/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debugowa/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/lab1-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Users/Arek/Desktop/QTLABS/lab1/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debugowa/lab1.exe
    GENERATE_QT_CONF
)
