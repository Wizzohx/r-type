# r-type
R-type game client and server
# Présentation
R-type est un jeu de type shooteur le but de ce projet était donc de créer un serveur de jeu avec la possibilités de connecter plusieurs client sur un jeu de type shooteur
# Réalisation
Langage : C++
Installation - Compilation : conan
# Execution
# 1er terminal
cd r-type/server

mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --buid .

./rtype_server
# 2eme terminal
cd r-type/client

mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --buid .

./rtype
