echo "Kompilacja logiki"
g++ libleg\CAction.cpp libleg\CAdventure.cpp libleg\CEventManager.cpp libleg\CActor.cpp libleg\CBuilding.cpp libleg\CCity.cpp libleg\CItem.cpp libleg\CLegion.cpp libleg\CMainMap.cpp libleg\CPlayerPattern.cpp libleg\CPlayer.cpp libleg\Tools.cpp libleg\CShop.cpp libleg\CAi.cpp libleg\CSimulatedAction.cpp libleg\legcrypt\CLegCrypt.cpp libleg\legcrypt\CData.cpp -shared -o libleg.dll -Wl,--out-implib,libleg.a
echo "Kompilacja grafiki"
g++ lgfx\CButton.cpp lgfx\CGraphic.cpp lgfx\CGui.cpp lgfx\CWindow.cpp -shared -o libgfx.dll -lirrlicht.dll -Wl,--out-implib,libgfx.a
echo "Kompilacja execa"
g++ main-irrlicht.cpp -L. -lgfx -lleg -o legion.exe

pause
