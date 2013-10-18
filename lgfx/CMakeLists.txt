SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_library(lgfx SHARED 
    CGraphic.cpp
    CMapGui.cpp
    CWindow.cpp
    CButton.cpp
)

target_link_libraries (lgfx Irrlicht)
##target_link_libraries(leg sqlite3)
