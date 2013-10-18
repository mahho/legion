SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_library(leg SHARED CAction.cpp CAdventure.cpp
CEventManager.cpp
CActor.cpp
CBuilding.cpp
CCity.cpp
CItem.cpp
CLegion.cpp
CMainMap.cpp
CPlayerPattern.cpp
CPlayer.cpp
Tools.cpp
CShop.cpp

# sztuczna inteligencja + symulacja
CAi.cpp
CSimulatedAction.cpp

# obsluga plikow szyfrowanych
legcrypt/CLegCrypt.cpp
legcrypt/CData.cpp 
)

#target_link_libraries(leg lua)
